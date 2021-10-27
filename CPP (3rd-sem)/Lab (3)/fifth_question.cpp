/*Assume that an object represents an employee report that contains information like employee id, total bonus, total overtime
in a particular year.
Use an array of objects to represent n employees' reports.
Write a program that displays the report.
Use setpara() member function to set report attributes by passing the arguments and member function displayreport()
to show the report according to parameter passed. Display the report in following format.
Employee with ... ... ... has received Rs ... ... ...as bonus
and
had worked ... ... ... hours as a over time in  year ... ... ...*/

#include <iostream>
using namespace std;
class employee
{
    private:
    int employee_id;
    int total_bonus;
    int total_overtime;
    int year;
    public:
    setpara()
    {
        cout<<"For which year the data is to be entered? "<<endl;
        cin>>year;
        cout<<"Enter the employee id number: "<<endl;
        cin>>employee_id;
        cout<<"Enter the total bonus of employee in a particular year: "<<endl;
        cin>>total_bonus;
        cout<<"Enter the total overtime of employee in a particular year: "<<endl;
        cin>>total_overtime;
    }
    displayreport(){
    cout<<"Employee with "<<employee_id<<" has recieved Rs "<<total_bonus<<" as bonus and had worked "<<total_overtime<<" hours as an overtime in year "<<year<<endl;
    }
};
int main()
{
    employee e1;
    e1.setpara();
    e1.displayreport();
}