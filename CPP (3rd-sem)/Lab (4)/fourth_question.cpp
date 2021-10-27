/*
Assume that one constructor initializes data member
say num_vehicle, hour, and rate.
There should be a 10% discount if num_vehicle exceeds 10.
Display the total charge.
Use two objects and show a bit-by-bit copy of one object to another
(make your own copy constructor).
*/

#include <iostream>
using namespace std;
class Vehicle {
private:
int num_vehicle;
float hour;
float rate;
public:
Vehicle (int n,float h,float r):num_vehicle(n),hour(h),rate(r){};
Vehicle (Vehicle &v) {
    num_vehicle=v.getNumVehicle();
    hour=v.getHour();
    rate=v.getRate();
}
int getNumVehicle(){
    return num_vehicle;
}
int getHour(){
    return hour;
}
int getRate(){
    return rate;
}
float getTotal() {
    float total=rate*num_vehicle*rate;
    if (num_vehicle>10) {
        total*=0.9;
    }
    return total;
}
void display() {
cout<<"Total number of vehicles: "<<num_vehicle<<endl;
cout<<"The rate is: "<<rate<<endl;
cout<<"The hours are: "<<hour<<endl;
cout<<"Total charge is: "<<getTotal()<<endl;
}
};
int main() {
Vehicle v1(10,12,122),v2(12,11,123);
v1.display();
v2.display();
Vehicle v3=v1, v4=v2;
cout<<"Object created from copy constructor is as: "<<endl;
v3.display();
v4.display();
    return 0;
}