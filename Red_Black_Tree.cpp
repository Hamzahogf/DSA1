#include <iostream>
#include <cmath>
#include <cstdlib> // For rand() 
#include <ctime>   // For time()

//RED BLACK TREE
class RBT {
    private:
    enum COLOR{BLACK,RED};
    struct Node
    {
        int x;
        COLOR color;
        Node* parent;
        Node* rightchild;
        Node* leftchild;
        Node(const int& x,Node* parent=nullptr,COLOR color=RED , Node* left=nullptr,Node* right=nullptr): parent(parent), color(color), rightchild(right) , leftchild(left), x(x) {};
    };

    Node* head;

    void add(const int& x, Node*& t, Node* parent = nullptr) {
        if (t == nullptr) {
            t = new Node(x, parent); 

            if (parent == nullptr) {
                t->color = BLACK;
            }
            adjust(t);
        }
        else if (x < t->x) {
            add(x, t->leftchild, t);
        } else if (x > t->x) {
            add(x, t->rightchild, t);
        }
    }
    void adjust(Node*& t){
        if (!t || !t->parent || !t->parent->parent) return; 

        Node* parent = t->parent;
        Node* grandparent = parent->parent;
        Node* uncle = (grandparent->leftchild == parent) ? grandparent->rightchild : grandparent->leftchild;

        if( parent->color == RED){
            if ( uncle && uncle->color == RED){
                    parent->color = BLACK;
                    uncle->color=BLACK;
                    if(grandparent!=head){
                      grandparent->color = (grandparent->color==RED)? BLACK : RED;
                      adjust(parent);
                    }
            } else {
                if (parent == grandparent->leftchild) {
                    if (t == parent->rightchild) {
                        rotateleft(parent);
                        t = parent;
                        parent = t->parent;
                    }
                    rotateright(grandparent);
                } else {
                    if (t == parent->leftchild) {  
                        rotateright(parent);
                        t = parent;
                        parent = t->parent;
                    }
                    rotateleft(grandparent);
                }
                parent->color = BLACK;
                grandparent->color = RED;
            }
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
        //Balance(t);
    }
    Node* findMin(Node*& t){
        if(t==nullptr) {return t;}
        Node* current=t;
        while (current->leftchild){current=current->leftchild;}
        return current;
    }

    void print(Node*& now) const {
        if (!now) return;
        if (now->leftchild) print(now->leftchild);
        std::cout << now->x << " ";
        if (now->rightchild) print(now->rightchild);
    }
    void rotateright(Node*& k1) {
        Node* k2 = k1->leftchild;
        k1->leftchild = k2->rightchild;
        if (k2->rightchild) {
            k2->rightchild->parent = k1;
        }
        k2->parent = k1->parent;
        if (!k1->parent) {
            head = k2; // Update the root if necessary
        } else if (k1 == k1->parent->leftchild) {
            k1->parent->leftchild = k2;
        } else {
            k1->parent->rightchild = k2;
        }
        k2->rightchild = k1;
        k1->parent = k2;
    }
    void rotateleft(Node*& k1) {
        Node* k2 = k1->rightchild;
        k1->rightchild = k2->leftchild;
        if (k2->leftchild) {
            k2->leftchild->parent = k1;
        }
        k2->parent = k1->parent;
        if (!k1->parent) {
            head = k2; // Update the root if necessary
        } else if (k1 == k1->parent->leftchild) {
            k1->parent->leftchild = k2;
        } else {
            k1->parent->rightchild = k2;
        }
        k2->leftchild = k1;
        k1->parent = k2;
    }
     
    public:
    RBT() : head(nullptr) {};
    void add(const int& x) { add(x, head);}
    void delet(const int& x) { delet(x, head);}
    bool contain(const int& x) { return contain(x, head);} //you can not amrk the func as constant because when you are passing the member head the contain privat it expects that the passed pointer by refrence ; so the compiler will say oh that surely that these funct will modify it
    int findMin() {return findMin(head)->x;}
    void print() {print(head);}
    static RBT generate_of_height(int h){
        RBT RBT;
        std::cout<<"hello"<<std::endl;
        int n= ceil(exp(0.69*h));
		std::cout<<n<<std::endl;

        srand(static_cast<unsigned>(time(0))); 
        for (int i = 0; i <n; ++i) {
            int a;
            do {
                a = (rand() % n) + 1;
            } while (RBT.contain(a)); 
            RBT.add(a);
             std::cout<<i<<std::endl;
        }
    std::cout<<"kk"<<std::endl;

        return RBT;
    }
};