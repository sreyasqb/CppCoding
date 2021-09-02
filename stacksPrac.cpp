#include <iostream>
using namespace std;
int top=0;
const int n=8;
void push(int arr[],int value){
    if (top<n){
        arr[top]=value;
        top++;
    }
    else 
        cout<<"stack is full";
}
int pop(int arr[]){
    top--;
    return arr[top];
}
void display(int arr[]){
    for (int i=0;i<top;i++){
        cout<<arr[i]<<',';
    }
    cout<<endl;
}
void least_smaller(int arr[]){
    cout<<-1<<',';
    for (int i=1;i<n;i++){
        int temp[i];
        for (int j=0;j=i;j++)
            push(temp,arr[j]);
        display(temp);
        // for (int j=0;j<top;j++){
        //     int delit=pop(temp);
        //     if (delit<arr[i]){
        //         cout<<delit<<',';
        //         break;
        //     }
        //     else
        //         cout<<-1<<',';
        // }
        top=0;
    }
}
int main(){
    int arr[8]={39,27,11,4,24,32,32,1};
    least_smaller(arr);
}