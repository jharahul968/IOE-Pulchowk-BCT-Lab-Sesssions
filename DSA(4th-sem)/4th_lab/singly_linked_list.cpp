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
#define size 100
template <class T>
struct node
{
    T data;
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
        node<T> *temp = start;
        start = new node<T>();
        start->data = item;
        start->next = temp;
    }
    void deleteAtStart()
    {
        node<T> *temp = start;
        start = start->next;
        delete temp;
    }
    void insertAtEnd(T item)
    {
     if (start == NULL)
    {
        
        node<T>*start1 = new node<T>();
        start1->data=item;
        start1->next=NULL;
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
        if (!start)
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
            }
            if (!temp)
            {
                cout << "No such element in list." << endl;
                return;
            }
            node<T> *ptr = temp->next;
            temp->next = new node<T>();
            temp->next->data = item;
            temp->next->next = ptr;
        }
    }
    void deleteAfter(T after)
    {
        if (!start)
        {
            cout << "List Empty." << endl;
            return;
        }
        node<T> *temp = start;
        while (temp->data != after)
        {
            temp = temp->next;
        }
        if (!temp)
        {
            cout << "No such element." << endl;
            return;
        }
        temp->next = temp->next->next;
    }
    void insertBefore(T item, T before)
    {
        if (!start){
            cout<<"List Empty."<<endl;
            return;
        }
        node<T>* temp=start;
        node<T>* ptr=start;
        while(ptr->data!=before){
            temp=ptr;
            ptr->next=ptr;
        }
        if (!ptr){
            cout<<"No such element."<<endl;
            return;
        }
        node<T>* n=new node<T>();
        n.data=item;
        n.next=ptr;
        temp->next=n;
    }
    void printList(){
        node<T>* p=start;
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
    list.insertAtEnd(5);
    list.insertAtStart(4);
    list.insertAtStart(1);
    list.insertAfter(2,1);
    list.deleteAfter(1);
    list.printList();
}