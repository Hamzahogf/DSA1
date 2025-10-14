#include<iostream>
void swap(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int* maximum (int* A, int s){
    int* m=A;
    for (int i = 1; i < s; ++i) {
        if (A[i] > *m) {
            m= &A[i];
        }
    }
    return m;
}
int main() { 
    int* p = nullptr;
    std::cout << p << std::endl;  
    int v = 10;
    int* q = &v;
    std::cout << q << std::endl;  // Output: address of v
    std::cout << *q << std::endl; // Output: value at the address pointed by q (which is 10)

    *q = 20;
    std::cout << q << std::endl;  // Output: address of v
    std::cout << *q << std::endl; // Output: value at the address pointed by q (which is now 20)
    std::cout << v << std::endl;  // Output: modified value of v (which is 20)

    int w = *q;
    std::cout << w << std::endl; // Output: value at the address pointed by q (which is 20)

    int* r = q;
    std::cout << r << std::endl;  // Output: address of v (same as q)
    std::cout << *r << std::endl; // Output: value at the address pointed by r (which is 20)

    *r = 15;
    std::cout << r << std::endl;  // Output: address of v
    std::cout << *r << std::endl; // Output: value at the address pointed by r (which is now 15)
    std::cout << v << std::endl;  // Output: modified value of v (which is now 15)
    std::cout<<*q<<std::endl;
     
    int a=18 , b=14;
    int* k=&a;
    int* i=&b;
    swap(k,i);
    std::cout<<*k<<"jiji"<<*i<<std::endl;
    std::cout << a << "jiij " << b << std::endl;

    int A[5]={7,4,8,9,1};
    int* y=A;
    for (int i = 0; i < 5; i++)
    {
        std::cout<<y[i]<<std::endl;

    }
    int t=0;
    int* sum=&t;
    for (int i = 0; i < 5 ; i++)
    {
        *sum+=y[i];
    }
    std::cout<<*sum<<std::endl;
    
    int M[2][3]={1,2,5,6,9,0};
    int* z = &M[0][0];
    *sum=0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            *sum += *(z + i * 3 + j);
        }
        
    }
    std::cout<<*sum<<std::endl;

    int* l=maximum(A , 5);

    std::cout<<*l<<std::endl;
    
    return 0;
}
 