#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <limits> // For infinity


//d-heap : min-heap version      -- root at index 1 ; -- d = 2 Binary Heap
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
    void percolateUp(int hole,const Comparable &x){
        array[0] = std::move(x);
        for(;hole>1 && x < array[(hole - 2) / d + 1] ; hole= (hole - 2) / d + 1){
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
    void deletMin(){
        if(currentSize==0)
          throw  UnderflowException{};

        //percolate Down
        array[1]=std::move(array[--currentSize]);
        percolateDown(1);
    }
    Comparable findMin(){
        if(currentSize==0)
            throw  UnderflowException{};
        return array[1];
    }
    void decreaseKey(const int& pos ,const Comparable& delta){
        array[pos]-= delta;
        percolateUp(pos,array[pos]);
    }
    void increaseKey(const int& pos ,const Comparable& delta){
        array[pos]+= delta;
        percolateDown(pos);
    }
    void remove(int pos){
       decreaseKey(pos, std::numeric_limits<Comparable>::max());
       deletMin();
    }

};

//Leftist Heap 
template<typename Comparable>
class LH{
    private:
    struct LeftistNode
    {
        Comparable data;
        int npl;
        LeftistNode* LeaftChild;
        LeftistNode* RightChild;
        LeftistNode(const Comparable& x,const int& n = -1, LeftistNode* lc = nullptr,LeftistNode* rc=nullptr) : data(x), npl(n), LeaftChild(lc), RightChild(rc) {}
    };
    
    LeftistNode* root;
    LeftistNode* merge(LeftistNode* h1,LeftistNode* h2){
        if(h1==nullptr){return h2;}
        if(h2==nullptr){return h1;}
        if(h1->data < h2->data){
            return merge1(h1, h2);
        } else {
            return merge1(h2, h1);
        }
    }
    LeftistNode* merge1(LeftistNode* h1,LeftistNode* h2){
        if(h1->LeaftChild == nullptr){
            h1->LeaftChild=h2; 
        } else {
            h1->RightChild=merge(h1->RightChild,h2);
            if(h1->RightChild->npl > h1->LeaftChild->npl)
                swapechildren(h1);
            h1->npl=h1->RightChild->npl+1;
        }
        return h1;
    }
    void swapechildren(LeftistNode* h1){
         LeftistNode* oldright= h1->RightChild;
         h1->RightChild=h1->LeaftChild;
         h1->LeaftChild=oldright;
    }
    public:
    explicit LH() : root(nullptr) {}
    void insert(Comparable x) {
        root = merge(root, new LeftistNode(x));
    }
    void deletMin(){
        if (root == nullptr) throw std::runtime_error("Heap underflow");
        LeftistNode* oldroot = root;
        root = merge(root->LeaftChild, root->RightChild);
        delete oldRoot;
    }
    void merge(LH& rhs){
        if(this==rhs)
            return;
        root=merge(root,rhs.root);
        rhs.root  =  nullptr;
    }
};

//Skew Heap 
template<typename Comparable>
class SH{
    private:
    struct LeftistNode
    {
        Comparable data;
        int npl;
        LeftistNode* LeaftChild;
        LeftistNode* RightChild;
        LeftistNode(const Comparable& x,const int& n = -1, LeftistNode* lc = nullptr,LeftistNode* rc=nullptr) : data(x), npl(n), LeaftChild(lc), RightChild(rc) {}
    };
    
    LeftistNode* root;
    LeftistNode* merge(LeftistNode* h1,LeftistNode* h2){
        if(h1==nullptr){return h2;}
        if(h2==nullptr){return h1;}
        if(h1->data < h2->data){
            return merge1(h1, h2);
        } else {
            return merge1(h2, h1);
        }
    }
    LeftistNode* merge1(LeftistNode* h1,LeftistNode* h2){
        if(h1->LeaftChild == nullptr){
            h1->LeaftChild=h2; 
        } else {
            h1->RightChild=merge(h1->RightChild,h2);
            if(h1->RightChild->npl > h1->LeaftChild->npl)
                swapechildren(h1);
            h1->npl=h1->RightChild->npl+1;
        }
        return h1;
    }
    void swapechildren(LeftistNode* h1){
         LeftistNode* oldright= h1->RightChild;
         h1->RightChild=h1->LeaftChild;
         h1->LeaftChild=oldright;
    }
    public:
    explicit SH() : root(nullptr) {}
    void insert(Comparable x) {
        root = merge(root, new LeftistNode(x));
    }
    void deletMin(){
        if (root == nullptr) throw std::runtime_error("Heap underflow");
        LeftistNode* oldroot = root;
        root = merge(root->LeaftChild, root->RightChild);
        delete oldRoot;
    }
    void merge(LH& rhs){
        if(this==rhs)
            return;
        root=merge(root,rhs.root);
        rhs.root  =  nullptr;
    }
};

//2-min-max-heap 
template<typename Comparable>
class BH{
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
    explicit BH(int size = 13): array(size) {
        currentSize=0;
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


// Custom exception
class UnderflowException : public std::runtime_error {
public:
    UnderflowException() : std::runtime_error("Heap underflow") {}
};
