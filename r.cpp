#include <iostream>

int main() {
    const int SIZE = 3;
    const char* strings[SIZE] = {"Banana", "Cherry", "Apple"};


    for (int i = 0; i < SIZE; ++i) {
        std::cout << "String at index " << i << ": " << *(strings +i )<< std::endl;
    }

    const char *arr[] = {"c", "c++", "java", "VBA"};
    const char *(*ptr)[4] = &arr;
      std::cout<<++(*ptr)[2];
    



    char str1[] = "Hello mki";
    char str2[] = "World";
    char (*per)[10] = &str1;


     std::cout<<*(*per);
     std::cout<<(* per);




    
    return 0;

    return 0;
}
