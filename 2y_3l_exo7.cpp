#include<iostream>

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* topNode; // Pointer to the top of the stack

public:
    Stack() : topNode(nullptr) {};

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode; 
        topNode = newNode;    
    }

    ~Stack(){while (topNode) pop;}

    void pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty.");
        }
        Node* temp = topNode;
        topNode = topNode->next; 
        delete temp;             
    }

    int top() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty");
        }
        return topNode->data;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

   
};
