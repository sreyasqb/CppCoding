#include <iostream>
#include <vector>
using namespace std;
#include <bits/stdc++.h>
int main(){
    //initialising arrays with 4 values
    int arr[]={11,12,13,14};

    //initialising the vector with 5 elements
    vector<int> v={1,2,3,4,5};
    // adding elements 6,7,8,9,10 to the vector
    for(int i=6;i<11;i++){
        v.push_back(i);
    }
    cout<<endl<<"USING NORMAL FOR LOOP :"<<endl;
    for (int i=0;i<v.size();i++){//this is the most common method
        cout<<v[i]<<',';
    }
    cout<<endl<<endl<<"USING FOR EACH LOOP FOR VECTORS:"<<endl;
    for (int value : v){  //for each loops used for vectors as well as arrays 
        cout<<value<<',';
    }
    cout<<endl<<endl<<"USING FOR EACH LOOP FOR ARRAYS:"<<endl;
    for (int value : arr){ 
        cout<<value<<',';
    }
    cout<<endl;

    //syntax for declaring an iterator
    //type_container::iterator var_name

    vector<int>::iterator it;
    it=v.begin();

    //in vector iterators we can access any specific element

    cout<<endl<<"PRINTING SOME VALUES OF ITERATORS :"<<endl;
    cout<<*it<<" // "<<*(it+2)<<" // "<<*(it+v.size()-1)<<endl;


    //we can do iterator addition/incremenet similar to pointers
    //it++;
    //it--;

    //using iterators to print all elements of a vector
    cout<<endl<<"USING ITERATORS IN FOR LOOP FOR VECTORS:"<<endl;
    for (it=v.begin();it<v.end();it++){
        cout<<*it<<',';
    }
    cout<<endl<<endl;
    //THE UNSORTED ARRAY
    vector <int> toSort={7,8,1,3,5,11};
    cout<<"THE UNSORTED ARRAY NOW IS :"<<endl;
    for (int i:toSort){
        cout<<i<<',';
    }
    cout<<endl<<endl<<"THE SORTED ARRAY IS :"<<endl;
    sort(toSort.begin(),toSort.end());
    //for descending order it is
    //sort(toSort.begin(), toSort.end(), greater<int>());
    for (int i:toSort){
        cout<<i<<',';
    }
    cout<<endl<<endl;
    cout<<"LETS REVERSE THIS CURRENT VECTOR V:"<<endl;
    for (int i :v){
        cout<<i<<',';
    }
    cout<<endl<<endl<<"NOW THE REVERSE OF THIS VECTOR IS:"<<endl;
    reverse(v.begin(),v.end());
    for (int i :v){
        cout<<i<<',';
    }
    

    cout<<endl<<endl;


}
