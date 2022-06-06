/*
Write a program that has a class to represent time.
The class should have constructors to initialize:
data members hour, minute and second to 0 and
to initialize them to values passed as arguments.
The class should have member function to add time objects and
return the result as time object.
There should be another function to display the result in 24 hour format.
*/

#include <iostream>
using namespace std;
class representTime
{
    private:
    int hr,min,sec;

    public:
    representTime()
    {
        hr=0;
        min=0;
        sec=0;
    }
    representTime(int h,int m,int s)
    {
        hr=h;
        min=m;
        sec=s;
    }
    int getHour(){return hr;}
    int getMin(){return min;}
    int getSec(){return sec;}

    representTime &addTime(representTime a){
        sec+=a.getSec();
        min=a.getMin();
        hr=a.getHour();
        if (sec>=60){
            min+=(sec/60);
            sec=sec%60;
        }
        if (min>=60){
            hr+=(min/60);
            min=min%60;
        }
        if (hr>=24){
            hr=hr%24;
        }
        return *this;
    }
    void displayTime(){
        cout<<hr<<":"<<min<<":"<<sec<<endl;
    }
};
int main() {
    int hr,min,sec;
    cout<<"Enter hour: "<<endl;
    cin>>hr;
    cout<<"Enter min: "<<endl;
    cin>>min;
    cout<<"Enter sec: "<<endl;
    cin>>sec;
    representTime t(hr,min,sec);
    cout<<"Enter hour: "<<endl;
    cin>>hr;
    cout<<"Enter min: "<<endl;
    cin>>min;
    cout<<"Enter sec: "<<endl;
    cin>>sec;
    representTime t1(hr,min,sec);
    cout<<"Added time is as: "<<endl;
    t.addTime(t1).displayTime();
    
    return 0;
}