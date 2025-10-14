#include <iostream>

void reverseArray(int A[], int n) {
    for (int i = 0; i < n / 2; ++i) {
        int temp = A[i];
        A[i] = A[n - i - 1];
        A[n - i - 1] = temp;
    }
}

int main() {
    const int maxSize = 100;
    int arr[maxSize];

    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

    std::cout << "Enter " << size << " elements for the array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Enter element at position " << i << ": ";
        std::cin >> arr[i];
    }

    reverseArray(arr, size);

    std::cout << "Reversed array:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Position " << i << ": " << arr[i] << "\n";
    }

    return 0;
}
