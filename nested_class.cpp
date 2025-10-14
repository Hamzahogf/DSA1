#include <iostream>
#include <string>
#include <cmath> // For square root function
#include <algorithm>
class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    void reduce() {
        int gcd_val = gcd(numerator, denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;
    }

public:
    Rational(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        reduce();
    }

    Rational add(const Rational& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Rational(num, denom);
    }

    Rational subtract(const Rational& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Rational(num, denom);
    }

    Rational multiply(const Rational& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Rational(num, denom);
    }

    Rational divide(const Rational& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Rational(num, denom);
    }

    void print() const {
        std::cout << numerator << " / " << denominator;
    }

    double printFloat() const {
        return static_cast<double>(numerator) / denominator;
    }
};
class Point {
private:
    Rational x;
    Rational y;

public:
    Point(const Rational& x_val = Rational(), const Rational& y_val = Rational()) : x(x_val), y(y_val) {}

    void setX(const Rational& x_val) {
        x = x_val;
    }

    void setY(const Rational& y_val) {
        y = y_val;
    }

    Rational getX() const {
        return x;
    }

    Rational getY() const {
        return y;
    }
};
class Segment {
private:
    Point start;
    Point end;

public:
    Segment(const Point& start_val = Point(), const Point& end_val = Point()) : start(start_val), end(end_val) {}

    double getDistance() const {
        Rational diffX = end.getX().subtract(start.getX());
        Rational diffY = end.getY().subtract(start.getY());

        double diffX_float = diffX.printFloat();
        double diffY_float = diffY.printFloat();

        return std::sqrt(diffX_float * diffX_float + diffY_float * diffY_float);
    }
};


class University {
private:
    class Student {
    public:
        std::string name;
        int age;
        std::string studentID;
        Student() : name(""), age(0), studentID("") {std::cout<<"sss"<<std::endl;}

        Student(const std::string& n, int a, const std::string& id) : name(n), age(a), studentID(id) {}
    };

    static const size_t MAX_STUDENTS = 100;  // Maximum number of students
    Student students[MAX_STUDENTS];          // Array to store students
    size_t numStudents;                      // Current number of students

public:
    University() : numStudents(0) {std::cout<<"oooooooooop"<<std::endl;}

    void addStudent(const std::string& name, int age, const std::string& studentID) {
        if (numStudents >= MAX_STUDENTS) {
            std::cerr << "Error: Maximum number of students reached." << std::endl;
            return;
        }

        students[numStudents++] = Student(name, age, studentID);
    }

    void removeStudent(const std::string& studentID) {
        for (size_t i = 0; i < numStudents; ++i) {
            if (students[i].studentID == studentID) {
                // Remove the student by shifting the remaining elements
                for (size_t j = i; j < numStudents - 1; ++j) {
                    students[j] = students[j + 1];
                }
                --numStudents;
                return;
            }
        }
        std::cerr << "Error: Student not found." << std::endl;
    }

    void printAllStudents() const {
        std::cout << "List of Students:" << std::endl;
        for (size_t i = 0; i < numStudents; ++i) {
            std::cout << "Name: " << students[i].name << ", Age: " << students[i].age << ", Student ID: " << students[i].studentID << std::endl;
        }
    }
};


class Bak {
private:
    class Account {
    private:
        int accountNumber;
        std::string accountType;
        double balance;

    public:
        Account() = default; //accountNumber(0), accountType(""), balance(0.0) {}
        Account(int number, const std::string& type, double initialBalance) : accountNumber(number), accountType(type), balance(initialBalance) {}

        int getAccountNumber() const { return accountNumber; }

        void deposit(double amount) {
            balance += amount;
        }

        bool withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
                return true;
            }
            return false;
        }

        void printAccountDetails() const {
            std::cout << "Account Number: " << accountNumber << std::endl;
            std::cout << "Account Type: " << accountType << std::endl;
            std::cout << "Balance: " << balance << std::endl;
        }
    };

    Account accounts[100];
    int nextAccountNumber;
 Account* findAccount(int accountNumber) {
        for (int i = 0; i < nextAccountNumber - 1; ++i) {
            if (accounts[i].getAccountNumber() == accountNumber) {
                return &accounts[i];
            }
        }
        return nullptr;
    }
public:
    Bak() : nextAccountNumber(1) {}

    void createAccount(const std::string& accountType, double initialBalance) {
        accounts[nextAccountNumber - 1] = Account(nextAccountNumber++, accountType, initialBalance);
    }

    void deposit(int accountNumber, double amount) {
        auto account = findAccount(accountNumber);
        if (account != nullptr) {
            account->deposit(amount);
        } else {
            std::cerr << "Error: Account not found." << std::endl;
        }
    }

    void withdraw(int accountNumber, double amount) {
        auto account = findAccount(accountNumber);
        if (account != nullptr) {
            if (!account->withdraw(amount)) {
                std::cerr << "Error: Insufficient balance." << std::endl;
            }
        } else {
            std::cerr << "Error: Account not found." << std::endl;
        }
    }
    void printAccountDetails(int accountNumber)  {
        auto account = findAccount(accountNumber);
        if (account != nullptr) {
            account->printAccountDetails();
        } else {
            std::cerr << "Error: Account not found." << std::endl;
        }
    }



   
};




class Bnk {
public:
    class Account {
    private:
        int accountNumber;
        std::string accountType;
        double balance;

    public:
        Account() = default;
        Account(int number, const std::string& type, double initialBalance) : accountNumber(number), accountType(type), balance(initialBalance) {}

        int getAccountNumber() const { return accountNumber; }

        void deposit(double amount) {
            balance += amount;
        }

        bool withdraw(double amount) {
            if (balance >= amount) {
                balance -= amount;
                return true;
            }
            return false;
        }

        void printAccountDetails() const {
            std::cout << "Account Number: " << accountNumber << std::endl;
            std::cout << "Account Type: " << accountType << std::endl;
            std::cout << "Balance: " << balance << std::endl;
        }
    };

private:
    Account accounts[100];
    int nextAccountNumber;
    
Account* findAccount(int accountNumber) {
    for (int i = 0; i < nextAccountNumber; ++i) {
        if (accounts[i].getAccountNumber() == accountNumber) {
            return &accounts[i];
        }
    }
    return nullptr;
}


public:
    Bnk() : nextAccountNumber(1) {}
void createAccount(const std::string& accountType, double initialBalance) { 
    accounts[nextAccountNumber] = Account(nextAccountNumber + 1, accountType, initialBalance);
    nextAccountNumber++;
}

    void deposit(int accountNumber, double amount) {
        auto account = findAccount(accountNumber);
        if (account != nullptr) {
            account->deposit(amount);
        } else {
            std::cerr << "Error: Account not found." << std::endl;
        }
    }

    void withdraw(int accountNumber, double amount) {
        auto account = findAccount(accountNumber);
        if (account != nullptr) {
            if (!account->withdraw(amount)) {
                std::cerr << "Error: Insufficient balance." << std::endl;
            }
        } else {
            std::cerr << "Error: Account not found." << std::endl;
        }
    }
    
    void printAccountDetails(int accountNumber)  {
        auto account = findAccount(accountNumber);
        if (account != nullptr) {
            account->printAccountDetails();
        } else {
            std::cerr << "Error: Account not found." << std::endl;
        }
    }
};



int main() {
    University university;

    // Add students
    university.addStudent("John Doe", 20, "001");
    university.addStudent("Jane Smith", 22, "002");
    university.addStudent("Alice Johnson", 19, "003");

    // Print all students
    university.printAllStudents();

    // Remove a student
    university.removeStudent("002");

    // Print all students after removal
    university.printAllStudents();

     Bak bank;

    // Create two accounts
    bank.createAccount("s", 500.0);  // Account 1234 with balance 500.
    bank.createAccount("r", 1000.0); // Account 5678 with balance 1000.0

    // Deposit money into an account
    bank.deposit(1234, 200.0);  // Deposit 200.0 into account 1234

    // Withdraw money from an account
    bank.withdraw(5678, 500.0); // Withdraw 500.0 from account 5678

    // Print account details
    bank.printAccountDetails(1234); // Print account details for account 1234
    bank.printAccountDetails(5678); // Print account details for account 5678


    return 0;
}
