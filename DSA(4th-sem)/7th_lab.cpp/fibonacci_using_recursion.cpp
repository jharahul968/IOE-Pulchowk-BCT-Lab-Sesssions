// RECURSION
// WRITE AN ALGORITHM AND PROGRAM FOR FOLLOWING USING RECURSION:
// a. FIND THE FACTORIAL FOR GIVEN NUMBER ‘N’.
// b. FIND THE FIBONACCI NUMBER FOR GIVEN TERM ‘N’.
// c. SOLVE ABOVE QUESTIONS (a And b) USING TAIL RECURSION.
// d. SOLVE TOWER OF HANOI PROBLEM FOR ‘N’ DISCS.

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int fibo(int n, int a=0, int b=1){
    if (n==0)
    return a;
    if (n==1)
    return b;
    return fibo(n-1,b,a+b);
}
int main(){
    int n;
    cout<<"Enter the number of terms: "<<endl;
    cin>>n;
    int i=0;
    cout<<"The fibonacci series is: ";
    while(i<n){
    cout<<" "<<fibo(i++);
    }
}