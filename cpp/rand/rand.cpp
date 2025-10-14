#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    int minRange = 8;
    int maxRange = 23;

    int num1 = rand() % (maxRange - minRange + 1) + minRange;
    int num2 = rand() % (maxRange - minRange + 1) + minRange;

    // Generate and display the random numbers
    std::cout << "Find the sum of two random numbers between " << minRange << " and " << maxRange << ".\n";
    std::cout << "First random number: " << num1 << std::endl;
    std::cout << "Second random number: " << num2 << std::endl;

    int correctSum = num1 + num2;
    int playerGuess;

    // Prompt the player for their answer
    std::cout << "Enter your guess for the sum: ";
    std::cin >> playerGuess;

    // Check if the player's answer is correct
    if (playerGuess == correctSum) {
        std::cout << "Congratulations! You win the game!\n";
    } else {
        std::cout << "Sorry, your answer is incorrect. The correct sum is: " << correctSum << "\n";
    }

    return 0;
}



