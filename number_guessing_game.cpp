
#include <iostream>
#include <cstdlib>
#include <ctime>

void playNumberGuessingGame() {
    int number, guess, attempts = 0;
    const int MAX_NUMBER = 100;

    // Seed the random number generator
    std::srand(std::time(0));
    number = std::rand() % MAX_NUMBER + 1;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have selected a number between 1 and " << MAX_NUMBER << ".\n";
    std::cout << "Can you guess what it is?\n\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > number) {
            std::cout << "Too high! Try again.\n";
        } else if (guess < number) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        }

    } while (guess != number);
}

int main() {
    char playAgain;

    do {
        playNumberGuessingGame();

        std::cout << "\nDo you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thank you for playing! Goodbye!\n";
    return 0;
}
