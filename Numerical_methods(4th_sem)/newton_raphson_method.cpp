#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
float f(float a)
{
    return (a * a * a - 3 * a - 9);
}
float g(float a)
{
    return (3 * a * a - 3);
}
int main()
{
    float x0, x1, allowed_tolerance, calculated_error;
    int n,i = 0;
    cout << "Enter initial assumption: " << endl;
    cin >> x0;
    cout << "Enter error tolerance: " << endl;
    cin >> allowed_tolerance;
    cout<<"Enter the number of iterations: "<<endl;
    cin>>n;
    do
    {
        if (fabs(g(x0)) < allowed_tolerance)
        {
            cout << "error" << endl;
            return 1;
        }
        x1 = x0 - (f(x0) / g(x0));
        calculated_error = fabs(x0 - x1);
        x0=x1;
        i++;
        if (i > n)
        {
            cout << "curve oscillation occurs" << endl;
            exit(1);
        }
    } while (calculated_error > allowed_tolerance);
    cout << "root is: " << x1 << endl;
    return 0;
}