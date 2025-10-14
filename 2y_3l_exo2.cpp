#include <iostream>

class LinkedList{
 private:
  struct Node
  {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {} 
  };

  Node* head;
  int size=0;

 public:
  LinkedList() : head(nullptr), size(0) {}

    void printList(){
        Node* current=head;
        while (current->next!=nullptr)
        {
            std::cout<<current->data<<std::endl;
            current=current->next;
        }
    }

    bool testValue(int x){
        Node* current=head;
        while (current->next!=nullptr)
        {
            if (current->data == x)
            {
                return true;
            }

            current=current->next;
        }
        return false;   
    }
    
    void insertValue(int x){
        if (testValue(x)==false)
        {
            Node* newnode=new Node(x);
            newnode->next=head;
            head=newnode;
            size++;
        }
    }

    void insertValueEnd(int X) {
   if (!testValue(X)) {
            Node* newNode = new Node(X);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
            size++;
        }
        
    }

    int ReturnSizr() {
        std::cout<<size<<std::endl;
    }
    void remove(int x) {
        if (head == nullptr) return;

        if (head->data == x) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != x) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            size--;
            return;
        }
    }



    void swapAdjucent(int x) {
        Node* prev=head;
        Node* current=head;
        Node* p_prev=nullptr;

        while (current->data!=x)
        {
            prev=current;
            current=current->next;
        }
        p_prev=prev->next;
        current=current->next;
        
        prev->next=current;
        p_prev->next=current->next;
        current->next=p_prev;
            

    }

};



int main() {
    LinkedList list;
    list.insertValue(1);
    list.insertValue(2);
    list.insertValue(3);
    list.insertValue(4);

    std::cout << "before :";

    list.swapAdjucent(2);

    std::cout << "after : ";
    list.printList();
    getchar();

    return 0;
}