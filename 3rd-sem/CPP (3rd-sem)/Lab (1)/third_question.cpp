#include<iostream>
using namespace std;

    struct studentRecord
    {
        char studentName[100];
        int marksInC;
    };

int main()
{
    studentRecord sem1[1000];
    int i;
    int studentCount;
    char ans;
    cout<<"How many students are there in 1st semester? "<<endl;
    cin>>studentCount;
    for (i=0;i<studentCount;i++)
    {
        cout<<"Enter the name of student "<<i+1<<":"<<endl;
        cin>>sem1[i].studentName;
        cout<<"Enter the marks of student "<<i+1<<" in C programming subject:"<<endl;
        cin>>sem1[i].marksInC;
    }
    cout<<"Do you want to see the results? (Y for yes and N for no) "<<endl;
    cin>>ans;
    if (ans=='Y'){
        cout<<"Name of Students and their respective marks are as below: "<<endl;
    for (i=0;i<studentCount;i++)
    {
        cout<<i+1<<". "<<sem1[i].studentName<<" has got "<<sem1[i].marksInC<<" marks in C programming."<<endl;

    }
    }
    else if (ans=='N')
    cout<<"Thank you for your time. "<<endl;

    return 0;
}