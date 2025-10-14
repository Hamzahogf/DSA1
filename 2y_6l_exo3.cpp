#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits> 
#include <cmath> 

//2-heap : min-max-heap version   
template<typename Comparable>
class DH{
    private:
    std::vector<Comparable> array;
    int currentSize;
    void percolateDownMin(int hole){
        int child;
        Comparable tmp= std::move(array[hole]);
        for(;(hole*2)<= currentSize;hole=child){
            child = (hole*2) ;
            for(size_t i = 1  ; i< 2 ; i++){
                if(child + i <= currentSize && array[child+i] < array[child] )
                    child++;
            }   
            if(array[child] < tmp){
                array[hole] = std::move(array[child]);
            } else {
                break;
            }
    }
        array[hole]=std::move(tmp);
    }
    void percolateDownMin(int hole){
        int child;
        Comparable tmp= std::move(array[hole]);
        for(;(hole*2)<= currentSize;hole=child){
            child = (hole*2) ;
            for(size_t i = 1  ; i< 2 ; i++){
                if(child + i <= currentSize && array[child+i] > array[child] )
                    child++;
            }   
            if(array[child] > tmp){
                array[hole] = std::move(array[child]);
            } else {
                break;
            }
    }
        array[hole]=std::move(tmp);
    }
    void percolateUp(int hole, Comparable x) {
        if (hole == 1) {  
            array[hole] = std::move(x);
            return;
        }

        bool isMinLevel = getDepth(hole) % 2 == 0;

        if (isMinLevel) {
            if (hole / 2 > 0 && array[hole / 2] < x) {
                array[hole] = std::move(array[hole / 2]);
                percolateUp(hole / 2, x);
            } else if (hole / 4 > 0 && array[hole / 4] > x) {
                array[hole] = std::move(array[hole / 4]);
                percolateUp(hole / 4, x);
            } else {
                array[hole] = std::move(x);
            }
        } else {
            if (hole / 2 > 0 && array[hole / 2] > x) {
                array[hole] = std::move(array[hole / 2]);
                percolateUp(hole / 2, x);
            } else if (hole / 4 > 0 && array[hole / 4] < x) {
                array[hole] = std::move(array[hole / 4]);
                percolateUp(hole / 4, x);
            } else {
                array[hole] = std::move(x);
            }
        }
    }
    int getDepth(int index) {
        return static_cast<int>(std::log2(index));
    }
    public:
    explicit DH(int size = 13): array(size) {
        currentSize=0;
    }
    explicit DH(const std::vector<Comparable>& items):array(items.size() + 1), currentSize(items.size()){
        //Build Heap
        for(size_t i = 1 ; i <= items.size() ; i++)
            array[i]=items[i-1];
        for(size_t i=  currentSize / d ; i >0 ; i--)
            percolateDown(i);
    }
    void insert(const Comparable& x) {
        if (currentSize + 1 >= array.size())
            array.resize(array.size() * 2);

        percolateUp(++currentSize, x);
    }
    void deletMin(){
        if(currentSize==0)
          throw  UnderflowException{};

        //percolate Down
        array[1]=std::move(array[--currentSize]);
        percolateDownMin(1);
    }
    void deletMax(){
        if(currentSize==0)
          throw  UnderflowException{};

        int i = (currentSize > 1 && array[2] > array[3]) ? 2 : 3;

        array[i]=std::move(array[--currentSize]);
        percolateDownMax(i);
    }
    Comparable findMin(){
        if(currentSize==0)
            throw  UnderflowException{};
        return array[1];
    }
    Comparable findMax() {
        if (currentSize == 0)
            throw std::underflow_error("Heap is empty.");
        if (currentSize == 1)
            return array[1];
        return (array[2] > array[3]) ? array[2] : array[3];
    }
};
