#include <iostream>


int* splice(const int* A1, int n1, const int* A2, int n2, int p, int& newSize) {
    newSize = n1 + n2;

    int* A3 = new int[newSize];

    for (int i = 0; i < p; ++i) {
        A3[i] = A1[i];
    }

    for (int i = 0; i < n2; ++i) {
        A3[p + i] = A2[i];
    }

    for (int i = p; i < newSize; ++i) {
        A3[i + n2] = A1[i];
    }

    return A3;
}


int main(){

    int size;
    std::cin >> size;
    int* dynamicArray = new int[size];
    for (int i = 0; i < size; ++i) {
        std::cin>>dynamicArray[i];
    }
    for (int i = 0; i < size; ++i) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;
    delete[] dynamicArray;


    int n1;
    std::cin >> n1;
    int A1[n1];
    for (int i = 0; i < n1; ++i) {
        std::cin >> A1[i];
    }

    int n2;
    std::cin >> n2;
    int A2[n2];
    for (int i = 0; i < n2; ++i) {
        std::cin >> A2[i];
    }
    int position;
    std::cin >> position;
    int newSize;
    int* A3 = splice(A1, n1, A2, n2, position, newSize);
    for (int i = 0; i < newSize; ++i) {
        std::cout << A3[i] << " ";
    }
    std::cout << std::endl;
    delete[] A3;

}
