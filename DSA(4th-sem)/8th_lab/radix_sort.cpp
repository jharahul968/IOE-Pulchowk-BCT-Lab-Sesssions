// LAB #9: SORTING 
// WAP to sort given data using following algorithms: 
// a. Bubble Sort b. Selection Sort c. Insertion Sort d. Quick Sort e. Shell Sort f. Merge Sort g. Radix Sort 
// LAB #10: SEARCHING 
// WAP to search given "key" from set of data using following algorithms: 
// a. Linear Search b. Binary Search (iterative method + recursive method)

#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void printArr(int arr[],int size){
    int i;
    for (i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int getMax(int arr[], int n){
    int max=arr[0];
    for (int i=0;i<n;i++){
        if (arr[i]>max)
        max=arr[i];
    }
    return max;
}
void countSort(int arr[], int n, int exp){
    int output[n];
    int i, count[10]={0};
    for (i=0;i<n;i++)
    count[(arr[i]/exp)%10]++;
    for (i=1;i<10;i++)
    count[i]+=count[i-1];
    for (i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for (i=0;i<n;i++)
    arr[i]=output[i];
}
void radixSort(int arr[], int n){
    int max=getMax(arr,n);
    for (int e=1;max/e>0;e*=10)
    countSort(arr,n,e);
}

int main(){
    int arr[]={5,424,43,21,4,43,52,2,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);
    cout<<"Sorted Array: "<<endl;
    printArr(arr,n);
}