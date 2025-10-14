#include <iostream>
#include <cmath>
using namespace std;
double moukhtarya(double x1, double y1, double x2, double y2){
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2)) ;
   
}
int main() {
    double x1,y1,x2,y2 ,d;
    cin>>x1>>y1>>x2>>y2 ;
     d=moukhtarya(x1,y1,x2,y2) ;
    cout<<"D:  "<< d;
    return 0;
}