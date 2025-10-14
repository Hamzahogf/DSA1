#include <iostream>
#include <vector>
//#include <stdexcept>
//#include <utility> //for the templat std::pair and you can do not use at all this lib because c11++ it handles the pair 

//class foo;
//friend class foo;
//using const on the gett or set or.. is to be sure that the object(.n) do not get modified ;
//the ElectricCar is-a car    
//public => pub is pub , pri is pri , prot is a prot
//private => everything is private
//protected => pub is protected , pri is pri , prot is prot     
//  -- protected u can access it only on the child class but not in the main--
// delete p  -ptr- here the destructor of child then the parent ; comes and constructor -of the child- the base then the child constructores comes   &&  and also here we can also know when we ust the deconstructor when we have a ptr as privat member or even in the puublic or even the protected members ; 
// when u use the virtual :  virtual = dynamic binding = overriding   ||   when u do not : static binding = redefing 
//and when u virtual u must use & or * in functions or in the main  (this is the propriete of polymorphism )  else u are in the redefing
//also another thing when u point from bast to object of child - p - and let say the function gett is not overriding then u can not do : sptr-> p.gett() ; u do it only when the func is virtual 
//we can inherant the pure virtual func that is to say we can inheret the abstraction attribute 
//memberwise assignement foo f=g ||  FOO g(f) ; but let assum that u have a ptr in the privat so when u want to copy using -memberwise assignement- this would be bad because if u modify the copied object u will touch also the prginal object and here it comes the importance of the copy constructor memberwise assignement  ||   u can overload the = operator so he works similar to the copy constructor;
//the operator functions can not be inherited (they can not be virtual also), for thes reason we can defin them as friend function 
// in the reational operators if u want to use *this u have to pree define the operator that u have been defined which was defined wihtout *this ;
//when u want to play with size  :  make func that return a size (or in its parameter ) || even thou in for loops  || even when u want to creat variable that a size  it is better to use size_t
//   only for accessing an element on str            |           u can use it either to access an element on the str or assign
//    char operator[](size_t index) const  {         |                   char& operator[](size_t index)   { 
//       return str[index];    }                     |                        return str[index];  }
//If you do not explicitly provide a destructor, the compiler creates an “empty” destructor
//the desrutctor is needed when u have in the private section a pointer 
//the copy constructor and the operator= serve to the same but the copy works only when u define and assign ?yclass obj2=obj1 , but the = there and here obj2=obj1
//assumption : the void (const myclass& obj) const { } / the first const is just to be sure that i do not want to change my obj & the 2nd const is to be sure that ob1.set(..) ob1 do not get modified 
//The term "instances of a class" refers to individual objects created from that class.
//and the static keyword indicates that the function belongs to the class itself rather than to instances of the class ; When you call Population::getNumBorn(), you're invoking the static member function getNumBorn() on the Population class. This function returns the value of the static member variable numBorn, which represents the total number of objects that have been instantiated from the Population class throughout the lifetime of the program.







class car {
private:
    int year;
    std::string model, brand;
    static int counter;

public:
    car() : model("Gclass"), brand("Audi"), year(2020) {
     // counter++;  if you remove it from the display friend func here we can remove this comment
    }

    car(std::string m, std::string b, int y) : model(m), brand(b), year(y) {       //contsrucor it can be used to intilawing and also for assigning at the first time , & u can use the settter instead of model(m);        counter++;
        if (y < 0) {
            throw std::invalid_argument("Year cannot be negative");
        }
    }
//copy constructor
    car(const car& c) : model(c.model), brand(c.brand), year(c.year) {
        counter++;   //c.getmodel
    }
   virtual ~car() {};
    void modelfun(std::string m) { model = m; } //mutator or the setter is used in assigning and also changing which this last point is not gived to the constructor
    void yearfun(int y) { year = y; }
    void brandfun(std::string b) { brand = b; }
    std::string modelget()  { return model; } //accessor
    std::string brandget()  { return brand; }
    int yearget()  { return year; }
    int curryear() ;
    friend  void display(car c);
    static int getCounter() {
        return counter;
    }
    virtual void dis() {
        std::cout << "Model: " << model << "\n";
        std::cout << "Year: " << year << "\n";
       std::cout << "Brand: " << brand << "\n";
        std::cout << "Age is " << curryear() << " years.\n";
       std::cout<<"counter is "<<car::getCounter()<<"\n"; 
    }
car operator+( car c)  {
    car result;
    result.year = year + c.year;
    result.model = model + c.model;
    result.brand = brand + c.brand;
    return result;
}

};
int car::counter = 0;


class ElectricCar : public::car{
    private: 
    int battery;
    public:
  virtual ~ElectricCar() {};
    ElectricCar():car(), battery(0) {}
    ElectricCar(std::string m,std::string b,int y,int bt):car(m,b,y) ,battery(bt){}
    void dis() override {
        car::dis();
        std::cout<<battery<<std::endl;
    }
};

template <class T,class U>
class container{
    T y;
    U r;
    public:
    container<T,U>(T x=0 ,U o=0) : y(x) ,r(o) {}
    void set_t(T x) {y=x;}
    std::pair<T, U> get_t() { return std::make_pair(y, r); }
};



class LinkedList {
private:
    struct node {
        int data;
        node* next;

        node(int value) : data(value), next(nullptr) {}
    };

    node* head;
      

    
    void display_rec(node* head){
        if (head==nullptr)
        {
            return;
        } else {
            std::cout<<head->data<<" ";
            display_rec(head->next);
        }
        
    }

public:
    LinkedList() : head(nullptr) {}

    // Insert a new node at the beginning of the list
    void insert(int value) {
        node* newnode = new node(value);
        newnode->next = head;
        head = newnode;
    }

    // Display the elements of the linked list
    void display() const{
        node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

   int length_rec(node* current) const {
        if (current == nullptr) {
            return 0;
        } else {
            return 1 + length_rec(current->next);
        }
    }
   void insert_at_pos(int value , int pos){
    node* new_node=new node(value);
    node* cuur=head;
    node* prev=head;
    if (pos==1)
    {
        insert(value);
    } else {
        for (int i = 0; i < pos-1; i++)
        {
            prev=cuur;
            cuur=cuur->next;
        }
        prev->next=new_node;
        new_node->next=cuur;
    }
    
   }
   int length(){
    int i=0;
    while (head!=nullptr)
    {
        i++;
        head=head->next;
    }
    return i;
    
   }
   int get_length_rec() const {
        return length_rec(head);
    }


   void get_display_rec(){
    display_rec(head);
   }

void revers_lis() {
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

    // Destructor to free memory when the linked list is destroyed
    ~LinkedList() {
        node* current = head;
        node* nextnode;

        while (current != nullptr) {
            nextnode = current->next;
            delete current;
            current = nextnode;
        }
         std::cout<<"i am here!";
    }
   
};




class Population {
public:
    Population() {
        numBorn++;     // Increment numBorn when an object is instantiated
        numLiving++;   // Increment numLiving when an object is instantiated
    }

    ~Population() {
        numLiving--;   // Decrement numLiving when an object is destructed
    }

    static int getNumBorn() {
        return numBorn;
    }

    static int getNumLiving() {
        return numLiving;
    }

private:
    static int numBorn;    // Number of objects instanced
    static int numLiving;  // Number of objects currently in existence
};

int Population::numBorn = 0;
int Population::numLiving = 0;


class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance; // Only created once
        return instance;
    }

    void doSomething() {
        std::cout << "Singleton instance doing something!" << std::endl;
    }

 Singleton& operator=(const Singleton&) = delete  ;  //you can't have more than one of the special obj

private:
    Singleton() {} // Private constructor
};


class MathStats {
public:
    static double average(const std::vector<int>& numbers) {
        if (numbers.empty()) {
            throw std::invalid_argument("Empty vector");
        }
        double sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        return sum / numbers.size();
    }

 };








int main()
{
    // car&electricar
    try
    {
        car myCar("Civic", "Honda", -2019);

        myCar.dis();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    container<std::string, int> t("gg", 7);
    auto values = t.get_t();
    std::cout << "Value of y: " << values.first << std::endl;
    std::cout << "Value of r: " << values.second << std::endl;

    car *cptr[] = {new car("gg", "jo", 2023), new ElectricCar("ji", "kk", 2023, 15)};
    for (car *it : cptr)
    {
        it->dis();
    }
    for (car *it : cptr)
    {
        delete it;
    }
    // linked_list
    LinkedList l;
    l.insert_at_pos(4, 1);
    l.insert_at_pos(8, 2);
    l.insert_at_pos(7, 3);
    l.insert_at_pos(-1, 4);
    l.display();
    l.revers_lis();
    l.get_display_rec();

    std::cout << "nmout 3lik Yacine ";

    // population
    Population p2;
    Population p3;

    std::cout << "Number of born objects: " << Population::getNumBorn() << std::endl; //or u can remove the static in the class and here u make : p3.getNumBorn()
    std::cout << "Number of living objects: " << Population::getNumLiving() << std::endl;

    Population p4;

    std::cout << "Number of born objects: " << Population::getNumBorn() << std::endl;
    std::cout << "Number of living objects: " << Population::getNumLiving() << std::endl;

    // singleton
    Singleton &s = Singleton::getInstance();
    s.doSomething(); // this thing that will happen it will also happens to do the t
    Singleton &t = Singleton::getInstance();

    // static function usage
    std::vector<int> numbers = {1, 3, 2, 4, 2, 2};
    std::cout << "Average: " << MathStats::average(numbers) << std::endl;
    return 0;
}




















int car::curryear()  {
    return 2024 - year;
}
void display(car c) {    //no   car::display()
    std::cout << "Model: " << c.model << "\n";
    std::cout << "Year: " << c.year << "\n";
    std::cout << "Brand: " << c.brand << "\n";
   std::cout << "Age is " << c.curryear() << " years.\n";
  std::cout<<"counter is "<<car::getCounter()<<"\n";

     //c.dis();
}













   /*  MyClass* increment() {
        value++;
         return this;  // Returns a pointer to the current object
     } 
    
     obj->increment()->increment()->display();

    
                                                          is it equivalence to    

      MyClass& increment() {
        value++;
        return *this;   //Returns a reference to the current object
    }    
    
     obj.increment().increment().display(); 
      */
 



     /* std::tuple<T, U, Z> get_t() {
        return std::make_tuple(y, r, e);
    }

    std::cout << "Value of y: " << std::get<0>(values) << std::endl;
    std::cout << "Value of r: " << std::get<1>(values) << std::endl;
    std::cout << "Value of e: " << std::get<2>(values) << std::endl; */

