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
    node<T> *end;

public:
    LinkedList()
    {
        start = NULL;
        end = NULL;
    }
    void insertAtStart(T item)
    {
        if (start == NULL)
        {
            node<T> *temp = new node<T>();
            temp->data = item;
            temp->next = temp;
            start = temp;
            end = temp;
            return;
        }
        node<T> *temp = new node<T>();
        temp->data = item;
        temp->next = start;
        start = temp;
        end->next = start;
    }
    void deleteAtStart()
    {
        if (start==NULL){
            cout<<"List Empty."<<endl;
            return;
        }
        if (end==start){
            delete start;
            start=end=NULL;
            return;
        }
        node<T> *temp = start;
        start = start->next;
        end->next = start;
        cout << "Deleted item: " << temp->data << endl;
        delete temp;
    }
    void insertAtEnd(T item)
    {
        if (start == NULL)
        {

            node<T> *start1 = new node<T>();
            start1->data = item;
            start1->next = start1;
            start = start1;
            end = start1;
        }
        else
        {
            node<T> *temp = start;
            node<T> *end1 = new node<T>();
            while (temp->next != start)
            {
                temp = temp->next;
            }
            temp->next = end1;
            end1->data = item;
            end1->next = start;
        }
    }
    void deleteAtEnd()
    {
        if (start==NULL){
            cout<<"Empty List."<<endl;
            return;
        }
        if (end == start)
        {
            cout << "Deleted item: " << start->data << endl;
            deleteAtStart();
        }
        else
        {
            node<T> *temp = start;
            node<T> *ptr = new node<T>();
            while (temp->next != start)
            {
                ptr = temp;
                temp = temp->next;
            }
            ptr->next = start;
            cout << "Deleted item: " << temp->data << endl;
            delete temp;
        }
    }
    void insertAfter(T item, T after)
    {
        if (start == NULL)
        {
            cout << "List Empty." << endl;
            return;
        }
        if (after == end->data)
        {
            node<T> *e = new node<T>();
            e->data = item;
            e->next = start;
            end->next = e;
            end = e;
            return;
        }
        node<T> *temp = start;
        if (temp->data==after){
        node<T> *ptr = new node<T>();
        ptr->data = item;
        ptr->next = temp->next;
        temp->next = ptr;
        return;
        }
        while (temp->data != after)
        {
            temp = temp->next;
            if (temp == start)
            {
                cout << "No such element in list." << endl;
                break;
            }
        }
        if (temp == start)
        {
            return;
        }
        node<T> *ptr = new node<T>();
        ptr->data = item;
        ptr->next = temp->next;
        temp->next = ptr;
    }
    void deleteAfter(T after)
    {
        if (start==NULL)
        {
            cout << "List Empty." << endl;
            return;
        }
        if (start->next==start){
            cout<<"No such element."<<endl;
            return;
        }
        if (after==start->data){
            node<T>* temp=start->next;
            start->next=temp->next;
            cout<<"The deleted item is: "<<temp->data<<endl;
            delete temp;
            return;
        }
        node<T> *temp = start;
        while (temp->data != after)
        {
            temp = temp->next;
        if (temp==start)
        {
            break;
        }
        }
        if (temp==start)
        {
            cout << "No such element." << endl;
            return;
        }
        node<T>* n=temp->next;
        temp->next = n->next;
        if (n==start)
        start=start->next;
        if (n==end)
        end=temp;
        cout << "Deleted item: " << temp->data << endl;
        delete n;
    }
    void insertBefore(T item, T before)
    {
        if (start == NULL)
        {
            cout << "List Empty." << endl;
            return;
        }
        if (before == start->data)
        {
            node<T> *temp = new node<T>();
            temp->data = item;
            temp->next = start;
            start = temp;
            end->next = start;
            return;
        }
        node<T> *temp;
        node<T> *ptr = start;
        while (ptr->data != before)
        {
            temp = ptr;
            ptr = ptr->next;
            if (ptr == start)
            {
                cout << "No such element." << endl;
                break;
            }
        }
        if (ptr == start)
        {
            return;
        }
        node<T> *n = new node<T>();
        n->data = item;
        temp->next = n;
        n->next = ptr;
    }
    void printList()
    {
        if (start == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }
        cout << "Linked List items: " << endl;
        node<T> *p = start;
        while (p->next != start)
        {
            cout << p->data << endl;
            p = p->next;
        }
        cout << p->data << endl;
    }
};
int main()
{
    LinkedList<int> list;
    list.insertAtEnd(5);
    list.printList();
    list.insertAtStart(4);
    list.printList();
    list.insertAtStart(1);
    list.printList();
    list.insertAfter(2,1);
    list.printList();
    list.deleteAfter(1);
    list.printList();
    // int choice, num, before, after;
    // bool quit = 0;
    // while (quit == 0)
    // {
    //     cout << "Press 1 to insert at beginning." << endl;
    //     cout << "Press 2 to insert before a specific value." << endl;
    //     cout << "Press 3 to insert after a specific value." << endl;
    //     cout << "Press 4 to insert at end." << endl;
    //     cout << "Press 5 to delete at beginning." << endl;
    //     cout << "Press 6 to delete after a specific value." << endl;
    //     cout << "Press 7 to delete at end." << endl;
    //     cout << "Press 8 to display the elements." << endl;
    //     cout << "Press any other key to quit" << endl;
    //     cin >> choice;

    //     switch (choice)
    //     {
    //     case 1:
    //         cout << "Enter the number to insert at beginning." << endl;
    //         cin >> num;
    //         list.insertAtStart(num);
    //         break;
    //     case 2:
    //         cout << "Enter the number you would like to insert." << endl;
    //         cin >> num;
    //         cout << "Enter the number before which you would like to insert the entered number." << endl;
    //         cin >> before;
    //         list.insertBefore(num, before);
    //         break;
    //     case 3:
    //         cout << "Enter the number you would like to insert." << endl;
    //         cin >> num;
    //         cout << "Enter the number after which you would like to insert the entered number." << endl;
    //         cin >> after;
    //         list.insertAfter(num, after);
    //         break;
    //     case 4:
    //         cout << "Enter the number to insert at end." << endl;
    //         cin >> num;
    //         list.insertAtEnd(num);
    //         break;
    //     case 5:
    //         list.deleteAtStart();
    //         break;
    //     case 6:
    //         cout << "Enter the value after which you would like to delete." << endl;
    //         cin >> after;
    //         list.deleteAfter(after);
    //         break;
    //     case 7:
    //         list.deleteAtEnd();
    //         break;
    //     case 8:
    //         list.printList();
    //         break;
    //     default:
    //         cout << "Terminating the program." << endl;
    //         quit = 1;
    //         break;
    //     }
    // }
}