#include <iostream>
using namespace std;

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

        Node* maxNode(Node * node){
            Node * temp=node;
            while (temp->right!=NULL){
                temp=temp->right;
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
        void printRange(Node *root, int k1, int k2)
        {
            
            if ( NULL == root )
                return;

            if ( k1 < root->data )
                printRange(root->left, k1, k2);

            if ( k1 <= root->data && k2 >= root->data )
                cout<<root->data<<" , ";

            printRange(root->right, k1, k2);
        }

        void subTree(Node *root, int k){
            Node *subTreeRoot= search(root,k);
            
            
            inorder(subTreeRoot);

        }
        void inorder(Node *root){

            if (root==NULL) return;
            inorder(root->left);
            cout<<root->data<<" , ";
            inorder(root->right);

        }




};
int main(){

    AVLTree tree;
    int n;
    cout<<"CREATE AVL TREE"<<endl;
    cout<<"How many nodes would you like : ";
    cin>>n;
    
    for (int i=0;i<n;i++){
        int temp;
        cout<<"Enter the data of node "<<i+1<<": ";
        cin>>temp;
        Node * newNode=new Node(temp);
        tree.root=tree.insert(tree.root,newNode);
    }
    //between 2 values
    int k1,k2;
    cout<<endl<<endl;
    cout<<"To find the range k1 <= k <= k2 "<<endl;
    cout<<"Enter k1 : ";
    cin>>k1;
    cout<<"Enter k2 : ";
    cin>>k2;
    tree.printRange(tree.root,k1,k2);
    cout<<endl<<endl;
    // k>=k1
    cout<<"To find the range k1>= k"<<endl;
    cout<<"Enter k1 : ";
    cin>>k1;
    
    tree.printRange(tree.root,k1,tree.maxNode(tree.root)->data);
    cout<<endl<<endl;

    // k<=k2

    cout<<"To find the range k1<= k"<<endl;
    cout<<"Enter k1 : ";
    cin>>k1;
    tree.printRange(tree.root,tree.minNode(tree.root)->data,k1);
    cout<<endl<<endl;

    //to find the subtree
    cout<<"To find the subtree of the node k "<<endl;
    cout<<"Enter k : ";
    cin>>k1;
   
    tree.subTree(tree.root,k1);
    cout<<endl;

};