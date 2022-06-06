/*
Write a program that stores the information about students (name, student id,
department, and address) in a structure and then transfers the information to a file
in your directory. Finally, retrieve the information from your file and print it in the
proper format on your output screen.
*/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
struct Students{
    string name;
    int student_id;
    string department;
    string address;
    void display(){
    cout << "Name: " << name << endl;
    cout << "Id: " << student_id << endl ;
    cout << "Department: " << department << endl;
    cout << "Address: " << address << endl;
    }
};
int main(){
    ofstream file;
    char ans;
    file.open("file.dat",ios::out|ios::binary);
    do{
    Students s;
    cout<<"Enter the data: "<<endl;
    cout<<"Name: ";
    cin>>s.name;
    //file<<"Name: "<<s.name<<endl;
    cout<<"Student ID: ";
    cin>>s.student_id;
    //file<<"Student ID: "<<s.student_id<<endl;
    cout<<"Department: ";
    cin>>s.department;
    //file<<"Department: "<<s.department<<endl;
    cout<<"Address: ";
    cin>>s.address;
    //file<<"Address: "<<s.address<<endl;
    file.write(reinterpret_cast<char *>(&s),sizeof(s));
    cout<<"Do you want to enter more data?"<<endl;
    cin>>ans;
    }while(ans=='y' || ans=='Y');
    file.close();

    ifstream file1;
    file1.open("file.dat",ios::in|ios::binary);
    while(!file1.eof()){
        Students s;
        file1.read(reinterpret_cast<char *>(&s),sizeof(s));
        if (file1)
        s.display();
    }
    file1.close();
    return 0;
}