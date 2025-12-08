#include <iostream>
using namespace std;

int main() {
int year_of_birth;
string name;
int current_year = 2025;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your year of birth: ";
    cin >> year_of_birth;
    int age = current_year - year_of_birth;
    
    cout << "Hello, " << name << endl << "You are "<< age << " years old!" << endl;
    return 0;
}