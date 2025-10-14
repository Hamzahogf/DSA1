#include <iostream>

void scanArray(int A[], int n) {
    std::cout << "Enter " << n << " elements for the array:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter element at position " << i << ": ";
        std::cin >> A[i];
    }
}

void printArray(int A[], int n) {
    std::cout << "Array elements with their respective positions:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Position " << i << ": " << A[i] << "\n";
    }
}

int main() {
    const int maxSize = 100;  

    int myArray[maxSize];
    int sizeOfArray;

    std::cout << "Enter the size of the array: ";
    std::cin >> sizeOfArray;

    
  scanArray(myArray, sizeOfArray);
   printArray(myArray, sizeOfArray);


    return 0;
}

