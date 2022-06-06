#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

int main(){
    float x[100],y[100],xp,yp=0,p;
    int i,j,n;
    cout<<"Enter the number of data points: ";
    cin>>n;
    cout<<"Enter the data: "<<endl;
    for (i=0;i<n;i++){
        cout<<"x,y = ";
        cin>>x[i]>>y[i];        
    }
    cout<<"Enter the point for interpolation: ";
    cin>>xp;
    for (i=0;i<n;i++){
        p=1;
        for (j=0;j<n;j++){
            if (i!=j){
                p=p*(xp-x[j])/(x[i]-x[j]);
            }
        }
        yp=yp+p*y[i];
    }
    cout<<"The interpolated value at given xp "<<xp<<" is "<<yp;
}