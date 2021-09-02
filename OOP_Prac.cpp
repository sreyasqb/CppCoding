#include <iostream>
using namespace std;
class Address
{
    private:
        int houseNo;
        int street;
        int apNo;
        string city;
        string state;
        int postalCode;
    public:
        Address(int apNo,int street ,int houseNo, string city, string state, int postalCode)

        {
            this->apNo=apNo;
            this->street=street;
            this->houseNo=houseNo;
            this->city=city;
            this->state=state;
            this->postalCode=postalCode;
        }
        Address(int street ,int houseNo, string city, string state, int postalCode)

        {
            apNo=0;
            this->street=street;
            this->houseNo=houseNo;
            this->city=city;
            this->state=state;
            this->postalCode=postalCode;
        }
        Address();
        bool comesbefore(Address obj);
        void display();
        void read();
};

void Address::display()
{
    cout<<street<<endl<<city<<','<<state<<','<<postalCode<<endl;
}
Address::Address()
{
    
}
void Address::read()
{
    cout<<"enter apNo: ";
    cin>>apNo;

}
bool Address::comesbefore(Address obj)
{
    if (obj.street==street && obj.postalCode==postalCode)
}
int main()
{
    Address rhuban(5,7,36,"madurai","tamil nadu",5000);
    Address psg;
    psg.read();
    cout<<rhuban.comesbefore(psg);
    // rhuban.street=5;
    // rhuban.apNo=36;
    // rhuban.houseNo=7;
    // rhuban.city="madurai";
    // rhuban.state="tamil nadu";
    // rhuban.postalCode=50000;

    rhuban.display();


}