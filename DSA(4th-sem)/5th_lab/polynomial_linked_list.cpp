// SINGLY LINKED LIST(CONTD..)
// WRITE AN ALGORITHM AND PROGRAM FOR THE FOLLOWING:
// 1. IMPLEMENT STACK AS LINKED LIST
// 2. IMPLEMENT QUEUE AS LINKED LIST
// 3. REPRESENT THE POLYNOMIAL EQUATION USING LINKED LIST TO PERFORM
// ADDITION OF TWO POLYNOMIALS.

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
        cout << "Press 7 to delete at end." << endl;
        cout << "Press 8 to display the elements." << endl;
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
            list.deleteAtEnd();
            break;
        case 8:
            list.printList();
            break;
        default:
            cout << "Terminating the program." << endl;
            quit = 1;
            break;
        }
    }
}