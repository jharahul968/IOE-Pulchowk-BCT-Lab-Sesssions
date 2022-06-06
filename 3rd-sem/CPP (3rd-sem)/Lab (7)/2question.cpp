/*
Create a class Person and two derived classes Employee, and Student, inherited from
class Person. Now create a class Manager which is derived from two base classes
Employee and Student. Show the use of the virtual base class.
*/
#include <iostream>
using namespace std;
class Person{
private:
string name;
public:
Person(){}
Person(string s){
    name=s;
}
string getName(){
    return name;
}
};
class Employee:virtual public Person{
private:
int salary;
public:
Employee(string s,int i):Person(s),salary(i){};
int getSalary(){
    return salary;
}
};
class Student:virtual public Person{
private:
int rank;
public:
Student(string s,int r):Person(s),rank(r){};
int getRank(){
    return rank;
}
};
class Manager:public Employee,public Student{
private:
public:
Manager(string s,int r,int r1):Person(s),Employee(s,r),Student(s,r1){};
};
int main(){
    Manager m("Rahul",30000,1);
    cout<<"Name: "<<m.getName()<<endl;
    cout<<"Salary: "<<m.getSalary()<<endl;
    cout<<"Rank: "<<m.getRank();
    return 0;
}