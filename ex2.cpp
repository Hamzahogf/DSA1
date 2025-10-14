#include <iostream>
#include <algorithm>

const int MAX_SIZE = 100;

// Function to construct the frequency array
void constructFrequencyArray(int arr[], int n, int freqArray[][2]) {
    int currentIndex = 0;
    int count = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1]) {
            // If the current element is equal to the previous one, increment the count
            ++count;
        } else {
            // If a new element is encountered, update the frequency array
            freqArray[currentIndex][0] = arr[i - 1];
            freqArray[currentIndex][1] = count;

            // Move to the next row in the frequency array
            ++currentIndex;

            // Reset count for the new element
            count = 1;
        }
    }

    // Handle the last element of the array
    freqArray[currentIndex][0] = arr[n - 1];
    freqArray[currentIndex][1] = count;
}

// Function to compare rows based on the count (used for sorting)
bool compareRows(const int row1[], const int row2[]) {
    return row1[1] > row2[1]; // Sort in descending order based on count
}

int main() {
    int arr[MAX_SIZE];
    int n;

    // Get the size of the array from the user
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    if (n <= 0 || n > MAX_SIZE) {
        std::cerr << "Invalid array size. Exiting program." << std::endl;
        return 1;
    }

    // Get the elements of the array from the user
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Sort the array
    std::sort(arr, arr + n);

    // Initialize the frequency array
    int freqArray[MAX_SIZE][2] = {0};

    // Construct the frequency array
    constructFrequencyArray(arr, n, freqArray);

    // Sort the frequency array based on count
    std::sort(freqArray, freqArray + n, compareRows);

    // Print the sorted elements based on frequency
    std::cout << "Sorted array based on frequency: ";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < freqArray[i][1]; ++j) {
            std::cout << freqArray[i][0] << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
