#include <iostream>


void removeElementArray(int v, int &n, int A[]) {
    int index = -1;
    for (int i = 0; i < n; ++i) {
        if (A[i] == v) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < n - 1; ++i) {
            A[i] = A[i + 1];
            
        }

       --n;

        
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

    int valueToRemove;
    std::cout << "Enter the value to remove: ";
    std::cin >> valueToRemove;

    removeElementArray(valueToRemove, size, arr);

    std::cout << "Modified array after removing " << valueToRemove << ":\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Position " << i << ": " << arr[i] << "\n";
    }

    return 0;
}
