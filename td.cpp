#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>
#include <functional>  // For std::hash
#include <cstdlib> // For rand() 
#include <ctime>   // For time()


bool isPrime(int num) { 
    if (num % 2 == 0) return false;  
    int limit = std::sqrt(num);
    for (int i = 3; i <= limit; i += 2) 
        if (num % i == 0) return false; 
    return true;
}
int nextprime(int n) {
    if (n <= 2) return 2;  
    int candidate = n % 2 == 0 ? n + 1 : n; 
    while (!isPrime(candidate)) {
        candidate += 2;  
    }
    return candidate;
}


//avl
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
    static const int DEPACED = 1;

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
bool contain(const int& x, Node* t) const {
    if (t == nullptr) return false;
    if (x < t->x) return contain(x, t->leftchild);
    else if (x > t->x) return contain(x, t->rightchild);
    else return true;
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
    void print(Node* now) const {
        if (!now) return;
        if (now->leftchild) print(now->leftchild);
        std::cout << now->x << " ";
        if (now->rightchild) print(now->rightchild);
    }
    
    void delet_all(Node*& t){
        if (!t) return; 
        delet_all(t->leftchild);
        delet_all(t->rightchild);
        delete t;
        t=nullptr; 
    }

    void Balance(Node*& t) {
        if(!t) return;
        if(height(t->leftchild)-height(t->rightchild)> DEPACED){
            if(height(t->leftchild->rightchild)-height(t->leftchild->leftchild)>DEPACED-1){
                rotateleftright(t);
            } else {
                rotateleft(t);
            }
        } else if(height(t->rightchild)-height(t->leftchild)> DEPACED){
            if(height(t->rightchild->leftchild)-height(t->rightchild->leftchild)>DEPACED-1){
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
    void rotateright(Node*& k1){
        Node* k2=k1->rightchild;
        k2->rightchild=k1->leftchild;
        k2->leftchild=k1;
        k1->h=std::max(height(k1->leftchild),height(k1->rightchild))+1;
        k2->h=std::max(height(k2->leftchild),height(k2->rightchild))+1;        
        k1=k2;
    }
    void rotateleft(Node*& k1){
        Node* k2=k1->leftchild;
        k2->leftchild=k1->rightchild;
        k2->rightchild=k1;
        k1->h=std::max(height(k1->leftchild),height(k1->rightchild))+1;
        k2->h=std::max(height(k2->leftchild),height(k2->rightchild))+1;        
        k1=k2;
    }
      
    public:
    AVL() : head(nullptr) {};
    void add(const int& x) { add(x, head);}
    void delet(const int& x) { delet(x, head);}
    void delet_all(){delet_all(head);}

    bool contain(const int& x) const { return contain(x, head);} 
    void print() const {print(head);}
};


//separate chaining hash
class SCH_AVL {
    private:
    std::vector<AVL> array;
    int CurrentSize;
    void rehash(){
        std::vector<AVL> oldtable = array;
        array.resize(nextprime(2*array.size()));
        for(auto& thislist : array )
            thislist.delet_all();

    }
    int myhach(const int& ho) const { return ho % array.size();}
    public:
    explicit SCH_AVL(int size =101) : array(nextprime(size)) , CurrentSize(0) {};
  
    bool exist(const int& x) const {
        auto& w = array[myhach(x)];
        return w.contain(x);
    }
    void insert(const int& ho){
        if(!exist(ho)){ 
            auto& thislist = array[myhach(ho)];
            thislist.add(ho);
            CurrentSize++;

            if(CurrentSize>= array.size()/2){
                rehash();
            }
        } else {
          std::cout<<"existed"<<std::endl;
          return;
        }
    }
    void insert(int&& ho){                   
    }
    void zero_it(){
        for(auto& thislist : array)
            thislist.delet_all();
    }
    void delete_it(const int & ho){
        if(exist(ho)){ 
            auto& thislist= array[myhach(ho)];
            if(thislist.contain(ho)){ 
                thislist.delet(ho);
                --CurrentSize;
            }
        }
    }
    double CurrentLoad(){
        return static_cast<double>(CurrentSize) / array.size(); 
    }
    void print() const {
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << "Bucket " << i << ": ";
        array[i].print();
        std::cout << std::endl;
    }
}

};

int main() {
      SCH_AVL w;
    w.insert(5);
    w.insert(8);
    w.insert(5);
    w.insert(15);
    w.insert(23);
    w.insert(5);
    

}

