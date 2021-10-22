#include <iostream>

class BTreeNode{

  public:
    int *keys;
    int order; // m value in m-way search true
    BTreeNode **C; //pointer of pointers
    int n; //curernt no of keys
    bool leaf;
    BTreeNode(int _order,bool _leaf):keys(new int[_order-1]),n(0),leaf(_leaf),order(_order),C(new BTreeNode *[_order]){};
    BTreeNode* search(int k){
        int i;
        for (i=0;i<n && k>=keys[i];i++){
            if (keys[i]==k) return this;
            
        }
        if (leaf) return NULL;

        return C[i]->search(k);
    }
    void splitChild(int i,BTreeNode *y){
        // BTreeNode *z= new BTreeNode(y->)
    }
    
  

};
class BTree{

    public:
        BTreeNode *root;
        int order;
        void insert(int k){

            if (!root){
                root=new BTreeNode(order,true);
                root->keys[0]=k;
                root->n=1;
            }
            else{
                if (root->n==order-1){
                    BTreeNode *temp=new BTreeNode(order,false);
                    //making the parent have the left most child
                    temp->C[0]=root;
                    // temp->splitChild();
                }
            }


        }
    
};

int main(){

}