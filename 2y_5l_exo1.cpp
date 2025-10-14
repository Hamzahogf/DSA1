#include <iostream>

const int UNINITIALIZED = -1;
const int SIZE=1000;

class Hash_Table {
    private:
    int array[SIZE] = {UNINITIALIZED};
    int currentsize;
    int numcollision;
    int myhash(const int& x)  {
        return x % SIZE;
    }
    public:
    Hash_Table() : currentsize(0), numcollision(0) {
        for (int i = 0; i < SIZE; ++i) {
            array[i] = UNINITIALIZED;
        }
    }
    void insert(const int& x)  {
        if(currentsize!=SIZE){
            if(array[myhash(x)]==UNINITIALIZED){
                array[myhash(x)] = x ;
                currentsize++;
            } else {numcollision++;}
        }
    }
    void remove(const int& x)  {
        int pos = myhash(x);
        if(array[pos]==x){
            array[pos]=UNINITIALIZED;
            currentsize--;
        }
    }
    int num_collision(){return numcollision;}
    double load(){return static_cast<double>(currentsize) / SIZE;}
};

int main(){
    Hash_Table t;
    while (t.load()<=0.2)
    {
        t.insert(rand());
    }

    std::cout<< "current collisions "<< t.num_collision()<<std::endl;

    while (t.load()<=0.5)
    {
        t.insert(rand());
    }

    std::cout<< "current collisions "<< t.num_collision()<<std::endl;

    while (t.load()<=0.8)
    {
        t.insert(rand());
    }

    std::cout<< "current collisions "<< t.num_collision()<<std::endl;

}