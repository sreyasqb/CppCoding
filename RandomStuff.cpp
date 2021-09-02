#include<iostream>
using namespace std;
// void swapref(int &x,int &y){
//     int temp=x;
//     x=y;
//     y=temp;
// }
// void swappoint(int *x,int *y){
//     int temp=*x;
//     *x=*y;
//     *y=temp;
// }

// int &setvalue(){
//     static int x=10;
//     return x;
// }
// int fun(int &x){
//     return x;
// }
// void swap(char * &str1, char * &str2)
// {
//   char *temp = str1;
//   str1 = str2;
//   str2 = temp;
// }
int main()
{   
    // int x = 10;
    // int *ptr = &x;
    // int * & ptr1 = ptr;
    // *ptr=5;
    // x=7;
    // cout<<*ptr1<<','<<*ptr<<','<<x;
     int *ptr = NULL;
    int &ref = *ptr;
    cout << ref;
    // char *str1 = "GEEKS";
    // char *str2 = "FOR GEEKS";
    // swap(str1, str2);
    // cout<<"str1 is "<<str1<<endl;
    // cout<<"str2 is "<<str2<<endl;
    // return 0;
    // setvalue()=30;
    // cout<<setvalue();
    //cout<<fun(10);
    // int x=5,z=9;
    // int &y=x;
    // y=z;    
    // cout<<y<<","<<z<<','<<z<<endl;
    // int a=5,b=10,c=19,d=21;
    // swapref(a,b);
    // swappoint(&c,&d);
    // cout<<a<<","<<b<<endl;
    // cout<<c<<","<<d;
    
}
