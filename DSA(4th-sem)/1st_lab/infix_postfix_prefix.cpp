#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include <bits/stdc++.h>

#define sizeT 10

using namespace std;

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

string toPrefix(string infix) {
  Stack<char> s;
  string prefix;
  reverse(infix.begin(), infix.end());
  for (int i = 0; i < infix.length(); i++) {
    if (infix[i] == '(') {
      infix[i] = ')';
    } else if (infix[i] == ')') {
      infix[i] = '(';
    }
  }
  for (int i = 0; i < infix.length(); i++) {
    if (infix[i] >= 'a' && infix[i] <= 'z' ||
        infix[i] >= 'A' && infix[i] <= 'Z')
      prefix.append(std::string(1, infix[i]));
    else if (infix[i] == '(')
      s.push(infix[i]);
    else if (infix[i] == ')') {
      while ((s.giveTop() != '(') && (!s.isEmpty()))
        prefix.append(string(1, s.giveTop()));
      s.pop();
    }
    if (s.giveTop() == '(')
      s.pop();
    else if (isOperator(infix[i])) {
      if (s.isEmpty())
        s.push(infix[i]);
      else {
        if (precedence(infix[i]) > precedence(s.giveTop()))
          s.push(infix[i]);
        else if (precedence(infix[i] == precedence(s.giveTop())) &&
                 infix[i] == '^') {
          while (precedence(infix[i] == precedence(s.giveTop())) &&
                 infix[i] == '^') {
            prefix.append(string(1, s.giveTop()));
            s.pop();
          }
          s.push(infix[i]);
        } else if (precedence(infix[i]) == precedence(s.giveTop()))
          s.push(infix[i]);
        else {
          while ((precedence(infix[i]) < precedence(s.giveTop())) &&
                 (!s.isEmpty())) {
            prefix.append(string(1, s.giveTop()));
            s.pop();
          }
          s.push(infix[i]);
        }
      }
    }
  }
  while (!s.isEmpty()) {
    prefix.append(std::string(1, s.giveTop()));
    s.pop();
  }
  reverse(prefix.begin(), prefix.end());
  return (prefix);
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