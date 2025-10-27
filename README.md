# 🤖 CLEAR: Collision-Less Environment-Aware Robot

This repository contains my implementation of the **CLEAR (Collision-Less Environment-Aware Robot) Project**, developed as part of my *Robotics and Embedded Systems research*.

##  Overview
CLEAR is a mobile robot running on an **Arduino**, equipped with an **ultrasonic sensor** in front to detect distances in real-time. The robot maintains a **safe distance of 10 cm** from obstacles to prevent collisions.  

Key components of the project:
- Real-time **distance measurement** using an ultrasonic sensor 📏
- Noise attenuation using a **digital 2nd-order low-pass filter** to smooth sensor readings 🔇
- **PID control** for maintaining safe distance with **no overshoot**, optimized using MATLAB PID Tuner 🎯
- Tuning of filter frequencies for delay and behavior optimization ⚡

The system ensures that the robot **stops before reaching an object**, prioritizing safety and precision.

## 📷 Visual Demonstrations (images + tags)

Below are the screenshots and demonstration images.  
Place the image files in the repository folder `assets/` and ensure filenames match exactly.

| Image file (assets/) | Tags | Caption |
|---|---:|---|
| `robot-overview.png` | `CLEAR`, `Arduino`, `mobile-robot`, `setup` | Mobile robot hardware setup with Arduino and ultrasonic sensor. |
| `ultrasonic-readings.png` | `ultrasonic`, `distance`, `sensor-data`, `filter` | Real-time ultrasonic distance readings with 2nd-order low-pass filter applied. |
| `pid-response.png` | `PID`, `control`, `no-overshoot`, `MATLAB` | PID controller response showing precise stopping at 10 cm without overshoot. |
| `robot-navigation.png` | `navigation`, `collision-avoidance`, `safe-distance` | Robot approaching obstacle while maintaining safe distance. |

---

### Inline images with captions

### 📏 Real-Time Distance Sensing
Uses ultrasonic sensor data smoothed with a 2nd-order digital low-pass filter.

<figure>
  <img src="assets/ultrasonic-readings.png" alt="CLEAR - Ultrasonic Readings" />
  <figcaption><strong>Ultrasonic Readings</strong> · Tags: <code>ultrasonic</code>, <code>distance</code>, <code>sensor-data</code>, <code>filter</code></figcaption>
</figure>

---

### 🎯 PID Distance Control
Maintains a safe 10 cm distance using a PID controller with no overshoot, tuned with MATLAB.

<figure>
  <img src="assets/pid-response.png" alt="CLEAR - PID Response" />
  <figcaption><strong>PID Response</strong> · Tags: <code>PID</code>, <code>control</code>, <code>no-overshoot</code>, <code>MATLAB</code></figcaption>
</figure>

---

### 🤖 Mobile Robot Setup
Arduino-based mobile robot with front-facing ultrasonic sensor for collision avoidance.

<figure>
  <img src="assets/robot-overview.png" alt="CLEAR - Robot Overview" />
  <figcaption><strong>Robot Setup</strong> · Tags: <code>CLEAR</code>, <code>Arduino</code>, <code>mobile-robot</code>, <code>setup</code></figcaption>
</figure>

<figure>
  <img src="assets/robot-navigation.png" alt="CLEAR - Navigation Demo" />
  <figcaption><strong>Navigation Demo</strong> · Tags: <code>navigation</code>, <code>collision-avoidance</code>, <code>safe-distance</code></figcaption>
</figure>

---

## ⚙️ How to Run
1. Connect the Arduino to your PC.
2. Upload `CLEAR.ino` (Arduino sketch) to the robot.
3. Open the Serial Monitor to view real-time distance readings.
4. The robot will automatically stop before obstacles, maintaining **10 cm safe distance**.

```bash
# Example commands for Arduino CLI
arduino-cli compile --fqbn arduino:avr:uno CLEAR
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno CLEAR
