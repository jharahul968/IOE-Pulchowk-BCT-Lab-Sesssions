#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
int main() {
    float a[20][20],b[10],c;
    int n;
    cout<<"Enter the number of variables: "<<endl;
    cin>>n;
    //Data entry
    for (int i=0; i<n;i++){
        for (int j=0;j<n+1;j++){
            cout<<"Enter the element at "<<i<<"x"<<j<<endl;
            cin>>a[i][j];
        }
    }
    //Diagonal operations
    for (int j=0; j<n;j++){
        for (int i=j+1;i<n;i++){
                c=a[i][j]/a[j][j];
                for (int k=0;k<n+1;k++){
                    a[i][k]=a[i][k]-c*a[j][k];
                }
        }
    }
    for (int i=n-1;i>=0;i--){
    float sum=0;
    for (int j=i+1;j<n;j++){
        sum+=a[i][j]*b[j];
    }
    b[i]=(a[i][n]-sum)/a[i][i];
    }        
    cout<<"The solutions are :"<<endl;
    for (int i=0;i<n;i++){
        cout<<b[i]<<endl;
    }
}