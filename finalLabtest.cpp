#include <iostream>
using namespace std;
class Node{
    public:
        int data,npl;
        Node *left,*right;
        Node(int d,Node *l=NULL,Node *r=NULL,int np=0) :data(d),left(l),right(r),npl(np){};

};
class LeftistHeap{

    public:
        Node *root;
        LeftistHeap():root(NULL){};

        void swapChildren(Node *t){
            Node *temp=t->left;
            t->left=t->right;
            t->right=temp;
        }
        void merge(LeftistHeap &r){
            if (this==&r) return;
            root=merge(root,r.root);
            r.root=NULL;
        }
        Node *merge(Node *h1,Node *h2){
            if (!h1) return h2;
            if (!h2) return h1;
            if (h1->data < h2->data) return merge1(h1,h2);
            else return merge1(h2,h1);
        }

        Node *merge1(Node *h1,Node *h2){
            if (!h1->left) h1->left=h2;
            else{
                h1->right=merge(h1->right,h2);
                if (h1->left->npl < h1->right->npl) swapChildren(h1);
                h1->npl=h1->right->npl+1;
            }
            return h1;
        }
        
        void insert(int k){
            root=merge(new Node(k),root);
        }


};

int main(){
    LeftistHeap h;
    h.insert(5);
    h.insert(0);
    h.insert(2);
    LeftistHeap h1;
    h1.insert(6);
    h1.insert(1);
    h1.insert(9);
    // cout<<h1.root->data;
    h.merge(h1);
    // h.insert(0);
     
    cout<<h.root->data<<endl;
}
