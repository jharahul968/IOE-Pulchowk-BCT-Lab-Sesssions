/*
Modify the stack class given in the previous lab to add the exception when user
tries to add item while the stack is full and when user tries to add item while the
stack is empty. Throw exception in both of the cases and handle these exceptions.
*/
#include <iostream>
#include <cstring>
#define size 2
using namespace std;
class error{
    public:
    string message;
};
template <class T>
class Stack{
    private:
    T arr[size];
    int top;
    public:
    Stack(){
        top=-1;
    };
    void push(T data);
    T pop();
};
template<class T>
    void Stack<T>::push(T data){
        try{
            if (top>=size-1){
                top=size-1;
                error e;
                e.message="Stack size is full. Can't add data.";
                throw e;
            }
            else{
                arr[++top]=data;
            }
        }
    
    catch (error e){
        cerr<<e.message<<endl;
    }
    }
    template<class T>
        T Stack<T>::pop(){
        try{
            if (top<0){
                error e_;
                e_.message="Stack is empty. Can't remove anything.";
                throw e_;
            }
            else{
                return arr[top--];
            }
        }
        catch (error e_){
            cerr<<e_.message<<endl;
        }
    }
int main(){
    Stack<int> s;
    s.push(3);
    s.push(2);
    s.push(2);
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    return 0;
}