#include<iostream>
#include<stack>

bool check(const std::string& s){
    std::stack<char> p;
    p.push('*');

   for(auto i : s)
   {
     if (i==']' && p.top()=='['){p.pop(); continue;}
     if (i==')' && p.top()=='('){p.pop(); continue;}
     p.push(i);    
   }

    return p.top() == '*';
}

int main(){
    std::string s="[()][()()]()]";
    if (check(s)) {
        std::cout << "The string is: Balanced" << std::endl;
    } else {
        std::cout << "The string is: Not balanced" << std::endl;
    }
    return 0;
}