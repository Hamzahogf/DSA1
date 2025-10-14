#include <iostream>
#include <cmath>
#include <cstdlib> // For rand() 
#include <ctime>   // For time()

class AVL {
    private:
    struct Node
    {
        int x;
        int h;
        Node* rightchild;
        Node* leftchild;
        Node(const int& x, Node* left=nullptr,Node* right=nullptr) : rightchild(right) , leftchild(left), x(x), h(0) {};
    };

    Node* head;
    static const int BALANCE_FACTOR = 1;

    int height(Node*& t){
        return (t==nullptr)? -1 : t->h;
    }
    void add(const int& x,Node*& t){
        if (t == nullptr) { 
            t = new Node(x); // Fixed: Correctly assigning to t when creating a new node
        }
        else {
            if(x < t->x) {add(x,t->leftchild);}
            else if(x > t->x) {add(x,t->rightchild);}
        }

        Balance(t);
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
        Balance(t);
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
        if (!now) return;
        if (now->leftchild) print(now->leftchild);
        std::cout << now->x << " ";
        if (now->rightchild) print(now->rightchild);
    }
    void Balance(Node*& t) {
        if(!t) return;
        if(height(t->leftchild)-height(t->rightchild)> BALANCE_FACTOR){
            if(height(t->leftchild->rightchild)-height(t->leftchild->leftchild)>BALANCE_FACTOR-1){
                rotateleftright(t);
            } else {
                rotateleft(t);
            }
        } else if(height(t->rightchild)-height(t->leftchild)> BALANCE_FACTOR){
            if(height(t->rightchild->leftchild)-height(t->rightchild->rightchild)>BALANCE_FACTOR-1){
                rotaterightleft(t);
            } else {
                rotateright(t);
            }
        }
        t->h=std::max(height(t->leftchild),height(t->rightchild))+1;
    }
    void rotateleftright(Node*& k3){
        rotateright(k3->leftchild);
        rotateleft(k3);
    }
    void rotaterightleft(Node*& k3){
        rotateleft(k3->rightchild);
        rotateright(k3);
    }
    void rotateright(Node*& k1) {
    Node* k2 = k1->leftchild;  // k2 is the left child of k1
    k1->leftchild = k2->rightchild;  // k1's left child becomes k2's right child
    k2->rightchild = k1;  // k2's right child becomes k1

    // Update heights
    k1->h = std::max(height(k1->leftchild), height(k1->rightchild)) + 1;
    k2->h = std::max(height(k2->leftchild), height(k2->rightchild)) + 1;

    k1 = k2;  // Update the root of the subtree
}
    void rotateleft(Node*& k1) {
    Node* k2 = k1->rightchild;  // k2 is the right child of k1
    k1->rightchild = k2->leftchild;  // k1's right child becomes k2's left child
    k2->leftchild = k1;  // k2's left child becomes k1

    // Update heights
    k1->h = std::max(height(k1->leftchild), height(k1->rightchild)) + 1;
    k2->h = std::max(height(k2->leftchild), height(k2->rightchild)) + 1;

    k1 = k2;  // Update the root of the subtree
}

    public:
    AVL() : head(nullptr) {};
    AVL(const AVL& avl) : head(nullptr) {head=clone(avl.head);}
    void add(const int& x) { add(x, head);}
    void delet(const int& x) { delet(x, head);}
    bool contain(const int& x) { return contain(x, head);} //you can not amrk the func as constant because when you are passing the member head the contain privat it expects that the passed pointer by refrence ; so the compiler will say oh that surely that these funct will modify it
    int findMin() {return findMin(head)->x;}
    void print() {print(head);}
    static AVL generate_of_height(int h){
        AVL avl;
        std::cout<<"hello"<<std::endl;
        int n= ceil(exp(0.69*h));
		std::cout<<n<<std::endl;

        srand(static_cast<unsigned>(time(0))); 
        for (int i = 0; i <n; ++i) {
            int a;
            do {
                a = (rand() % n) + 1;
            } while (avl.contain(a)); 
            avl.add(a);
             std::cout<<i<<std::endl;
        }
    std::cout<<"kk"<<std::endl;

        return avl;
    }
};




int main(){
	AVL wiw= AVL::generate_of_height(2);
    std::cout<<"kk"<<std::endl;

    wiw.print();
}
