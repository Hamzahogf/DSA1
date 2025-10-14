#include <iostream>
using namespace std;
void moukhtarya(int n ){
    for(int i = 2; i <= n/2; i++) {
        if(n % i ==0) {
            cout<<"your number is not prime";
            else cout<<"your number is prime";
        }
    }
}
int main() {
    int n;
    cin>>n ;
    moukhtarya(n);
    return 0;
}