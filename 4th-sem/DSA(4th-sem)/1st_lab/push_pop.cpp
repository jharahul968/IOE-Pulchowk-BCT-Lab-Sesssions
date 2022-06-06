#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

#define size 10
template<class T>
class Stack{
    private:
        T stack[size];
        int top;
    public:
        Stack(){
            top=-1;
        }
        void push(T item){
            if (top==size-1){
                cout<<"Stack Overflow";
                exit(1);}
            else{
                stack[++top]=item;
            }
        }
        T pop(){
            if (top==-1){
                cout<<"Stack Underflow";
                exit(1);}
            else
                return stack[top--];
        }
        bool isEmpty(){
            return (top==-1);
        }
        bool isFull(){
            return (top>=(size-1));
        }
        int giveTop(){
            return stack[top];
        }      
};

int main(){
    Stack<int> s;
    char c;
    cout<<"Enter only numeric values for entry."<<endl;
    do{
    cout<<"Enter 1 to push, 2 to pop, 3 to check if stack is empty, 4 to check if stack is full and 5 to show top element and 6 for stop."<<endl;
    cin>>c;
    switch(c){
        case '1':{
        cout<<"Enter item to push."<<endl;
        int a;
        cin>>a;
        s.push(a);
        break;}
        case '3':{
            cout<<s.isEmpty()<<endl;
            break;
        }
        case '4':{
            cout<<s.isFull()<<endl;
            break;
            exit(0);
        }
        case '5':{
        if (s.isEmpty())
        cout<<"Stack Empty."<<endl;
        else
        cout<<s.giveTop()<<endl;
        break;
        }
        case '2':{
            if (s.isEmpty())
            cout<<"Stack Underflow";
            else
            cout<<s.pop();
            break;
        }
        case '6':
        exit(1);
        default:
        cout<<"Wrong option"<<endl;
        break;
    }
    }while(c!='6');
    cout<<endl;
}