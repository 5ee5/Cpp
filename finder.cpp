#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    char symbol;
    int count = 0;
    
    cout << "Ievadi vardu:";
    cin >> word;
    
    cout << "ievadi simbolu: ";
    cin >> symbol;
    
    for (char c : word) {
        if (c == symbol) {
            count++;
        }
    }
    cout << "\nAtrada " << count << " simbolus\n";

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();
return 0;
}