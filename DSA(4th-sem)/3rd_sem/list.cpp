//WRITE AN ALGORITHM AND PROGRAM FOR FOLLOWING CASES IN LIST (STATIC IMPLEMENTATION)

// a. INSERTION OPERATIONS
//     i. INSERT NODE AT BEGINNING OF THE LIST
//     ii. INSERT NODE AT END OF THE LIST
//     iii. INSERT NODE AFTER SPECIFIC NODE
// b. DELETION OPERATIONS
//     i. DELETE NODE FROM BEGINNING OF THE LIST
//     ii. DELETE NODE FROM END OF THE LIST
//     iii. DELETE NODE AFTER SPECIFIC NODE

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define size 10
using namespace std;
struct Node {
    int data,next;
};
class List{
    private:
    int avail=-1;
    int start;
    struct Node node[size];
    int getnode(){
        int a;
        if (avail==-1){
            cout<<"Overflow."<<endl;
            exit(1);
        }
        a=avail;
        avail=node[avail].next;
        return a;
    }
    void freenode(int a){
        node[a].next=avail;
        avail=a;
        return;
    }
    void init(){
        avail=0;
        for (int i=0;i<size-1;i++){
            node[i].next=i+1;
        }
        node[size-1].next=-1;
    }
    public:
    List(int a){
        init();
        start=getnode();
        node[start].data=a;
        node[start].next=-1;
    }
    void insafter(int a,int x){
        int q;
        if (a==-1){
        cout<<"Void Insertion."<<endl;
        return;
    }
    q=getnode();
    node[q].data=x;
    node[q].next=node[a].next;
    node[a].next=q;
    return;
    }
    void delafter(int p,int* px){
        int q;
        if ((p==-1) || (node[p].next==-1)){
            cout<<"Void deletion."<<endl;
            //return;
        }
        q=node[p].next;
        *px=node[q].data;
        node[p].next=node[q].next;
        freenode(q);
        //return;
    }
    void insertAfter(int data,int value){
        int t=start;
        while(node[t].data!=data){
            if (t==-1)
            cout<<"No such node."<<endl;
            t=node[t].next;
        }
        insafter(t,value);
    }
    void deleteAfter(int data,int* ret){
        int t=start;
        while(node[t].data!=data){
            if (t==-1)
            cout<<"No such node."<<endl;
            t=node[t].next;
        }
        delafter(t,ret);
    }
};
int main(){
    List list(2);
    list.insertAfter(2,3);
    list.insertAfter(3,69);
    int p=0;
    list.deleteAfter(2,&p);
    cout<<p;
    return 0;
}