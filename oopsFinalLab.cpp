#include <iostream>
using namespace std;

class Date{

    protected:
        int day;   //TO GET THE DATE IN D/M/Y form
        int month;
        int year;
    public:
        Date(int,int,int); //CONSTRUCTOR TO SET THE DATES
        Date();
        string dispDate();//to DISPLAY THE DATE IN D/M/Y format

};

Date::Date(int d,int m,int y):day(d),month(m),year(y){};//USING INITIALISER LIST
Date::Date():day(0),month(0),year(0){};
string Date::dispDate(){
    return to_string(day)+"/"+to_string(month)+"/"+to_string(year);
};


class Employee{
    protected:
        string name;
        int age;
        Date DOB;
    public:
        Employee(string ,int,Date);
        Employee();
        string getName();
        int getAge();  
        string getDob();  
        void setName(string);
        void setAge(int);
        void setDob(Date);
        virtual void printData();
        
    
};

Employee::Employee(string _name,int _age,Date dob):name(_name),age(_age),DOB(dob){};
Employee::Employee():name(""),age(0),DOB(){};
string Employee::getName(){
    return name;
}
int Employee::getAge(){
    return age;
}
string Employee::getDob(){
    return DOB.dispDate();
}
void Employee::setName(string temp){
    name=temp;
}
void Employee::setAge(int temp){
    age=temp;
}
void Employee::setDob(Date temp){
    DOB=temp;
}
void Employee::printData(){
    cout<<"Name : "<< name<<endl<<"Age :"<<age<<endl<<"DOB :"<<DOB.dispDate()<<endl;
}

class PersonalRecord:public Employee{

    private:
        string Fname;//Fathers Name
        string Mname;//Mothers Name
        string hobbies;//Employees interests
        char gender;
        string martialStatus;//To check if the employee is married or single or so on
    public:
        PersonalRecord(string,int,Date,string,string,string,char,string);//Inherting from employee so setting all the name,age,dob  AND first 3 parameters are for Employee() constructor
        PersonalRecord();
        string getFname();
        string getMname();
        string getHobbies();
        char getGender();
        string getMartialStatus();
        void setFname(string);
        void setMname(string);
        void setHobbies(string);
        void setGender(char);
        void setMaritalStatus(string);
        void printData();
};

PersonalRecord::PersonalRecord(string _name,int _age,Date dob,string _fname,string _mname,string _hobbies,char _gender,string _marstatus):Employee(_name,_age,dob),Fname(_fname),Mname(_mname),hobbies(_hobbies),gender(_gender),martialStatus(_marstatus){};
PersonalRecord::PersonalRecord():Employee(),Fname(""),Mname(""),hobbies(""),gender(' '),martialStatus(""){};
string PersonalRecord::getFname(){
    return Fname;
}
string PersonalRecord::getMname(){
    return Mname;
}
string PersonalRecord::getHobbies(){
    return hobbies;
}
char PersonalRecord::getGender(){
    return gender;
}
string PersonalRecord::getMartialStatus(){
    return martialStatus;
}
void PersonalRecord::setFname(string temp){
    Fname=temp;
}
void PersonalRecord::setMname(string temp){
    Mname=temp;
}
void PersonalRecord::setHobbies(string temp){
    hobbies=temp;
}
void PersonalRecord::setGender(char temp){
    gender=temp;
}
void PersonalRecord::setMaritalStatus(string temp){
    martialStatus=temp;
}
void PersonalRecord::printData(){
    Employee::printData();
    cout<<"Father's Name : "<<Fname<<endl<<"Mother's Name : "<<Mname<<endl<<"Hobbies : "<<hobbies<<endl<<"Gender : "<<gender<<endl<<"Martial status : "<<martialStatus<<endl;
}


class ProfessionalRecord:public Employee{

    private:
        string jobTitle;
        double salary;
        Date dateJoin;
        int yearsExp;//years of experience
        string internships;//Companies worked for internships
        string reference;
    public:
        ProfessionalRecord(string,int,Date,string,double,Date,int,string);//first 3 parameters are for Employee() constructor
        ProfessionalRecord();
        string getJobTitle();
        double getSalary();
        string getDateJoin();
        int getYearsExp();
        string getInernships();
        void setJobTitle(string);
        void setSalary(double);
        void setDateJoin(Date);
        void setYearsExp(int);
        void setInternships(string);
        void printData();
        void setReference(Employee);
};

ProfessionalRecord::ProfessionalRecord(string _name,int _age,Date dob,string _job,double _sal,Date DJ,int yexp,string intern):Employee(_name,_age,dob),jobTitle(_job),salary(_sal),dateJoin(DJ),yearsExp(yexp),internships(intern){};
ProfessionalRecord::ProfessionalRecord():Employee(),jobTitle(""),salary(0.0),dateJoin(),yearsExp(0),internships(""){};
string ProfessionalRecord::getJobTitle(){
    return jobTitle;
}
double ProfessionalRecord::getSalary(){
    return salary;
}
string ProfessionalRecord::getDateJoin(){
    return dateJoin.dispDate();
}
int ProfessionalRecord::getYearsExp(){
    return yearsExp;
}
string ProfessionalRecord::getInernships(){
    return internships;
}
void ProfessionalRecord::setJobTitle(string temp){
    jobTitle=temp;
}
void ProfessionalRecord::setSalary(double temp){
    salary=temp;
}
void ProfessionalRecord::setDateJoin(Date temp){
    dateJoin=temp;
}
void ProfessionalRecord::setYearsExp(int temp){
    yearsExp=temp;
}
void ProfessionalRecord::setInternships(string temp){
    internships=temp;
}
void ProfessionalRecord::setReference(Employee e){
    reference=e.getName();
}
void ProfessionalRecord::printData(){
    Employee::printData();
    cout<<"Job Title :"<<jobTitle<<endl<<"Salary :"<<salary<<endl<<"Date of Join :"<<dateJoin.dispDate()<<endl<<"Years of experience :"<<yearsExp<<endl<<"Internships in companies :"<<internships<<endl<<"Reference from Employee : "<<reference<<endl;   
}


class AcademicRecord:public Employee{

    private:
        string board;//eg Tamil Nadu board ,CBSE
        double marks12;//getting marks for 12th
        double marks10;//marks for 10th boards
        string achievements;//ALL CERTIFICATE WONS such as hackathons,GSOC etc.
        string exams;//ALL COMPETATIVE EXAMS TAKEN PLACE IN
    public:
        AcademicRecord(string,int,Date,string,double,double,string,string);//FIRST 3 arguments are for Employee() constructor
        AcademicRecord();
        string getBoard();
        double getMarks12();
        double getMarks10();
        string getAchievements();
        string getExams();
        void setBoard(string);
        void setMarks12(double);
        void setMarks10(double);
        void setAchievements(string);
        void setExams(string);
        void printData();
        
};

AcademicRecord::AcademicRecord(string _name,int _age,Date dob,string _board,double m12,double m10,string ach,string ex):Employee(_name,_age,dob),board(_board),marks12(m12),marks10(m10),achievements(ach),exams(ex){};
AcademicRecord::AcademicRecord():Employee(),board(""),marks12(0.0),marks10(0.0),achievements(""),exams(""){};
string AcademicRecord::getBoard(){
    return board;
}
double AcademicRecord::getMarks12(){
    return marks12;
}
double AcademicRecord::getMarks10(){
    return marks10;
}
string AcademicRecord::getAchievements(){
    return achievements;
}
string AcademicRecord::getExams(){
    return exams;
}
void AcademicRecord::setBoard(string temp){
    board=temp;
}
void AcademicRecord::setMarks12(double temp){
    marks12=temp;
}
void AcademicRecord::setMarks10(double temp){
    marks10=temp;
}
void AcademicRecord::setAchievements(string temp){
    achievements=temp;
}
void AcademicRecord::setExams(string temp){
    exams=temp;
}
void AcademicRecord::printData(){
    Employee::printData();
    cout<<"Board : "<<board<<endl<<"12th Board Marks : "<<marks12<<endl<<"10th Board Marks :"<<marks10<<endl<<"Achievemenets/Certficates won : "<<achievements<<endl<<"Competative exams given : "<<exams<<endl;
}


int main(){


    Date dobRakesh(8,4,1996);
    Date dobSukith(7,2,1994);
    Date joinDateRakesh(20,8,2020);
    Employee sukith("Sukith",26,dobSukith);//REFERENCE EMPLOYEE
    cout<<"THE PERSONAL RECORD FOR RAKESH IS :"<<endl;
    //USING CONSTRUCTOR TO SET DATA
    PersonalRecord personalRakesh("Rakesh",24,dobRakesh,"Rajeev","Lakshmi","Dancing/Singing",'M',"Single");
    personalRakesh.printData();
    
    cout<<endl<<"THE PROFFESIONAL RECORD FOR RAKESH IS : "<<endl;
    ProfessionalRecord professionalRakesh;
    //Setting without Constructor to show the methods
    professionalRakesh.setName("Rakesh");
    professionalRakesh.setAge(24);
    professionalRakesh.setDob(dobRakesh);
    professionalRakesh.setDateJoin(joinDateRakesh);
    professionalRakesh.setSalary(190000.0);
    professionalRakesh.setYearsExp(1);
    professionalRakesh.setJobTitle("Backend Developer");
    professionalRakesh.setInternships("1 year at microsense");
    professionalRakesh.setReference(sukith);//SUKITH REFFERED RAKESH
    professionalRakesh.printData();


    cout<<endl<<"THE ACADEMIC RECORD FOR RAKESH IS : "<<endl;
    //using constructor
    AcademicRecord academicRakesh("Rakesh",24,dobRakesh,"ICSE",96.4,97.2,"Winner of GSOC 2017,2018","JEE->AIR 1231");
    academicRakesh.printData();
    cout<<endl;



}