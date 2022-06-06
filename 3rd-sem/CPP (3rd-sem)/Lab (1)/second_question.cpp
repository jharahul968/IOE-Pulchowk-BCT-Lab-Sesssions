#include<iostream>
using namespace std;
int main()
{
    char sentence[]= "idea without execution is worthless";
    char toFind='c';
    int i=0,j=0;
    int index=0;
    int len=0;
    int positions[100];
    while (sentence[i]!='\0')
    {
        len+=1;
        i++;
    }

    for (i=0;i<len;i++)
    {
        if (sentence[i]==toFind)
        {
            positions[j]=i;
            j++;
        }


    }
    for (i=0;i<j;i++)
    {
    cout<<positions[i]<<" ";
    }

    return 0;
}
