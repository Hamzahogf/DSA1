#include <iostream>
#include <vector>
#include <stdexcept>


//Inseertion Sorting
template<typename comparable>
std::vector<comparable> IS(std::vector<comparable>& v){
    size_t r;
    for (size_t i = 1; i < v.size()-1; i++)
    {   r=i;
        for(size_t j=i-1; j>=0 ; j--,r--){
            if(v[r]<=v[j])
                std::swap(v[j],v[r]);
        }
    }
    return v;
}


//Shell Sorting
template<typename comparable>
std::vector<comparable> SS(std::vector<comparable>& v){
    int gap = v.size()/2;
    size_t r,k;
    while (gap>0)
    {   r=0;
        for (size_t  j = gap; j < v.size()-1 ; j++,r++)
        {
           if(v[j]<=v[r]){
            std::swap(v[j],v[r]);
            for(size_t t=j-1,k=r-1 ; j>0 && k>=0; j-- , k--){
                if(v[t]<=v[k]){
                  std::swap(v[k],v[t]);
             }
           }
        }
        gap/=2;
    }
    }
    return v;
}


//Heap Sorting (max-d-heap)
template<typename Comparable,int d>
class DH{
    private:
    std::vector<Comparable> array;
    int currentSize;
    void percolateDown(int hole){
        int child;
        Comparable tmp= std::move(array[hole]);
        for(;(hole*d)-(d-2)<= currentSize;hole=child){
            child = (hole*d)-(d-2) ;
            for(size_t i = 1  ; i< d ; i++){
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
    void percolateUp(int hole,const Comparable &x){
        array[0] = std::move(x);
        for(;hole>1 && x > array[(hole - 2) / d + 1] ; hole= (hole - 2) / d + 1){
            array[hole] = std::move(array[(hole - 2) / d + 1]);
        }
        array[hole]= std::move(array[0]); 
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
    void deletMax(){
        if(currentSize==0)
          throw  UnderflowException{};

        //percolate Down
        array[0] = std::move(array[1]);
        array[1]=std::move(array[--currentSize]);
        percolateDown(1);
        array[currentSize+1]= std::move(array[0]);
    }
    void remove(int pos){
       decreaseKey(pos, std::numeric_limits<Comparable>::max());
       deletMin();
    }
    void Sort(){
        int size= currentSize;
        for(size_t i=0 ; i<size ; i++){
            deletMax();
        }
        currentSize = size;
    }
};


//Merge Sorting
template<typename comparable>
std::vector<comparable> MS(std::vector<comparable>& v){
    std::vector<comparable> temp;
    Merge_Sort(v , temp , 0 , v.size()-1);
}
template<typename comaprable>
void Merge_Sort(std::vector<comaprable>& v , std::vector<comaprable>& temp, int left , int right){
    if(left<right){
        int center = (left+ right) /2;
        Merge_Sort(a,temp, left , center);
        Merge_Sort(a,temp, center+1 , right);
        Merge(a,temp,left,center+1,right);
    }
}
template<typename comaprable>
void Merge(std::vector<comaprable>& v , std::vector<comaprable>& tmpArray, int leftPos , int rightPos, int rightEnd){
    int leftPos = rightPos-1;
    int tmpPos=leftPos;
    int numElements=rightEnd-leftPos+1;
    while( leftPos <= leftEnd && rightPos <= rightEnd )
     if(a[leftPos]<= a[rightPos])
      tmpArray[tmpPos++]  =  std::move(a[leftPos++]);
     else 
        tmpArray[tmpPos++] = std::move(a[rightPos++]); 
    while(leftPos<=leftEnd)        
        tmpArray[tmpPos++] = std::move(a[leftPos++]);
    while( rightPos  <=  rightEnd  )  
        tmpArray[tmpPos++]= std::move(a[rightPos++]);        
    for( int i = 0; i < numElements; ++i,--rightEnd)
        a[rightEnd]=std::move(tmpArray[rightEnd]);

} 


//Quick Sort
template<typename comaprable>
void QS(std::vector<comaprable>& v){
  Quick_Sort(v,0,v.size()-1);
}
template<typename comprable>
comprable& median3(std::vector<comprable>& a , int left ,int right){ 
    int center = (left+right)/2;
    if(a[center] < a[left])
        std::swap(a[center],a[left]);
    if(a[left]<a[right])
        std::swap(a[right],a[left]);
    if(a[right]< a[center])
        std::swap(a[center],a[right]);

    std::swap(a[center],a[right-1]);
    return a[right-1];
}
template<typename comaprable>
void Quick_Sort(std::vector<comaprable>& a , int left , int right){
    if (left + 10 <= right) {
        comaprable pivot = median3(a,left,right);

        int i = left, j = right - 1;
        for (;;) {
            while (a[++i] < pivot) {}
            while (pivot < a[--j]) {}
            if (i < j)
                swap(a[i], a[j]);
            else
                break;
        }

        // Restore pivot to its correct position
        swap(a[i], a[right - 1]);

        quicksort(a, left, i - 1);  
        quicksort(a, i + 1, right); 
    } else {
        ISS(a, left, right); //i need to modify mine
    }
}


template<typename Comparable>
void ISS(std::vector<Comparable>& a, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        Comparable tmp = a[i];
        int j = i;
        while (j > left && tmp < a[j - 1]) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = tmp;
    }
}