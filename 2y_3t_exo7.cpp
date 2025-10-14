#include<iostream>

class crrque {
    private:
        int* arr;
        int capacity;
        int size,f,r;
    public:
        crrque(int& sizt){
            if (sizt>1)
            {
            capacity=sizt;
             arr = new int[capacity];
             f=-1;
             r=-1;
             size=0;
            }
        }

        ~crrque(){delete[] arr;}
        bool isfull(){
            return (size==capacity)? 0:1;
        }
        bool isempty(){
            return (size==0)? 0:1;
        }
        int size(){
            return size;
        }
        int front(){
            if(f!=-1){ 
                return arr[f];
            }
        }
        int rear(){
            if (r!=-1)
            {
                return arr[r];
            }
        }
       
        void enque(int& x){
            if (isfull())
            {
                return;
            }
            
            if (r==-1)
            {
                r=f=0;
                arr[r]=x;
            } else if((r+1)%capacity!=f || (r==f && size!=0) )
            {
                r=(r+1)%capacity;
                arr[r]=x;
            } 
            
            size++;
        }

        void deque(){
            if (isempty())
            {
                return;
            }
            if (f==r)
            {   f=r=-1;
                size=0;
            } else {
                f=(f+1)%capacity;
                size--;
            }
            
        }
};