//concept to be used is inline funtion

#include <iostream>
using namespace std;
#define tax_rate 10.0
inline float netPay (int income){ return (income - (income*(tax_rate/100)));}
int main()
{
    int income;
    cout<<"Enter the employee's salary: "<<endl;
    cin>>income;
    cout<<"Payment to the employee by company is: "<<netPay(income)<<endl;
    return 0;
}