//
// Created by 91988 on 17-04-2021.
//

#ifndef OOPSAPPV6_LOGINCPP_H
#define OOPSAPPV6_LOGINCPP_H
#include <string>
#include <iostream>

using namespace std;

class ContactUs{

    private:
        string email;
        string phoneNo;
        int rating;
        string feedback;
    public:
        ContactUs(string,string,int,string);
        ContactUs();
        string getEmail();
        string getPhoneNo();
        int getRating();
        string getFeedback();


};

ContactUs::ContactUs(string _e,string _p,int _r,string _f){
    email=_e;
    phoneNo=_p;
    rating=_r;
    feedback=_f;
}
ContactUs::ContactUs(){
    email="";
    phoneNo="";
    rating=5;
    feedback="";
}
string ContactUs::getEmail(){
    return email;
}
string ContactUs::getPhoneNo(){
    return phoneNo;
}
int ContactUs::getRating(){
    return rating;
}
string ContactUs::getFeedback(){
    return feedback;
}






class Client{

protected:
    string username;
    string password;
    
public:
    string getUsername();

};


class Login:public Client{

public:

    Login(string ,string );
    Login();
    bool validate(string,string);

};

class LocationCpp{

protected:
    int id;
    long double lati;
    long double longi;
    string title;
    string description;
    string address;
public:
    LocationCpp(int,string,long double,long double,string);
    LocationCpp();
    long double getLatitude();
    long double getLongitude();
    void setTitle(string);
    string getTitle();
    string getDescription();
    void setDescription(string);
    void setAddress(string);
    string getAddress();
    int getIdCpp();
};



string Client::getUsername(){
    return username;
}

Login::Login(string username,string password){
    this->username=username;
    this->password=password;
}
Login::Login(){
    username="";
    password="";
}
bool Login::validate(string username,string password){
    if (username==this->username && password==this->password)
        return true;
    else
        return false;
}
LocationCpp::LocationCpp(int id,string title,long double lati,long double longi,string address){
    this->lati=lati;
    this->longi=longi;
    this->title=title;
    description="";
    this->address=address;
    this->id=id;
}
LocationCpp::LocationCpp(){
    lati=0.0;
    longi=0.0;
    description="";
    title="";
}
long double LocationCpp::getLatitude(){
    return lati;
}
long double LocationCpp::getLongitude(){
    return longi;
}
string LocationCpp::getTitle(){
    return title;
}
string LocationCpp::getDescription(){
    return description;
}
void LocationCpp::setDescription(string desc){
    description=desc;
}
void LocationCpp::setAddress(string add){
    address=add;
}
string LocationCpp::getAddress(){
    return address;
}
int LocationCpp::getIdCpp(){
    return id;
}
void LocationCpp::setTitle(string title){
    this->title=title;

}
int main(){
    LocationCpp temp(1,"Nothing",12.321312,97.123132,"NoAddress");
    cout<<temp.getAddress()<<endl;
    temp.setAddress("Hello");
    cout<<temp.getAddress();

    
}




#endif //OOPSAPPV6_LOGINCPP_H


