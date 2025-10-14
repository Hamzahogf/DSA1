#include <iostream>

constexpr  int MAX_CHILDREN = 10; //  It allows the compiler to evaluate the value of an expression at compile time rather than at runtime. This can lead to performance improvements because the value is known at compile time, and there's no need to compute it at runtime


class TreeNode {
private:
    int value;
    TreeNode* children[MAX_CHILDREN]; // Array to store pointers to child nodes
    int numChildren; // Number of children currently in the array

public:
    TreeNode(int val) : value(val), numChildren(0) {}

    // Add a child node to the current node
    void addChild(TreeNode* child) {
        if (numChildren < MAX_CHILDREN) {
            children[numChildren++] = child;
        } else {
            std::cerr << "Maximum children reached for this node." << std::endl;
        }
    }
   
    // Depth-first traversal
    void depthFirstTraversal() const {
        std::cout << value << " ";
        for (int i = 0; i < numChildren; ++i) {
            children[i]->depthFirstTraversal();
        }
    }

    // Calculate the height of the tree
    int getHeight() const {
        int maxHeight = 0;
        for (int i = 0; i < numChildren; ++i) {
            int height = children[i]->getHeight();
            maxHeight = std::max(maxHeight, height);
        }
        return 1 + maxHeight;
    }

    // Count the number of nodes in the tree
    int countNodes() const {
        int count = 1; // Count the current node
        for (int i = 0; i < numChildren; ++i) {
            count += children[i]->countNodes();
        }
        return count;
    }

    // Search for a value within the tree
    bool search(int target) const {
        if (value == target) {
            return true;
        }
        for (int i = 0; i < numChildren; ++i) {
            if (children[i]->search(target)) {
                return true;
            }
        }
        return false;
    }
};


class Queue {
private:
    int* data;
    int capacity;
    int front;
    int rear;

    void resize() {
        // Implement resizing logic when the queue is full
        // For example, double the capacity
        capacity *= 2;
        int* newData = new int[capacity];
        int j = 0;
        for (int i = front; i <= rear; ++i) {
            newData[j++] = data[i % (capacity / 2)];
        }
        front = 0;
        rear = j - 1;
        delete[] data;
        data = newData;
    }

public:
    Queue() : capacity(10), front(0), rear(-1) {
        data = new int[capacity];
    }

    void enqueue(int value) {
        if ((rear + 1) % capacity == front) {
            resize();
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            // Handle underflow condition
            return -1; // Placeholder value
        }
        int value = data[front];
        front = (front + 1) % capacity;
        return value;
    }

    int peek() const {
        if (isEmpty()) {
            // Handle empty queue
            return -1; // Placeholder value
        }
        return data[front];
    }

    bool isEmpty() const {
        return (rear + 1) % capacity == front;
    }

    ~Queue() {
        delete[] data;
    }
};




class Employee {
private:
    std::string name;
    int id;
    std::string department;

public:
    Employee(const std::string& name, int id, const std::string& department)
        : name(name), id(id), department(department) {}

    void displayInfo() {
        std::cout << "Name: " << name << ", ID: " << id << ", Department: " << department << std::endl;
    }
};

class EmployeeManager {
private:
    static Employee* currentEmployee;

public:
    static void hireEmployee(const std::string& name, int id, const std::string& department) {
        if (!currentEmployee)
            currentEmployee = new Employee(name, id, department);
    }

    static void displayEmployeeInfo() {
        if (currentEmployee)
            currentEmployee->displayInfo();
        else
            std::cerr << "No employee hired yet!" << std::endl;
    }
};

Employee* EmployeeManager::currentEmployee = nullptr;

int main() {
    EmployeeManager::hireEmployee("John Doe", 1001, "Engineering");
    EmployeeManager::displayEmployeeInfo();

    return 0;
}















class LinkedList {
private:
    struct node
    {
        int data;
        node *next;

        node(int value) : data(value), next(nullptr) {}
    };

    node *head;

    int length_rec(node *current) const
    {
        if (current == nullptr)
        {
            return 0;
        }
        else
        {
            return 1 + length_rec(current->next);
        }
    }

    void display_rec(node* head){
        if (head==nullptr)
        {
            return;
        } else {
            std::cout<<head->data<<" ";
            display_rec(head->next);
        }
        
    }

public:
    LinkedList() : head(nullptr) {}

    // Insert a new node at the beginning of the list
    void insert(int value) {
        node* newnode = new node(value);
        newnode->next = head;
        head = newnode;
    }

    // Display the elements of the linked list
    void display() const{
        node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

   
   void insert_at_pos(int value , int pos){
    node* new_node=new node(value);
    node* cuur=head;
    node* prev=head;
    if (pos==1)
    {
        insert(value);
    } else {
        for (int i = 0; i < pos-1; i++)
        {
            prev=cuur;
            cuur=cuur->next;
        }
        prev->next=new_node;
        new_node->next=cuur;
    }
    
   }
   int length(){
    int i=0;
    while (head!=nullptr)
    {
        i++;
        head=head->next;
    }
    return i;
    
   }
   int get_length_rec() const {
        return length_rec(head);
    }


   void get_display_rec(){
    display_rec(head);
   }

void revers_lis() {
    node* prev = nullptr;
    node* current = head;
    node* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
}

    // Destructor to free memory when the linked list is destroyed
    ~LinkedList() {
        node* current = head;
        node* nextnode;

        while (current != nullptr) {
            nextnode = current->next;
            delete current;
            current = nextnode;
        }
         std::cout<<"i am here!";
    }
   
};

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
class Linkedlist {
private:
    Node* head;

    // Helper function for inserting a node at a specific position recursively
    Node* insertNodeAtPositionRecursive(Node* current, int position, int value) {
        if (position == 1) {
            Node* newNode = new Node(value);
            newNode->next = current;
            return newNode;
        }
        current->next = insertNodeAtPositionRecursive(current->next, position - 1, value);
        return current;
    }

    // Helper function for deleting a node with a given value recursively
    Node* deleteNodeWithValueRecursive(Node* current, int value) {
        if (current == nullptr) {
            return nullptr;
        }
        if (current->data == value) {
            Node* nextNode = current->next;
            delete current;
            return nextNode;
        }
        current->next = deleteNodeWithValueRecursive(current->next, value);
        return current;
    }

    // Helper function for reversing the linked list recursively
    Node* reverseListRecursive(Node* current) {
        if (current == nullptr || current->next == nullptr) {
            return current;
        }
        Node* newHead = reverseListRecursive(current->next);
        current->next->next = current;
        current->next = nullptr;
        return newHead;
    }

    // Helper function for finding the nth node from the end of the list recursively
    Node* findNthFromEndRecursive(Node* current, int n, int& counter) {
        if (current == nullptr) {
            return nullptr;
        }
        Node* node = findNthFromEndRecursive(current->next, n, counter);
        counter++;
        if (counter == n) {
            return current;
        }
        return node;
    }

public:
    Linkedlist() : head(nullptr) {}

    // Method to insert a node at a specific position
    void insertNodeAtPosition(int position, int value) {
        if (position < 1) {
            std::cerr << "Invalid position." << std::endl;
            return;
        }
        head = insertNodeAtPositionRecursive(head, position, value);
    }

    // Method to delete a node with a given value
    void deleteNodeWithValue(int value) {
        head = deleteNodeWithValueRecursive(head, value);
    }

    // Method to reverse the linked list
    void reverseList() {
        head = reverseListRecursive(head);
    }

    // Method to find the nth node from the end of the list
    Node* findNthFromEnd(int n) {
        int counter = 0;
        return findNthFromEndRecursive(head, n, counter);
    }

    // Method to display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to deallocate memory
    ~Linkedlist() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};


int main() {
    // Create a tree structure
    TreeNode* root = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    root->addChild(node2);
    root->addChild(node3);
    node2->addChild(node4);
    node2->addChild(node5);

    // Perform operations on the tree
    std::cout << "Depth-first traversal: ";
    root->depthFirstTraversal();
    std::cout << std::endl;

    std::cout << "Height of the tree: " << root->getHeight() << std::endl;

    std::cout << "Number of nodes in the tree: " << root->countNodes() << std::endl;

    int target = 5;
    std::cout << "Search for value " << target << ": " << (root->search(target) ? "Found" : "Not Found") << std::endl;

    // Clean up memory (assuming the tree is dynamically allocated)
    delete root;
    delete node2;
    delete node3;
    delete node4;
    delete node5;



   LinkedList l;
    l.insert_at_pos(4, 1);
    //l.display_rec(l.getHead()); here when i put the rec display in the pub but if u want to do it u have to add function that return the head and then l.reverse_di(l.getHead())




    return 0;
}