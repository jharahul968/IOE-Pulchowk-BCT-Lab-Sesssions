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
int fibo(int n){
    if (n==0 || n==1)
    return n;
    else
    return (fibo(n-1)+fibo(n-2));
}
int main(){
    int n;
    cout<<"Enter the number of terms in series: "<<endl;
    cin>>n;
    cout<<"The fibonacci series is: ";
    int i=0;
    while(i<n){
        cout<<" "<<fibo(i++);
    }
}