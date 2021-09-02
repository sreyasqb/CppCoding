#include <iostream>
using namespace std;


class BasicShape{
    protected:
        double area;
    public:
        double getArea(){
            return area;
        }
        virtual void calcArea()=0;


};
class Circle:public BasicShape{

    private:
        long int centerX;
        long int centerY;
        double radius;
    public:
        Circle(long int x,long int y,int r):centerX(x),centerY(y),radius(r){};
        void calcArea(){
            area= 3.14*radius*radius;
        }
        long int getCenterX(){
            return centerX;
        }
        long int getCenterY(){
            return centerY;
        }
        double getRadius(){
            return radius;
        }
};
class Rectangle:public BasicShape{
    private:
        long int width;
        long int height;
    public:

        Rectangle(long int w,long int h):width(w),height(h){};
        void calcArea(){
            area=width*height;
        }
        long int getWidth(){
            return width;
        }
        long int getHeight(){
            return height;
        }

};
int main(){
    Circle c1(3.5,4.5,5);
    c1.calcArea();
    cout<<c1.getArea();
}
