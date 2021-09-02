#include <iostream>
#include <string>
using namespace std;

class Date{

    private:
        int day;
        int month;
        int year;
    public:
        Date(int d,int m,int y):day(d),month(m),year(y){};
        Date(){
            day=0;
            month=0;
            year=0;
        }
        string dispDate(){
            return to_string(day)+"/"+to_string(month)+"/"+to_string(year);
        }
        
};

class PersonType{
    protected:
        string name;
        Date DOB;
        int age;
    public:
        PersonType(string s,Date d,int a):name(s),DOB(d),age(a){};
        
        string getName(){
            return name;
        }
        string getDate(){
            return DOB.dispDate();
        }
        int getAge(){
            return age;
        }


};
class DoctorType:public PersonType{
    private:
        string speciality;
    public:

        DoctorType(string s,Date d,int a,string spec):PersonType(s,d,a),speciality(spec){};

        string getSpeciality(){
            return speciality;
        }

        void operator =(const DoctorType &D){
            age=D.age;
            name=D.name;
            DOB=D.DOB;
            speciality=D.speciality;
        } 


};

class PatientType:public PersonType{

    protected:
        int patientID;
        string phy_name;
        Date admit;
        Date discharge;
    public:
        PatientType(string s,Date d,int a,int p,string phy,Date ad,Date dis):PersonType(s,d,a),patientID(p),phy_name(phy),admit(ad),discharge(dis){};
        int getPatientID(){
            return patientID;
        }
        // string getPhyName(){
        //     return phy_name;
        // }
        string getAdmit(){
            return admit.dispDate();
        }
        string getDischarge(){
            return discharge.dispDate();
        }
};

class BillType:public PatientType{

    private:
        double pharmacyFee;
        double doctorFee;
        double roomFee;
    public:
        BillType(string s,Date d,int a,int p,string phy,Date ad,Date dis,double fee1,double fee2,double fee3):PatientType(s,d,a,p,phy,ad,dis),pharmacyFee(fee1),doctorFee(fee2),roomFee(fee3){};
        double getPharmacyFee(){
            return pharmacyFee;
        }
        double getDoctorFee(){
            return doctorFee;
        }
        double getRoomFee(){
            return roomFee;
        }

};


int main(){

    Date aniDob(6,4,2002);
    Date admission(9,8,2018);
    Date disi(11,8,2019);
    BillType bill1("anirudh",aniDob,18,1900,"nikhilesh",admission,disi,78912.9,898.8,21332.9);
    cout<<bill1.getRoomFee()<<endl<<bill1.getDischarge();
    


}