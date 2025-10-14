#include <iostream>

void scanArray(int A[], int n) {
    std::cout << "Enter " << n << " elements for the array:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter element at position " << i << ": ";
        std::cin >> A[i];
        

    }
}
  
void printOccurrence(int A[], int n) {
    const int range = 21; 

    int count[range] = {0};

    for (int i = 0; i < n; ++i) {
        count[A[i]]++;
    }

    for (int i = 0; i < range; ++i) {
        std::cout << "- The number " << i << " appears " << count[i] << " times.\n";
    }
}

int main() {
    const int maxSize = 100; 
    int arr[maxSize];

    int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    scanArray(arr, size);
    printOccurrence(arr, size);

    return 0;
}
