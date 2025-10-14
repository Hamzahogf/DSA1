#include <iostream>
#include "sort.h"

void scan(int A[] , int s){
    for(int i=0 ; i<s ; i++){
        std::cin >>A[i]  ;
    }

}

int main() {
    const int SIZE=100;
    int A[SIZE] ,s;
    std::cin>>s ;
    scan(A , s);
    select_sort(A , s);
    for(int i=0 ; i<s ; i++){
      int j=i , r;
        do
        {
            if(A[i]==A[])
            r++;
            j++;
        } while (A[i]=A[j+1]);
        
    }
}