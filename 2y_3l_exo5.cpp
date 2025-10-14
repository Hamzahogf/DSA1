#include<iostream>

class Stack {
    private:
  struct Node
  {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {} 
  };
    int size=0;
    Node* Current;
    public:
    Stack(): Current(nullptr) , size(0) {};

    void push(int x){
        if (Current==nullptr)
        {
            Node* nody = new Node(x);
            Current=nody;
            nody->next=nullptr;
        } else {
            Node* nody = new Node(x);
            Current->next=nody;
            Current=Current->next;
            nody->next=nullptr;
        }
        size++;
    }
    void pop(){
        if (Current==nullptr)
        {
            return;
        } else 
        
    }
};