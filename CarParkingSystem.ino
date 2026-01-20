#include <Servo.h>
#include <HX711.h>

// HX711
#define DT A0
#define SCK A1
#define RED_LED 5
#define GREEN_LED 4

// Ultrasonic
#define trigPin 12
#define echoPin 8

// Servo
#define SERVO_PIN 2
Servo gateServo;

// LDR
#define LDR_PIN A2
#define LIGHT_LED 13

HX711 scale;

bool gateOpen = false;
unsigned long gateTimer = 0;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(LIGHT_LED, OUTPUT);

  gateServo.attach(SERVO_PIN);
  gateServo.write(0);

  scale.begin(DT, SCK);
  scale.set_scale(2280.0);   // ⚠️ CHANGE AFTER CALIBRATION
  scale.tare();

  Serial.println("Car Park System Ready");
}

void loop() {

  /* ---------- LDR ---------- */
  int ldrValue = analogRead(LDR_PIN);
  digitalWrite(LIGHT_LED, ldrValue < 500 ? HIGH : LOW);

  /* ---------- Ultrasonic ---------- */
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);
  distance = duration * 0.034 / 2;

  if (distance > 0 && distance <= 10 && !gateOpen) {
    gateServo.write(90);
    gateOpen = true;
    gateTimer = millis();
    Serial.println("Gate Open");
  }

  if (gateOpen && millis() - gateTimer > 3000) {
    gateServo.write(0);
    gateOpen = false;
    Serial.println("Gate Close");
  }

  /* ---------- Load Cell ---------- */
  if (scale.is_ready()) {
    float weight = scale.get_units();
    Serial.print("Weight: ");
    Serial.println(weight);

    if (weight > 1000) {
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
    }
    else if (weight > 100) {
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
    }
    else {
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, LOW);
    }
  }

  delay(200);
}
