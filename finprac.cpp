#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template <class T>
T add(T x, T y){
   return x + y;
}
class A{
   
   public:
      
      virtual void display(){
         cout<<"A";
      }
      // static int f;
   

};
// class B :public A{
//    void display(){
//       cout<<"B";
//    }
// };


int main(){
   
   cout<<setfill('*')<<setw(6)<<100;
   
   
}
