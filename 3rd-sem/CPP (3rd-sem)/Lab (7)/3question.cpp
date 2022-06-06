/*
Write a program with Student as abstract class and create derive classes Engineering,
Medicine and Science from base class Student. Create the objects of the derived classes
and process them and access them using array of pointer of type base class Student.
*/
#include <iostream>
#include <cstring>
using namespace std;
class Student{
protected:
string name,major;
public:
Student(){}
Student(string s1,string s2):name(s1),major(s2){};
virtual string getName()=0;
virtual string getMajor()=0;
};
class Engineering:public Student{
public:
Engineering(string s1,string s2){
    name=s1;
    major=s2;
}
string getName(){
    return name;
}
string getMajor(){
    return major;
}
};
class Medicine:public Student{
public:
Medicine(string s1,string s2){
    name=s1;
    major=s2;}
    string getName(){
    return name;
}
string getMajor(){
    return major;
}
};
class Science:public Student{
public:
Science(string s1,string s2){
    name=s1;
    major=s2;}
    string getName(){
    return name;
}
string getMajor(){
    return major;
}
};
int main(){
    Student *s[3];
    s[0]=new Engineering("Rahul","Computer");
    s[1]=new Medicine("Ram","Cardio");
    s[2]=new Science("Hari","Physics");
    cout<<"Details: "<<endl;
    for (int i=0;i<3;i++){
        cout<<"Name: "<<s[i]->getName()<<endl;
        cout<<"Major: "<<s[i]->getMajor()<<endl<<endl;
    }
    return 0;
}