#include <iostream>
#include <cmath>
using namespace std;

double calculateFunctionValue(double x, bool& isDefined) {
    if ((x >= 1) && (x >= 2)) {
        isDefined = true;
        double result = sqrt((x - 1) * (x - 2));
        return result;
    } else {
        isDefined = false;
        return 0.0; // Return a default value (you can change this if needed)
    }
}

int main() {
    double x ;  // Replace with the desired value of x
    bool isDefined;  // Replace with the determination of whether the function is defined at x
    cin>>x;
    double result = calculateFunctionValue(x, isDefined);

    if (isDefined) {
        std::cout << "The function is defined at x = " << x << " and the result is " << result << std::endl;
    } else {
        std::cout << "The function is not defined at x = " << x << std::endl;
    }

    return 0;
}
