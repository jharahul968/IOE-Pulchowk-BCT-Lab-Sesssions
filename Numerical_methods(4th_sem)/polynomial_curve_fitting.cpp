#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    float a,b,c;
    int n,s;
    cout<<"Enter the number of data points: ";
    cin>>n;
    float x[n],y[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the value of x and y: "<<endl;
        cin>>x[i];
        cin>>y[i];
    }
    cout<<"Enter the highest degree of polynomial equation: ";
    cin>>s;
    float m[s+1][s+2],res[s+1];
    for (int i=0;i<=s;i++){
        for (int j=0;j<=s;j++){
            float sum=0;
            for (int k=0;k<n;k++)
            sum+=pow(x[k],i+j);
            m[i][j]=sum;
        }
        float sum=0;
        for (int k=0;k<n;k++)
            sum+=pow(x[k],i)*y[k];
            m[i][s+1]=sum;
    }
    for (int j=0; j<s+1;j++){
        for (int i=0;i<s+1;i++){
            if (i!=j){
                c=m[i][j]/m[j][j];
                for (int k=j;k<=s+1;k++){
                    m[i][k]=m[i][k]-c*m[j][k];
                }
            }
        }
    }
    for (int i=0;i<s+1;i++)
        res[i]=m[i][s+1]/m[i][i];
    cout<<"Output: "<<endl;
    for (int i=0;i<s+1;i++)
    cout<<res[i]<<endl;
    return 0;
}