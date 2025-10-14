#include <iostream>
using namespace std;

int main() {
    int N, sum = 0;

    cout << "Enter the value of N: ";
    cin >> N;

    if (N <= 0) {
        cout << "N must be a positive integer." << endl;
    } else {
        for (int i = 1, count = 0; count < N; i += 2, count++) {
            sum += i;
        }

        cout << "Sum of the first " << N << " odd natural numbers is: " << sum << endl;
    }

    return 0;
}