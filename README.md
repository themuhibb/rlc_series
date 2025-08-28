# ⚡ RLC Series Circuit Calculator

A modern **C++ console-based tool** for analyzing **RLC series circuits**.
This program walks you step by step through the calculations of reactances, impedance, current, and voltage drops across each element — both in **rectangular** and **polar form** — with beautifully formatted outputs using SI prefixes.

Whether you are an **electrical engineering student**, a **hobbyist**, or just curious about AC circuit analysis, this project provides both **accuracy** and **clarity** in learning and verification.

---

## ✨ Features

* 📥 **Smart Input Handling**
  Enter values with SI prefixes like `1k`, `100m`, `470n`, `10u`, etc.

* 🔢 **Step-by-Step Calculations**
  Shows every formula and substitution along the way — making it an **educational tool** as well as a calculator.

* 📐 **Dual Representation of Complex Numbers**

  * Rectangular Form: `a + jb`
  * Polar Form: `|Z| ∠ θ°`

* ⚡ **Comprehensive Results**

  * Inductive Reactance (XL)
  * Capacitive Reactance (XC)
  * Total Impedance (Z)
  * Circuit Current (I)
  * Voltage drops across R, L, and C

* 🎯 **Human-Friendly Output**
  Automatic formatting with **unit prefixes** (k, m, µ, n, p) and clean equation display.

---

## 📊 Example Run

```
Hello, Welcome to the RLC Series Circuit Calculator!
----------------------------------------------------

Enter the Measured Value of Resistance (Ohm, e.g., 1k): 2.1k
Enter the Measured Value of Inductance (H, e.g., 100m): 25.56m
Enter the Measured Value of Capacitance (F, e.g., 470n): 470n
Enter the AC Source Frequency (Hz, e.g., 60): 1k
Enter the AC Source Voltage Magnitude (V, e.g., 10): 10

--- Calculation Steps ---

Calculating Inductive Reactance (XL)...
Formula: XL = 2πfL
XL = 160.69 Ohm

Calculating Capacitive Reactance (XC)...
Formula: XC = 1 / (2πfC)
XC = 338.63 Ohm

...
Total Impedance (Z):
  - Rectangular Form: 2100.000 Ohm - j177.940 Ohm
  - Polar Form:       2107.532 Ohm ∠ -4.85°
```

---

## 🛠️ How to Build & Run

### Prerequisites

* A C++17 (or later) compatible compiler (e.g., `g++`, `clang++`, MSVC).

### Build

```bash
g++ -std=c++17 -o rlc_calculator rlc_calculator.cpp
```

### Run

```bash
./rlc_calculator
```

---

## 📚 Educational Value

This project was written with the intent to be more than a calculator:

* **For Students** → Reinforces AC circuit concepts, phasor representation, and impedance analysis.
* **For Teachers** → Acts as a live demonstration tool in classrooms.
* **For Enthusiasts** → Helps double-check hand calculations and simulations.

---

## 🚀 Future Improvements

* Add support for **parallel RLC circuits**.
* Option to export results into **CSV/Markdown/PDF**.
* Enhanced formatting with **LaTeX-style equations** in output.
* GUI version for an interactive experience.

---

## ❤️ Contribution

Contributions, suggestions, and improvements are most welcome!
If you find a bug, have an idea, or want to enhance the features, feel free to **open an issue** or **submit a pull request**.

---

## 📜 License

This project is released under the **MIT License**. You are free to use, modify, and distribute it with attribution.

---

🔥 **RLC Series Circuit Calculator — Turning Complex Numbers into Simple Insights!** ⚡

---

