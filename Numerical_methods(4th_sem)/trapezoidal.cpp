#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

float f(float x){
    return (1+x*x);
}

int main(){
float lower,upper,integration,stepsize,k;
int i,subinterval;
cout<<"Enter lower and upper limits of integration: ";
cin>>lower>>upper;
cout<<"Enter the number of subintervals: ";
cin>>subinterval;
stepsize=(upper-lower)/subinterval;
integration=f(lower)+f(upper);
for (i=1;i<=subinterval;i++){
    k=lower+i*stepsize;
    integration+=2*f(k);
}
integration*=stepsize*(1/2);
cout<<"The final value of integration is "<<integration;
}