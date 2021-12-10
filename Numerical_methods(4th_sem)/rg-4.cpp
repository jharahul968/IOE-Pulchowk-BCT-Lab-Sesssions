#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
float f(float x, float y)
{
    return ((x - y) / (x + y));
}
int main ()
{
    float x, y, h, a, b, t, k, k1, k2, k3, k4;
    cout << "Enter the initial values of x, y, value of step (h) and xn: "<<endl;
    cin>>x>>y>>h>>t;
    a=x;
    b=y;
    cout<<"x"<<"    "<<"y"<<endl;
    while (a < t)
    {
        k1 = f(a, b);
        k2 = f(a + 0.5 * h, b + 0.5 * k1 * h);
        k3 = f(a + 0.5 * h, b + 0.5 * k2 * h);
        k4 = f(a + h, b + k3 * h);
        k = (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        b=b+k*h;
        a=a+h;
        cout << a << "     " << b << endl;
    }
}