// LAB #9: SORTING 
// WAP to sort given data using following algorithms: 
// a. Bubble Sort b. Selection Sort c. Insertion Sort d. Quick Sort e. Shell Sort f. Merge Sort g. Radix Sort 
// LAB #10: SEARCHING 
// WAP to search given "key" from set of data using following algorithms: 
// a. Linear Search b. Binary Search (iterative method + recursive method)

#include <iostream>
#include <conio.h>
using namespace std;

int binary_search(int arr[], int left, int right, int x){
    if (right>=left){
        int mid=left+(right-left)/2;
        if (arr[mid]==x)
        return mid;
        if (arr[mid]>x)
        return binary_search(arr,left,mid-1,x);
        return binary_search(arr,mid+1,right,x);
    }
    return -1;
}

int main(){
    int arr[]={2, 3, 4, 10, 40};
    int x=10;
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=binary_search(arr,0,n-1,x);
    (result==-1)?cout<<"Element not present in given array.":cout<<"Required index: "<<result;
}