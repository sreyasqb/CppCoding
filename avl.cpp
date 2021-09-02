#include <stdio.h>

class Node{
    public:
        int data;
        Node *left, *right;
        Node(int d) : data(d), left(NULL), right(NULL){};
        Node() : data(0), left(NULL), right(NULL){};

};

class AVLTree{

    public:
        Node *root;
        AVLTree() : root(NULL){};

        bool isTreeEmpty(){
            if (root==NULL) return true;
            return false;
        }
        
        int height(Node *root){
            if (root==NULL) return -1;
            else{
                int lheight=height(root->left);
                int rheight=height(root->right);
                
                if (lheight>rheight)
                    return lheight+1;
                else
                    return rheight+1;
            }
        }

        int balanceFactor(Node *node){
            if (node==NULL) return -1;
            return height(node->left)-height(node->right);
        }

        Node* minNode(Node * node){
            Node * temp=node;
            while (temp->left!=NULL){
                temp=temp->left;
            }
            return temp;
        }

        Node *rightRotate(Node *n1){
            Node *n2=n1->left;
            Node *temp=n2->right;
            
            n2->right=n1;
            n1->left=temp;
            return n2;
        }
        
        Node *leftRotate(Node *n1){
            Node *n2=n1->right;
            Node *temp=n2->left;

            n2->left=n1;
            n1->right= temp;
            return  n2;
        }

        Node *insert(Node *root, Node *newNode){
            //NORMAL BST INSERTION
            if (root==NULL){
                root=newNode;
                return root;
            }
            if (newNode->data < root->data){
                root->left=insert(root->left,newNode);
            }
            else{
                root->right=insert(root->right,newNode);
            }

            int bal=balanceFactor(root);

            if (bal>1 && newNode->data < root->left->data){
                return rightRotate(root);
            }
            if (bal<-1 && newNode->data > root->right->data){
                return leftRotate(root);
            }
            if (bal>1 && newNode->data > root->left->data){
                root->left=leftRotate(root->left);
                return rightRotate(root);
            }
            if (bal <-1 && newNode->data < root->right->data){
                root->right=rightRotate(root->right);
                return leftRotate(root);
            }
            return root;
        }

        Node* search(Node *root,int data){
            if (root==NULL || root->data == data)  return root;
            
            else if (data < root->data) return search(root->left,data);

            else return search(root->right,data);

        }

        Node *deleteNode(Node * root, int data){
            //Normal BST DELETION
            if (root==NULL) return NULL;

            else if (data<root->data){
                root->left=deleteNode(root->left,data);
            }
            else if (data>root->data){
                root->right=deleteNode(root->right,data);
            }
            else{

                Node *temp =minNode(root->right);
                root->data=temp->data;
                root->right=deleteNode(root->right,temp->data);
            }

            int bal=balanceFactor(root);

            if (bal==2 && balanceFactor(root->left)>-1) return rightRotate(root);
            
            else if (bal==-2 && balanceFactor(root->right)<1) return leftRotate(root);

            else if (bal==2 && balanceFactor(root->left)==-1){
                root->left=leftRotate(root->left);
                return rightRotate(root);
            }
            else if (bal==-2 && balanceFactor(root->right)==1){
                root->right=rightRotate(root->right);
                return leftRotate(root);
            }
            return root;
        }
            
};
int main(){
    
    AVLTree *tree;
    
}