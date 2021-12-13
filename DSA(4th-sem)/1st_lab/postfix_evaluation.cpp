#include <iostream>
#include <math.h>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#define sizeT 100

template<class T>
class Stack{
    private:
        T stack[sizeT];
        int top;
    public:
        Stack(){
            top=-1;
        }
        void push(T item){
            if (top==sizeT-1){
                cout<<"Stack Overflow";
                getch();
                exit(1);}
            else{
                stack[++top]=item;
            }
        }
        T pop(){
            if (top==-1){
                cout<<"Stack Underflow";
                getch();
                exit(1);}
            else
                return stack[top--];
        }
        bool isEmpty(){
            return (top==-1);
        }
        bool isFull(){
            return (top>=(sizeT-1));
        }
        int giveTop(){
            return stack[top];
        }      
};


bool isOperator(char c){
    return (c=='+' || c=='-' || c=='/' || c=='*' || c=='^');
}
int evaluate(string exp){
    Stack<int> s;
    int opA,opB;
    for(int i=0;i<exp.length();i++){
        if (isOperator(exp[i])){
            opA=s.pop();
            opB=s.pop();
            switch(exp[i]){
            case '+': 
            s.push(opA+opB);
            break;
            case '-':
            s.push(opB-opA);
            break;
            case '/':
            s.push(opB/opA);
            break;
            case '*':
            s.push(opA*opB);
            break;
            case '^':
            s.push(opB^opA);
            break;
            default:
            break;
            }
        }
        else if(exp[i]>='0' && exp[i]<='9')
        s.push(exp[i]-'0');
    }
    int result=s.pop();
    return result;
}

int main(){
string exp;
cout<<"Enter the postfix expression (integers only): \n";
cin>>exp;
cout<<"The evaluation is: "<<evaluate(exp);
}