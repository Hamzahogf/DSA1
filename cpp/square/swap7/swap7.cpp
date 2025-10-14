
#include <iostream>

void swapIntegers(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int main() {
    int a = 5;
    int b = 10;

    std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;

    swapIntegers(a, b);

    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;

    return 0;
}