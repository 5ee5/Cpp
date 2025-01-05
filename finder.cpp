#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    char symbol;
    int count = 0;
    
    cout << "Enter a word:";
    cin >> word;
    
    cout << "Enter a symbol: ";
    cin >> symbol;
    
    for (char c : word) {
        if (c == symbol) {
            count++;
        }
    }
    cout << "\nFound " << count << " symbols\n";

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();
return 0;
}