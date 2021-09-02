#include <iostream>
#include <string>
int a=0;
int CallNo()
{
    static int i=0;
    i+=1;
    a++;
    return i;
}
double Power(double base, int p=2)
{
    double ans=1;
    for (int i=0;i<p;i++)
    {
        ans*=base;
    }
    return ans;
}
void MovieTime(std::string name,int time=90)
{
    std::cout<<name<<"->"<<time<<std::endl;

}
/*void Smaller(int &x,)
{
    
}*/




int main()
{
    for (int i=0;i<10;i++)
        std::cout<<"This function is called "<<CallNo()<<" times"<<std::endl;
    std::cout<<a;
    /*std::cout<<Power(4,4);
    std::cout<<Power(4);*/
    /*MovieTime("Inception",45);
    MovieTime("Alphabet");*/
}