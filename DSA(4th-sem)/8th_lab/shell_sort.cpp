// LAB #9: SORTING 
// WAP to sort given data using following algorithms: 
// a. Bubble Sort b. Selection Sort c. Insertion Sort d. Quick Sort e. Shell Sort f. Merge Sort g. Radix Sort 
// LAB #10: SEARCHING 
// WAP to search given "key" from set of data using following algorithms: 
// a. Linear Search b. Binary Search (iterative method + recursive method)

#include <iostream>
#include <cstdlib>
using namespace std;

void printArr(int arr[],int size){
    int i;
    for (i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void shellSort(int arr[], int n){
    for (int gap=n/2;gap>0;gap/=2){
        for (int i=gap;i<n;i++){
            int temp=arr[i];
            int j;
            for (j=i;j>=gap && arr[j-gap]>temp;j-=gap)
            arr[j]=arr[j-gap];
            arr[j]=temp;
        }
    }
}

int main(){
    int arr[]={5,424,43,21,4,43,52,2,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    shellSort(arr,n);
    cout<<"Sorted Array: "<<endl;
    printArr(arr,n);
}