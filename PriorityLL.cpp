#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
    char data;
    int priority;
    struct node *link;
};
struct node *newNode(char data,int pri){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->priority=pri;
    temp->link=NULL;
    return temp;
}
void insert(struct node **head,char data,int pri){

    struct node *start=(*head);
    struct node *temp=newNode(data,pri);
    if ((*head)->priority>pri){
        temp->link=*head;
        (*head)=temp;
    }
    else{
        while(start->link!=NULL && start->link->priority<pri){
            start=start->link;
        }
        temp->link=start->link;
        start->link=temp;
    }
}
void display(struct node *head){
    while(head!=NULL){
        cout<<head->data<<',';
        head=head->link;
    }

}
int main(){
    struct node *head=newNode('A',1);
    insert(&head,'B',4);
    insert(&head,'C',5);
    insert(&head,'D',0);
    insert(&head,'F',3);
    display(head);
}