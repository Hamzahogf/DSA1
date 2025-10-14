#include <iostream>

int main() {
    int n;

    std::cout << "Enter an integer n: ";
    std::cin >> n;

    int u = 3; // Initial value for u(0)

    for (int i = 0; i < n; ++i) {
        u = 3 * u + 4;
    }

    std::cout << "u(" << n << ") = " << u << std::endl;

    return 0;
}















#include <iostream>

int main() {
    int n;

    std::cout << "Enter an integer n: ";
    std::cin >> n;

    int u0 = 1, u1 = 1;

    int result;

    if (n == 0) {
        result = u0;
    } else if (n == 1) {
        result = u1;
    } else {
        for (int i = 2; i <= n; ++i) {
            result = u0 + u1;
            u0 = u1;
            u1 = result;
        }
    }

    std::cout << "u(" << n << ") = " << result << std::endl;

    return 0;
}













#include <iostream>

int calculateUN(int n) {
    if (n == 0) {
        return 3;
    } else if (n == 1) {
        return 2;
    } else {
        int u0 = 3, u1 = 2, result;
        for (int i = 2; i <= n; ++i) {
            result = i * u1 + (i + 1) * u0 + i;
            u0 = u1;
            u1 = result;
        }
        return result;
    }
}
int main() {
    int n;

    
    std::cout << "Enter an integer n: ";
    std::cin >> n;

    
    int result = calculateUN(n);

    
    std::cout << "u(" << n << ") = " << result << std::endl;

    return 0;
}















#include <iostream>

int fibonacci(int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main() {
    int n;

    
    std::cout << "Enter an integer n: ";
    std::cin >> n;

   
    int result = fibonacci(n);

    
    std::cout << "u(" << n << ") = " << result << std::endl;

    return 0;
}













#include <iostream>


int findHCF(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

   
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    
    int hcf = findHCF(num1, num2);
    std::cout << "The HCF of " << num1 << " and " << num2 << " is: " << hcf << std::endl;

    return 0;
}












#include <iostream>
void printHollowRectangle(int rows, int columns) {
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= columns; ++j) {
            
            if (i == 1 || i == rows || j == 1 || j == columns) {
                std::cout << "*";
            } else {
                
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
int main() {
    int rows, columns;

    
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    std::cout << "Enter the number of columns: ";
    std::cin >> columns;

    
    printHollowRectangle(rows, columns);

    return 0;
}









#include <iostream>
int reverseDigits(int number) {
    int reversedNumber = 0;

    while (number != 0) {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }

    return reversedNumber;
}
int main() {
    int inputNumber;

    std::cout << "Enter an integer: ";
    std::cin >> inputNumber;

    int reversedNumber = reverseDigits(inputNumber);
    std::cout << "Reversed Number: " << reversedNumber << std::endl;

    return 0;
}












#include <iostream>

bool isPerfectNumber(int number) {
    if (number <= 0) {
        return false; 
    }

    int sum = 0;

    for (int i = 1; i <= number / 2; ++i) {
        if (number % i == 0) {
            sum += i;
        }
    }

    return (sum == number);
}
int main() {
    int inputNumber;

    std::cout << "Enter a positive integer: ";
    std::cin >> inputNumber;

    if (isPerfectNumber(inputNumber)) {
        std::cout << inputNumber << " is a perfect number.\n";
    } else {
        std::cout << inputNumber << " is not a perfect number.\n";
    }

    return 0;
}











#include <iostream>
#include <cmath>

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int countPrimesUpToN(int N) {
    int count = 0;

    for (int i = 2; i <= N; ++i) {
        if (isPrime(i)) {
            count++;
        }
    }

    return count;
}

int main() {
    int inputNumber;

    std::cout << "Enter an integer N: ";
    std::cin >> inputNumber;

    int primeCount = countPrimesUpToN(inputNumber);
    std::cout << "The number of prime numbers up to " << inputNumber << " is: " << primeCount << std::endl;

    return 0;
}












#include <iostream>

bool isPrime(int n) {
    if (n <= 1) {
        return false; 
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false; 
        }
    }

    return true; 
}
int nthPrime(int n) {
    int count = 0;
    int num = 2;

    while (count < n) {
        if (isPrime(num)) {
            count++;
        }
        if (count < n) {
            num++;
        }
    }

    return num;
}
int main() {
    int n;

    std::cout << "Enter the value of n: ";
    std::cin >> n;

    int result = nthPrime(n);
    std::cout << "The " << n << "th prime number is: " << result << std::endl;

    return 0;
}
