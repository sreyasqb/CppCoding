#include <iostream>
#include <math.h>
using namespace std;

void swap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;

}
class Minheap{
   
        
    public:
        const int capacity;
        
        int heap_size;
        int *harr;
        Minheap(int _limit):capacity(_limit),heap_size(0),harr(new int[_limit]) {};

        void linearSearch(int val){
            for (int i=0;i<heap_size;i++){
                if (harr[i]==val){
                    cout<<"Value found";
                    return;
                }
            }
            cout<<"Value not found";
        }
        void printArr(){
            for (int i=0;i<heap_size;i++)
                cout<<harr[i]<<',';
            cout<<endl;
        }
        int height(){
            return ceil(log2(heap_size+1))-1;
        }
        int parent(int i){
            return (i-1)/2;
        }
        void insertKey(int k){
            if (heap_size==capacity){
                cout<<"Overflow";
                return ;
            }
            heap_size++;
            int i=heap_size-1;
            harr[i]=k;
            while(i!=0 && harr[parent(i)]>harr[i]){
                swap(harr[i],harr[parent(i)]);
                i=parent(i);
            }
        }


};

int main(){
    Minheap minheap(10);
    minheap.insertKey(4);
    minheap.insertKey(2);
    minheap.insertKey(3);
    minheap.insertKey(1);
    minheap.printArr();


    
    



}