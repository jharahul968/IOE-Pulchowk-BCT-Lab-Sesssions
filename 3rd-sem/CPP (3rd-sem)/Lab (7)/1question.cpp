/*
Write a program to create a class shape with functions to find area of the shapes and
display the name of the shape and other essential component of the class.
Create derived classes circle, rectangle and trapezoid each having overridden
functions area and display.
Write a suitable program to illustrate virtual functions and virtual destructor.
*/
#include <iostream>
#include <cstring>
using namespace std;
class shape{
    protected:
    string shape_name;
    float shape_area;
    public:
    shape(){
        shape_name="Shape";
        shape_area=0;
    }
    shape(float a, string s="Shape"):shape_name(s),shape_area(a){};
    virtual float get_area(){
        return shape_area;
    }
    virtual string get_name(){
        return shape_name;
    }
    virtual ~shape(){
        cout<<"Destructor of shape class."<<endl;
    }
};
class circle:public shape{
protected:
float radius;
public:
circle(float r, string s="Circle"):radius(r){
    shape_name=s;
}
float get_area(){
shape_area=3.14*radius*radius;
return shape::shape_area;
}
string get_name(){
    //shape_name="Circle";
    return shape::shape_name;
}
~circle(){
    cout<<"Circle Destructor."<<endl;
}
};
class rectangle:public shape{
protected:
float length,breadth;
public:
rectangle(float l,float b, string s="Rectangle"):length(l),breadth(b){
    shape_name=s;
}
float get_area(){
    shape_area=length*breadth;
    return shape::shape_area;
}
string get_name(){
    //shape_name="Rectangle";
    return shape::shape_name;
}
~rectangle(){
    cout<<"Rectangle Destructor."<<endl;
}
};
class trapezoid:public shape{
protected:
float parallel_sides[2];
float non_parallel_sides[2];
public:
trapezoid(float p1,float p2,float np1,float np2, string s="Trapezoid"){
    parallel_sides[0]=p1;
    parallel_sides[1]=p2;
    non_parallel_sides[0]=np1;
    non_parallel_sides[1]=np2;
    shape_name=s;
}
float get_area(){
    shape_area=((parallel_sides[0]+parallel_sides[1])/2.0)*((non_parallel_sides[0]+non_parallel_sides[1])/2.0);
    return shape::shape_area;
}
string get_name(){
    //shape_name="Trapezoid";
    return shape::shape_name;
}
~trapezoid(){
    cout<<"Trapezoid Destructor"<<endl;
}
};
int main(){
    //Circle
    shape *s;
    s=new circle(14.28,"football");
    cout<<"Name of Shape: "<<s->get_name()<<endl;
    cout<<"Area of Shape: "<<s->get_area()<<endl;
    delete(s);
    //Rectangle
    s=new rectangle(12,14.28,"wall");
    cout<<"Name of shape: "<<s->get_name()<<endl;
    cout<<"Area of shape: "<<s->get_area()<<endl;
    delete(s);
    //Trapezoid
    s=new trapezoid(12,14.28,15.5,16,"ground");
    cout<<"Name of shape: "<<s->get_name()<<endl;
    cout<<"Area of shape: "<<s->get_area()<<endl;
    delete(s);
    return 0;
}