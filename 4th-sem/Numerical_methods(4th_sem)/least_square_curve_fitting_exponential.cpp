#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    float x[20],y[20],sum_x=0,sum_y=0,sum_xy=0,sum_x2=0,a,b;
    int n;
    cout<<"Enter the number of data points: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the value of x and y: ";
        cin>>x[i];
        cin>>y[i];
        y[i]=log(y[i]);
        sum_x+=x[i];
        sum_y+=y[i];
        sum_xy+=x[i]*y[i];
        sum_x2+=x[i]*x[i];
    }
    a=((sum_x2*sum_y-sum_x*sum_xy)*1.0)/((sum_x2*n-sum_x*sum_x)*1.0);
    b=((n*sum_xy-sum_x*sum_y)*1.0)/((n*sum_x2-sum_x*sum_x)*1.0);
    a=pow(2.718,a);
    cout<<"The value of a is: "<<a<<endl;
    cout<<"The value of b is: "<<b<<endl;
    cout<<"The equation of the line is: y="<<a<<"e^"<<b<<"x"<<endl;
    return 0;
}