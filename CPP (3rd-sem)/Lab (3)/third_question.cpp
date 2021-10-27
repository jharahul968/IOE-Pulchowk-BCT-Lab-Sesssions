/*Create a class called carpark that has int data member for car id, int data member for charge/hour, and float data member for the parked time.
Make functions to set data members and show the charges and parked hours of the corresponding car id.
Make functions for setting and showing the data members.
Member function should be called from other functions.*/
#include <iostream>
using namespace std;
class carpark
{
    private:
    int carID;
    int chargePerHour;
    float parkedTime;
    public:
    setData(){
    cout<<"Enter the car id: "<<endl;
    cin>>carID;
    cout<<"Enter the charge of parking in per hourly rate: "<<endl;
    cin>>chargePerHour;
    cout<<"Enter the time for which car has been parked in hours: "<<endl;
    cin>>parkedTime;
    }
    showData(){
        cout<<"The car id number is: "<<carID<<"."<<endl;
        cout<<"The parking charge in hourly rate is: "<<chargePerHour<<"."<<endl;
        cout<<"The time for which car has been parked is: "<<parkedTime<<" hours."<<endl;
    }
};
int main(){
    carpark c1,c2;
    c1.setData();
    c2.setData();
    c1.showData();
    c2.showData();
    return 0;

}