/*
Write a program that illustrates the following relationship
and comment on them. 
i) const_object.non_const_mem_function
ii) const_object.const_mem_function
iii) non_const_object.non_const_mem_function
iv) non_const_object.const_mem_function
*/

#include <iostream>
using namespace std;

class Example {
    private:
    const int a;
    public:
    Example(int b):a(b){};
    int getConst()const
    {
        return a;
    }
    int get() {
        return a;
    }
};

int main() {
Example e(1);
cout<<"For non_const_object.non_const_mem_function: "<<e.get()<<endl;

cout<<"For non_const_object.const_mem_function: "<<e.getConst()<<endl;

const Example e_(2);
cout<<"For const_object.const_mem_function: "<<e_.getConst();
//cout<<"For const_object.non_const_mem_function: "<<e_.get();          //error
    return 0;
}