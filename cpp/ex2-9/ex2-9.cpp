#include <iostream>

int minArray(int A[], int n) {
    int minVal = A[0]; 
    int minPos = 0;    

    for (int i = 1; i < n; ++i) {
        if (A[i] < minVal) {
            minVal = A[i];
            minPos = i;
        }
    }

    return minPos;
}

void scanArray(int A[], int n) {
    std::cout << "Enter " << n << " elements for the array:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter element at position " << i << ": ";
        std::cin >> A[i];
    }
}

int main() {
const int maxSize = 100; 
    int arr[maxSize];

    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

  
    scanArray(arr, size);

    int position = minArray(arr, size);

    if (position != -1) {
        std::cout << "The minimum value is at position " << position << std::endl;
        std::cout << "The minimum value is: " << arr[position] << std::endl;
    }

    return 0;
}
