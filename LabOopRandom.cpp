#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Login{
    private:
        string emailId;
        string password;
    public:
        Login(string,string);
        void setEmailId(string);
        void setPassword(string);
        string getEmailId();
        string getPassword();
        bool validate(string ,string);

};
Login::Login(string u,string p):emailId(u),password(p){};
void Login::setEmailId(string s){
    emailId=s;
}
void Login::setPassword(string s){
    password=s;
}
string Login::getEmailId(){
    return emailId;
}
string Login::getPassword(){
    return password;
}
bool Login::validate(string u,string p){
    if (emailId==u && password==p)
        return true;
    return false;
}


class Email{

    private:
        Login user;
        string sender;
        string recipient;
        string text;
        vector <string> messages;
    public:
        Email(Login,string,string,string);
        string getSender();
        string getRecipient();
        string getText();
        void setSender(string);
        void setRecipient(string);
        void setText(string);
        void sendMessage(string,Email);
        void readMessages();

};
Email::Email(Login l,string s,string r,string m ):user(l),sender(s),recipient(r),text(m) {};
string Email::getSender(){
    return sender;
}
string Email::getRecipient(){
    return recipient;
}
string Email::getText(){
    return text;
}
void Email::setSender(string s){
    sender=s;
}
void Email::setRecipient(string s){
    recipient=s;
}
void Email::setText(string s){
    text=s;
}
void Email::sendMessage(string s,Email e){
    e.messages.push_back(s);
}
void Email::readMessages(){
    for (string i:messages){
        cout<<i<<endl;
    }
}