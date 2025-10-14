#include <iostream>
#include <vector>
#include <algorithm>

int sumVector(const std::vector<int>& vec, int index = 0) {
    if (index == vec.size()) {
        return 0; // Base case: sum of an empty vector is 0
    }
    return vec[index] + sumVector(vec, index + 1);
}

void reversvector(std::vector<int>& v, int findx, int fndx){
    std::swap(v[findx],v[fndx]);
    
if (fndx!=findx)
{
  return reversvector(v,findx+1,fndx-1);
} 
}

int findMax(const std::vector<int>& vec, int index = 0, int maxSoFar = 0) {
    if (index == vec.size()) {
        return maxSoFar;
    }
    return findMax(vec, index + 1, std::max(maxSoFar, vec[index]));
}

int binarySearch(const std::vector<int>& vec, int target, int low, int high) {
    if (low > high) {
        return -1; 
    }

    int mid = low + (high - low) / 2;

    if (vec[mid] == target) {
        return mid; 
    } else if (vec[mid] < target) {
        return binarySearch(vec, target, mid + 1, high);
    } else {
        return binarySearch(vec, target, low, mid - 1);
    }
}

void generatePermutations(std::vector<int>& vec, int start=0) {
    if (start == vec.size() - 1) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int i = start; i < vec.size(); ++i) {
        std::swap(vec[start], vec[i]);
        generatePermutations(vec, start + 1);
        std::swap(vec[start], vec[i]); // Backtrack
    }
}

void findCombinations(std::vector<int>& candidates, int target, int start, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
        current.push_back(candidates[i]);
        findCombinations(candidates, target - candidates[i], i, current, result);
        current.pop_back(); // Backtrack
    }
}

void matrix_vec_vecofvec(std::vector<std::vector<int>>& vm , int s){
    for (int i = 0; i <s ; i++)
    {
        std::vector<int> temp;
        for (int j = 0; j <s; j++)
        {
            temp.push_back(s);
        }
        vm.push_back(temp);
    }
    
}

void display_matrix_vecofvec(const std::vector<std::vector<int>>& vm){
    for (int i = 0; i < vm.size(); i++)
    {
        for (int j = 0; j<vm[i].size() ; j++)
        {
            std::cout<<vm[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    
}

void touwl_cap(std::vector<std::string> v){
   int p=0;
    for (int i = 0; i < v.size(); i++)
    {  v[p]=toupper(v[i][p]);
        if (v[i][p]==' ')
        {
            
        }
        
    }
    
}

int main() {
    std::vector<std::string> v = {"hdh"};

    // Use std::unique to remove consecutive duplicates
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());

    // Display each character after removing consecutive duplicates
    for (const auto& str : v) {
        for (char ch : str) {
            std::cout << ch << "   ";
        }
    }

    return 0;
}