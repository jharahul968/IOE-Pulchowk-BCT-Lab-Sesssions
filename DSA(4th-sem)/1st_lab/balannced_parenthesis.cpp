#include <iostream>
#include <conio.h>
#include <cstring>
//#include <bits/stdc++.h>
#define sizeT 100
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

char pairOf(char c) {
 return (c == ')') ? '(' : (c == '}') ? '{' : '[';
}
string check(string exp) {
 Stack <char> s;
 for (int i = 0; i < exp.length(); i++) {
 if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') s.push(exp[i]);
 else if ((exp[i] == ')' || exp[i] == '}' || exp[i] == ']') && !s.isEmpty()) 
 if (s.giveTop() == pairOf(exp[i])) s.pop(); 
 }
 if (s.isEmpty()) return "balanced parenthesis\n";
 else return "unpaired parenthesis\n";
}
int main() {
string p;
cout << "Enter an expression: ";
cin >> p;
cout << "The expression has " << check(p);
}