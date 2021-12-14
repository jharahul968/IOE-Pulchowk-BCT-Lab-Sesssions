#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    float x[20],y[20],sum_x=0,sum_y=0,sum_xy=0,sum_x2=0,a,b,r;
    int n;
    cout<<"Enter the number of data points: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the value of x and y: ";
        cin>>x[i];
        cin>>y[i];
        sum_x+=x[i];
        sum_y+=y[i];
        sum_xy+=x[i]*y[i];
        sum_x2+=x[i]*x[i];
    }
    a=(n*sum_xy-sum_x*sum_y)/(n*sum_x2-sum_x*sum_x);
    b=(sum_y-a*sum_x)/n;
    cout<<"The value of a is: "<<a<<endl;
    cout<<"The value of b is: "<<b<<endl;
    cout<<"The equation of the line is: y="<<a<<"+"<<b<<"x"<<endl;
    return 0;
}