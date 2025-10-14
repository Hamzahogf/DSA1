#include <iostream>

void scanArray(int A[], int n) {
    std::cout << "Enter " << n << " elements for the array:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter element at position " << i << ": ";
        std::cin >> A[i];
    }
}

bool F(int A[], int n) {
    for (int i = 0; i < n; ++i) {
        if (A[i] >= 0 && A[i] <= 10) {
            return true;
        }
    }
    return false;  
}

int main() {
    const int maxSize = 100;
    int arr[maxSize];

    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    scanArray(arr, size);

    bool k = F(arr, size);

    if (k) {
        std::cout << "yes";
    } else {
        std::cout << "maymknch impossi";
    }

    return 0;
}
