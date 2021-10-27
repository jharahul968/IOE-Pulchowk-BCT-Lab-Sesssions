/*
Write a class to store x, y, and z coordinates of a point
in three-dimensional space.
Overload addition and subtraction operators
for addition and subtraction of two coordinate objects.
Implement the operator functions as
non-member functions (friend operator functions).
*/
#include <iostream>
using namespace std;
class Coordinate{
    float x,y,z;
    public:
    Coordinate(float x_, float y_, float z_):x(x_),y(y_),z(z_){};
    friend Coordinate operator + (Coordinate a, Coordinate b);
    friend Coordinate operator - (Coordinate a, Coordinate b);
    void display(){
        cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
    }
};
Coordinate operator + (Coordinate a, Coordinate b){
    Coordinate temp(a.x+b.x,a.y+b.y,a.z+b.z);
    return temp;
}
Coordinate operator - (Coordinate a, Coordinate b){
    Coordinate temp(a.x-b.x,a.y-b.y,a.z-b.z);
    return temp;
}
int main(){
    Coordinate a(1,2,3);
    Coordinate b(2,3,4);
    Coordinate c=a+b;
    c.display();
    Coordinate d=a-b;
    d.display();
    return 0;
}