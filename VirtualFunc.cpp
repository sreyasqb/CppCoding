#include <iostream>
using namespace std;
class Animal{

    public:
        Animal(){
            cout<<"Animal constructor called\n";
        }
        virtual void display(){
            cout<<"This is animal \n";
        }
        // ~Animal(){
        //     cout<<"Animal desctructor called\n";
        // }
};

class Dog: public Animal{

    public:
        Dog(){
            cout<<"Dog constructor called\n";
        }
        void display(){
            cout<<"This is a dog\n";
            Animal::display();
        }
        // ~Dog(){
        //     cout<<"Dog desctructor called\n";
        // }
};


int main(){
    Animal *aniptr;
    Dog obj;
    aniptr=&obj;
    aniptr->display();

}