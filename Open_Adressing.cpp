#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include <bitset>

// !!! default constructor needed beacause the struct HashEntry is calling it in the its constructor, so be careful !!!
class Employee{
    public:
        Employee()= default;                                                                
        Employee(const std::string& n, int s, int e) : name(n), salary(s), seniority(e) {}
        const std::string& getName() const
            {return  name;}
        bool  operator==(const Employee&  rhs) const
            {return  getName()  ==  rhs.getName();}
        bool  operator!=(const Employee& rhs) const
            {return !(*this==rhs);}
    private:
        std::string name;
        double salary;
        int    seniority;
};

//special hash for strings
template<>
class std::hash<Employee>{
    public:
        size_t operator()(const Employee& item) const {
            return std::hash<std::string>()(item.getName());
        }
};


//linear probing f(i) = i
template<typename hashedobj>
class LP {
    private:
    enum EntryType {ACTIVE,EMPTY,DELETED};
    struct  HashEntry{
        hashedobj  element;
        EntryType  info;
        HashEntry(const hashedobj& e = hashedobj{},EntryType i=EMPTY) : element{e}, info{i} {}
        HashEntry(hashedobj&& e, EntryType i =EMPTY) : element{std::move(e)}, info{i} {}
    };
   
    std::vector<HashEntry> array;
    int  currentSize;
    bool isActive(int& p) {
        return array[p].info==ACTIVE;
    }
    int findPos(const hashedobj& x) const {
        int p = myhach(x);
        while(array[p].info != EMPTY && array[p].element != x){
            p = (p + 1) % array.size();
            if(p >= array.size())
                p -= array.size();
        }
        return p;
    }
    size_t myhach(const hashedobj& x) const {
        static std::hash<hashedobj> ho;
        return ho(x) % array.size();
    }
    void rehash(){
        std::vector<HashEntry> oldtable = array;
        array.resize(nextprime(2*array.size()));
        for(auto& item : array)
            item.info=EMPTY;
        
        currentSize=0;
        for(auto& item : oldtable)
           if(item.info == ACTIVE)
            insert(std::move(entry.element));
    }

    public:
    explicit LP(int size = 101 ) : array(nextprime(size)) , CurrentSize(0) {};
    bool contain(const hashedobj& x) const {
        return isActive(findPos(x));
    }
    bool isEmpty(){
        return currentSize==0;
    }
    void zero_it(){
        if(!isEmpty()){
            for(auto& entry : array)
                entry.info=EMPTY;
        }
    }
    void insert(const hashedobj& x){
        if(!contain(x)){
            array[findPos(x)].element=x;
            array[findPos(x)].info==ACTIVE;
            ++currentSize;
            if(currentSize>= array.size()/2){rehash();}
        }
    }
    void insert(hashedobj&& x){
        array[findPos(x)].element=x;
        array[findPos(x)].info==ACTIVE;
        ++currentSize;
    }      
    void delete_it(const hashedobj& x){
        if(contain(x))
            array[findPos(x)].info=DELETED;
    }
    double CurrentLoad(){
        return static_cast<double>(currentSize) / array.size();
    }
};

//Quadratic probing f(i) = i^2
template<typename hashedobj>
class QP {
    private:
    enum EntryType {ACTIVE,EMPTY,DELETED};
    struct  HashEntry{
        hashedobj  element;
        EntryType  info;
        HashEntry(const hashedobj& e = hashedobj{},EntryType i=EMPTY) : element{e}, info{i} {}
        HashEntry(hashedobj&& e, EntryType i =EMPTY) : element{std::move(e)}, info{i} {}
    };
   
    std::vector<HashEntry> array;
    int  currentSize;
    bool isActive(int& p) {
        return array[p].info==ACTIVE;
    }
    int findPos(const hashedobj& x) const {
        int p = myhach(x);
        int offset = 1;
        while(array[p].info != EMPTY && array[p].element != x){
            p +=offset;
            offset+=2;
            if(p >= array.size())
                p -= array.size();
        }
        return p;
    }
    size_t myhach(const hashedobj& x) const {
        static std::hash<hashedobj> ho;
        return ho(x) % array.size();
    }
void rehash(){
        std::vector<HashEntry> oldtable = array;
        array.resize(nextprime(2*array.size()));
        for(auto& item : array)
            item.info=EMPTY;
        
        currentSize=0;
        for(auto& item : oldtable)
           if(item.info == ACTIVE)
            insert(std::move(entry.element));
    }

    public:
    explicit QP(int size = 101 ) : array(nextprime(size)) , CurrentSize(0) {};
    bool contain(const hashedobj& x) const {
        return isActive(findPos(x));
    }
    bool isEmpty(){
        return currentSize==0;
    }
    void zero_it(){
        if(!isEmpty()){
            for(auto& entry : array)
                entry.info=EMPTY;
        }
    }
    void insert(const hashedobj& x){
        if(!contain(x)){
            array[findPos(x)].element=x;
            array[findPos(x)].info==ACTIVE;
            ++currentSize;
            if(currentSize>= array.size()/2){rehash();}
        }
    }
    void insert(hashedobj&& x){
        array[findPos(x)].element=x;
        array[findPos(x)].info==ACTIVE;
        ++currentSize;
    }      
    void delete_it(const hashedobj& x){
        if(contain(x))
            array[findPos(x)].info=DELETED;
    }
    double CurrentLoad(){
        return static_cast<double>(currentSize) / array.size();
    }
};

//Double hashing
template<typename hashedobj>
class DH {
    private:
    enum EntryType {ACTIVE,EMPTY,DELETED};
    struct  HashEntry{
        hashedobj  element;
        EntryType  info;
        HashEntry(const hashedobj& e = hashedobj{},EntryType i=EMPTY) : element{e}, info{i} {}
        HashEntry(hashedobj&& e, EntryType i =EMPTY) : element{std::move(e)}, info{i} {}
    };
   
    std::vector<HashEntry> array;
    int  currentSize;
    bool isActive(int& p) {
        return array[p].info==ACTIVE;
    }
    int findPos(const hashedobj& x) const {
        int p1 = p = hash1(x);
        int p2 = hash2(x);
        int offset=1;
        while (array[p].info != EMPTY && array[p].element != x)
        {
            p = ( p1 + offset * p2 ) % array.size(); 
            offset++;
            if(p>= array.size())
                p-=array.size();
        }
        return p;
    }
    size_t hash2(const hashedobj& x) const {
        int p = prevprime(array.size());
        static std::hash<hashedobj> ho;
        return p - (ho(x) % p);
    }
    size_t hash1(const hashedobj& x) const {
        static std::hash<hashedobj> ho;
        return ho(x) % array.size();
    }
    void rehash(){
        std::vector<HashEntry> oldtable = array;
        array.resize(nextprime(2*array.size()));
        for(auto& item : array)
            item.info=EMPTY;
        
        currentSize=0;
        for(auto& item : oldtable)
           if(item.info == ACTIVE)
            insert(std::move(entry.element));
    }

    public:
    explicit DH(int size = 101 ) : array(nextprime(size)) , CurrentSize(0) {};
    bool contain(const hashedobj& x) const {
        return isActive(findPos(x));
    }
    bool isEmpty(){
        return currentSize==0;
    }
    void zero_it(){
        if(!isEmpty()){
            for(auto& entry : array)
                entry.info=EMPTY;
        }
    }
    void insert(const hashedobj& x){
        if(!contain(x)){
            array[findPos(x)].element=x;
            array[findPos(x)].info==ACTIVE;
            ++currentSize;
            if(currentSize>= array.size()/2){rehash();}
        }
    }
    void insert(hashedobj&& x){
        array[findPos(x)].element=x;
        array[findPos(x)].info==ACTIVE;
        ++currentSize;
    }      
    
    void delete_it(const hashedobj& x){
        if(contain(x))
            array[findPos(x)].info=DELETED;
    }
    double CurrentLoad(){
        return static_cast<double>(currentSize) / array.size();
    }
};

//Cuckoo hashing
template<typename obj, typename hashFamily>
class CH{
    private:
    struct HashEntry
    {
        obj element;
        bool isActive;
        HashEntry(const obj& e = obj(), bool act = false ) : element(e), isActive(act) {};
        HashEntry(obj && e, bool act) : element(std::move(e)) , isActive(act) {}
    };
    
    std::vector<HashEntry> array;
    static const int ALLOWED_REHASH = 5;
    static const double ALLOWED_LOAD = 0.4;
    hashFamily FHG;
    int CurrentSize;
    UniformRandom r;

    bool isActive(int currentPos){
        return array[currentPos].isActive;
    }
    void expand(){
        rehash(static_cast<int>(array.size()/ALLOWED_LOAD));
    }
    void rehash(){
        FHG.generate_new_hashed();
        rehash(array.size()); // in order to re-allcoate the old element with the new hashes func
    }
    void rehash(int size){
        std::vector<HashEntry> oldarray = array ;
        array.resize(  nextPrime( Size )  );
        for(auto & i : array){
            i.isAcrive=false;
        }
        CurrentSize = 0;
        for(auto & e : oldarray){
            if(  e.isActive  )
              insert(std::move(e.element));
        }
    }
    bool contain(const obj& x){
        return findPos(x)!=-1;
    }
    int findPos(const obj& x){
        
        for(size_t i = 0 ; i < FHG.number_of_hash() ; i++){
            int pos = myhash(x, i);
            if(isActive(pos) && array[pos].element == x){
                return pos;
            }
        }
        return -1;
    }
    size_t myhash(const obj& x, int wich){
        return FHG.hash(x, wich) % array.size();
    }
    void hashme(const obj& xx){
        obj x =xx;
        int rehashes = 0;
        while (true)
        {
            int lastpos =-1;
            int pos;
            for(int c = 0 ; c < 100 ; c++){
                for(int i =0 ; i< FHG.number_of_hash() ; i++){
                    pos = myhash(x, i);
                    if(!isActive(pos)){
                        array[  pos  ] =  std::move(  HashEntry{  std::move(  x  ),  true  }  );
                        CurrentSize++;
                        return;
                    }
                }
                int i=0;
                do
                {
                    pos  =  myhash(  x,  r.nextInt(  numHashFunctions  )  );
                } while (pos == lastpos && i<5);
                lastpos = pos;
                std::swap(x , array[pos].element );
            }    

            if(++rehashes > ALLOWED_REHASH){
                expand();
                rehashes  =  0;
            } else {
                rehash();
            }
        }
        
    }
   
    public:
    CH(int size = 101 ) : array(nextprime(size)){
        makeEmpty();
    }
    void makeEmpty(){
        CurrentSize = 0 ;
        for(auto & i : array){
            i.isAcrive=false;
        }
    }
    void remove(const obj& x){
        int pos = findPos(x);
        if(pos!=-1){
            array[pos].isActive = false;
            CurrentSize--;
        }
    }
    void insert(const obj& x){
        if(CurrentSize>= array.size() * ALLOWED_LOAD){
            expand();
        }
        if(!contain(x)){
            hashme(x);
        }
        return;
    }     
};

//Hopscotch hashing
template<typename obj>
class HSH {
    private:
    static const int ALLOWED_STRETCH;
    enum EntryType {ACTIVE,EMPTY,DELETED};
    struct HashEntry
    {
        obj element ;
        EntryType info;
        std::bitset<ALLOWED_STRETCH> bit;
        HashEntry(const obj& e = obj(), EntryType i = EMPTY ,  std::bitset<ALLOWED_STRETCH> bt = std::bitset<ALLOWED_STRETCH> ("0000")) : element(e) , bit(bt), info(i) {}
    };
    
    std::vector<HashEntry> array;
    int currentSize;
    bool isActive(int pos){
        return array[pos].info == ACTIVE;
    }
    size_t myhash(const obj& x)  {
        static std::hash<obj> ho;
        return ho(x) % array.size();
    }
    size_t findPos(const obj& x){
        int pos = myhash(x);
        bool diplaced_possible = true;
        while(diplaced_possible)
        {
            int p = pos;
            while(array[p].info != EMPTY && array[p].element != x){
                p = (p + 1) % array.size();

            }
            if((p - pos) < ALLOWED_STRETCH ){
                array[pos].bit.set((p - pos)) ;
                array[p].element = x;
                array[p].info = ACTIVE ;
                return p ;
            }
            diplaced_possible =diplace(p);
        }
        return -1;
    }
    bool diplace(int index){
        int i = index - ALLOWED_STRETCH +1 ;
        for (i ; i <= index ; i++){
           if (i < 0 || i >= static_cast<int>(array.size())) continue; // Avoid out-of-bounds
           if(array[i].bit != std::bitset<ALLOWED_STRETCH>("0000") && array[i].info == ACTIVE){
                for(int j =0 ; j<4 ; j++){
                    if(array[i].bit.tets(j)){
                        array[i].bit.set(ALLOWED_STRETCH - 1);
                        array[i].bit.reset(j);

                        int targetIndex = i + j;
                        if (targetIndex >= array.size()) {
                            targetIndex -= array.size();                     // Handle wrapping ; in LP it was in findPos 
                        }

                        array[index].element= array[targetIndex].element;
                        array[targetIndex].info = EMPTY;
                        array[index].info = ACTIVE;
                        return true;
                    }
                }
           }
        }
        return false;
    }

    public:
    explicit HSH(int size = 101) : array(nextprime(size)) , currentSize(0) {}
    void insert(const obj& x){
        if(!contain(x)){
            int pos = findPos(x);
            if (pos != -1)
             ++currentSize;
        }
    }
    bool contain(const obj& x){
        return isActive(findPos(x));
    }

};


//main
int main() {
    LP<Employee> table;
    Employee emp1("Alice", 5000, 5);
    Employee emp2("Bob", 6000, 7);

    table.insert(emp1);
    table.insert(emp2);

    std::cout << "Contains Alice: " << table.contain(emp1) << "\n";
    table.delete_it(emp1);
    std::cout << "Contains Alice after removal: " << table.contain(emp1) << "\n";

    return 0;
}



//helper
bool isPrime(int num) { 
    if (num % 2 == 0) return false;  
    int limit = std::sqrt(num);
    for (int i = 3; i <= limit; i += 2) 
        if (num % i == 0) return false; 
    return true;
}
int nextprime(int n) {
    if (n <= 2) return 2;  
    int candidate = n % 2 == 0 ? n + 1 : n; 
    while (!isPrime(candidate)) {
        candidate += 2;  
    }
    return candidate;
}
int prevprime(int n){
        if (n <= 2) return 2;  
        int candidate =n-1; 
    while (!isPrime(candidate)) {
        candidate -= 2;  
    }
    return candidate;
}