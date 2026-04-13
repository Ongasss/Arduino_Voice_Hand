🤖 Arduino Voice Hand (Voice-Controlled Prosthesis)
This project enables the control of a robotic hand or prosthesis driven by servo motors using
voice commands in Portuguese. The system features a Python-based interface for audio
processing and real-time serial communication with the Arduino.

🛠️ Overview
Voice Recognition: Leverages the Google Speech Recognition API to convert spoken words into executable commands.

Serial Communication: Establishes a bridge between the PC and Arduino via USB for low-latency control.

Servo Actuation: Translates text commands into precise angular movements for the robotic limb.

Auto-Shutdown: Includes a "stop" command to safely close the serial port and terminate the script.

📋 Prerequisites
Hardware
Arduino Board: (Uno, Nano, or Mega)

Servo Motor: (e.g., SG90 or MG995)

Microphone: (Headset or built-in)

Jumpers and Breadboard

Software Dependencies
Python 3.12+

Libraries: SpeechRecognition, pyserial, pyaudio

🗣️ Voice Commands
The system is currently configured to recognize the following commands (in Portuguese):
"Abrir" (Open)  Moves the servo to 180°  b'A'
"Fechar" (Close)  Returns the servo to 0°  b'F'
"Parar" (Stop)  Closes connection and exits  exit()

🗂️ Project Structure
Plaintext
├── Hand/
│   ├── main.py              # Python brain (Speech-to-Serial)
│   ├── .gitignore           # Ignored files (pycache, pio, etc.)
│   └── src/
│       └── main.cpp         # Arduino firmware (C++)
└── README.md                # Project documentation

🤝 Contributing
Feel free to fork this project, report issues, or submit pull requests to improve the recognition accuracy or add new movement patterns.

Developed by Ongasss 🚀
