/*
Write a program to create a user-defined manipulator that will format the output by
setting the width, precision, and fill character at the same time by passing arguments.
*/
#include <iostream>
#include <iomanip>
using namespace std;
class Manip{
private:
int width,precision;
char fill;
public:
Manip(int w,int p,char c):width(w),precision(p),fill(c){};
void setManip(Manip m,float f){
    cout<<setw(m.width)<<setfill(m.fill)<<setprecision(m.precision)<<f;
}
};
int main(){
    Manip m(20,2,'*');
    m.setManip(m,1.23442);
    return 0;
}