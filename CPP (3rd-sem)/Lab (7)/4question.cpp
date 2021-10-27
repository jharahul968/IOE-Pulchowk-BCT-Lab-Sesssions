/*
Create a polymorphic class Vehicle and create other derived classes Bus, Car and
Bike from Vehicle.
With this program illustrate RTTI by the use of dynamic_cast and typeid operators.
*/
#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;
class Vehicle{
protected:
int engineNumber;
public:
Vehicle(){}
Vehicle(int i):engineNumber(i){};
int getEngineNumber(){
    return engineNumber;
}
};
class Bus:public Vehicle{
private:
string brandName;
public:
Bus(int i, string s):Vehicle(i),brandName(s){};
string getBrandName(){
    return brandName;
}
};
class Car:public Vehicle{
private:
string brandName;
public:
Car(int i, string s):Vehicle(i),brandName(s){};
string getBrandName(){
    return brandName;
}
};
class Bike:public Vehicle{
private:
string brandName;
public:
Bike(int i, string s):Vehicle(i),brandName(s){};
string getBrandName(){
    return brandName;
}
};
int main(){
    Vehicle *v[3];
    Bus *bus=new Bus(100,"Volvo");
    Car *car=new Car(10,"Hyundai");
    Bike *bike=new Bike(1,"Bajaj");
    v[0]=dynamic_cast<Bus *>(bus);
    v[1]=dynamic_cast<Car *>(car);
    v[2]=dynamic_cast<Bike *>(bike);
    cout<<"Details: "<<endl;
    for (int i=0;i<3;i++){
        cout <<"Type Id: "<<typeid(*v[i]).name() << endl;
        cout<<"Engine Number: "<<v[i]->getEngineNumber()<<endl;
    }
    cout <<"Type ID: "<<typeid(*bus).name() << endl;
    cout<<"Brand Name: "<<bus->getBrandName()<<endl;
    cout <<"Type ID: "<< typeid(*car).name() << endl;
    cout<<"Brand Name: "<<car->getBrandName()<<endl;
    cout << "Type ID: "<<typeid(*bike).name() << endl;
    cout<<"Brand Name: "<<bike->getBrandName()<<endl;
    return 0;
}