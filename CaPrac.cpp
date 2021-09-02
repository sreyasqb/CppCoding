#include <iostream>
using namespace std;

class Func{

    private:
        int x=0;
        int y=0;
        static int num;
    public:
        
        Func(int _x,int _y):x(_x),y(_y){num+=1;}
        Func(){num+=1;}
        void print(){
            cout<<x<<','<<y<<','<<num<<endl;
        }
        static void getObs(){
            cout<<num<<endl;
        }
        friend void data(Func &);
        friend class B;
        
};
class B{

    public:
        void output(const Func &f){
            cout<<f.x<<endl;
        }

};

void data(Func &f){
    f.x=1;
}

int Func::num=0;
int main(){
    int num=1;
    for (int i=0;i<num;i++){
        cout<<i<<endl;
    }

}

