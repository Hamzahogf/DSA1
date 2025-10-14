#include <iostream>

void insertElementArray(int e, int p, int &n, int A[]) {
   

    for (int i = n; i > p; i--) {
        A[i] = A[i - 1];
    }

    A[p] = e;

    ++n;
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

    int elementToInsert, positionToInsert;
    std::cout << "Enter the element to insert: ";
    std::cin >> elementToInsert;
    std::cout << "Enter the position to insert (0 to " << size << "): ";
    std::cin >> positionToInsert;

    insertElementArray(elementToInsert, positionToInsert, size, arr);

    std::cout << "Modified array after inserting " << elementToInsert << " at position " << positionToInsert << ":\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Position " << i << ": " << arr[i] << "\n";
    }

    return 0;
}
