#include <iostream>
#include <string>
#include <algorithm>

void quick_sort_helper(std::string &s, int low, int high) {
    if (low < high) {
        int pivot_index = high;
        int i = low - 1;

        for (int j = low; j < high; ++j) {
            if (s[j] < s[pivot_index]) {
                ++i;
                std::swap(s[i], s[j]);
            }
        }

        std::swap(s[i + 1], s[pivot_index]);
        pivot_index = i + 1;

        quick_sort_helper(s, low, pivot_index - 1);
        quick_sort_helper(s, pivot_index + 1, high);
    }
}

std::string quick_sort(std::string s) {
    int size = s.size();

    if (size <= 1) {
        return s;
    }

    quick_sort_helper(s, 0, size - 1);

    return s;
}

void BinRep(int n, int A[32]) {
    for (int i = 31; i >= 0; --i) {
        A[i] = n % 2;
        n /= 2;
    }
}

std::string recu_str(std::string &s, char x, char y) {
    int size = s.size();
    if (size == 1) {
        if (s[0] == x) {
            s[0] = y;
        }
        return s;
    } else {
        std::string R;
        for (int i = 0; i < size; i++) {
            std::string T = s.substr(i, 1);
            R += recu_str(T, x, y);
        }
        return R;
    }
}

struct cours {
    std::string name;
    int coef;
    int grad;
};

int main() {
    std::string s;
    std::cin >> s;
    std::string result = quick_sort(s);

    std::cout << "Sorted:   " << result << std::endl;



    std::string S;
    std::cin >> S;
    char x = 'j';
    char y = 't';
    std::string op = recu_str(S, x, y);

    std::cout << op << std::endl;

    return 0;
}
