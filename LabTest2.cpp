#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer{
    protected:
        string name;//setting customers name 
    public:
        void setName(){
            cout<<"please enter your name :";
            cin>>name;
        }
        string getName(){
            return name;
        }
};

class Slot{

    protected:
        int slotNo=0;
    public:
        int getSlotNo(){
            slotNo++;
            return slotNo;
        }
};
class Car{

    protected:
        string carNo;
    public:
        void setCarNo(){//JUST SETTING AND GETTING CAR NO
            cout<<"Please enter your car number :";
            cin>>carNo;
        }
        string getCarNo(){
            return carNo;
        }
    
};
class Time{
    protected:
        int hour;
        int min;
        int sec;
    public:
        Time(int h,int m,int s):hour(h),min(m),sec(s){}
        Time(){
            hour=0;
            min=0;
            sec=0;
        }
        void setHour(int hour){
            this->hour=hour;
        }
        void setMin(int min){
            this->min=min;
        }
        void setSec(int sec){
            this->sec=sec;
        }

        int getHour(){
            return hour;
        }
        int getMin(){
            return min;
        }
        int getSec(){
            return sec;
        }



        Time operator -(Time &t){//THE MATH TO FIND DIFFERENCE OF 2 TIMEs
            Time t3;
            if (sec<t.sec){
                min--;
                sec+=60;
            }
            t3.sec=sec-t.sec;
            if (min<t.min){
                hour--;
                min+=60;
            }
            t3.min=min-t.min;
            t3.hour=hour-t.hour;
            return t3;
        }
        virtual void display(){
            cout<<hour<<" hours : "<<min<<" mins :"<<sec<<" secs"<<endl;
        }

};
class Allotment:public Time{
    protected:
        Time in;
        Time out;
        Time total_time;
    public:
        void setInTime(){//Taking input for the time in which user enters
            int a,b,c;
            cout<<"Please enter the hour in which u entered :";
            cin>>a;
            cout<<"Please enter the minute in which u entered :";
            cin>>b;
            cout<<"Please enter the seconds in which u entered :";
            cin>>c;
            in.setHour(a);
            in.setMin(b);
            in.setSec(c);
            // cout<<in.getHour()<<endl;
        }
        void setOutTime(){//Taking input for the time the user exits
            int a,b,c;
            cout<<"Please enter the hour in which u exited :";
            cin>>a;
            cout<<"Please enter the minute in which u exited :";
            cin>>b;
            cout<<"Please enter the seconds in which u exited :";
            cin>>c;
            out.setHour(a);
            out.setMin(b);
            out.setSec(c);
        }
        Time getInTime(){
            return in;
        }
        Time getOutTime(){
            return out;
        }
        Time time_diff(){//finding the total time difference and returning it
            total_time=out-in;
            return total_time;
        }
        // void display(){
        //     cout<<getHour()<<':'<<min<<':'<<sec<<endl;
        // }
        
};

class Payment:public Allotment{
    protected:
        double price;
        double rate=0.7;
    public:
        void setRate(double rate){
            this->rate=rate;
        }
        double getRate(){
            return rate;
        }
        double getPrice(Time t){
            
            int totalSec=t.getHour()*60+t.getMin()*60+t.getSec(); //Calculating total seconds so that we can do 0.03rs/sec
            price=rate*totalSec;
            return price;
        }

};

int main(){
    
    int count=0;
    vector <Allotment> in_times;
    vector <string> names;
    int choices=-1;
    Customer c1;
    Allotment a1;
    Car car1;
    Slot s1;
    Payment p1;
    Time total_timespent;
    while (choices!=5){
        cout<<"Please make a new car allotment :\n";
        cout<<"1.Enter Name :\n2.Enter Car number : \n3.Enter time you entered : \n";
        cout<<"4.Enter time you exited : \n5.GetDetails :"<<endl;
        cin>>choices;
        
        if (choices==1){
            
            c1.setName();
        }
        if (choices==2){
            
            car1.setCarNo();
        }
        
        if (choices==3){
            a1.setInTime();
        }
        if (choices==4){
            a1.setOutTime();
        }
        total_timespent=a1.time_diff();
        
    }  
    cout<<endl<<"Name : "<<c1.getName()<<endl;
    cout<<"Car Number : "<<car1.getCarNo()<<endl;
    cout<<"Cars Slot number is :"<<s1.getSlotNo()<<endl;
    cout<<"The total time difference is : ";
    total_timespent.display();
    cout<<"Total fair at the rate of "<<p1.getRate()<<"rs/sec is : "<<p1.getPrice(total_timespent)<<" Rs"<<endl;
    cout<<endl;
}