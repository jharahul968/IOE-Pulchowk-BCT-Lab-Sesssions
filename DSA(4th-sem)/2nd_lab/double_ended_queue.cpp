#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define sizeT 10
using namespace std;
template <class T>
class Queue{
    int front,rear;
    T queue[sizeT];
    public:
    Queue(){
        front=-1;
        rear=0;
    }
    T viewFront(){
        if (!isEmpty())
        return queue[front];
        else
        cout<<"Queue empty."<<endl;
        exit(0);
    }
    T viewRear(){
        if (isEmpty() || rear<0){
            cout<<"Queue empty."<<endl;
            exit(0);
        }
        return queue[rear];
    }
    bool isFull(){
        if ((rear==sizeT-1 && front==0) || front==rear+1)
        return true;
        else 
        return false;
    }
    bool isEmpty(){
        if (front ==-1)
        return true;
        else
        return false;
    }
    int insertFront(int data){
        if (isFull()){
            cout<<"Stack Overflow."<<endl;
            return(1);
        }
        else{
            if (front==-1){
            front = 0;
            rear=0;
            }
            else if (front==0)
            front=sizeT-1;
            else
            front=front-1;
            queue[front]=data;
            }
        }
    int insertRear(int data){
        if (isFull()){
        cout<<"Overflow."<<endl;
        return(1);
        }
        if (front==-1){
            front=0;
            rear=0;
        }
        else if(rear==sizeT-1)
        rear=0;
        else
        rear=rear+1;
        queue[rear]=data;
    }
    T removeFront(){
        if (isEmpty()){
            cout<<"Underflow."<<endl;
            return(1);
        }
        else{
            T data=queue[front];
            if (front==rear){
                front=-1;
                rear=-1;
            }
            else if(front==sizeT-1){
                front=0;
            }
            else{
                front=front+1;
            }
            return data;
        }
    }
    T removeRear(){
        if (isEmpty()){
            cout<<"Underflow."<<endl;
            return(1);
        }
        else{
            T data=queue[rear];
            if (front==rear){
                front=-1;
                rear=-1;
            }
            else if(rear==0){
                rear=sizeT-1;
            }
            else{
                rear=rear-1;
            }
            return data;
        }
    }
};
int main(){
    Queue<int> q;
    char c;
    do{
    cout<<"Enter 1 to check if queue is empty, 2 to check if queue is full, 3 to display front element, 4 to display rear element, 5 to insert at front, 6 to insert at rear, 7 to delete at front, 8 to delete at rear and 9 to exit."<<endl;
    cin>>c;
    switch(c){
        case '1':
        cout<<q.isEmpty()<<endl;
        break;
        case '2':
        cout<<q.isFull()<<endl;
        break;
        case '3':
        cout<<q.viewFront();
        break;
        case '4':
        cout<<q.viewRear();
        case '5':
        cout<<"Enter element to insert at front: "<<endl;
        int cc;
        cin>>cc;
        q.insertFront(cc);
        break;
        case '6':
        cout<<"Enter element to insert at front: "<<endl;
        int ccc;
        cin>>ccc;
        q.insertRear(ccc);
        break;
        case '7':
        cout<<q.removeFront();
        break;
        case '8':
        cout<<q.removeRear();
        case '9':
        exit(1);
        default:
        cout<<"Wrong Option."<<endl;
        break;  
    }
    cout<<endl;
    }while(c!='9');
}