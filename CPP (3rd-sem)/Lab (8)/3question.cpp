/*
Write a program to overload stream operators to read a complex number and display
the complex number in a+ib format.
*/
#include <iostream>
using namespace std;

class Operator{
    private:
    int a,b;
    public:
    Operator(){};
    Operator(float a,float b):a(a),b(b){};
    friend ostream& operator<<(ostream& out,Operator &o);
    friend istream& operator>>(istream& in,Operator &o);
};
ostream& operator<<(ostream &out,Operator &o){
    out<<o.a;
    cout<<" + i";
    out<<o.b;
    return out;
}
istream& operator>>(istream &in,Operator &o){
    cout<<"Enter real part: "<<endl;
    in>>o.a;
    cout<<"Enter imaginary part: "<<endl;
    in>>o.b;
    return in;
}
int main(){
    Operator o(5,6);
    cout<<o<<endl;
    Operator i;
    cin>>i;
    cout<<i;
    return 0;
}