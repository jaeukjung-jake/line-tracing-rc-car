# Line-Tracing RC Car using Arduino and C

This project implements an autonomous line-tracing RC car using an Arduino Uno and IR sensors, fully programmed in C at the register level. Rather than relying on Arduino libraries, all control logic—including serial communication and PWM motor control—was implemented through custom header files to better understand low-level embedded system behavior.

---

## 📌 Features

- 🧩 Modular architecture using custom headers (`Serial.h`, `mylib.h`) in `include/` and `lib/`
- 🧠 Direction-tracking and line recovery using `enum`-based state logic
- 🛑 Stop-line detection with conditional delay and halt mechanism
- ⚙️ PWM motor control using Timer0 and Timer2 on the AVR (OCR0A, OCR2A)
- 🔧 Pure C implementation (no Arduino libraries used)

---

## 📂 Project Structure

EELAB/AVR/
├── CPP/
│ └── main.c # Main logic for sensor input and motor control
├── include/
│ └── Serial.h # Custom header for serial communication
├── lib/
│ └── mylib.h # Header file for motor control logic and pin macros
└── ...


---

## 🧪 How It Works

- The system uses **3 IR sensors** (left, center, right) to detect black lines on a white track.
- The car moves forward when the center sensor is active, and turns left or right based on side sensors.
- If all sensors are inactive (line lost), it recalls the last valid direction and uses a hard-turning routine to recover.
- **Stop line detection** is implemented to halt the car after a short delay when all sensors detect black.

---

## 🛠️ Built With

- C (AVR-level, compiled for Arduino Uno)
- Arduino Uno
- 3-channel IR sensor module
- L298N motor driver module
- Custom PWM/Serial control with `avr/io.h`, `util/delay.h`

---

## 📸 Demo

> _(You can add a YouTube or video link here)_  
> Example: [Watch the RC Car in Action](https://youtu.be/your-demo-link)

---

## 📜 License

This project is open-source and licensed under the MIT License.

---

## 🙋 Author

**Jaeuk Jung** ([@jaeukjung-jake](https://github.com/jaeukjung-jake))  
Feel free to explore, reuse, or contribute!
