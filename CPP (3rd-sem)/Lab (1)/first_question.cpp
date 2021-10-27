#include <iostream>
using namespace std;
int main()
{
    int year1;
    int year2;
    int numYears;
    float arr[100][100];
    int i;
    int j;
    float yearlyAverage[100];
    float k=0;
    float totalAverage;
    cout<<"Enter the range of years to be calculated : "<<endl;
    cout<<"Enter starting year: "<<endl;
    cin>>year1;
    cout<<"Enter last year for calculation: "<<endl;
    cin>>year2;
    numYears=year2-year1+1;
    for (i=0;i<numYears;i++){
        cout<<"Enter expenditure for year "<<year1+i<<endl;
        for (j=0;j<12;j++){
            cout<<"Enter average expenditure for month "<<j+1<<endl;
            cin>>arr[i][j];
        }
    }
for (i=0;i<numYears;i++){
        for (j=0;j<12;j++){
        k+=arr[i][j];
        }
        k/=12;
        yearlyAverage[i]=k;
        k=0;
        }


cout<<"The yearly average for the given range of years is as below: "<<endl;

for (i=0;i<numYears;i++){
cout<<yearlyAverage[i]<<" ";
}
cout<<endl;

    cout<<"The average expenditure table is as shown below: "<<endl;
    for (i=0;i<numYears;i++){
        for (j=0;j<12;j++){
            cout<<arr[i][j]<<" ";
}
        cout<<endl;
        }

 return 0;
}
