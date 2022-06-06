#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
float maximum(float z[], int order)
{
    float k=0;
    for (int i = 0; i < order; i++)
    {
        if (abs(k) < abs(z[i]))
            k = z[i];
    }
    return k;
}
int main()
{
    int n;
    cout << "Enter the order of matrix: " << endl;
    cin >> n;
    float a[n][n], x[n], z[n], e[n], e_, m;
    int count = 0;
    cout << "Enter matrix A elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Enter initial guess value of x: "<<endl;
    for (int i=0;i<n;i++)
    cin>>x[i];
    do
    {
        for (int i = 0; i < n; i++)
        {
            z[i] = 0;
            for (int j = 0; j < n; j++)
            {
                z[i] += a[i][j] * x[j];
            }
        }
        m = maximum(z, n);
        for (int i = 0; i < n; i++)
        {
            z[i] /= m;
        }
        for (int i = 0; i < n; i++)
        {
            e[i]=0;
            e[i] = abs(x[i] - z[i]);
        }
        e_=maximum(e,n);
        for (int i=0;i<n;i++)
            x[i]=z[i];
        count++;
        if (count>50)
        break;
    } while (e_>0.00005);
    cout<<"Dominant eigen value: "<<m<<endl;
    cout<<"Corresponding Eigen vector: "<<endl;
    for (int i=0;i<n;i++){
        cout<<z[i]<<endl;
    }
}