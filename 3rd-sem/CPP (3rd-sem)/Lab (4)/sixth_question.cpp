/*Create a class with a data member to hold a "serial number" for each object created from the class.
That is, the first object created will be numbered 1, the second 2, and so on by using the basic concept of static data members.
Use static member function if it is useful in the program.
Otherwise, make a separate program that demonstrates the use of static member function.
*/

#include <iostream>
using namespace std;
class SN {
private:
unsigned int sNo;
static unsigned int total;
public:
SN() {
    total++;
    sNo=total;
}
void display() {
    cout<<"The serial number is "<<sNo<<" and total number is "<<total<<"."<<endl;
}
unsigned int getTotal() {
    return total;
}
};
unsigned int SN::total=0;
int main() {
SN s1,s2,s3;
s1.display();
s2.display();
s3.display();
return 0;
}