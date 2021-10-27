//concept to be used is function overloading
#include <iostream>
using namespace std;
#define conversionFactor 12

void convert()
{
    int feet;
    cout<<"How many feets are to be comverted to inches? "<<endl;
    cin>>feet;
    cout<<"The feets in inches are: "<<feet*conversionFactor<<" inches"<<endl;
}
int convert(float feet)
{
    return feet*conversionFactor;
} 
void convert(float feet, float &inch)
{
    inch = feet*conversionFactor;
}
int main()
{
    float inches;
    float feet=12;
    convert();
    cout<<"12 feets in inches are: "<<convert(feet)<<endl;
    feet=12.12;
    convert(feet,inches);
    cout<<"12.12 feets in inches are: "<<inches<<endl;
    return 0;
}