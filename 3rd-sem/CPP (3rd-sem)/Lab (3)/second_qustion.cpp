/*Assume that you want to check whether the number is prime or not.
Write a program that asks for numbers repeatedly. When it finishes checking a number the program asks if the user wants to do another calculation.
The response can be 'y' or 'n'. Don't forget to use the object oriented concept.*/

#include <iostream>
using namespace std;
class primeChecker
{
    private:
    int n;
    public:
    void checkPrime()
    {
        int flag=0;
        cout<<"Enter the number you want to check if its a prime or not: "<<endl;
        cin>>n;

        for (int i=2;i<=(n/2);i++)
        {
            if (n%i==0)
            {
                flag=1;
                break;
            }
        }

        if (flag==0)
        cout<<"The given number "<<n<<" is prime."<<endl;
        else
        cout<<"The given number is not a prime number."<<endl;
    }
};
int main()
{
    primeChecker p;
    char ans;
    while(1)
    {
    cout<<"Do you want to check any number for it being prime? (answer in y for yes or n for no)"<<endl;
    cin>>ans;
    if (ans=='y')
    {
    p.checkPrime();
    }
    
    if (ans=='n')
    break;
    }
    cout<<"Thank you for your time."<<endl;
    return 0;
}