#include <iostream>

// Define a simple Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* list1, Node* list2) {
    // Create a dummy node to serve as the new head of the merged list
    Node* dummy = new Node(0);
    Node* current = dummy;

    // Traverse both lists and compare elements
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // If one list is not empty, append the remaining nodes
    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    // The dummy node was just a placeholder, actual merged list starts from dummy->next
    Node* mergedList = dummy->next;

    // Free the dummy node (not part of the final list)
    delete dummy;

    return mergedList;
}

// Function to create a sorted linked list from user input
Node* createSortedList() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    std::cout << "Enter the sorted elements:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;

        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Function to print a linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int length(Node* &source){
    int i=1;
    Node* cur=source;
    if (source == NULL)
    {
        std::cout<<"0";
    } else {
        while (cur->next != NULL)
        {
            cur=cur->next;
            i++;
        }
     
        return i;
        
    }
    


}

void select_sort(Node* head){
    Node* small=head , *cur, *start=head;
    int l=length(head);
    for (int i = 0; i < l; i++)
    {
        cur=start;
        while (cur->next != NULL)
        {
            if (cur->data < small->data)
            {
                small=cur;
                cur=cur->next;
            } else {
                cur=cur->next;
            }
            
        }

        int temp = small->data;
        small->data=start->data;
        start->data=temp;

        start=start->next;
        cur=start;
        small=start;
        
    }
    
}













int main() {
    // Example usage:
    // Create two sorted linked lists from user input
    Node* list1 = createSortedList();
    Node* list2 = createSortedList();

    // Print the original lists
    std::cout << "List 1: ";
    printList(list1);

    std::cout << "List 2: ";
    printList(list2);

    // Merge the lists
    Node* mergedList = mergeSortedLists(list1, list2);

    // Print the merged list
    std::cout << "Merged List: ";
    printList(mergedList);

    // Cleanup: Free the memory allocated for the lists
    // Note: Merged list nodes are not deleted here since they are reused from the input lists

    return 0;
}
