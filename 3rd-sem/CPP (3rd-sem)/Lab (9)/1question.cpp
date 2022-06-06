/*
Create a function called sum ( ) that returns the sum of the elements of an array. Make this function into a template so it will work with any numerical type. Write a main ( ) program that applies this function to data of various type.
*/
#include <iostream>
using namespace std;
template <typename T>
T sum(T arr[],int x){
        T sum=0;
    for (int i=0;i<x;i++){
        sum+=arr[i];
    }
    return sum;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    float arr_float[]={1,2,3,4,5,6,7,8,9.4};
    cout<<sum(arr,9)<<endl;
    cout<<sum(arr_float,9)<<endl;
    return 0;
}