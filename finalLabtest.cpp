#include <iostream>
using namespace std;
class Node{
    public:
        int data,npl;
        string name;
        Node *left,*right;
        Node(int d,string n,Node *l=NULL,Node *r=NULL,int np=0) :data(d),name(n),left(l),right(r),npl(np){};
        void printNode(){

        }

};
class LeftistHeap{

    public:
        Node *root;
        LeftistHeap():root(NULL){};
        //to swap children if npl is not satisfied
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
        void insert(int data,string name){
            root=merge(root,new Node(data,name));
        }
        void printMax(){
            Node *oldroot=root;
            root=merge(root->left,root->right);
            
        }


};

int main(){
    LeftistHeap h;
    // h.insert(5);
    // h.insert(1);
    // h.insert(9);
    // h.insert(2);
    // h.insert(7);
    // LeftistHeap h1;
    // h1.insert(6);
    // h1.insert(1);
    // h1.insert(9);
    // cout<<h1.root->data;
    // h.merge(h1);
    // h.insert(0);
     
    cout<<h.root->left->data<<endl;
}
