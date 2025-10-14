#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double number;
    double base, exponent;

    cout << "Enter the base: ";
    cin >> base;

    cout << "Enter the exponent: ";
    cin >> exponent;

    double result = pow(base, exponent);
    cout << "Result: " << result << endl;

    cout << "Enter a number: ";
    cin >> number;

    // Absolute value
    double absoluteValue = abs(number);
    cout << "Absolute value: " << absoluteValue << endl;

    // Exponential (e^x)
    double exponentialValue = exp(number);
    cout << "Exponential value: " << exponentialValue << endl;

    // Square root
    double squareRootValue = sqrt(number);
    cout << "Square root: " << squareRootValue << endl;

    // Natural logarithm (ln)
    double naturalLogValue = log(number);
    cout << "Natural logarithm: " << naturalLogValue << endl;


    return 0;
}