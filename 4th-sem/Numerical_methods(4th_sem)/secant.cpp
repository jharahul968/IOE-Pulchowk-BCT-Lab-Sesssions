#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
float f(float x){
    return (x*x*x-3*x-9);
}
int main() {
float a,b,c,d,e,count=0;
cout<<"Enter the values of a and b: "<<endl;
cin>>a>>b;
cout<<"Enter the value of allowed error tolerance: "<<endl;
cin>>e;
cout<<"Enter the value of maximum iterations: "<<endl;
cin>>d;
do{
    if (f(a)==f(b)){
        cout<<"The solution can't be found."<<endl;
        exit(1);
    }
    c=(a*f(b)-b*f(a))/(f(b)-f(a));
    a=b;
    b=c;
    count++;
    if (count==d)
    break;
}while(abs(f(c))>e);
cout<<"The solution is: "<<c<<endl;
}