#include <iostream>
#include <cstdlib> // For rand() 
#include <ctime>   // For time()

class BST {
    private:
    struct Node
    {
        int x;
        int y;
        Node* rightchild;
        Node* leftchild;
        Node(const int& x, Node* left=nullptr,Node* right=nullptr) : rightchild(right) , leftchild(left), x(x), y(1) {};
    };
    Node* head;
    void add(const int& x,Node*& t){
        if (t == nullptr) { 
            t = new Node(x); // Fixed: Correctly assigning to t when creating a new node
        }
        else {
            if(x < t->x) {add(x,t->leftchild);}
            else if(x > t->x) {add(x,t->rightchild);}
            else {t->y++;}
        }
 }
    bool contain(const int& x,Node*& t) const { //the return statement needed becaus it is bool not void 
    if (t == nullptr) { return false;}
    if (x < t->x) {return contain(x, t->leftchild); }
    else if (x > t->x) {return contain(x, t->rightchild); } 
    else { return true; }
}
    void delet(const int& x,Node*& t){
        if(t==nullptr){return;}
        if(x < t->x ){ delet(x, t->leftchild);}
        else if(x > t-> x){delet(x, t->rightchild);}
        else
          if(t->leftchild!=nullptr && t->rightchild!=nullptr){
            t->x=findMin(t->rightchild)->x;
            delet(t->x,t->rightchild);
          }
          else if(t->leftchild==nullptr && t->rightchild==nullptr){
            delete t;
            t=nullptr;           //pay atteinte
          }
          else {
            Node* target=t;
            t=(t->rightchild==nullptr)? t->leftchild:t->rightchild;
            delete target;
          }
    } 
    Node* findMin(Node*& t){
        if(t==nullptr) {return t;}
        Node* current=t;
        while (current->leftchild){current=current->leftchild;}
        return current;
    }
    Node* clone(Node* source) const {
        if (source == nullptr) {
            return nullptr; 
        } else {
           
            return new Node(source->x, clone(source->leftchild), clone(source->rightchild));
        }
    }
    void print(Node*& now) const {
        //in-order
        if (!now) return;
        if (now->leftchild) print(now->leftchild);
        std::cout << now->x << " ";
        if (now->rightchild) print(now->rightchild);
    }
    Node* generate_N_Node(const int& N) {
        srand(static_cast<unsigned>(time(0))); 
        for (int i = 0; i < N; ++i) {
            int a;
            do {
                a = (rand() % N) + 1; 
            } while (contain(a)); 
            add(a); 
        }
        return head;
    }
    
   public:
    BST() : head(nullptr) {};
    BST(const BST& bst) : head(nullptr) {
        head=clone(bst.head);
    }
    void add(const int& x) { 
        add(x, head);
    }
    void delet(const int& x) { 
        delet(x, head);
    }
    bool contain(const int& x) { 
        return contain(x, head);} //you can not amrk the func as constant because when you are passing the member head the contain privat it expects that the passed pointer by refrence ; so the compiler will say oh that surely that these funct will modify it
    int findMin() {
        return findMin(head)->x;
    }
    void print() {
        print(head);
    }
    BST(const int& N) : head(nullptr) {
         head=generate_N_Node(N);
    }
    /* static BST generate_n_Node(const int& N) {
        BST newTree;
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < N; ++i) {
            int a;
            do {
                a = (rand() % N) + 1;
            } while (newTree.contain(a)); 
            newTree.add(a);
        }
        return newTree;
    }
    BST wiw=BST::generate_N_Node(5);
    */
};



int main() {
    BST tree;

    // Add elements to the tree
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(3);
    tree.add(7);

    // Print the tree
    std::cout << "Tree elements (in-order): ";
    tree.print();
    std::cout << std::endl;

    // Check containment
    std::cout << "Tree contains 7? " << (tree.contain(7) ? "Yes" : "No") << std::endl;
    std::cout << "Tree contains 20? " << (tree.contain(20) ? "Yes" : "No") << std::endl;

    // Delete an element
    std::cout << "Deleting 5..." << std::endl;
    tree.delet(5);

    // Print the tree after deletion
    std::cout << "Tree elements (in-order): ";
    tree.print();
    std::cout << std::endl;

    // Find minimum
    std::cout << "Minimum element: " << tree.findMin() << std::endl;
    //copy constructor is triggered
    BST three= tree;
    std::cout << "Tree elements (in-order): ";
    three.print();
    std::cout << std::endl;
    int n=5;
    BST wiw(n);
    std::cout << "wiw elements (in-order): ";
    wiw.print();
    std::cout << std::endl;
    return 0;
}