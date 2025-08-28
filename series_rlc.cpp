#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <complex>
#include <sstream>

using namespace std;

const char ANGLE_SYMBOL[] = "\u2220";
const char DEGREE_SYMBOL[] = "\u00B0";
const char PI_SYMBOL[] = "\u03C0";
const double PI = M_PI;

double to_degrees(double radians) {
    return radians * 180.0 / PI;
}

double get_prefixed_value(const string& prompt) {
    string input_str;
    cout << prompt;
    cin >> input_str;

    double multiplier = 1.0;
    char prefix = ' ';

    if (!input_str.empty()) {
        prefix = input_str.back();
        switch (prefix) {
            case 'k': // Kilo (10^3)
                multiplier = 1e3;
                break;
            case 'm': // Milli (10^-3)
                multiplier = 1e-3;
                break;
            case 'u': // Micro (10^-6)
                multiplier = 1e-6;
                break;
            case 'n': // Nano (10^-9)
                multiplier = 1e-9;
                break;
            case 'p': // Nano (10^-12)
                multiplier = 1e-9;
                break;
	
            default:
                break;
        }
    }


    if (multiplier != 1.0) {
        input_str = input_str.substr(0, input_str.length() - 1);
    }

    return stod(input_str) * multiplier;
}

string format_prefixed_value(double value, const string& unit) {
    if (value == 0.0) {
        return "0 " + unit;
    }
    
    const double powers[] = {1e9, 1e6, 1e3, 1, 1e-3, 1e-6, 1e-9, 1e-12};
    const string prefixes[] = {"G", "M", "k", "", "m", "u", "n", "p"};
    
    double abs_value = abs(value);
    int prefix_index = 3; // Start at the 'no prefix' position
    
    if (abs_value >= 1000.0) {
        for (int i = 0; i < 3; ++i) {
            if (abs_value >= powers[i]) {
                prefix_index = i;
                break;
            }
        }
    } else if (abs_value < 1.0) {
        for (int i = 4; i < 8; ++i) {
            if (abs_value >= powers[i]) {
                prefix_index = i;
                break;
            }
        }
    }
    
    stringstream ss;
    ss << fixed << setprecision(3) << value / powers[prefix_index] << " " << prefixes[prefix_index] << unit;
    return ss.str();
}

void print_rectangular(const complex<double>& val, const string& unit) {
    cout << format_prefixed_value(val.real(), unit);
    if (val.imag() >= 0) {
        cout << " + j" << format_prefixed_value(val.imag(), unit);
    } else {
        cout << " - j" << format_prefixed_value(abs(val.imag()), unit);
    }
}

void print_polar(const complex<double>& val, const string& unit) {
    cout << format_prefixed_value(abs(val), unit) << ANGLE_SYMBOL << to_degrees(arg(val)) << DEGREE_SYMBOL;
}

int main() {
    cout << "Hello, Welcome to the RLC Series Circuit Calculator!" << endl;
    cout << "----------------------------------------------------" << endl;


    double resistance = get_prefixed_value("Enter the Measured Value of Resistance (Ohm, e.g., 1k): ");
    double inductance = get_prefixed_value("Enter the Measured Value of Inductance (H, e.g., 100m): ");
    double capacitance = get_prefixed_value("Enter the Measured Value of Capacitance (F, e.g., 470n): ");
    double frequency = get_prefixed_value("Enter the AC Source Frequency (Hz, e.g., 60): ");
    double source_voltage_magnitude = get_prefixed_value("Enter the AC Source Voltage Magnitude (V, e.g., 10): ");
    complex<double> source_voltage(source_voltage_magnitude, 0.0);

    cout << "\n--- Calculation Steps ---" << endl;
    
    cout << "\nCalculating Inductive Reactance (XL)..." << endl;
    cout << "Formula: XL = 2" << PI_SYMBOL << "fL" << endl;
    cout << "XL = 2(" << PI << ")(" << format_prefixed_value(frequency, "") << ")(" << format_prefixed_value(inductance, "") << ")" << endl;
    double xl_magnitude = 2.0 * PI * frequency * inductance;
    cout << "XL = " << format_prefixed_value(xl_magnitude, "Ohm") << endl;

    cout << "\nCalculating Capacitive Reactance (XC)..." << endl;
    cout << "Formula: XC = 1 / (2" << PI_SYMBOL << "fC)" << endl;
    cout << "XC = 1 / (2(" << PI << ")(" << format_prefixed_value(frequency, "") << ")(" << format_prefixed_value(capacitance, "") << "))" << endl;
    double xc_magnitude = 1.0 / (2.0 * PI * frequency * capacitance);
    cout << "XC = " << format_prefixed_value(xc_magnitude, "Ohm") << endl;


    complex<double> xl(0.0, xl_magnitude);
    complex<double> xc(0.0, -xc_magnitude);
    complex<double> resistor_z(resistance, 0.0);


    cout << "\nCalculating Total Impedance (Z)..." << endl;
    cout << "Formula: Z = R + j(XL - XC)" << endl;
    cout << "Z = " << format_prefixed_value(resistance, "") << " + j(" << format_prefixed_value(xl_magnitude, "") << " - " << format_prefixed_value(xc_magnitude, "") << ")" << endl;
    complex<double> total_impedance = resistor_z + xl + xc;
    cout << "Z = ";
    print_rectangular(total_impedance, "Ohm");
    cout << endl;
    cout << "\nZ in Polar Form:" << endl;
    cout << "Magnitude |Z| = sqrt(R^2 + (XL - XC)^2)" << endl;
    cout << "|Z| = sqrt(" << format_prefixed_value(resistance, "") << "^2 + (" << format_prefixed_value(xl_magnitude, "") << " - " << format_prefixed_value(xc_magnitude, "") << ")^2)" << endl;
    cout << "|Z| = " << format_prefixed_value(abs(total_impedance), "Ohm") << endl;
    cout << "Phase Angle " << ANGLE_SYMBOL << "Z = arctan((XL - XC) / R)" << endl;
    cout << ANGLE_SYMBOL << "Z = arctan((" << format_prefixed_value(xl_magnitude, "") << " - " << format_prefixed_value(xc_magnitude, "") << ") / " << format_prefixed_value(resistance, "") << ")" << endl;
    cout << ANGLE_SYMBOL << "Z = " << to_degrees(arg(total_impedance)) << DEGREE_SYMBOL << endl;

    cout << "\nCalculating Total Current (I)..." << endl;
    cout << "Formula: I = V_source / Z" << endl;
    cout << "I = (" << format_prefixed_value(source_voltage_magnitude, "") << ANGLE_SYMBOL << "0" << DEGREE_SYMBOL << ") / (" << format_prefixed_value(abs(total_impedance), "") << ANGLE_SYMBOL << to_degrees(arg(total_impedance)) << DEGREE_SYMBOL << ")" << endl;
    complex<double> total_current = source_voltage / total_impedance;
    cout << "I = ";
    print_polar(total_current, "A");
    cout << endl;


    cout << "\nCalculating Voltage Drop across Resistor (VR)..." << endl;
    cout << "Formula: VR = IR" << endl;
    cout << "VR = (";
    print_polar(total_current, "");
    cout << ")(" << format_prefixed_value(resistance, "") << ANGLE_SYMBOL << "0" << DEGREE_SYMBOL << ")" << endl;
    complex<double> voltage_resistor = total_current * resistor_z;
    cout << "VR = ";
    print_polar(voltage_resistor, "V");
    cout << endl;

    cout << "\nCalculating Voltage Drop across Inductor (VL)..." << endl;
    cout << "Formula: VL = IjXL" << endl;
    cout << "VL = (";
    print_polar(total_current, "");
    cout << ")(" << format_prefixed_value(xl_magnitude, "") << ANGLE_SYMBOL << "90" << DEGREE_SYMBOL << ")" << endl;
    complex<double> voltage_inductor = total_current * xl;
    cout << "VL = ";
    print_polar(voltage_inductor, "V");
    cout << endl;
    
    cout << "\nCalculating Voltage Drop across Capacitor (VC)..." << endl;
    cout << "Formula: VC = I(-jXC)" << endl;
    cout << "VC = (";
    print_polar(total_current, "");
    cout << ")(" << format_prefixed_value(xc_magnitude, "") << ANGLE_SYMBOL << "-90" << DEGREE_SYMBOL << ")" << endl;
    complex<double> voltage_capacitor = total_current * xc;
    cout << "VC = ";
    print_polar(voltage_capacitor, "V");
    cout << endl;


    cout << "\n--- Final Circuit Values ---" << endl;


    cout << "Circuit Parameters:" << endl;
    cout << "  - Resistance:   " << format_prefixed_value(resistance, "Ohm") << endl;
    cout << "  - Inductance:   " << format_prefixed_value(inductance, "H") << endl;
    cout << "  - Capacitance:  " << format_prefixed_value(capacitance, "F") << endl;
    cout << "  - Frequency:    " << format_prefixed_value(frequency, "Hz") << endl;
    cout << "  - Source Voltage: " << format_prefixed_value(source_voltage_magnitude, "V") << endl;
    cout << "--------------------------------------------" << endl;

    cout << "Total Impedance (Z):" << endl;
    cout << "  - Rectangular Form: ";
    print_rectangular(total_impedance, "Ohm");
    cout << endl;
    cout << "  - Polar Form:       ";
    print_polar(total_impedance, "Ohm");
    cout << endl;
    cout << "--------------------------------------------" << endl;

    cout << "Total Current (I):" << endl;
    cout << "  - Rectangular Form: ";
    print_rectangular(total_current, "A");
    cout << endl;
    cout << "  - Polar Form:       ";
    print_polar(total_current, "A");
    cout << endl;
    cout << "--------------------------------------------" << endl;

    cout << "Voltage Drop across Resistor (VR):" << endl;
    cout << "  - Rectangular Form: ";
    print_rectangular(voltage_resistor, "V");
    cout << endl;
    cout << "  - Polar Form:       ";
    print_polar(voltage_resistor, "V");
    cout << endl;

    cout << "\nVoltage Drop across Inductor (VL):" << endl;
    cout << "  - Rectangular Form: ";
    print_rectangular(voltage_inductor, "V");
    cout << endl;
    cout << "  - Polar Form:       ";
    print_polar(voltage_inductor, "V");
    cout << endl;

    cout << "\nVoltage Drop across Capacitor (VC):" << endl;
    cout << "  - Rectangular Form: ";
    print_rectangular(voltage_capacitor, "V");
    cout << endl;
    cout << "  - Polar Form:       ";
    print_polar(voltage_capacitor, "V");
    cout << endl;

    return 0;
}
