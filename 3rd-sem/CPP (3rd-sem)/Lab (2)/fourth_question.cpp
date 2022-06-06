#include <iostream>
using namespace std;
int &temp(int &temp1,int &temp2)
{
    if (temp1<temp2)
    return temp2;
    else
    return temp1;
}
int takeInput()
{
    int n;
    cout<<"Enter user's value: "<<endl;
    cin>>n;
    return n;
}
int main()
{
    int userValue;
    int temp1,temp2;
    cout<<"Enter first temperature: "<<endl;
    cin>>temp1;
    cout<<"Enter second temperature: "<<endl;
    cin>>temp2;
    userValue=takeInput();
    temp(temp1,temp2)=userValue;
    cout<<"The temperature values are "<<temp1<<" and "<<temp2<<endl;

    return 0;
}