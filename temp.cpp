#include <iostream>
using namespace std;

int main() {
int temperature_in_celsius;
int temperature_in_fahrenheit;
string choice;

    cout << "Enter your choice (CtoF or FtoC): ";
    cin >> choice;

    if (choice == "CtoF") {
        cout << "Enter temperature in Celsius: ";
        cin >> temperature_in_celsius;
        temperature_in_fahrenheit = (temperature_in_celsius * 9/5) + 32;
        cout << "Temperature in Fahrenheit: " << temperature_in_fahrenheit << endl;
    }
    else if (choice == "FtoC") {
        cout << "Enter temperature in Fahrenheit: ";
        cin >> temperature_in_fahrenheit;
        temperature_in_celsius = (temperature_in_fahrenheit - 32) * 5/9;
        cout << "Temperature in Celsius: " << temperature_in_celsius << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}