#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
int main() {
float a[20][20],b[20][20],c;
    int n;
    cout<<"Enter the number of variables: "<<endl;
    cin>>n;
    //Data entry
    for (int i=0; i<n;i++){
        for (int j=0;j<n;j++){
            cout<<"Enter the element at "<<i<<"x"<<j<<endl;
            cin>>a[i][j];
            if (i==j)
            b[i][j]=1;
            else
            b[i][j]=0;
        }
    }
    //Diagonal operations
    for (int j=0; j<n;j++){
        for (int i=0;i<n;i++){
            if (i!=j){
                c=a[i][j]/a[j][j];
                for (int k=0;k<n;k++){
                    a[i][k]=a[i][k]-c*a[j][k];
                    b[i][k]=b[i][k]-c*b[j][k];
                }
            }
        }
    }
for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
        b[i][j]/=a[i][i];
    }
}
cout<<"The inverse is: "<<endl;
for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
        cout<<b[i][j]<<"\t";
    }
    cout<<endl;
}
}