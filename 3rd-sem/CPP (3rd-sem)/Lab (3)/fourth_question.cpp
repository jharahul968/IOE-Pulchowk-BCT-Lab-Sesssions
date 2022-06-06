/*Write a program with classes to represent circle, rectangle, and triangle.
Each class should have data members to represent the actual objects and member functions to read and display objects,
find perimeter and area of the objects, and other useful functions.
Use the classes to create objects in your program.*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class circle
{
    private:
    float radius;
    public:
    askRadius()
    {
    cout<<"Enter the radius of circle: "<<endl;
    cin>>radius;
    }
    printRadius()
    {
    cout<<"The radius of cicle is "<<radius<<"."<<endl;
    }
    printPerimeter()
    {
    cout<<"The perimeter of circle is: "<<2.*3.14*radius<<endl;
    }
    printArea()
    {
    cout<<"The area of circle is: "<<3.14*radius*radius<<endl;
    }
};
class rectangle
{
    private:
    float length, breadth;
    public:
    askLength()
    {
    cout<<"Enter the length of rectangle: "<<endl;
    cin>>length;
    }
    askBreadth()
    {
    cout<<"Enter the breadth of rectangle: "<<endl;
    cin>>breadth;
    }
    printLength()
    {
    cout<<"The length of rectangle is "<<length<<"."<<endl;
    }
    printBreadth()
    {
    cout<<"The breadth of rectangle is "<<breadth<<"."<<endl;
    }
    printPerimeter()
    {
    cout<<"The perimeter of rectangle is: "<<2.0*(length+breadth)<<endl;
    }
    printArea()
    {
    cout<<"The area of rectangle is: "<<length*breadth<<endl;
    }
};
class triangle
{
    private:
    float side1,side2,side3;
    public:
    askSides()
    {
    cout<<"Enter the sides of triangle: "<<endl;
    cin>>side1>>side2>>side3;
    }
    printSides()
    {
    cout<<"The sides of triangle are "<<side1<<setw(5)<<side2<<setw(5)<<side3<<"."<<endl;
    }
    printPerimeter()
    {
    cout<<"The perimeter of triangle is: "<<side1+side2+side3<<endl;
    }
    printArea()
    {
    float s=(side1+side2+side3)/2.;
    cout<<"The area of triangle is: "<<sqrt(s*(s-side1)*(s-side2)*(s-side3))<<endl;
    }
};
int main()
{
    char ans;
    cout<<"Let's start the calculations: "<<endl;
    cout<<"What do you want to analyse? "<<endl;
    cout<<"Enter 1 for triangle, 2 for rectangle and 3 for circle: "<<endl;
    cin>>ans;
    if (ans=='1'){
    triangle t;
    t.askSides();
    t.printSides();
    t.printArea();
    t.printPerimeter();
    }
    else if(ans=='2'){
        rectangle r;
        r.askLength();
        r.askBreadth();
        r.printLength();
        r.printBreadth();
        r.printPerimeter();
        r.printArea();}
        else{
            circle c;
            c.askRadius();
            c.printRadius();
            c.printArea();
            c.printPerimeter();
        }
    
return 0;
}