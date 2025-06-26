
# Line-Tracing RC Car using Arduino and C

This project implements an autonomous line-tracing RC car using Arduino Uno and IR sensors, fully controlled with low-level C programming. Rather than using Arduino's built-in functions, core features like `Serial`, `PWM`, and GPIO control were implemented manually to deepen understanding of the AVR microcontroller.

---

## 📌 Features

- 🔧 Direct register-level motor control using C (no Arduino libraries)
- 🧠 Direction memory & dynamic recovery logic using enums
- 🛑 Stop line detection based on IR sensor patterns
- ⚙️ PWM control using Timer0 and Timer2 (AVR register settings)
- 🧩 Modular structure using custom headers (`Serial.h`, `mylib.h`, etc.)

---

## 📂 Project Structure

