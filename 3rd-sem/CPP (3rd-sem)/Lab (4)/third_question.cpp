/*
Write a class that can store Department ID and Department Name
with constructors to initialize its members.
Write destructor member in the same class and display the message
"Object n goes out of the scope".
Your program should be made such that
it should show the order of constructor and destructor invocation.
*/

#include <iostream>
#include <cstring>
using namespace std;
class Department {
    private:
    int dID;
    char dName[20];
    public:
    Department (int id, const char *name):dID(id) {
        strncpy(dName,name,20);
        cout<<"Object "<<dName<<" is creted with id "<<dID<<endl;
    }
~Department(){
    cout<<"Object "<<dName<<" goes out of the scope"<<endl;
}
};
int main() {
    Department p(1,"Pulchowk"),d(2,"dMart");;
    return 0;
}