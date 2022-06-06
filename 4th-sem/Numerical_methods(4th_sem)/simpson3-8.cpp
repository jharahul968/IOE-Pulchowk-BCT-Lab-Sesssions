#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

float f(float x){
    return (1+pow(x,2));
}

int main(){
float lower,upper,integration=0.0,stepsize,k;
int i,subinterval;
cout<<"Enter upper and lower limits of integration: ";
cin>>upper>>lower;
cout<<"Enter the number of subintervals: ";
cin>>subinterval;
stepsize=(upper-lower)/subinterval;
integration=f(lower)+f(upper);
for (i=1;i<subinterval;i++){
    k=lower+i*stepsize;
    if (i%3==0){
        integration+=2*f(k);
    }
    else{
        integration+=4*f(k);
    }
}
integration*=stepsize*(3/8);
cout<<"The final value of integration is "<<integration;
}