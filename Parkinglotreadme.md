# Ultrasonic Sensor-Based Automatic Gate Control

This project uses an **ultrasonic sensor** and a **servo motor** to detect nearby objects (like vehicles) and automatically open a gate when the object is within a specified distance.

## 📌 Components Used
- Arduino UNO (or compatible board)
- Ultrasonic Sensor (HC-SR04)
- Servo Motor (e.g., SG90)
- Jumper Wires
- Breadboard (optional)

## ⚙️ Pin Configuration

| Component        | Arduino Pin |
|------------------|-------------|
| Ultrasonic Trig  | 6           |
| Ultrasonic Echo  | 7           |
| Servo Signal     | 9           |

## 🧠 How It Works
1. The ultrasonic sensor continuously measures distance.
2. If the measured distance is **less than 10 cm**, the servo rotates to open the gate.
3. The gate remains open for **3 seconds**, then automatically closes.
4. If the object is not within range, the gate remains closed.

## 🧾 Code Overview

- `servo.attach(servoPin)`: Connects servo to digital pin.
- Sends ultrasonic pulse and listens for the echo.
- Converts pulse duration into distance.
- Uses `servo.write(90)` to open gate and `servo.write(0)` to close it.

## 📟 Serial Monitor Output

The serial monitor displays the current distance reading from the ultrasonic sensor in centimeters.


## ⏱️ Delays
- `delayMicroseconds(10)`: Triggers ultrasonic pulse.
- `delay(3000)`: Keeps gate open for 3 seconds when an object is detected.
- `delay(500)`: Adds a short delay between distance checks to stabilize readings.

## 📷 Schematic Diagram
> (Optional: You can insert a Fritzing diagram or photo of your setup here.)

## 🔐 Applications
- Smart gates or parking barriers
- Contactless access systems
- Automated door systems

## 📄 License
This project is open-source and available for educational and hobby use.

---

