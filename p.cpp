#include <iostream>
#include <cstring>
struct person {
char name[50];
int age;
person* next; };




void insert_in_order(person* list, char n[], int a) {
person* new_person = new person;
strcpy(new_person->name, n);
new_person->age = a;
new_person->next = nullptr;
 if (list==NULL)
 {
    list=new_person;
 } else 
 {
    person* cur=list;
    while (cur->next != NULL)    {
        if (new_person->name >  cur->name)
        {
            list=new_person;
            new_person->next = cur;
            return;
        }
        cur=cur->next;
    }
    
 }
 
 
}

int main(){
    person* list=NULL;
    in
}