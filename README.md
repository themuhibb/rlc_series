# rlc_series
RLC Series Circuit Solver Giving Voltages and Currents using Phasor Representation

📋 Table of Contents
Project Overview

Features

Getting Started

How to Use

Example Walkthrough

Contributing

License

💡 Project Overview
The core purpose of this project is to simplify the complex calculations involved in AC circuit analysis. By handling the math for reactance and impedance, the program serves as an excellent educational tool for electrical engineering students and a useful utility for hobbyists and professionals. The output is formatted clearly, making it easy to check intermediate values and understand the entire process.

✨ Features
Interactive Console Interface: Prompts the user for all necessary circuit parameters.

Engineering Prefix Support: Accepts common prefixes like k (kilo), m (milli), u (micro), n (nano), and p (pico) for input values.

Comprehensive Calculations: Computes:

Inductive Reactance (X_L)

Capacitive Reactance (X_C)

Total Circuit Impedance (Z)

Total Circuit Current (I)

Voltage Drops across Resistor (V_R), Inductor (V_L), and Capacitor (V_C).

Dual Format Output: All calculated complex values (Impedance, Current, Voltages) are displayed in both rectangular (a+jb) and polar (r
angle
theta) forms.

Step-by-Step Breakdown: Shows the formulas and intermediate calculation steps to help in understanding the solution process.

🚀 Getting Started
Prerequisites
To compile and run this program, you need a C++ compiler installed on your system.

Windows: MinGW, Visual Studio

macOS: Xcode Command Line Tools

Linux: g++ (usually pre-installed or can be installed via your package manager)

Installation and Build
Clone this repository to your local machine:

Bash

git clone https://github.com/your-username/rlc-calculator.git
cd rlc-calculator
Compile the main.cpp file using your C++ compiler. For g++, use the following command:

Bash

g++ main.cpp -o rlc_calculator
This command creates an executable file named rlc_calculator (or rlc_calculator.exe on Windows).

Run the executable from your terminal:

Bash

./rlc_calculator
📝 How to Use
The program will guide you through the required inputs. Simply follow the prompts and enter the requested values. The program intelligently handles the units based on the prefixes you provide.

Example Input Prompts:

Enter the Measured Value of Resistance (Ohm, e.g., 1k):

Enter the Measured Value of Inductance (H, e.g., 100m):

Enter the AC Source Frequency (Hz, e.g., 60):

🧪 Example Walkthrough
Let's run the calculator with a sample set of values to see the output.

Input Values:

Resistance (R): 100
Omega

Inductance (L): 100
textmH

Capacitance (C): 470
textnF

Frequency (f): 60
textHz

Source Voltage (V): 10
textV

Output from the program:

Hello, Welcome to the RLC Series Circuit Calculator!
----------------------------------------------------
Enter the Measured Value of Resistance (Ohm, e.g., 1k): 100
Enter the Measured Value of Inductance (H, e.g., 100m): 100m
Enter the Measured Value of Capacitance (F, e.g., 470n): 470n
Enter the AC Source Frequency (Hz, e.g., 60): 60
Enter the AC Source Voltage Magnitude (V, e.g., 10): 10

--- Calculation Steps ---

Calculating Inductive Reactance (XL)...
Formula: XL = 2πfL
XL = 2(3.142)(60)(100.0 m)
XL = 37.700 Ohm

Calculating Capacitive Reactance (XC)...
Formula: XC = 1 / (2πfC)
XC = 1 / (2(3.142)(60)(470.0 n))
XC = 5.643 kOhm

Calculating Total Impedance (Z)...
Formula: Z = R + j(XL - XC)
Z = 100 + j(37.700 - 5.643 k)
Z = 100.000 + j-5.605 kOhm

Z in Polar Form:
Magnitude |Z| = sqrt(R^2 + (XL - XC)^2)
|Z| = sqrt(100.000^2 + (37.700 - 5.643 k)^2)
|Z| = 5.606 kOhm
Phase Angle ∠Z = arctan((XL - XC) / R)
∠Z = arctan((37.700 - 5.643 k) / 100.000)
∠Z = -88.98°

Calculating Total Current (I)...
Formula: I = V_source / Z
I = (10.000∠0°) / (5.606 k∠-88.98°)
I = 1.784 m∠88.98°A

...and so on for the voltage drops...
🤝 Contributing
Contributions are welcome! If you find a bug or have an idea for an improvement, please open an issue or submit a pull request.

📄 License
This project is licensed under the MIT License. See the LICENSE file for details.
