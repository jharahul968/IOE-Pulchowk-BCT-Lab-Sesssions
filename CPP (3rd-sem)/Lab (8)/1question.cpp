/*
1. Write a program to demonstrate the use of different ios flags and functions to
format the output. Create a program to generate the bill invoice of a department
store by using different formatting.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    ofstream bill("bill.txt", ios::out);
    bill << setw(40) << "Jha Pvt Ltd" << endl;
    cout << setw(40) << "Jha Pvt Ltd" << endl;
    int sNo = 1;
    char subject_Name[20];
    int quantity;
    int price;
    int total = 0;
    int subtotal;
    char ans;
    bill << setw(4) << "S.N." << setw(20) << left << "Subject Name" << setw(10) << "Quantity" << setw(6) << "Price" << setw(10) << "Sub-Total" << endl;
    do
    {
        cout << "Subject Name: ";
        cin >> subject_Name;
        cout << "Quantity: ";
        cin >> quantity;
        cout << "Price: ";
        cin >> price;
        subtotal = quantity * price;
        total += subtotal;
        cout << "Sub-Total: " << subtotal;
        bill << setw(4) << sNo << setw(20) << left << subject_Name << setw(10) << quantity << setw(6) << price << setw(10) << subtotal << endl;
        cout << "Do you want to enter more items? (y/n)";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    cout << "Total" << total;
    bill << setw(34) << "total" << setw(10) << total << endl;
    bill.close();
    return 0;
}