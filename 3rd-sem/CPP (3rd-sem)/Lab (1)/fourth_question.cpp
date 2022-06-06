#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct studentData
{
    char name[100];
    int rollNumber;
    char address[100];
    char phoneNumber[20];
};
int sortData(struct studentData list[],int start, int stop)
{
    int middle=(start+stop)/2;
    if ((stop-start)<=1)
    return 0;
    else
    {
        sortData(list,start,middle);
        sortData(list,middle,stop);
        struct studentData newOne[stop-start];
        int list1=start;
        int list2=middle;
        int newpos=0;
        while (list1<middle || list2<stop)
        {
            if (list1<middle && list2 < stop)
            {
                if (strcmp(list[list1].name,list[list2].name)<0)
                {
                    newOne[newpos]=list[list1];
                    list1++;
                }
                else{
                    newOne[newpos]=list[list2];
                    list2++;
                }
            }
            else if(list1==middle)
            {
            newOne[newpos]=list[list2];
            list2++;
            }
                else{
                    newOne[newpos]=list[list1];
                    list1++;
                }
                newpos++;
            }
            int i;
            for (i=0,list1=start;i<(stop-start);i++,list1++)
            {
                list[list1]=newOne[i];
            }
        }

    }

int main()
{
    int i,j;
    ofstream dataFile;
    dataFile.open("data.txt");
studentData classData[100];
int n;
char ans;
string String;
cout<<"How many students are there in class? "<<endl;
cin>>n;
cout<<"Enter the Data of your classes: "<<endl;
for (i=0;i<n;i++)
{
cout<<"Enter data for student "<<i+1<<" :"<<endl;
dataFile<<"Data of student "<<i+1<<endl;
cout<<"Enter name of the student: "<<endl;
cin>>classData[i].name;
dataFile<<"Name: "<<classData[i].name<<endl;
cout<<"Enter the roll number: "<<endl;
cin>>classData[i].rollNumber;
dataFile<<"Roll Number: "<<classData[i].rollNumber<<endl;
cout<<"Enter the address: "<<endl;
cin>>classData[i].address;
dataFile<<"Address: "<<classData[i].address<<endl;
cout<<"Enter phone number: "<<endl;
cin>>classData[i].phoneNumber;
dataFile<<"Phone Number: "<<classData[i].phoneNumber<<endl;
dataFile.close();
}
cout<<"Do you want to retrieve the file? (Y for yes and N for no) "<<endl;
cin>>ans;
if (ans=='N' || ans=='n')
cout<<"Thank you for your time.";
else if (ans=='Y' || ans=='y')
{
ifstream dataFile;
dataFile .open("data.txt");
sortData(classData,0,n);
while (!dataFile.eof())
{
getline(dataFile,String);
cout<<String<<endl;
}
dataFile.close();
}

    return 0;
}