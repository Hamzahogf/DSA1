#include <iostream>

int main() {
    int N;
    std::cout << "Enter the value of N: ";
    std::cin >> N;

    int sum = 0;
    int count = 1; // Start with the first odd natural number

    for (int i = 1; i <= N; i++) {
        sum += count;
        count += 2; // Move to the next odd natural number
    }

    std::cout << "The sum of the first " << N << " odd natural numbers is: " << sum << std::endl;

    return 0;
}