/*
4. Write three derived classes inheriting functionality of base class person (should have a member
function that asks to enter name and age) and with added unique features of student, and employee, and
functionality to assign, change and delete records of student and employee. And make one member function
for printing address of the objects of classes (base and derived) using this pointer.
Create two objects of base class and derived classes each and print the addresses of individual objects.
Using calculator, calculate the address space occupied by each object and verify this with address
spaces printed by the program.
*/
#include <iostream>
#include <cstring>
using namespace std;
class person{
    private:
    string Name;
    int Age;
    public:
    void askName(){
        cout<<"What is the name? "<<endl;
        cin>>Name;
    }
    void askAge(){
        cout<<"What is the age? "<<endl;
        cin>>Age;
    }
    void printName(){
        cout<<"Name: "<<Name<<endl;
    }
    void printAge(){
        cout<<"Age: "<<Age<<endl;
    }
    void printAddress(){
        cout<<this<<endl;
    }
};
class student: public person{
private:
int rollNo;
int level;
public:
void printRollNo(){
    cout<<"Roll Number: "<<rollNo<<endl;
}
void printLevel(){
    cout<<"Level: "<<level<<endl;
}
};
class employee: public person{
private:
int salary;
int idNo;
public:
void printSalary(){
    cout<<"Salary: "<<salary<<endl;
}
void printIdNo(){
    cout<<"Id Number: "<<idNo<<endl;
}
};
int main(){
    person p1,p2;
    student s1,s2;
    employee e1,e2;
    cout<<"Address of p1: ";
    p1.printAddress();
    cout<<"Address of p2: ";
    p2.printAddress();
    cout<<"Address of s1: ";
    s1.printAddress();
    cout<<"Address of s2: ";
    s2.printAddress();
    cout<<"Address of e1: ";
    e1.printAddress();
    cout<<"Address of e2: ";
    e2.printAddress();
    cout<<"Size of p1: "<<sizeof(p1)<<endl;
    cout<<"Size of p2: "<<sizeof(p1)<<endl;
    cout<<"Size of s1: "<<sizeof(p1)<<endl;
    cout<<"Size of s2: "<<sizeof(p1)<<endl;
    cout<<"Size of e1: "<<sizeof(p1)<<endl;
    cout<<"Size of e2: "<<sizeof(p1)<<endl;
    return 0;
}
