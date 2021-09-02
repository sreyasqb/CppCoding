#include <string>
#include <iostream>
using namespace std;
class Publication{

    protected:
        string title;
        float price;
    public:
        void getData(){
            cout<<"The title is :"<<title<<" and price is :"<<price<<endl;
        }
        void putData(string title,float price){
            this->title=title;
            this->price=price;
        }
        

};
class Book:public Publication{
    protected:
        int pageCount;
    public:
        void getData(){
            Publication::getData();
            cout<<"and the number of pages is :"<<pageCount<<endl;
        }
        void putData(int pageCount){
            this->pageCount=pageCount;
        }

};
class Tape:public Publication{
    private:
        float minutes;
    public:
        void getData(){
                Publication::getData();
                cout<<"and the length of the tape is :"<<minutes<<endl;
            }
            void putData(string title,float price,int minutes){
                this->title=title;
                this->price=price;
                this->minutes=minutes;
            }
};

class Grades{
    protected:
        int studclass;
        char section;
    public:
        Grades(int s,char sec):studclass(s),section(sec){}
        void display(){
            cout<<studclass<<"  "<<section<<endl;
        }

};
class Student:public Grades{
    private:
        string name;

    public:
        Student(string n,int s, char sec):Grades(s,sec),name(n){}
        void display(){
            cout<< name<<" "<<studclass<<"  "<<section<<endl;
        }

};



int main(){

    Grades obj1(7,'A');
    //obj1.display();
    Student s1("Sreyas",7,'A');
    s1.display();







    // Publication b1;
    // b1.putData("Sreyas",200);
    // //b1.getData();
    // Tape b2;
    // b2.putData("Sreyas",200,60);
    // b2.getData();
   
}
