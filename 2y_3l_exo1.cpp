#include <iostream>
#include <list>

void printLots(const std::list<int>& L, const std::list<int>& P) {
    auto lIt = L.begin();
    int index = 0;

    for (auto pIt = P.begin(); pIt != P.end(); ++pIt) {
        int pos = *pIt; 

        while (index < pos && lIt != L.end()) {
            ++lIt;
            ++index;
        }

        if (lIt != L.end() && index == pos) {
            std::cout << *lIt << " ";
        }
    }
}




int main(){
    std::list<int> L= {1,2,5,8};
    std::list<int> P= {1,5};
    printLots(L,P);
    return 0;
}