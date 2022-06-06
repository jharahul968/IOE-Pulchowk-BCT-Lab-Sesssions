/*
Write a class for instantiating the objects that represent the two-dimensional Cartesian coordinate system.
A. Make a particular member function of one class as a friend function of another class for addition.
B. Make the other three functions to work as a bridge between the classes for multiplication, division, and subtraction.
C. Also write a small program to demonstrate that all the member functions of one class are the friend functions of another class if the former class is made friend to the latter.
Make least possible classes to demonstrate all the above in a single program without conflict.
*/
#include <iostream>
using namespace std;
class Cartesian;
class Addition{
    public:
    Cartesian add(Cartesian a, Cartesian b);
};
class Operations{
    public:
    Cartesian sub(Cartesian a, Cartesian b);
    Cartesian mul(Cartesian a, Cartesian b);
    Cartesian div(Cartesian a, Cartesian b);
};
class Cartesian{
    private:
    float x,y;
    public:
    Cartesian(float x_,float y_):x(x_),y(y_){};
    friend Cartesian Addition::add(Cartesian a, Cartesian b);           //friend class Addition
    friend class Operations;
    void display(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};

Cartesian Addition::add(Cartesian a, Cartesian b){
    Cartesian temp(a.x+b.x,a.y+b.y);
    return temp;
}
Cartesian Operations::sub(Cartesian a, Cartesian b){
    Cartesian temp(a.x-b.x,a.y-b.y);
    return temp;
}
Cartesian Operations::mul(Cartesian a, Cartesian b){
    Cartesian temp(a.x*b.x,a.y*b.y);
    return temp;
}
Cartesian Operations::div(Cartesian a, Cartesian b){
    Cartesian temp(a.x/b.x,a.y/b.y);
    return temp;
}
int main(){
float x,y;
cout<<"Enter x-ordinate of first Co-ordinate: "<<endl;
cin>>x;
cout<<"Enter y-ordinate of first Co-ordinate: "<<endl;
cin>>y;
Cartesian first(x,y);
cout<<"Enter x-ordinate of second Co-ordinate: "<<endl;
cin>>x;
cout<<"Enter y-ordinate of second Co-ordinate: "<<endl;
cin>>y;
Cartesian second(x,y);
cout<<"The entered coordinates are as: "<<endl;
first.display();
cout<<endl;
second.display();
cout<<endl;
Addition a;
Cartesian c=a.add(first,second);
cout<<"The added value is: "<<endl;
c.display();
cout<<endl;
Operations o;
Cartesian d=o.sub(first,second);
cout<<"The subtracted value is: "<<endl;
d.display();
cout<<endl;
Cartesian e=o.mul(first,second);
cout<<"The multiplied value is: "<<endl;
e.display();
cout<<endl;
Cartesian f=o.div(first,second);
cout<<"The divided value is: "<<endl;
f.display();
cout<<endl;
    return 0;
}
