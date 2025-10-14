#include <iostream>

struct node {
    int data;
    node* next;
};

struct node2
{
    int data;
    node2* next;
};
node2* pead=nullptr;

void insert_end(int value, node*& head) {
    node* newNode = new node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct Node {
    int data;
    Node* next;
    Node* child;
};

Node* flattenNestedList(Node* pead) {
    Node* current = pead;

    while (current != nullptr) {
        if (current->child != nullptr) {
            Node* nextNode = current->next;
            Node* childTail=flattenNestedList(current->child); 
        

            current->next = current->child;
            current->child->next = nextNode;
            current->child = nullptr;

            current = childTail;
        }

        current = current->next;
    }
}


node* findKthFromMiddle(node* head, int k) {
    node* middle = findMiddleNode(head);

    for (int i = 0; i < k && middle != nullptr; ++i) {
        middle = middle->next;
    }

    return middle;
}


void delete_end(node* &source) {
    if (source == nullptr) {
        std::cout << "Empty list" << std::endl;
    } else {
        node* last = source, *pre = source;
        while (last->next != nullptr) {
            pre = last;
            last = last->next;
        }
        if (pre == last) {
            source = nullptr;
        } else {
            pre->next = nullptr;
        }
        delete last;
    }
}

void insert_beg(node*& head, int value) {
    node* newNode = new node{value, nullptr};
    newNode->next = head;
    head = newNode;
}

void display(node*& head) {
    if (head == nullptr) {
        std::cout << "Empty list";
    } else {
        node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
    }
    std::cout << std::endl;
}

void insert_spe(node*& head,int value , int position){
    if (position ==1)
    {
        insert_beg(head ,value);
    } else {
        node* new_node=new node;
        new_node->data =value;
        node* pre=head , *cur=head;
        for (int i = 1; i <position; i++)
        {
            pre=cur;
            cur=cur->next;
        }
        pre->next=new_node;
        new_node->next=cur;
        
    }
    
}

void delet_beg(node*& head){
    if (head==nullptr)
    {
        std::cout<<"jbdh wldi";
    } else {
        node* first=head;
        head=first->next;
        delete(first);
    }
    
}

void delet_end(node*& head){
    if (head==nullptr)
    {
        std::cout<<"jbdha wlidou";
    } else {
        node* last=head, *pre=head;
        while (last->next != nullptr)
        {
            pre=last;
            last=last->next;
        }
        pre->next=nullptr;
        delete(last);
        
    }
    
}
void reverseList(node*& head) {
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

int length(node* source) {
    int i = 0;
    node* cur = source;

    while (cur != nullptr) {
        cur = cur->next;
        i++;
    }

    return i;
}

void select_sort(node*& head) {
    node* small = head;
node* cur  , *start=head;
   cur=start->next;
    int l = length(head);

    for (int i = 0; i < l; i++) {

        while (cur->next != nullptr) {
            if (cur->data < small->data) {
                small = cur;
            }

            cur = cur->next;
        }

        int temp = small->data;
        small->data = start->data;
        start->data = temp;

        start = start->next;
        cur = start;
        small = start;
    }

}

node* bubbleSort(node* head) {
    if (!head || !head->next) {
        return head; // Already sorted or empty list
    }

    bool swapped;
    node* current;
    node* lastSorted = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                // Swap data
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                swapped = true;
            }

            current = current->next;
        }

        lastSorted = current;
    } while (swapped);

    return head;
}
node* findMiddleNode(node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    node* slow = head;
    node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


void display_rec(node* head) {
    if (head) {
        std::cout << head->data << " ";
        display_rec(head->next);
    }
}

int length_rec(node* head){
    if (head==nullptr)
    {
        return 0;
    }else if (head->next ==nullptr)
    {
        return 1;
    }else {
        node* first = head;
        node* oead=first->next;
        first->next=nullptr;
        return 1+length_rec(oead);
    }
    
    
}

node* reverse_List(node* head, node* previous = nullptr) {
    if (head == nullptr) {
        return previous;
    }

    node* nextNode = head->next;  // Storing the next node
    head->next = previous;        // Reversing the pointer to the previous node
    return reverse_List(nextNode, head);  // Recursively call the function with updated pointers
}
int main() {
node* head=nullptr;
    insert_beg(head,9);
    insert_end(5,head);
    insert_end(8,head);
    //int t=length_rec(head);
    //std::cout<<t<<std::endl;
    head=reverse_List(head);
    display_rec(head);
    return 0;
}