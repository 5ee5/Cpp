#include <iostream>
using namespace std;
#include <cstdlib>    // For rand(), srand(), and getenv()
#include <ctime>      // For time()
#include <limits>     // For std::numeric_limits
#include <string>     // For std::string
#include <vector>     // For std::vector to store guesses

int main() {
    // Get the username from the environment variable
    const char* username = getenv("USER");

    // Greet the user
    if (username) {
        cout << "Hello, " << username << "! Welcome to the Number Guessing Game!\n";
    } else {
        cout << "Hello, Linux user! Welcome to the Number Guessing Game!\n";
    }

    srand(static_cast<unsigned int>(std::time(0)));

    bool playAgain = true;
    std::string input;
    int totalRounds = 0;  // Counter for the number of rounds played

    while (playAgain) {
        totalRounds++;  // Increment rounds counter
        int target = rand() % 100 + 1;  // Random number between 1 and 100
        int guess;
        int attempts = 0;           // Track guesses within the current game
        vector<int> guesses;   // Vector to store each guess in the current game
        
        cout << "I've chosen a number between 1 and 100. Try to guess it!\n";
        cout << "Type 'exit' anytime to quit the game.\n";

        bool guessedCorrectly = false;
        
        // Game loop
        while (!guessedCorrectly) {
            cout << "Enter your guess: ";
            cin >> input;

            // Check if the player wants to exit
            if (input == "exit") {
                cout << "Thanks for playing! Goodbye, " << (username ? username : "Linux user") << "!\n";
                cout << "Total rounds played: " << totalRounds - 1 << "\n";  // Subtract 1 to not count the unfinished game
				cout << "Correct number was: " << target << "\n";
                return 0;  // Exit the program immediately
            }

            // Convert input to an integer if it's a valid guess
            try {
                guess = stoi(input);
            } catch (...) {
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            // Check if the guess is out of range
            if (guess < 1 || guess > 100) {
                cout << "Out of range! Please guess a number between 1 and 100.\n";
                continue;
            }

            attempts++;  // Count valid guesses in the current game
            guesses.push_back(guess);  // Store the guess in the vector

            // Check if the guess is correct
            if (guess > target) {
                cout << "Too high! Try again.\n";
            } else if (guess < target) {
                cout << "Too low! Try again.\n";
            } else {
                cout << "Congratulations! You guessed it in " << attempts << " attempts.\n";
                guessedCorrectly = true;
            }
        }

        // Display all guesses made during the game
        cout << "Your guesses in this game were: ";
        for (int g : guesses) {
            cout << g << " ";
        }
        cout << "\n";
        cout << "Total guesses in this game: " << attempts << "\n";

        // Ask if the player wants to play again
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

