#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
float f(float x, float y,float z)
{
    return 0.5*(x*x*x-2*y*y/3+y);
}
float g(float x, float y,float z){
    return (2*y*y-3*z*z*z);
}

int main ()
{
    float x, y, z, h, l, xn, k, k1, k2, k3, k4,l1,l2,l3,l4;
    int n;
    cout << "Enter the initial values of x, y, z, xn and number of iteratiions(n): ";
    cin>>x>>y>>z>>xn>>n;
    h=(xn-x)/n;
    cout<<"x\t\ty\t\tz"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<x<<"\t\t"<<y<<"\t\t"<<z<<endl;
        k1 = h*f(x,y,z);
        l1 = h*g(x,y,z);
        k2 = h*f(x + 0.5 * h, y + 0.5 * k1, z+0.5*l1);
        l2 = h*g(x + 0.5 * h, y + 0.5 * k1, z+0.5*l1);
        k3 = h*f(x + 0.5 * h, y + 0.5 * k2, z+0.5*l2);
        l3 = h*g(x + 0.5 * h, y + 0.5 * k2, z+0.5*l2);
        k4 = h*f(x + h, y + k3, z+l3);
        l4 = h*g(x + h, y + k3, z+l3);
        k = (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        l = (1.0 / 6.0) * (l1 + 2 * l2 + 2 * l3 + l4);
        y=y+k;
        z=z+l;
        x=x+h;
    }
}