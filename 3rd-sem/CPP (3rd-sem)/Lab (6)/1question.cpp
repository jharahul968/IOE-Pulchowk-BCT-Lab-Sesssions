/*
1. Write a program that can convert the Distance (meter, centimeter) to 
meters measurement in float and vice versa. Make a class distance with two 
data members, meter and centimeter.
You can add function members as per your requirement.
*/
#include <iostream>
using namespace std;
class Distance
{
private:
    float m, cm;

public:
    Distance();
    Distance(float mm, float ccmm) : m(mm), cm(ccmm){};
    Distance(float mm) {
        m=int(mm);
        cm=(mm - int(mm)) * 100;}
    float toMeters()
    {
        float mm = m + (cm / 100);
        return mm;
    }
    // Distance toM_CM()
    // {
    //     Distance temp;
    //     temp.m = int(m);
    //     temp.cm = (m - int(m)) * 100;
    //     return temp;
    // }
    void display()
    {
        cout<< m <<" meters "<< cm <<" centimeters."<<endl;
    }
};
int main()
{
    Distance d1(5.617), d2(5, 670);
    cout << "Distance from meter only to meter and centimeter: ";
    d1.display();
    cout << "Distance from meter and centimeter to meter only: ";
    cout<<d2.toMeters()<<" meters.";
    return 0;
}