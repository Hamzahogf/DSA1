#include <iostream>
#include <memory>
class rectangle {
    private :
    float length;
    float width;
    public :
    rectangle(): length(0) , width(0) {}
    rectangle(float l, float w): length(l) , width(w) {}
   void setter(float l , int w) { length=l , width=w ;}
  std::pair<float, float> get_t() { return std::make_pair(length, width); }

   float area()const{return width*length; }
  float perimeter()const{return 2*(width+length);}
  ~rectangle() {} 

}; 

int main() {
 float a,b;
 std::cin>>a>>b;
 rectangle arr[4];
 for (size_t i = 0; i < 1; i++)
 {
float a,b;
 std::cin>>a>>b;
 arr[i].setter(a,b);
  }
 
for (size_t i = 0; i < 1; i++)
{
   auto dimensions = arr[i].get_t();
   std::cout << "Rectangle " << i + 1 << ": (" << dimensions.first << ", " << dimensions.second << ")" << std::endl;}

std::shared_ptr<rectangle> r=std::make_shared<rectangle>();
r->setter(5,4);
auto dim=r->get_t();
std::cout<<dim.first<<std::endl;
std::cout<<dim.second;
return 0;


 return 0;
}