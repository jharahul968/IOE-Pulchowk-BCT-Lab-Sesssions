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
int factorial(int n){
    if (n==0 || n==1)
    return 1;
    else
    return n*factorial(n-1);
}
int main(){
    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    cout<<"The factorial is: "<<factorial(n);
}