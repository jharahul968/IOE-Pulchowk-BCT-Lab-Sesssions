/*
Write a program to compare two objects of a class that contains
an integer value as its data member.
Make overloading functions to overload equality(==), less than(<),
greater than(>), not equal (!=), greater than or equal to (>=)
and less than or equal to(<=) operators using member operator functions.
*/
#include <iostream>
using namespace std;
class toCompare{
    private:
    int data;
    public:
    toCompare(int d):data(d){};
    bool operator ==(toCompare a)
    {
        if (a.data==data)
        return true;
        else
        return false;
    }
    bool operator <(toCompare a)
        {
        if (data<a.data)
        return true;
        else
        return false;
    }
    bool operator >(toCompare a)
        {
        if (data>a.data)
        return true;
        else
        return false;
    }
    bool operator !=(toCompare a)
        {
        if (a.data!=data)
        return true;
        else
        return false;
    }
    bool operator >=(toCompare a)
        {
        if (data>=a.data)
        return true;
        else
        return false;
    }
};
int main(){
    toCompare first(2);
    toCompare second(3);
    cout<<(first>second)<<endl;
    cout<<(first==second)<<endl;
    cout<<(first>=second)<<endl;
    cout<<(first!=second)<<endl;
    cout<<(first<second)<<endl;
    return 0;
}