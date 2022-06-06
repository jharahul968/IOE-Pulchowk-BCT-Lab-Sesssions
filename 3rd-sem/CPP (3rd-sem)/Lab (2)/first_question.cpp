//concept to be used is structures


#include <iostream>
using namespace std;
struct dateHolder
{
    int month;
    int date;
    int year;
};
int dateAssigner(dateHolder *dates)
{
    cout<<"Enter the month: "<<endl;
    cin>>dates->month;
    cout<<"Enter the date: "<<endl;
    cin>>dates->date;
    cout<<"Enter the year: "<<endl;
    cin>>dates->year;
    return 0;
}
int datePrinter(dateHolder dates)
{
    cout<<"Date: "<<dates.month<<"/"<<dates.date<<"/"<<dates.year<<endl;
    return 0;
}
int main()
{
    dateHolder dates;
    dateAssigner(&dates);
    datePrinter(dates);
    return 0;
}