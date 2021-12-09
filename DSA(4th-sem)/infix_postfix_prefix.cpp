#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#define size 10
using namespace std;
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
            return (top>=(size-1));
        }
        int giveTop(){
            return stack[top];
        }      
};
bool isOperator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}
int precedence(char ch){
    if(ch=='+'||ch=='-')
        return 1;
    else if(ch=='*'||ch=='/')
        return 2;
    else if(ch=='^')
        return 3;
    else
        return -1;
}
string reverse(string infix){
    string rev;
    for (int i=0;i<=infix.length();i++){
        rev[i]=infix[infix.length()-i-1];
    }
    return rev;
}
string toPostfix(string infix){
    Stack<char> s;
    string postfix;
    for (int i=0;i<infix.length();i++){
        if (infix[i]>='a' && infix[i]<='z' || infix[i]>='A' && infix[i]<='Z'){
            postfix+=infix[i];
        }
        else if (infix[i]=='('){
            s.push(infix[i]);
        }
        else if (infix[i]==')'){
            while (!s.isEmpty() && s.giveTop()!='('){
                postfix+=s.pop();
            }
            if (s.giveTop()=='(')
            s.pop();
        }
        else if (isOperator(infix[i]))
        {
            if (s.isEmpty())
            s.push(infix[i]);
            else if(precedence(infix[i])>precedence(s.giveTop()))
            s.push(infix[i]);
            else{
                while (!s.isEmpty() && precedence(infix[i])<=precedence(s.giveTop())){
                    postfix+=s.pop();
                }
                s.push(infix[i]);
            }
        }
        }
        while (!s.isEmpty()){
            postfix+=s.pop();
        }
        return postfix;
    }
string toPrefix(string infix){
    Stack<char> s;
    string prefix;
    infix=reverse(infix);
    for (int i=0;i<infix.length();i++){
        if (infix[i]=='(')
        infix[i]=')';
        else if (infix[i]==')')
        infix[i]='(';
    }
    for (int i=0;i<infix.length();i++){
        if (infix[i]>='a' && infix[i]<='z' || infix[i]>='A' || infix[i]<='Z')
        prefix+=infix[i];
        else if (infix[i]=='(')
        s.push(infix[i]);
        else if(infix[i]==')'){
            while((s.giveTop()!='(') && (!s.isEmpty())){
                prefix+=s.giveTop();
                s.pop();
            }
            if (s.giveTop()=='(')
            s.pop();
            else if(isOperator(infix[i])){
                if (s.isEmpty())
                s.push(infix[i]);
                else if(precedence(infix[i]>precedence(s.giveTop())))
                s.push(infix[i]);
                else if(precedence(infix[i]==precedence(s.giveTop())) && (infix[i]=='^'))
                while((precedence(infix[i])==precedence(s.giveTop())) && (infix[i]=='^'))
                prefix+=s.pop();
            }
            s.push(infix[i]);
        }
        else{
            while((!s.isEmpty()) && (precedence(infix[i]) < precedence(s.giveTop())))
            prefix+=s.pop();
            s.push(infix[i]);
        }
    }
    while(!s.isEmpty())
    prefix+=s.pop();
    return reverse(prefix);
}
int main(){
    string infix,postfix,prefix;
    cout<<"Enter Infix Expression: ";
    cin>>infix;
    postfix=toPostfix(infix);
    cout<<"Postfix Expression: "<<postfix<<endl;
    prefix=toPrefix(infix);
    cout<<"Prefix Expression: "<<prefix<<endl;
    return 0;
}