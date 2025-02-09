# **RoboGuideX**  
**Autonomous Mobile Robot for Obstacle Avoidance and Traffic Light Detection**  

## **📌 Overview**  
RoboGuideX is an **Arduino-based autonomous mobile robot** designed to navigate safely in dynamic environments. It integrates multiple sensors for **real-time obstacle avoidance** and **traffic light recognition**, enabling smooth and intelligent movement with minimal human intervention.  

## **🔹 Features**  
✅ **Obstacle Detection & Avoidance** – Uses an **ultrasonic sensor** to detect and navigate around obstacles.  
✅ **Traffic Light Recognition** – A **TCS230 color sensor** identifies red traffic lights and stops accordingly.  
✅ **Smart Navigation System** – Prioritizes stopping at traffic lights while efficiently avoiding obstacles.  
✅ **DC Motor Control** – Uses an **L298N motor driver** for precise movement control.  
✅ **Arduino-Based Implementation** – Powered by an **Arduino Uno** for efficient processing.  

## **🛠️ Components & Hardware**  
- **Arduino Uno R3** – Main controller for decision-making.  
- **HC-SR04 Ultrasonic Sensor** – Detects obstacles in the path.  
- **TCS230 Color Sensor** – Recognizes traffic light colors.  
- **L298N Motor Driver** – Controls motor movement.  
- **DC Motors with Gearbox** – Enables movement and navigation.  
- **SG90 Servo Motor** – Adjusts the sensor’s angle for better obstacle detection.  
- **Power Supply (Batteries)** – Provides energy for the system.  
- **2-Wheel Robot Chassis** – Physical base for the robot.  

## **🔧 System Architecture & Working**  
1. **Obstacle Avoidance**:  
   - The **ultrasonic sensor** continuously scans for objects in front of the robot.  
   - If an obstacle is detected, the robot decides whether to move left, right, or stop.  

2. **Traffic Light Detection**:  
   - The **color sensor** checks for red lights.  
   - If a red signal is detected, the robot halts until it turns green.  

3. **Movement & Decision Making**:  
   - The robot prioritizes **stopping at red lights** over obstacle avoidance.  
   - If no traffic signal is detected, it continues moving while avoiding obstacles.  

## **📜 Installation & Setup**  
### **1️⃣ Clone the Repository**  
```bash
git clone https://github.com/Nadazeineedin/RoboGuideX.git
cd RoboGuideX
```
### **2️⃣ Upload Code to Arduino**  
- Open the **Arduino IDE**.  
- Connect the **Arduino Uno** via USB.  
- Upload the provided **Arduino C code** (`RoboGuideX.ino`).  

### **3️⃣ Assemble the Hardware**  
- Connect the **ultrasonic and color sensors** to the Arduino.  
- Wire the **L298N motor driver** to the motors.  
- Secure the components onto the **chassis**.  

### **4️⃣ Power Up & Test**  
- Insert the batteries and power on the system.  
- Place obstacles and traffic signals in its path to test functionality.  

## **📌 Future Enhancements**  
🔹 Implement **machine learning** for smarter navigation.  
🔹 Enhance **traffic signal recognition** with more color detection.  
🔹 Integrate **GPS and Bluetooth** for remote control and tracking.  
🔹 Use **LiDAR sensors** for more precise obstacle detection.  

## **📄 License**  
This project is licensed under the **MIT License** – you are free to modify and distribute it.

Note 🌟
This project done by 
**Nada Zeineddin** 
**khaled Alyousef**
**zuhour Alsaqa**

## 🎥 Demo Video  
[![Watch the Video](https://img.youtube.com/vi/VIDEO_ID/maxresdefault.jpg)](https://github.com/user-attachments/assets/5f307b24-138e-4543-bc58-131b10712d67)


## **📩 Contact & Contributions**  
💡 **Contributions are welcome!** Feel free to submit issues or pull requests.  
📧 For inquiries, reach out to **[nadazeineddin29@gmail.com]**.  

---
