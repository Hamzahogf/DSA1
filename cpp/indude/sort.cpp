

#include "sort.h"
#include <iostream>

void select_sort(int A[], int s) {
    int temp;
    for (int i = 0; i < s; i++) {
        int sml = A[i];
        int idx = i; // Keep track of the index of the smallest element
        for (int j = i + 1; j < s; j++) {
            if (A[j] < sml) {
                sml = A[j];
                idx = j;
            }
        }
        // Swap A[i] and the smallest element found
        temp = A[i];
        A[i] = sml;
        A[idx] = temp;
    }
    for (int i = 0; i < s; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

void selectp_sort(char arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

void bubbl_sort(int A[], int s) {
    int temp;
    int j;
    for (int i = 0; i < s; i++) {
        if (A[i] > A[i + 1]) {
            temp = A[i];
            A[i] = A[i + 1];
            A[i + 1] = temp;
            j = i;
            while (j > 0 && A[j] < A[j - 1]) {
                temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
                j--;
            }
        }
    }
    for (int u = 0; u < s; u++) {
        std::cout << A[u] << " ";
    }
    std::cout << std::endl;
}
void bubbl_sort(char A[], int s) {
    char temp;
    int j;
    for (int i = 0; i < s; i++) {
        if (A[i] > A[i + 1]) {
            temp = A[i];
            A[i] = A[i + 1];
            A[i + 1] = temp;
            j = i;
            while (j > 0 && A[j] < A[j - 1]) {
                temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
                j--;
            }
        }
    }
    for (int u = 0; u < s; u++) {
        std::cout << A[u] << " ";
    }
    std::cout << std::endl;
}


void insert_sort(int A[], int s) {


    int key, j;

    for (int i = 1; i < s; i++) {
        key = A[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }

        A[j + 1] = key;
    }
}
void insert_sort(char A[], int s) {
    char key;
    int j;

    for (int i = 1; i < s; i++) {
        key = A[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }

        A[j + 1] = key;
    }
}
