#include <iostream>
using namespace std;

int main() {
    char character;

    cout << "Enter a character: ";
    cin >> character;

    // Convert the character to lowercase to handle both upper and lower case vowels
    character = tolower(character);

    if (character >= 'a' && character <= 'z') {
        if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u') {
            cout << character << " is a vowel." << endl;
        } else {
            cout << character << " is a consonant." << endl;
        }
    } else {
        cout << character << " is not a valid alphabet character." << endl;
    }

    return 0;
}