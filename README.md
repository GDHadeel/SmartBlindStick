# Smart Blind Stick Using Arduino

## Introduction
The Smart Blind Stick is designed to assist visually impaired individuals in navigating safely and independently. It uses ultrasonic sensors, a water sensor, a buzzer, and a vibration motor to provide real-time feedback on obstacles and hazardous surfaces.

## Features
- **Obstacle Detection:** Ultrasonic sensors (front, left, right) detect nearby objects.
- **Water Detection:** Identifies wet/slippery surfaces to prevent slips.
- **Feedback:** Buzzer and vibration motor provide auditory and tactile alerts.

## Components
- Arduino Uno  
- 3 Ultrasonic Sensors (HC-SR04)  
- Water Sensor  
- Buzzer  
- Vibration Motor  
- 9V Battery  

## Functionality
- **Obstacle & Water Detection:** Sensors measure distances and monitor moisture levels.  
- **Feedback Mechanisms:** Buzzer and motor activate when hazards are detected.  
- **Melody Alerts:** Plays distinct tunes for water and obstacles.  
- **Serial Monitor:** Displays real-time sensor data.  

## Circuit
- **Ultrasonic sensors:** Pins 9, 5, 7 (TRIG), and 10, 6, 8 (ECHO).  
- **Water sensor:** Pin A0.  
- **Buzzer:** Pin 11.  
- **Vibration motor:** Pin 12.  

## Future Enhancements
- GPS integration for navigation.  
- Bluetooth audio feedback.  
- Improved ergonomic design.  

## Acknowledgments
Developed by **Hadeel Balahmar**, **Deema AHmidah**, **Shumokh Abdullah**, and **Wejdan Alshateri** for the **CS4111 - Programming Embedded Systems** course at Effat University, supervised by **Dr. Zain Balfagih**.
