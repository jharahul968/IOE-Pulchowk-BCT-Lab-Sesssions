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
void merge(int arr[], int const left, int const mid, int const right){
    int const subArrayOne=mid-left+1;
    int const subArrayTwo=right-mid;
    int *leftArray=new int[subArrayOne];
    int *rightArray=new int[subArrayTwo];
    for (int i=0;i<subArrayOne;i++){
        leftArray[i]=arr[left+i];
    }
    for (int i=0;i<subArrayTwo;i++){
        leftArray[i]=arr[mid+1+i];
    }
    int subArrayOneIndex=0;
    int subArrayTwoIndex=0;
    int mergedArrayIndex=left;
}
void mergeSort(int arr[], int low, int high){
}

int main(){
    int arr[]={5,424,43,21,4,43,52,2,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,n);
    cout<<"Sorted Array: "<<endl;
    printArr(arr,n);
}