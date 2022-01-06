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
    int top;
    node<T>* topNode;
    node<T>* start;

public:
    LinkedList()
    {
        topNode=NULL;
        start=NULL;
        top = -1;
    }
    void push(T item)
    {
        if (start==NULL)
        {
            node<T>* start1=new node<T>();
            start1->data=item;
            start1->next=NULL;
            start=topNode=start1;
            top++;
            return;
        }
        node<T> *temp=start;
        node<T> *end = new node<T>();
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=end;
        end->data=item;
        end->next=NULL;
        topNode=end;
        top++;
    }
    void pop(){
        if (top<0){
            cout<<"Stack Underflow."<<endl;
            return;
        }
        if (start==topNode){
            node<T>* temp=start;
            start=topNode=NULL;
            cout<<"Popped Element: "<<temp->data<<endl;
            delete temp;
            top--;
            return;
        }
        node<T>* temp=start;
        node<T>* ptr=start;
        while(temp->next!=NULL){
            ptr=temp;
            temp=temp->next;
        }
        cout<<"Popped Element: "<<temp->data<<endl;
        ptr->next=NULL;
        topNode=ptr;
        delete temp;
        top--;
    }
    void peek(){
        if (top<0){
            cout<<"Stack Empty."<<endl;
            return;
        }
        cout<<"Top Element: "<<topNode->data<<endl;
    }
    bool isEmpty(){
        return (top<0);
    }
    void display(){
        if (top<0){
            cout<<"Stack Empty."<<endl;
            return;
        }
         T arr[top+1];
         int i=top;
        node<T>* p=start;
        cout<<"Stack elements are: "<<endl;
        while(p->next!=NULL){
            arr[i--]=p->data;
            p=p->next;
        }
        arr[i--]=p->data;
        cout<<"Stack items: "<<endl;
        for (int j=0;j<=top;j++)
        cout<<arr[j]<<endl;
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
    int choice, num;
    bool quit = 0;
    while (quit == 0)
    {
        cout << "Press 1 to push" << endl;
        cout << "Press 2 to pop." << endl;
        cout << "Press 3 to check if stack is empty." << endl;
        cout << "Press 4 to see top element." << endl;
        cout << "Press 5 to display the stack elements." << endl;
        cout << "Press any other key to quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the number to push at top." << endl;
            cin >> num;
            list.push(num);
            break;
        case 2:
            list.pop();
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