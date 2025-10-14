#include <iostream>
#include <list>

void printLots(const std::list<int>& L1 ,const std::list<int>& L2) {
    std::list<int> L3;  
    auto it1 = L1.begin();
    auto it2 = L2.begin();

    while (it1 != L1.end() && it2 != L2.end()) {
        if (*it1 < *it2) {
            ++it1;  
        } else if (*it1 > *it2) {
            ++it2; 
        } else {
            L3.push_back(*it1);
            ++it1;
            ++it2;
        }
    }

    std::cout << "Intersection: ";
    for (const auto& item : L3) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::list<int> L1={1,5,9,15};
    std::list<int> L2={1,5,8};
    printLots(L1,L2);
    return 0;
}