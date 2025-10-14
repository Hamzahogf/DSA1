#include <iostream>

struct node
{
    int data;
    node* next;
};

void insert_end(int value, node* &source) {
    node* new_node = new node;
    new_node->data = value;
    new_node->next = nullptr;

    if (source == nullptr) {
        source = new_node;
    } else {
        node* last = source;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = new_node;
    }
}

int length(node* source) {
    int i = 0;
    node* cur = source;

    while (cur != NULL) {
        cur = cur->next;
        i++;
    }

    return i;
}

int length_rec(node* head) {
    if (head == nullptr) {
        return 0;
    }
    return 1 + length_rec(head->next);
}

void display_rec(node* head) {
    if (head == nullptr) {
      return;
    } else {
        std::cout << head->data << " ";
        display_rec(head->next);
    }
}

void insert_end_rec(node* &head , int val){
    if (head==NULL)
    {
        node* new_node= new node;
        new_node->data=val;
        new_node->next=NULL;
        head=new_node;
    } else if (head->next==NULL)
    {
        node* new_node= new node;
        new_node->data=val;
        new_node->next=NULL;
        head->next=new_node;
    } else {
        insert_end_rec(head->next , val);
    }
    
    
    
}

bool search_rec(node* head , int val){
    if (head==NULL)
    {
        return false;
    } else if (head->next==NULL)
    {
        if (head->data==val)
        {
         return true;
        } else {
            return false;
        }
        
    } else {
        return search_rec(head->next , val);
    }
    
    
}
int main() {
    node* head=NULL;
    insert_end(9, head);
    insert_end(5,head);
    insert_end(8,head);
    insert_end(1,head);
    //display_rec(head);


    insert_end_rec(head , 4);
    display_rec(head);
    int t=length_rec(head);
    std::cout<<t<<std::endl;
    bool u=search_rec(head , 0);

    return 0;
}