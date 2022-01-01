// SINGLY LINKED LIST
// LINKED LIST:
// WRITE AN ALGORITHM AND PROGRAM FOR FOLLOWING CASES IN SINGLY LINEAR LINKED LIST:
// 1.     INSERTION OPERATIONS
// a.     INSERT NODE AT BEGINNING OF THE LIST
// b.     INSERT NODE AT END OF THE LIST
// c.      INSERT NODE AFTER SPECIFIC NODE
// d.     INSERT NODE BEFORE SPECIFIC NODE
// 2.     DELETION OPERATIONS
// a.     DELETE NODE FROM BEGINNING OF THE LIST
// b.     DELETE NODE FROM END OF THE LIST
// c.      DELETE NODE AFTER SPECIFIC NODE
// MAKE NECESSARY MODIFICATIONS IN ABOVE PROGRAM TO PERFORM OPERATIONS IN CIRCULAR LINKED LIST.

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node* head;
    node()
    {
        head=NULL;
    }

};
void insertAtBeginning(struct node* head_ref,int new_data){
    struct node* new_node=new struct node;
    new_node->data=new_data;
    new_node->next=head_ref;
    head_ref=new_node;
}
void insertAfter(struct node* prev_node,int new_data){
    if (prev_node==NULL){
        cout<<"Previous node is null."<<endl;
        return;
    }
    struct node* new_node=new struct node;
    new_node->data=new_data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}
void insertAtEnd(struct node* head_ref,int new_data){
    struct node* new_node=new struct node;
    struct node* last=head_ref;
    new_node->data=new_data;
    new_node->next=NULL;
    if (head_ref==NULL){
        head_ref=new_node;
        return;
    }
    while (last->next!=NULL) last=last->next;
    last->next=new_node;
    return;
}
void deleteNode(struct node* head_ref,int key){
    struct node *temp=head_ref,*prev;
    if (temp!=NULL && temp->data==key){
        head_ref=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL) return;
    prev->next=temp->next;
    free(temp);
}
void printList(struct node* n){
    cout<<"Linked List: "<<endl;
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
}
int main(){
    

    struct node n;
    //insertAtEnd(head,1);
    // cout<<"here we go"<<endl;
    insertAtBeginning(n.head,2);
    cout<<n.head<<endl;
    // insertAtBeginning(head,3);
    // cout<<"here we go"<<endl;
    // insertAtEnd(head,4);
    // cout<<"here we go"<<endl;
    // insertAfter(head->next,5);
    // cout<<"here we go"<<endl;
    // printList(head);
    // cout<<"here we go"<<endl;
    // deleteNode(head,3);
    printList(n.head);
    cout<<"here we go"<<endl;
}