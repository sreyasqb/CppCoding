#include <iostream>
using namespace std;
class A{
    public:
        A(){
            cout<<"Constructor Called";
        }
        virtual void show(){
            cout<<"hello";
        }
        void bye(){
            cout<<"bye";
        }
};
class B:public A{
    public:
        void show(){
            cout<<"DERIVED";
        }
        void come(){
            cout<<"COME";
        }
};
int main(){
    A *obj=new B;
    obj->show();
    int y=1;
    int const &x=y;
    
}

