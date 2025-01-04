#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <vector>

int main() {
    const char* username = getenv("USER");

    if (username) {
        cout << "Hello, " << username << "! Welcome to the Number Guessing Game!\n";
    } else {
        cout << "Hello, Linux user! Welcome to the Number Guessing Game!\n";
    }

    srand(static_cast<unsigned int>(std::time(0)));

    bool playAgain = true;
    std::string input;
    int totalRounds = 0;

    while (playAgain) {
        totalRounds++;
        int target = rand() % 100 + 1;
        int guess;
        int attempts = 0;
        vector<int> guesses;
        
        cout << "I've chosen a number between 1 and 100. Try to guess it!\n";
        cout << "Type 'exit' anytime to quit the game.\n";

        bool guessedCorrectly = false;
        
        while (!guessedCorrectly) {
            cout << "Enter your guess: ";
            cin >> input;

            if (input == "exit") {
                cout << "Thanks for playing! Goodbye, " << (username ? username : "Linux user") << "!\n";
                cout << "Total rounds played: " << totalRounds - 1 << "\n";
				cout << "Correct number was: " << target << "\n";
                return 0;
            }

            try {
                guess = stoi(input);
            } catch (...) {
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            if (guess < 1 || guess > 100) {
                cout << "Out of range! Please guess a number between 1 and 100.\n";
                continue;
            }

            attempts++;
            guesses.push_back(guess);

            if (guess > target) {
                cout << "Too high! Try again.\n";
            } else if (guess < target) {
                cout << "Too low! Try again.\n";
            } else {
                cout << "Congratulations! You guessed it in " << attempts << " attempts.\n";
                guessedCorrectly = true;
            }
        }

        cout << "Your guesses in this game were: ";
        for (int g : guesses) {
            cout << g << " ";
        }
        cout << "\n";
        cout << "Total guesses in this game: " << attempts << "\n";

        char choice;
        cout << "Do you want to play again? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            playAgain = false;
            cout << "Thanks for playing, " << (username ? username : "Linux user") << "! Goodbye!\n";
            cout << "Total rounds played: " << totalRounds << "\n";
        }
    }

    return 0;
}

