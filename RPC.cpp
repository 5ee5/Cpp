#include <iostream>
#include <vector>
#include <random>
using namespace std;
int main() {
    char player;

    cout << "Enter Your choice (R/P/S): ";
    cin >> player;
    vector<char> rps = {'R', 'P', 'S'};

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, rps.size() - 1);
    char computer = rps[dist(gen)];
    cout << "Computer picked: " << computer << endl;

    if (computer == player) {
        cout << "It's a tie!" << endl;
    }
    if ((player == 'R' && computer == 'S') ||
        (player == 'P' && computer == 'R') ||
        (player == 'S' && computer == 'P')) {
        cout << "You win!" << endl;
    }
    else {
        cout << "Computer wins!" << endl;
    }


    return 0;
}