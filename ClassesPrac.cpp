#include <iostream>
using namespace std;
class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        void setDay(int day)
        {
            this->day=day;
            
        }
        void setMonth(int month)
        {
            this->month=month;
            
        }
        void setYear(int year)
        {
            this->year=year;
        }
        int getDay()
        {
            
            return day;
        }
        int getMonth()
        {
            
            return month;
        }
        int getYear()
        {
            return year;
        }
        void display() const
        {
            cout<<day<<"/"<<month<<"/"<<year;
        }
    
};

int main()
{
    Date today;
    Date &today_ref=today;
    Date *today_ptr=&today;
    
    today.setDay(5);
    today.setMonth(6);
    today.setYear(2002);
    cout<<today_ref.getDay()<<endl;
    cout<<today_ptr->getMonth();
    //today.display();

    //cout<<today.month;
    //cout<<today.getDay()<<"/"<<today.getMonth()<<"/"<<today.getYear()<<endl;
}