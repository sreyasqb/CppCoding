#include <iostream>
using namespace std;
class SLL{
    private:
        int data;
        SLL *link;
    public:
        SLL(int value){
            data=value;
            link=NULL;
        }
        void insertBeg(int value){
            SLL *block=new SLL(value);
            block->link=link;
            link=block;
        }
        void insertEnd(int value){
            SLL *block=new SLL(value);
            cout<<link->link->data<<','<<data<<endl;
            while(link!=NULL){
                link=link->link;
            }
            link=block;

        }
        void print(){
            
            while (link!=NULL)
            {
                cout<<link->data<<',';
                link=link->link;
            }
            cout<<data<<endl;
        }
};
int main(){
    SLL node(5);
    node.insertBeg(6);
    node.print();
    node.insertEnd(7);
    node.print();
}