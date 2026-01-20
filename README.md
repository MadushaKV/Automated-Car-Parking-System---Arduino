# Automated-Car-Parking-System---Arduino
An Arduino-based automated car park system using ultrasonic sensor, load cell, LDR and servo motor.

---

## 📌 Project Overview
This project demonstrates an automated car park system using Arduino.  
The system controls vehicle entry, lighting, and vehicle weight checking automatically using sensors and actuators.

---

## 🔧 Hardware Components
- Arduino Uno
- Ultrasonic Sensor (HC-SR04)
- Servo Motor (Gate Mechanism)
- Load Cell with HX711 Module
- LDR Sensor
- Red LED and Green LED
- External 5V Power Supply

---

## ⚙️ System Functionality

### 🚦 Gate Control (Ultrasonic + Servo)
The ultrasonic sensor detects a vehicle approaching the gate.
- When a vehicle is detected within 10 cm, the servo motor rotates 90° to open the gate.
- After a short delay, the gate automatically closes.

### ⚖️ Vehicle Weight Detection (Load Cell)
The load cell measures the vehicle weight:
- Weight **> 1000g** → Red LED turns ON (Overweight vehicle)
- Weight **100g – 1000g** → Green LED turns ON (Allowed vehicle)
- Weight **≤ 100g** → Both LEDs OFF

### 💡 Automatic Lighting System (LDR)
The LDR sensor monitors ambient light:
- Low light conditions → Parking lights turn ON
- Bright conditions → Parking lights turn OFF

---

## 📷 Project Images
All project images such as the circuit diagram, hardware setup, and working demonstration are available in this **Repo**.

---

## 🧠 Applications
- Smart parking systems
- Automated access control systems
- Smart city projects
- Educational Arduino projects

---

## 👤 Author
**L. G. Madusha Kavinda**  
Bachelor of ICT – University of Sri Jayewardenepura

