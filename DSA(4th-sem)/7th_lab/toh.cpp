// RECURSION
// WRITE AN ALGORITHM AND PROGRAM FOR FOLLOWING USING RECURSION:
// a. FIND THE FACTORIAL FOR GIVEN NUMBER ‘N’.
// b. FIND THE FIBONACCI NUMBER FOR GIVEN TERM ‘N’.
// c. SOLVE ABOVE QUESTIONS (a And b) USING TAIL RECURSION.
// d. SOLVE TOWER OF HANOI PROBLEM FOR ‘N’ DISCS.

//TOWER OF HANOI

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
void TOH(int n, string from, string to, string aux){
    if (n==0)
    return;
    TOH(n-1,from,aux,to);
    cout<<"Move disc "<<n<<" from rod "<<from<<" to rod "<<to<<"."<<endl;
    TOH(n-1,aux,to,from);
}
int main(){
    int n;
    cout<<"Enter the number of discs: "<<endl;
    cin>>n;
    TOH(n,"source","destination","auxiliary");
}