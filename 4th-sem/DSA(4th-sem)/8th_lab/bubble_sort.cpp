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
void bubbleSort(int arr[], int n){
    int i,j;
    for (i=0;i<n-1;i++){
        for (j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1])
            swap(&arr[j],&arr[j+1]);
        }
    }
}
void printArr(int arr[],int size){
    int i;
    for (i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={5,424,43,21,4,43,52,2,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    cout<<"Sorted Array: "<<endl;
    printArr(arr,n);
}