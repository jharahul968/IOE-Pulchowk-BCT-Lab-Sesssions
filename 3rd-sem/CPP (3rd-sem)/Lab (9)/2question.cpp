/*
Write a class template for queue class. Assume the programmer using the queue won't 
make mistakes, like exceeding the capacity of the queue, or trying to remove an item
when the queue is empty. Define several queues of different data types and insert
and remove data from them.
*/
#include <iostream>
using namespace std;
template <typename T>
class queue{
    private:
    T arr[100];
    int position;
    public:
    queue(){
        position=0;
        for (int i=0;i<100;i++)
        arr[i]=0;
    }
    void add(T data){
        arr[position]=data;
        position++;
    }
    T get(){
        T data=arr[0];
        for (int i=0;i<position;i++){
            arr[i]=arr[i+1];
        }
        position--;
        return data;
    }
};
int main(){
    queue<int> list2;
    list2.add(1);
    list2.add(2);
    cout<<list2.get()<<endl;
    cout<<list2.get()<<endl;
    queue<float> list1;
    list1.add(1.1);
    list1.add(2.1);
    cout<<list1.get()<<endl;
    cout<<list1.get()<<endl;
    return 0;
}