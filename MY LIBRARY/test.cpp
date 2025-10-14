#include<iostream>
#include "sort.h"
using namespace mylib;

void scan(int A[] , int s){
    for (int i = 0; i < s; i++)
    {
        std::cin >> A[i] ;
    }
    
}


int main() {
    const int SIZE=100;
    int A[SIZE] , s , r=0;
    std::cin >> s;
    scan(A , s);
  //  for(int i=0 ; i<s ; i++){
  //      int j=i;
  //      do
   //     {
  //          if(A[i]=A[j+1]){
   //             r++;
   //         }
   //         j++;
    //    } while (j<s);      
    //}
  //  int M[r][2] ;

}

