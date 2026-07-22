#include <iostream>
#include <string>
#include <algorithm> // for transform
using namespace std;
// decimal has to be 0 and return to '0'
// Function 1: Decimal to Binary
string decimalToBinary(int decimal) {
    if (decimal == 0) return "0";
    string binary = "";
    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}
//change binary to decimal 
// Function 2: Binary to Decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int length = binary.length();
    for (int i = 0; i < length; i++) {
        char bit = binary[length - i - 1];
        if (bit == '1') {
            decimal += 1 << i;
        } else if (bit != '0') {
            throw invalid_argument("Invalid binary digit!");



        }
    }
    return decimal;
}
// change decimal to hexadecimal
// Function 3: Decimal to Hexadecimal
string decimalToHexadecimal(int decimal) {
    if (decimal == 0) return "0";
    string hex = "";
    string hexDigits = "0123456789ABCDEF";
    while (decimal > 0) {
        hex = hexDigits[decimal % 16] + hex;
        decimal /= 16;
    }
    return hex;
}

// Function 4: Hexadecimal to Decimal
int hexadecimalToDecimal(string hex) {
    int decimal = 0;
    int base = 1; // 16^0
    transform(hex.begin(), hex.end(), hex.begin(), ::toupper); // ensure uppercase
    for (int i = hex.length() - 1; i >= 0; i--) {
        char c = hex[i];
        if (c >= '0' && c <= '9') {
            decimal += (c - '0') * base;



        } else if (c >= 'A' && c <= 'F') {
            decimal += (c - 'A' + 10) * base;
        } else {
            throw invalid_argument("Invalid hexadecimal digit!");
        }
        base *= 16;
    }
    return decimal;
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        cout << "\nConversion Menu:\n";
        cout << "1. Decimal to Binary\n";
        cout << "2. Binary to Decimal\n";
        cout << "3. Decimal to Hexadecimal\n";
        cout << "4. Hexadecimal to Decimal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        try {
            switch (choice) {



                case 1: {
                    int decimal;
                    cout << "Enter a decimal number: ";
                    cin >> decimal;
                    cout << "Binary representation: " << decimalToBinary(decimal) << endl;
                    break;
                }
                case 2: {
                    string binary;
                    cout << "Enter a binary number (only 0s and 1s): ";
                    cin >> binary;
                    cout << "Decimal representation: " << binaryToDecimal(binary) << endl;
                    break;
                }
                case 3: {
                    int decimal;
                    cout << "Enter a decimal number: ";
                    cin >> decimal;
                    cout << "Hexadecimal representation: " << decimalToHexadecimal(decimal) <<
endl;
                    break;
                }
                case 4: {
                    string hex;
                    cout << "Enter a hexadecimal number (0-9, A-F): ";
                    cin >> hex;



                    cout << "Decimal representation: " << hexadecimalToDecimal(hex) << endl;
                    break;
                }
                case 5:
                    running = false;
                    cout << "Exiting program..." << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } catch (const invalid_argument &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
