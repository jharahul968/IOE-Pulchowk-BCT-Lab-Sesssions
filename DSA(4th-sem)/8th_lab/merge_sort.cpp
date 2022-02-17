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
    for (i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void merge(int arr[], int left, int mid, int right){
    int subArrayOne=mid-left+1;
    int subArrayTwo=right-mid;
    int leftArray[subArrayOne];
    int rightArray[subArrayTwo];

    for (int i=0;i<subArrayOne;i++)
        leftArray[i]=arr[left+i];
    
    for (int j=0;j<subArrayTwo;j++)
        leftArray[j]=arr[mid+1+j];
    

    int subArrayOneIndex=0;
    int subArrayTwoIndex=0;
    int mergedArrayIndex=left;
    while (subArrayOneIndex<subArrayOne && subArrayTwoIndex<subArrayTwo){
        if (leftArray[subArrayOneIndex]<=rightArray[subArrayTwoIndex]){
            arr[mergedArrayIndex]=leftArray[subArrayOneIndex];
            subArrayOneIndex++;
        }
        else{
            arr[mergedArrayIndex]=rightArray[subArrayTwoIndex];
            subArrayTwoIndex++;
        }
        mergedArrayIndex++;
    }
    while (subArrayOneIndex<subArrayOne){
        arr[mergedArrayIndex]=leftArray[subArrayOneIndex];
        subArrayOneIndex++;
        mergedArrayIndex++;
    }
    while (subArrayTwoIndex<subArrayTwo){
        arr[mergedArrayIndex]=rightArray[subArrayTwoIndex];
        subArrayTwoIndex++;
        mergedArrayIndex++;
    }
}
void mergeSort(int arr[], int begin, int end){
    if (begin<end){
    int mid=begin+(end-begin)/2;
    mergeSort(arr,begin,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,begin,mid,end);
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    cout<<"Sorted Array: "<<endl;
    printArr(arr,n);
}