#include <iostream>
#include <vector>
#include <cmath>
#include <memory> //std::unique_ptr<..> ptr=std::make_unique<..>(no-new-here ...)  these is for deleting the memory if happens an exeption  | one owner i.e no p2=p1   -all type of pointer-  | p1.swap(p2) u can yse the std::swap(p1,p2) , p1.reset(p2) change only the content of p1 with the content of p2 and p2 do not get effected  u if instead of p2 there is nothing that means p1 is Null , p2-is unique-=std::move(p1-is also-) that means ching the ownership and then p1 is Null , int* p=p1.release() here u are cgoing from smart to raw-simple pointer- and when u end u have to delete p  , int* p=p1.get() u do not need to delete it & u need it when u want to go ftom raw to API  | is dealocate the heap when it goes out of scoop or reset`| all the smart pointer are template classes | do not support use_count() 
                 // std::shared_ptr<..> ptr=std::make_shared<..>(no-new-here..)        //          //           //           //            | any own can own  i.e yes p2=p1 -only the raw ptr u can't- |  shared ptrs are thread safe-control obj- and not thread safe-manedge obj- because the shared ptrs have 2 thing : 1/manadje obg 2/control obj  | p1.use_count() but if u make std::shared_ptr<..> &p=p1-shared ptr- these will count ony 1 which is first we create p1 because &^is hwa hwa |  is dealocate the heap when it goes out of scoop or reset or intialse it with other shared ptr | there is the reset funciton & swap
                 // 8 for arrays only or 9 a class that in its privat a *||** for arr or vec or int.. u these 2 smart pointers can not delete the memory heap of an array -there si not on their template class-     for these reason we have 3 type to customize the deleter of an array on the heap      
                 //  the type`of deleter      ||                                       1d                                               ||                  2d
                 //---------------------------||----------------------------------------------------------------------------------------||---------------------------------------------------------------------------------
                //   Lambda function          || 8 std::shared_ptr<int> p(new int[10], [](int* arr) { delete[] arr; });                 || 8 std::shared_ptr<int> arr2D(new int[rows * cols], [](int* ptr) { delete[] ptr; });
                //                            || 9 std::shared_ptr<Foo> p(new Foo(42, userProvidedArr), [](Foo* obj) { delete obj; });  ||
                //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                //     Function pointer       || 8 std::shared_ptr<int> p(new int[10], arrayDeleter<int>);                              || 8 std::shared_ptr<int> arr1D(new int[rows * cols], ArrayDeleter());
                //                            ||                                                                                        ||  template <typename T>
                //                            ||     template <typename T>                                                              ||     void array2DDeleter(T** arr, size_t rows) {
                //                            ||    void arrayDeleter(T* arr) {                                                         ||      for (size_t i = 0; i < rows; ++i) {
                //                            ||    delete[] arr; }                                                                     ||      delete[] arr[i]; }
               //  ---------------------------||----------------------------------------------------------------------------------------||---------------------------------------------------------------------------------                                                                                                                          
               //     Functor                 || 8 std::shared_ptr<int> p(new int[10], arrayDeleter<int>);                              || 8 std::shared_ptr<int> arr1D(new int[rows * cols], ArrayDeleter());
               //                             ||                                                                             struct ArrayDeleter {
              //                              ||                                                                                template <typename T>
               //                             ||                                                                                void operator()(T* arr) const { 
               //                             ||                                                                                delete[] arr;  }  };
               //                             ||                                          - you can change the struct to a templat class and the operator put it on thepublic no private members -
              //----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
             // p.get()[1] = 5 even in the cout
             // std::weak_ptr<..> ptr there is no make_weak & generally this pointer is it intilized with a pointer that it is managed by a shared pointer -std::weak_ptr<..> p(shp)-   he purpose of a std::weak_ptr is to observe the lifetime of the resource managed by a std::shared_ptr without keeping it alive    & it can not be derefrence & the use_count() will get const until u creat a shared pointer and giveing it the weak ptr and this is can be used to derefrence the weak ptr but u have to check if it is looked or not : if(std::shared_ptr<..> po=p-weak-.lock()) because if shp.reset() or if p.reset() so this condition is not verified  we can also use the bool p.expired() to check wether is still exist or not   &  also when u intilaze another shared by weak u czn from here change the value of the first shared ptr   &   actualy is used to remove cyclic dependency & 


class matrix {
private:
    std::vector<std::vector<int>> vm;

public:
    
    matrix(const std::vector<std::vector<int>>& mat={}) : vm(mat) {}

    // Getter functions for rows and columns
    size_t rows() const {
        return vm.size();
    }

    size_t columns() const {
        return vm[0].size();
    }

    // Overloaded operator+ for matrix addition
   matrix operator+(const matrix& vr)const  {
    matrix result=*this;
    for (size_t i = 0; i < rows();i++) {
        for (size_t j = 0; j < columns(); ++j) {
            result.vm[i][j] = vm[i][j] + vr.vm[i][j];
        }
    }

    return result;
}

       void display() const {
        for (size_t i = 0; i < rows();i++) {
            for (size_t j = 0; j < columns(); ++j) {
                std::cout << vm[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

class Polynomial {
private:
    std::vector<int> coefficients;

public:
    // Constructors
    Polynomial(const std::vector<int>& coeffs={}) : coefficients(coeffs) {}

    // Overloaded + operator for polynomial addition
    Polynomial operator+(const Polynomial& other) const {
        size_t size1 = coefficients.size();
        size_t size2 = other.coefficients.size();
        size_t maxSize = std::max(size1, size2);

        std::vector<int> resultCoeffs(maxSize, 0);

        for (size_t i = 0; i < size1;i++) {
            resultCoeffs[i] = coefficients[i];
        }

        for (size_t i = 0; i < size2;i++) {
            resultCoeffs[i] += other.coefficients[i];
        }

        return Polynomial(resultCoeffs);
    }



    // Overloaded * operator for polynomial multiplication
    Polynomial operator*(const Polynomial& other) const {
        size_t size1 = coefficients.size();
        size_t size2 = other.coefficients.size();
        size_t resultSize = size1 + size2 - 1;

        std::vector<int> resultCoeffs(resultSize, 0);

        for (size_t i = 0; i < size1;i++) {
            for (size_t j = 0; j < size2; ++j) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(resultCoeffs);
    }

    // Function to evaluate the polynomial for a given value of x
    int evaluate(int x) const {
        int result = 0;
        size_t size = coefficients.size();

        for (size_t i = 0; i < size;i++) {
            result += coefficients[i] * pow(x, i);
        }

        return result;
    }

    // Display the polynomial
    void display() const {
        size_t size = coefficients.size();

        for (size_t i = 0; i < size;i++) {
            std::cout << coefficients[i] << "x^" << i;
            if (i < size - 1) {
                std::cout << " + ";
            }
        }

        std::cout << std::endl;
    }
};

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) { simplify();}
    Fraction operator+(const Fraction& other) const {
        int resultNumerator = numerator * other.denominator + other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;

        return Fraction (resultNumerator, resultDenominator);
    }

    int findGCD(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        int gcd = findGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
};

class date {
    private :
    int day;
    int month;
    int year;
    public:
    date(int d=0,int m=0,int y=0) : day(d) , month(m), year(y) {}
date& operator=(const date& dmy) { //dmy2=dmy1;
    if (this != &dmy) { 
        day = dmy.day;
        month = dmy.month;
        year = dmy.year;
    }
    return *this;
}

bool operator>(const date& dmy) const {return dmy > *this; }

    bool operator<=(const date& other) const {
        return !(other <= *this);
    }

};



class Person {
private:
    std::string name;
    std::shared_ptr<int> pAge;

public:
    Person(const std::string& n, int a) : name(n) {
        // Error handling for dynamic resource allocation
        try {
            pAge = std::make_shared<int>(a);
        } catch (const std::bad_alloc& e) {
            std::cerr << "Error: Failed to allocate memory for age. " << e.what() << std::endl;
            // Handle the error or rethrow the exception
        }
    }

    ~Person() {
        // Destructor takes care of releasing resources managed by shared_ptr                      no need
    }

    void display() const {
        if (pAge) {
            std::cout << "Name: " << name << ", Age: " << *pAge << std::endl;
        } else {
            std::cout << "Person data is not available." << std::endl;
        }
    }
};

class PeopleDatabase {
private:
    std::vector<std::shared_ptr<Person>> people;

public:
    // Option 1: Exclusive ownership
    void addPerson(const Person& person) {
        people.push_back(std::make_shared<Person>(person));
    }

    // Option 2: Shared ownership
    void sharePerson(std::shared_ptr<Person> person) {
        people.push_back(person);
    }

    void transferOwnership(PeopleDatabase& other, size_t index) {
        if (index < people.size()) {
            other.addPerson(*people[index]);
            people.erase(people.begin() + index);
        }
    }

    void displayPeople() const {
        for (const auto& person : people) {
            person->display();
        }
    }
};

int main() {
    // Task 1: Basic Class with Pointer Member
    Person person1("Alice", 25);
    person1.display();

    // Task 2: Managing Resources with Smart Pointers
    Person person2("Bob", 30);
    std::shared_ptr<Person> sharedPerson = std::make_shared<Person>("Charlie", 35);

    // Task 3: Copy Constructor and Copy Assignment Operator
    Person person3 = person2;
    person3.display();

    // Task 4: Move Constructor and Move Assignment Operator
    Person person4 = std::move(person3);
    person4.display();

    // Task 5: Custom Deleter
    std::shared_ptr<Person> customPtr(new Person("David", 40), [](Person* ptr) { delete ptr; });

    // Task 7: Resource Management in Containers
    PeopleDatabase database1;
    database1.addPerson(person1);
    database1.addPerson(person2);
    database1.displayPeople();

    // Task 8: Ownership Transfer
    PeopleDatabase database2;
    database2.transferOwnership(database1, 0);
    database2.displayPeople();

    // Task 9: Resource Release Strategy
    PeopleDatabase database3;
    database3.sharePerson(sharedPerson);
    database3.displayPeople();

    // Task 10: Error Handling
    Person personWithError("Eve", 45);  // Will print an error message if allocation fails
    personWithError.display();

    return 0;
}
