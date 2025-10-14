#include <iostream>
#include <vector>     //v.front()    v.back()   v.pop_back()           - int* dataArray=v.data()-    
                      //v.researve(int )     -v.capacity()=v.size()-     - cout << dataArray[i]-    -v.resize(int) it will still hold-
                      //v.clear()                                                                 -the first capacity but when you -
                      //v.max_size()=1073741823                                                   -try to cout the elements it will-
                      //v.empty()                                                                 -stop until the resize so to avoid-
                      //                                                                          -this capacity use v.shrink_to_fit()-
                      /*                             insertion
                                iterator insert(iterator pos, const T& value);
                                v.insert(iterator pos, size_type count, const T& value);
                                v.iterator insert(iterator pos, InputIt first, InputIt last);
                                v.iterator insert(iterator pos, std::initializer_list<T> ilist);
                       */
                      /*                            assignement
                                void assign(size_type count, const T& value);
                                void assign(InputIt first, InputIt last);
                      */

                       /*                              erasing
                                iterator erase(iterator pos);  //         vec.erase(vec.begin() + pos);    //     auto it = std::find(vec.begin(), vec.end(), val);  then       if (it != vec.end()) { vec.erase(it); }

                                iterator erase(iterator first, iterator last);
                        */
                       /*                              swapping
                                std::swap(v[],v[])        ||         std::swap(vector1, vector2)    ||   vector1.swap(vector2)
                       */
                       /*                               iteration
                                v.begin()=v.rend()-1      ||    v.rbegin() = v.end()-1    
                             for (auto it = myVector.rbegin(); it != myVector.rend(); it++)  for cout in reverse
                             for (auto it = myVector.begin(); it != myVector.end(); it++)    for cout in ordered
                       */

#include <algorithm>  //sort(pointer to the first element, ponter to the last element, (optional if you want the descending order you can
                      //    write your own bool function or use std::greater<int>()))  sort=heapsort+quicksort+inserionsort   O(n²)
                      // string            sort(begin(str), end(str));
                      //1d array           sort(arr, arr + size);     size=sizeof(arr)/sizeof(arr[]);
                      //2d array           sort(matrix, matrix + rows);
                      // 1d vector         sort(v.begin(), v.end());
                      //2d vector            vector<vector<int>> matrix = {
                      //                                                        {5, 2, 8, 3},
                      //                                                        {1, 7, 4, 6},
                      //                                                        {9, 0, 2, 1}
                      //                                                                     };
                      //                    sort(matrix.begin(), matrix.end(), compareRows);
                       




class SparseVector {
private:
    std::vector<double> data; // Non-zero values

public:
    // Constructor
    SparseVector(const std::vector<double>& denseVector) {
        for (double value : denseVector) {
            if (value != 0.0) {
                data.push_back(value);
            }
        }
    }

    // Addition of two sparse vectors
    SparseVector operator+(const SparseVector& other) const {
        SparseVector result(*this);
        for (double value : other.data) {
            result.data.push_back(value);
        }
        return result;
    }

    // Subtraction of two sparse vectors
    SparseVector operator-(const SparseVector& other) const {
        SparseVector result(*this);
        for (double value : other.data) {
            result.data.push_back(-value);
        }
        return result;
    }

    // Scalar multiplication of a sparse vector
    SparseVector operator*(double scalar) const {
        SparseVector result(*this);
        for (double& value : result.data) {
            value *= scalar;
        }
        return result;
    }

    // Display the sparse vector
    void display() const {
        for (double value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Example usage

    std::vector<double> t={1,0,1,4};
    SparseVector v(t);
    //v.display();
    std::vector<double> denseVector1 = {0, 2, 0, 4, 0, 0, 0, 7, 0};
    std::vector<double> denseVector2 = {1, 0, 0, 0, 0, 6, 0, 0, 9};
   
    SparseVector sparseVector1(denseVector1);
    SparseVector sparseVector2(denseVector2);
sparseVector1.display();
    SparseVector resultAddition = sparseVector1 + sparseVector2;
    std::cout << "Addition: ";
    resultAddition.display();

    SparseVector resultSubtraction = sparseVector1 - sparseVector2;
    std::cout << "Subtraction: ";
    resultSubtraction.display();

    SparseVector resultScalarMultiplication = sparseVector1 * 2.5;
    std::cout << "Scalar Multiplication: ";
    resultScalarMultiplication.display();

    return 0;
}
