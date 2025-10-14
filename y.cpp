#include <iostream>
#include <string>

struct Node {
    int data;
    Node* next;  // Horizontal pointer
    Node* down;  // Vertical pointer

    Node(int value) : data(value), next(nullptr), down(nullptr) {}
};

// Function to flatten a multilevel linked list
Node* flattenList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* current = head;
    Node* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    while (current != nullptr) {
        if (current->down != nullptr) {
            std::cout << "Flattening sublist starting from " << current->data << std::endl;
            tail->next = flattenList(current->down);
            while (tail->next != nullptr) {
                tail = tail->next;
            }
        }
        current = current->next;
    }

    return head;
}




const int MAX_CHARACTERS = 100; // Adjust the size according to your needs

struct mode {
    std::string data;
    mode* next;

    mode(const std::string& value) : data(value), next(nullptr) {}
};

// Function to display the linked list
void displayList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to create a singly linked list from user input
mode* createSinglyList() {
    int length;
    std::cout << "Enter the length of the singly linked list: ";
    std::cin >> length;

    if (length <= 0) {
        return nullptr;
    }

    std::cout << "Enter values for the singly linked list:" << std::endl;

    mode* pead = nullptr;
    mode* current = nullptr;

    for (int i = 0; i < length; ++i) {
        std::string input;
        std::cout << "Enter value " << i + 1 << ": ";
        std::cin.ignore(); // Ignore the newline character left in the buffer
        std::getline(std::cin, input);

        mode* newNode = new mode(input);

        if (current) {
            current->next = newNode;
            current = newNode;
        } else {
            if (!pead) {
                pead = newNode;
            } else {
                mode* temp = pead;
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            current = newNode;
        }
    }

    return pead;
}



// Function to display the linked list
void displayList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example of a multilevel linked list
    Node* head = new Node(1);
    head->next = new Node(8);
    head->down = new Node(4);
    head->down->next = new Node(7);
    head->next->next = new Node(9);
    head->next->down = new Node(6);
    head->next->down->next = new Node(7);

    // Adding a new multilevel structure in node 8
    head->next->down->down = new Node(5);
    head->next->down->down->next = new Node(0);
    head->next->down->down->next->down = new Node(-1);

    // Print the original multilevel linked list
    std::cout << "Original Multilevel Linked List: ";
    displayList(head);

    // Flatten the multilevel linked list
    head = flattenList(head);

    // Display the flattened linked list
    std::cout << "Flattened Linked List: ";
    displayList(head);

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

