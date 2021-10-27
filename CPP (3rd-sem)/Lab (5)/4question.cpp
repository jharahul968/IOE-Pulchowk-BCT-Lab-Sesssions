/*
Write a class Date that overloads prefix and postfix operators to increase
day by one of the Date objects, while causing appropriate increments to
the month and year (use the appropriate condition for leap year).
The prefix and postfix operators in the
Date class should behave exactly like the built-in increment operators.
*/
#include <iostream>
using namespace std;
int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
class Date{
    private:
    int d,m,y;
    public:
    Date(int yy,int mm,int dd):d(dd),m(mm),y(yy){};
    static bool isLeap(int y){
        if (y%4==0)
        return true;
        else
        return false;
    }
    Date operator ++(){         //pre increment
        d+=1;
        if (m==2 && isLeap(y)==true){
        if (d>29){
            d=d%29;
            m+=d/29;
        }
        }
        else{
            if (d>days[m-1]){
                int temp=m;
                m+=d/days[temp-1];
                d=d%days[temp-1];
            }
        }
        if (m>12){
            y+=m/12;
            m=m%12;
        }
        return *this;
    }
    Date operator ++(int){          //post increment
    Date temp=*this;
    ++(*this);
    return temp;
    }
    void display(){
        cout<<y<<"/"<<m<<"/"<<d<<endl;
    }
};
int main(){
Date d1(2133,2,33), d2(2132,3,14);
cout<<"Post increment: "<<endl;
(d1++).display();
cout<<"Pre increment: "<<endl;
(++d2).display();
    return 0;
}