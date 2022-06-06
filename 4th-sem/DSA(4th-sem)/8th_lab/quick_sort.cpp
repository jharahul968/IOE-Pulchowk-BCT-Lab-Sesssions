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
int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=low-1;
    for (int j=low;j<high;j++){
        if (arr[j]<pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}
void quickSort(int arr[], int low, int high){
    if (low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int arr[]={5,424,43,21,4,43,52,2,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    cout<<"Sorted Array: "<<endl;
    printArr(arr,n);
}