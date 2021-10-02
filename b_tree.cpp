#include <iostream>

class BTreeNode{

  int *keys;
  int order;
  BTreeNode **C;
  int n;
  bool leaf;
  public:
    BTreeNode(int _order,bool _leaf):keys(new int[_order-1]),n(0),leaf(_leaf),order(_order),C(new BTreeNode *[_order]){};
    BTreeNode* search(int k){
        int i;
        for (i=0;i<n && k>=keys[i];i++){
            if (keys[i]==k) return this;
            
        }
        if (leaf) return NULL;

        return C[i]->search(k);
    }
  

};

int main(){

}