#include <iostream>
using namespace std;

int main() {
    char character;

    cout << "Enter a character: ";
    cin >> character;

    int asciiValue = static_cast<int>(character);

    cout << "ASCII value of " << character << " is " << asciiValue << endl;

    return 0;
}