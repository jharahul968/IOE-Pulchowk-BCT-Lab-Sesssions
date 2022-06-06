//concept to be used is default argument
#include <iostream>
using namespace std;
float currentSalary(float salary=18000, float increment=12)
{
    return (salary+(salary*(increment/100)));
}
int main()
{
    cout<<"For Chief Executive Officer: "<<endl;
    cout<<"Current increased salary is "<<currentSalary(35000,9)<<endl;
    cout<<"For Information Officer: "<<endl;
    cout<<"Current increased salary is "<<currentSalary(25000,10)<<endl;
    cout<<"For System Analyst: "<<endl;
    cout<<"Current increased salary is "<<currentSalary(24000)<<endl;
    cout<<"For Programmer: "<<endl;
    cout<<"Current increased salary is "<<currentSalary()<<endl;    
    return 0;
}