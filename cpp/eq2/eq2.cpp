#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    double discriminant, root1, root2;

    cout << "Enter the coefficients (a, b, and c) of the quadratic equation ax^2 + bx + c = 0: ";
    cin >> a >> b >> c;

    // Calculate the discriminant
    discriminant = b * b - 4 * a * c;

    // Check the discriminant to find the roots
    if (discriminant > 0) {
        // Two real and distinct roots
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Root 1 = " << root1 << endl;
        cout << "Root 2 = " << root2 << endl;
    } else if (discriminant == 0) {
        // One real root
        root1 = -b / (2 * a);
        cout << "Root = " << root1 << endl;
    } else {
        // Complex roots
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i" << endl;
    }

    return 0;
}