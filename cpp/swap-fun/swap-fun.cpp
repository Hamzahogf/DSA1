#include <iostream>
using namespace std;
int moukhtarya(int a , int b){
    int c ;
    c=a;
    a=b;
    cout<<a<<endl ;
    cout<<c ;

}
int main() {
    int a , b;
    cin>>a>>b;
    moukhtarya(a,b);
    return 0;
}