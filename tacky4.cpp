#include <iostream>

class Setintegere {
private:
    int arr[101] = {0};
    void utile(int ar[], int size);

public:
    Setintegere(int ar[] = nullptr, int size = 0);
    void intersectionOfSets(const Setintegere& s2);
    void unionOfSet(const Setintegere& s2);
    void insertElement(int val);
    void deleteElement(int val);
    void inputSet(int inputArr[], int size);
    void printSet();
    bool isEqual(const Setintegere& s1, const Setintegere& s2);
};

void Setintegere::utile(int ar[], int size) {
    int curr;
    for (size_t i = 0; i < size; i++) {
        curr = ar[i];
        if (curr >= 0 && curr <= 100) {
            arr[curr] = 1;
        }
    }
}

Setintegere::Setintegere(int ar[], int size) {
    if (ar != nullptr) {
        utile(ar, size);
    }
}

void Setintegere::unionOfSet(const Setintegere& s2) {
    Setintegere result;
    for (size_t i = 0; i < 101; i++) {
        result.arr[i] = (arr[i] != 0 || s2.arr[i] != 0) ? 1 : 0;
    }
    result.printSet();
}

void Setintegere::intersectionOfSets(const Setintegere& s2) {
    Setintegere result;
    for (size_t i = 0; i < 101; i++) {
        result.arr[i] = (arr[i] != 0 && s2.arr[i] != 0) ? 1 : 0;
    }
    result.printSet();
}

void Setintegere::insertElement(int val) {
    if (val >= 0 && val <= 100) {
        arr[val] = 1;
    }
}

void Setintegere::deleteElement(int val) {
    if (val >= 0 && val <= 100) {
        arr[val] = 0;
    }
}

void Setintegere::inputSet(int inputArr[], int size) {
    utile(inputArr, size);
}

void Setintegere::printSet() {
    bool empty=true;
    for (size_t i = 0; i < 101; i++) {
        if (arr[i]!=0)
        {
          empty=false;
          break;
        }
        
    }
    if (empty==false)
    {
        for (size_t i = 0; i <= 101; i++)
        {
            if (arr[i]!=0)
            {
                std::cout<<i<<" ";
            }
            
        }
        
    } else {
        std::cout<<" - - ";
    }
    
}

bool Setintegere::isEqual(const Setintegere& s1, const Setintegere& s2) {
    for (size_t i = 0; i < 101; i++) {
        if (s1.arr[i] != s2.arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int set1[] = {1, 3, 5, 7, 9};  // Example set 1
    int set2[] = {2, 4, 6, 8, 10}; // Example set 2
    int size1 = sizeof(set1) / sizeof(set1[0]);
    int size2 = sizeof(set2) / sizeof(set2[0]);
    Setintegere s1(set1, size1); // Create Setintegere object with set1
    Setintegere s2(set2, size2); // Create Setintegere object with set2

    // Test set operations
    std::cout << "Set 1: ";
    s1.printSet();
    std::cout << "Set 2: ";
    s2.printSet();

    std::cout << "Union of sets: ";
    s1.unionOfSet(s2);

    std::cout << "Intersection of sets: ";
    s1.intersectionOfSets(s2);

    return 0;
}