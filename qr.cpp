#include <iostream>

struct node
{
    int data;
    node* next;
};
node* head=nullptr;

const char* findLargestWord(const char* arr[], int size) {
    const char* largestWord = arr[0];

    for (int i = 1; i < size; ++i) {
        // Compare lengths without using strlen
        int lengthI = 0;
        int lengthLargest = 0;

        while (arr[i][lengthI] != '\0') {
            ++lengthI;
        }

        while (largestWord[lengthLargest] != '\0') {
            ++lengthLargest;
        }

        if (lengthI > lengthLargest) {
            largestWord = arr[i];
        }
    }

    return largestWord;
}


void generate_Permutations(std::string text, int left, int right) {
  if (left == right) {
    std::cout << text << std::endl; 
    return;
  }
 
  for (int i = left; i <= right; i++) {
    std::swap(text[left], text[i]); 
    generate_Permutations(text, left + 1, right); 
    std::swap(text[left], text[i]);
  }
}

void displayReverseRecursive(node* current) {
    if (current == nullptr) {
        return;  
    }

    displayReverseRecursive(current->next);

    std::cout << current->data << " ";
}



int main() {
    const char* names[] = {"Alice", "Bob", "Charlie", "David"};
    std::string inputString = "This is a sample string";
 generate_Permutations(inputString, 0, inputString.length() - 1);
    return 0;
}
