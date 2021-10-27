/*Write a simple program that converts the temperature in Celsius scale to Fahrenheit scale and vice versa using the basic concept of class and object.
Make separate classes for Celsius and Fahrenheit which will have the private members that hold the temperature value
and make conversion functions in each class for conversion from one to another.
For example, you need to have a function toFahrenheit() in class Celsius that converts to Fahrenheit scale and returns the value.*/

#include <iostream>
using namespace std;
class Celsius
{
    private:
    float celsius;
    float fahrenheit;
    public:
    void toFahrenheit()
    {
        cout<<"What is the temperature in celsius scale? "<<endl;
        cin>>celsius;
        fahrenheit=(((9./5.)*celsius)+32);
        cout<<"The temperature in Fahreneheit is "<<fahrenheit<<" degrees."<<endl;
    }
};
class Fahrenheit
{
    private:
    float celsius;
    float fahrenheit;
    public:
    void toCelsius()
    {
        cout<<"What is the temperature in fahrenheit scale? "<<endl;
        cin>>fahrenheit;
        celsius=(fahrenheit-32)*(5./9.);
        cout<<"The temperature in celsius is "<<celsius<<" degrees."<<endl;
    }
};
int main()
{
    Celsius c;
    Fahrenheit f;
    c.toFahrenheit();
    f.toCelsius();
    return 0;
}