#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
float f( float x, float y) {
return ((x-y)/(x+y));
}
int main() {
float x,y,h, xn,a,b,t,k;
cout<<"Enter the initial values of x, y, value of step (h) and xn"<<endl;
cin>>x>>y>>h>>t;
a=x;
b=y;
cout<<"x"<<"     "<<"y"<<endl;
while (x<=t) {
k=h*f(x,y);
y=y+k;
x=x+h;
cout<<x<<"     "<<y<<endl;
}
}