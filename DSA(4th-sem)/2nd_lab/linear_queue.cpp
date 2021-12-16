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
        rear=-1;
    }
    T peek(){
        if (!isEmpty())
        return queue[front];
        else
        cout<<"Queue empty."<<endl;
        exit(1);
    }
    bool isFull(){
        if (rear==sizeT-1)
        return true;
        else 
        return false;
    }
    bool isEmpty(){
        if (front <0 || front > rear)
        return true;
        else
        return false;
    }
    int enqueue(int data){
        if (isFull()){
            cout<<"Overflow."<<endl;
            exit(1);
        }
        else{
            if (front == - 1)
            front = 0;
            rear+=1;
            queue[rear]=data;
            return 1;
        }
    }
    T dequeue(){
        if (isEmpty()){
            cout<<"Underflow."<<endl;
            exit(1);
        }
        else{
            T data=queue[front];
            front=front+1;
            return data;
        }
    }
};
int main(){
    Queue<int> q;
    char c;
    do{
    cout<<"Enter 1 to check if queue is empty, 2 to check if queue is full, 3 to display front element, 4 to enqueue, 5 to dequeue and 6 to exit."<<endl;
    cin>>c;
    switch(c){
        case '1':
        cout<<q.isEmpty()<<endl;
        break;
        case '2':
        cout<<q.isFull()<<endl;
        break;
        case '3':
        cout<<q.peek();
        break;
        case '4':
        cout<<"Enter element to enqueue: "<<endl;
        int cc;
        cin>>cc;
        q.enqueue(cc);
        break;
        case '5':
        cout<<q.dequeue();
        break;
        case '6':
        exit(1);
        default:
        cout<<"Wrong Option."<<endl;
        break;  
    }
    cout<<endl;
    }while(c!='6');
}