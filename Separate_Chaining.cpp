#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>
#include <functional>  // For std::hash
#include <cstdlib> // For rand() 
#include <ctime>   // For time()

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
    bool contain(const int& x,Node*& t) const { 
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
    void print(Node*& now) const {
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

    bool contain(const int& x) { return contain(x, head);} 
    void print() {print(head);}
};

//separate chaining hash
template<typename Hashedobj>
class SCH_AVL {
    private:
    std::vector<AVL<Hashedobj>> array;
    int CurrentSize;
    void rehash(){
        std::vector<AVL<Hashedobj>> oldtable = array;
        array.resize(nextprime(2*array.size()));
        for(auto& thislist : array )
            thislist.delet_all();

        CurrentSize=0;
        for(auto& thelist : oldtable)
            traverse_and_reinsert(tree, *this);

    }
    int myhach(const Hashedobj& ho) const {
        static std::hash<Hashedobj> h;
        return h(ho) % array.size();
    }
    public:
    explicit SCH_AVL(int size =101) : array(nextprime(size)) , CurrentSize(0) {};
  
    bool exist(const Hashedobj& x) const {
        return array[myhash(x)].contain(x);
    }

    void insert(const Hashedobj& ho){
        if(!exist(ho)){ 
            auto& thislist = array[myhach(ho)];
            thislist.add(ho);
            CurrentSize++;
            if(CurrentSize>= array.size()/2){
                rehash();
            }
        }
    }
    void insert(Hashedobj&& ho){
        thislist.add(std::move(ho));  
        CurrentSize++;                   
    }
    void zero_it(){
        for(auto& thislist : array)
            thislist.delet_all();
    }
    void delete_it(const Hashedobj & ho){
        if(exist(ho)){ 
            auto& thislist= array[myhach(ho)];
            if(thislist.contain(ho)){ 
                thislist.delet(ho);
                --CurrentSize;
            }
        }
    }
    double CurrentLoad(){
        return static_cast<double>(currentSize) / array.size(); 
    }
    void traverse_and_reinsert(AVL<Hashedobj>& tree, SCH_AVL& newTable) {
        // Use an in-order traversal to access elements
        auto insert_all = [&newTable](const Hashedobj& obj) {
            newTable.insert(obj);
        };
        tree.in_order_traversal(insert_all); // AVL should have a method for this
    }
};


//for illustration
class Employee{
    public:
        Employee(const std::string& n, int s, int e) : name(n), salary(s), seniority(e) {}
        const std::string& getName() const
            {return  name;}
        bool  operator==(const Employee&  rhs) const
            {return  getName()  ==  rhs.getName();}
        bool  operator!=(const Employee& rhs) const
            {return !(*this==rhs);}
    private:
        std::string name;
        double salary;
        int    seniority;
};

//hash key
template<>
class std::hash<Employee>{
    public:
        size_t operator()(const Employee& item) const {
            return std::hash<std::string>()(item.getName());
        }
};

//separate chaining hash
template<typename Hashedobj>
class SCH {
    private:
    std::vector<std::list<Hashedobj>> array;
    int CurrentSize;
    void rehash(){
        std::vector<list<Hashedobj>> oldtable = array;
        array.resize(nextprime(2*array.size()));
        for(auto& thislist : array )
            thislist.clear();

        CurrentSize=0;
        for(auto& thelist : oldtable)
            for(auto& item : thelist)
                insert(std::move(item));
    }
    int myhach(const Hashedobj& ho) const {
        static std::hash<Hashedobj> h;
        return h(ho) % array.size();
    }
    public:
    explicit SCH(int size =101) : array(nextprime(size)) , CurrentSize(0) {};
    bool exist(const Hashedobj& ho) const{
        auto& thislist = array[myhach(ho)];
        return std::find(thislist.begin(), thislist.end(), ho) != thislist.end();
    }
    void insert(const Hashedobj& ho){
        if(!exist(ho)){ 
            auto& thislist = array[myhach(ho)];
            thislist.push_back(ho);
            CurrentSize++;
            if(CurrentSize>= array.size()/2){
                rehash();
            }
        }
    }
    void insert(Hashedobj&& ho){
        thislist.push_back(std::move(ho));  
        CurrentSize++;                   
    }
    void zero_it(){
        for(auto& thislist : array)
            thislist.clear();
    }
    void delete_it(const Hashedobj & ho){
        if(exist(ho)){ 
            auto& thislist= array[myhach(ho)];
            auto  itr = std::find(thislist.begin(), thislist.end(), ho);
            if(itr != thislist.end()){ 
                thislist.erase(itr);
                --CurrentSize;
            }
        }
    }
    double CurrentLoad(){
        return static_cast<double>(currentSize) / array.size(); 
    }

};



//main
int main() {
    Employee e1("Alice", 50000, 5);
    Employee e2("Bob", 60000, 7);
    Employee e3("Charlie", 55000, 6);

    SCH<Employee> hashTable(10);
    hashTable.insert(e1);
    hashTable.insert(e2);
    hashTable.insert(e3);

    std::cout << "Hash table operations completed successfully!" << std::endl;
    return 0;
}








//helper
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
