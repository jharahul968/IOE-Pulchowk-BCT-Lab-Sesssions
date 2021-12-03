#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
float func(float a){
    return (a*a*a - 3*a -9);
}
int main(){
    float a,b,c,error_tolerance,root;
    int i=0;
    float allowed_steps;
    cout<<"Enter the value of a and b: "<<endl;
    cin>>a>>b;
    cout<<"Enter the value of error_tolerance: "<<endl;
    cin>>error_tolerance;
    allowed_steps=(log(fabs(b-a))-log(error_tolerance))/log(2);
    if (func(a)*func(b)>0){
        cout<<"Invalid interval."<<endl;
        exit(0);
    }
    do{
        i+=1;
        c=(a+b)/2;
        if (func(a)*func(c)<0){
            b=c;
        }
        else
        a=c;
        if (i>int(2*allowed_steps)){
            cout<<"root is: "<<c<<endl;
            break;
        }
        if (fabs(func(c))<error_tolerance){
            root=c;
            cout<<"root is: "<<root<<endl;
        }
    }while(fabs(func(c))>error_tolerance);
    return 0;
}