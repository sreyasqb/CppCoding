#include <iostream>
using namespace std;
class Node{
    public:
        int npl;
        double data;
        string name;
        Node *left,*right;
        Node(double d,string n,Node *l=NULL,Node *r=NULL,int np=0) :data(d),name(n),left(l),right(r),npl(np){};
        void printNode(){
            cout<<name<< " "<<data<<endl;
        }

};
class LeftistHeap{

    public:
        Node *root;
        LeftistHeap():root(NULL){};
        //to swap children if npl is not satisfied
        bool isEmpty(){
            return root==NULL;
        }
        void swapChildren(Node *t){
            Node *temp=t->left;
            t->left=t->right;
            t->right=temp;
        }
        // to merge 2 heaps
        void merge(LeftistHeap &r){
            if (this==&r) return;
            root=merge(root,r.root);
            r.root=NULL;
        }
        //merge 2 nodes based on heap property
        Node *merge(Node *h1,Node *h2){
            if (!h1) return h2;
            if (!h2) return h1;
            if (h1->data > h2->data) return merge1(h1,h2);
            else return merge1(h2,h1);
        }
        //extension of merge checking leftist property
        Node *merge1(Node *h1,Node *h2){
            if (!h1->left) h1->left=h2;
            else{
                h1->right=merge(h1->right,h2);
                if (h1->left->npl < h1->right->npl) swapChildren(h1);
                h1->npl=h1->right->npl+1;
            }
            return h1;
        }
        //insert function
        void insert(double data,string name){
            root=merge(root,new Node(data,name));
        }
        //to get the root node which is max
        void printMax(){
            if (isEmpty()){
                cout<<"Heap is empty!!!"<<endl;
                return ;
            }
            Node *oldroot=root;
            root=merge(root->left,root->right);
            oldroot->printNode();
            
            delete oldroot;
            
        }


};

int main(){
    
    
    LeftistHeap CS,IT,Both,IT2;
    int n;

    cout<<endl<<"Enter the number of students in CS branch : ";
    cin>>n;
    
    cout<<endl<<"For CS branch : "<< endl;
    for (int i=0; i<n; i++){
        string name;
        double cgpa;
        cout<<endl<<"Enter name and cgpa seperated by spaces for student "<<i+1<<endl;
        cin>>name>>cgpa; //taking input 
        CS.insert(cgpa,name); //inserting into CS heap
        Both.insert(cgpa,name);
    }
    cout<<endl<<"Enter the number of students in IT branch : ";
    cin>>n;
    
    cout<<endl<<"For IT branch : "<< endl;
    for (int i=0; i<n; i++){
        string name;
        double cgpa;
        cout<<endl<<"Enter name and cgpa seperated by spaces for student "<<i+1<<endl;
        cin>>name>>cgpa; //taking input 
        
        IT.insert(cgpa,name); //inserting into CS heap
        IT2.insert(cgpa,name);
    }
    cout<<endl<<endl;

    Both.merge(IT2);

    
    int n1;
    string choice;
    cout<<"Enter number of students to find best cgpa : ";
    cin>>n1;
    cout<<"Enter CS to find top " <<n1<< " students of CS"<<endl;
    cout<<"Enter IT to find top " <<n1<< " students of IT"<<endl;
    cout<<"Enter Both to find top " <<n1<< " students of Both"<<endl;
    cout<<"Enter : ";
    cin>>choice;
    cout<<endl<<"The top "<<n1<< " Students of " << choice<< " Are : "<<endl<<endl;
    if (choice=="CS")
        for (int i=0; i<n1; i++)
            CS.printMax();
        
    else if (choice=="IT")
        for (int i=0;i<n1;i++)
            IT.printMax();
        

    else if (choice=="Both")
        for (int i=0;i<n1;i++)
            Both.printMax();

    cout<<endl;
    

}
