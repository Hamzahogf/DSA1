#include <iostream>

int main() {
    int sum = 0;
    int count = 0;
    int num;

    std::cout << "Enter positive integers (type a negative number to retype, 0 to calculate):" << std::endl;

    while (true) {
        std::cin >> num;

        if (num < 0) {
            std::cout << "ERROR: Please enter a positive integer." << std::endl;
        } else if (num == 0) {
            if (count > 0) {
                double mean = static_cast<double>(sum) / count;
                std::cout << "Average: " << mean << std::endl;
            } else {
                std::cout << "No positive integers entered, so no average to calculate." << std::endl;
            }
            break;
        } else {
            sum += num;
            count++;
        }
    }

    return 0;
}