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
    int front,rear;
    node<T>* Front;
    node<T>* Rear;

public:
    LinkedList()
    {
        Front=NULL;
        Rear=NULL;
        front = -1;
        rear=-1;
    }
    void enqueue(T item)
    {
        if (Front==NULL)
        {
            node<T>* start1=new node<T>();
            start1->data=item;
            start1->next=NULL;
            Front=Rear=start1;
            front=0;
            rear++;
            return;
        }
        node<T> *temp=Front;
        node<T> *end = new node<T>();
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=end;
        end->data=item;
        end->next=NULL;
        Rear=end;
        rear++;
    }
    void dequeue(){
        if (front==-1){
            cout<<"Queue Empty."<<endl;
            return;
        }
        if (front==rear){
            node<T>* temp=Front;
            Front=Rear=NULL;
            cout<<"Dequeued Element: "<<temp->data<<endl;
            delete temp;
            front=rear=-1;
            return;
        }
        node<T>* temp=Front;
        node<T>* ptr=Front;
        cout<<"Dequeued Element: "<<temp->data<<endl;
        ptr=ptr->next;
        Front=ptr;
        delete temp;
        front++;
    }
    void peek(){
        if (front==-1){
            cout<<"Queue Empty."<<endl;
            return;
        }
        cout<<"Front Element: "<<Front->data<<endl;
    }
    bool isEmpty(){
        return (front==-1);
    }
    void display(){
        if (front==-1){
            cout<<"Queue Empty."<<endl;
            return;
        }
        node<T>* p=Front;
        cout<<"Queue elements are: "<<endl;
        while(p->next!=NULL){
            cout<<p->data<<endl;
            p=p->next;
        }
        cout<<p->data<<endl;
    }
};
int main()
{
    LinkedList<int> list;
    int choice, num;
    bool quit = 0;
    while (quit == 0)
    {
        cout << "Press 1 to enqueue." << endl;
        cout << "Press 2 to dequeue." << endl;
        cout << "Press 3 to check if queue is empty." << endl;
        cout << "Press 4 to see front element." << endl;
        cout << "Press 5 to display the queue elements." << endl;
        cout << "Press any other key to quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number to enqueue at rear." << endl;
            cin >> num;
            list.enqueue(num);
            break;
        case 2:
            list.dequeue();
            break;
        case 3:
            cout<<list.isEmpty()<<endl;
            break;
        case 4:
            list.peek();
            break;
        case 5:
            list.display();
            break;
        default:
            cout << "Terminating the program." << endl;
            quit = 1;
            break;
        }
    }
}