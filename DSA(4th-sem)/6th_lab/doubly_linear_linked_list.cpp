// WRITE AN ALGORITHM AND PROGRAM FOR FOLLOWING CASES IN DOUBLY
// LINEAR LINKED LIST:
// 1. INSERTION OPERATIONS
// a. INSERT NODE AT BEGINNING OF THE LIST
// b. INSERT NODE AT END OF THE LIST
// c. INSERT NODE AFTER SPECIFIC NODE
// d. INSERT NODE BEFORE SPECIFIC NODE
// 2. DELETION OPERATIONS
// a. DELETE NODE FROM BEGINNING OF THE LIST
// b. DELETE NODE FROM END OF THE LIST
// c. DELETE NODE AFTER SPECIFIC NODE
// d. DELETE NODE BEFORE SPECIFIC NODE

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#define size 100
template <class T>
struct node
{
    T data;
    struct node *prev;
    struct node *next;
};
template <class T>
class LinkedList
{
private:
    node<T> *start;

public:
    LinkedList()
    {
        start = NULL;
    }
    void insertAtStart(T item)
    {
        node<T> *temp = new node<T>();
        temp->data = item;
        temp->prev = NULL;
        temp->next= start;
        if (start!=NULL)
        start->prev=temp;
        start=temp;
    }
    void deleteAtStart()
    {
        node<T> *temp = start;
        start = start->next;
        start->prev=NULL;
        if (start==NULL)
        start->next=NULL;
        delete temp;
    }
    void insertAtEnd(T item)
    {
     if (start == NULL)
    {
        
        node<T>*start1 = new node<T>();
        start1->data=item;
        start1->next=NULL;
        start->prev=NULL;
        start=start1;
    }
    else
    {
        node<T> *temp = start;
        node<T> *end = new node<T>();
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = end;
        end->data = item;
        end->next = NULL;
        end->prev=temp;
    }
    }
    void deleteAtEnd()
    {
        if (start->next == NULL)
            deleteAtStart();
        else
        {
            node<T> *temp = start;
            node<T> *ptr = new node<T>();
            while (temp->next != NULL)
            {
                ptr = temp;
                temp = temp->next;
            }
            ptr->next = NULL;
            delete temp;
        }
    }
    void insertAfter(T item, T after)
    {
        if (start==NULL)
        {
            cout << "List Empty." << endl;
            return;
        }
        else
        {
            node<T> *temp = start;
            while (temp->data != after)
            {
                temp = temp->next;
            if (temp==NULL)
            {
                cout << "No such element in list." << endl;
                break;
            }
            }
            if (temp==NULL)
                return;
            node<T> *ptr = temp->next;
            node<T>*pptr = new node<T>();
            temp->next=pptr;
            pptr->data = item;
            pptr->next = ptr;
            pptr->prev=temp->next;
        }
    }
    void deleteAfter(T after)
    {
        if (!start)
        {
            cout << "List Empty." << endl;
            return;
        }
        if (start->next==NULL && start->data==after){
            cout<<"Only one element in the list. Invalid Operation."<<endl;
            return;
        }
        if (after==start->data && start->next!=NULL && start->next->next==NULL){
            deleteAtStart();
            return;
        }
        node<T> *temp = start;
        while (temp->data != after)
        {
            temp = temp->next;
        if (!temp)
        {
            break;
        }
        }
        if (!temp)
        {
            cout << "No such element." << endl;
            return;
        }
        temp->next = temp->next->next;
        temp->next->prev=temp;
    }
    void insertBefore(T item, T before)
    {
        if (!start){
            cout<<"List Empty."<<endl;
            return;
        }
        if (before==start->data){
            insertAtStart(item);
            return;
        }
        node<T>* temp=start;
        node<T>* ptr=start;
        while(ptr->data!=before){
            temp=ptr;
            ptr=ptr->next;
        if (ptr==NULL){
            break;
        }
        }
        if (ptr==NULL){
            cout<<"No such element."<<endl;
            return;
        }
        node<T>* n=new node<T>();
        n->data=item;
        n->prev=temp;
        n->next=ptr;
        temp->next=n;
        ptr->prev=n;
    }
    void deleteBefore(T before){
        if (!start){
            cout<<"List Empty."<<endl;
            return;
        }
        if (before==start->data){
            cout<<"Invalid Operation. No data before given data."<<endl;
            return;
        }
        if (before==start->next->data){
            deleteAtStart();
            return;
        }
        node<T>*ptr=start;
        node<T>*temp=start;
        node<T>* pptr=start;
        while(ptr->data!=before){
            pptr=ptr;
            temp=ptr->prev;
            ptr=ptr->next;
            if (!ptr){
                cout<<"No such element."<<endl;
                break;
            }
        }
        if (!ptr){
            return;
        }
        temp->next=ptr;
        ptr->prev=temp;
        delete pptr;
    }
    void printList(){
        node<T>* p=start;
        cout << "Linked List items: " << endl;
        while(p->next!=NULL)
        {
            cout<<p->data<<endl;
            p=p->next;
        }
        cout<<p->data<<endl;
    }
};
int main()
{
    LinkedList<int> list;
    // list.insertAtEnd(5);
    // list.printList();
    // list.insertAtStart(4);
    // list.printList();
    // list.insertAtStart(1);
    // list.printList();
    // list.insertAfter(2,1);
    // list.printList();
    // list.deleteAfter(1);
    // list.printList();
    int choice, num, before, after;
    bool quit = 0;
    while (quit == 0)
    {
        cout << "Press 1 to insert at beginning." << endl;
        cout << "Press 2 to insert before a specific value." << endl;
        cout << "Press 3 to insert after a specific value." << endl;
        cout << "Press 4 to insert at end." << endl;
        cout << "Press 5 to delete at beginning." << endl;
        cout << "Press 6 to delete after a specific value." << endl;
        cout << "Press 7 to delete before a specific value." << endl;
        cout << "Press 8 to delete at end." << endl;
        cout << "Press 9 to display the elements." << endl;
        cout << "Press any other key to quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number to insert at beginning." << endl;
            cin >> num;
            list.insertAtStart(num);
            break;
        case 2:
            cout << "Enter the number you would like to insert." << endl;
            cin >> num;
            cout << "Enter the number before which you would like to insert the entered number." << endl;
            cin >> before;
            list.insertBefore(num, before);
            break;
        case 3:
            cout << "Enter the number you would like to insert." << endl;
            cin >> num;
            cout << "Enter the number after which you would like to insert the entered number." << endl;
            cin >> after;
            list.insertAfter(num, after);
            break;
        case 4:
            cout << "Enter the number to insert at end." << endl;
            cin >> num;
            list.insertAtEnd(num);
            break;
        case 5:
            list.deleteAtStart();
            break;
        case 6:
            cout << "Enter the value after which you would like to delete." << endl;
            cin >> after;
            list.deleteAfter(after);
            break;
        case 7:
            cout << "Enter the value before which you would like to delete." << endl;
            cin >> before;
            list.deleteBefore(before);
            break;
        case 8:
            list.deleteAtEnd();
            break;
        case 9:
            list.printList();
            break;
        default:
            cout << "Terminating the program." << endl;
            quit = 1;
            break;
        }
        list.printList();
    }
}