# 🔐 DIY Arduino Security Camera

A personal project aimed at building a DIY security camera system using Arduino. The system detects motion and captures images, sending alerts via email or SMS.

## 📸 Project Overview

This project integrates an Arduino with a motion sensor and a camera module to monitor a designated area. When motion is detected, the system captures an image and sends an alert to a predefined contact.

## 🧰 Features

- **Motion Detection**: Utilizes a PIR sensor to detect movement.
- **Image Capture**: Captures images upon motion detection.
- **Alerts**: Sends notifications via email or SMS.
- **Modular Design**: Easy to expand with additional features like cloud storage or real-time streaming.

## 🛠️ Hardware Requirements

- Arduino Uno or compatible board
- PIR Motion Sensor
- Camera Module (e.g., OV7670)
- Wi-Fi Module (e.g., ESP8266) or GSM Module for SMS
- Jumper wires and breadboard
- Power supply

## 🖥️ Software Requirements

- Arduino IDE
- Python 3.x
- Required Python libraries:
  - `opencv-python`
  - `pyserial`
  - `smtplib`
  - `dotenv`

## 🚀 Getting Started

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/bgowda14/ARDUINO.git
Set Up the Arduino:

Connect the PIR sensor and camera module to the Arduino as per the schematic.

Upload the Motion_Sensor.ino sketch to the Arduino using the Arduino IDE.

Configure the Python Script:

Navigate to the Security directory.

Create a .env file with your email credentials:

ini
Copy
Edit
EMAIL_USER=your_email@example.com
EMAIL_PASSWORD=your_email_password
Install the required Python libraries:

bash
Copy
Edit
pip install opencv-python pyserial python-dotenv
Run the Python script:

bash
Copy
Edit
python security.py
📁 Repository Structure
pgsql
Copy
Edit
ARDUINO/
├── Hand Recognition/
│   └── [Files related to hand recognition feature]
├── Motion_Sensor.ino
├── Security/
│   └── security.py
└── README.md
🤝 Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your enhancements.

📬 Contact
For questions or suggestions, feel free to open an issue or contact me at bgowda1412@gmail.com.

 
