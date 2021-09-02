#include <iostream>
using namespace std;
class Point{
    protected:
        float x;
        float y;
    public:
        Point(float _x,float _y):x(_x),y(_y){}
        Point(){
            x=0;
            y=0;
        }
        Point operator + (Point p2){
            Point p3;
            p3.x=x+p2.x;
            p3.y=y+p2.y;
            return p3;

        }

        friend ostream & operator <<(ostream &out,const Point & p){
            cout<<'('<<p.x<<','<<p.y<<')'<<endl;
            return out;
        }
        friend istream & operator >>(istream &in,Point & p){
            cout<<"Enter the x value :";
            in>>p.x;
            cout<<"Enter the y value :";
            in>>p.y;
            return in;


        }

        
};
int main(){

    Point p1(4.5,5),p2(6.3,7.2);
    Point p3=p1+p2;
    cout<<p3;
    
    Point p4;
    cin>>p4;
    cout<<p4;


}

