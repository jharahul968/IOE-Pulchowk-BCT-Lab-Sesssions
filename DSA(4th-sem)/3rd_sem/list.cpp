//1.	WAP TO INSERT AND DELETE IN A LIST.

#include <iostream>
using namespace std;

const int MAXSIZE=5;
int avail=0,list1=-1;//avail points to the available node in the array node and list1 points to the first node of the created list

template <class T>
struct nodetype{
    T info;
    int next;
};

template <class T>
int findIndex(nodetype<T>*node,T refe)//this function finds the array_index of the node containing the reference element in array of nodes
{
    int node_index=list1;
    while(true)
    {
       if(refe==node[node_index].info)//this finds the index of the element if it is present
        break;
       else if(node_index==-1)//if the reference element is not in the list then at last node the next field is -1 and marks the end of iteration
        break;
       node_index=node[node_index].next;
    }
    return node_index;
}

template <class T>
void initialOrdering(nodetype<T>*node)//ordering the array of nodes so that each points to the consecutive node
{
    for(int i=0;i<MAXSIZE-1;i++)
        node[i].next=i+1;
    node[MAXSIZE-1].next=-1;
}

template <class T>
int getnode(nodetype<T>*node,T input)
{
    int node_index;
    if(avail==-1)
        throw "Overflow";
    node_index=avail;
    avail=node[avail].next;
    node[node_index].info=input;
    node[node_index].next=-1;
    return node_index;
}

template <class T>
void freenode(nodetype<T>*node,int node_index)//node_index points to the array index of the node which is to be deleted from the list
{
    node[node_index].next=avail;
    avail=node_index;
    if(node_index==list1)//if the node is the only one node present
        list1=-1;
}

template <class T>
void InsertBeg(nodetype<T>*node,T input)
{
    int index;
    index=getnode(node,input);
    node[index].next=list1;
    list1=index;
}

template <class T>
void insafter(T refe,T input,nodetype<T>*node)
{
    int q,i;
    i=findIndex(node,refe);
    if(i==-1)
        throw "Reference element is not present";
    q=getnode(node,input);
    node[q].next=node[i].next;
    node[i].next=q;
}

template <class T>
void InsertEnd(nodetype<T>*node,T input)
{
    int index,i;
    if(list1==-1)
    {
        InsertBeg(node,input);
    }
    else
    {
        index=getnode(node,input);
        i=list1;
        while(node[i].next!=-1)
        {
            i=node[i].next;
        }
        node[i].next=index;
    }
}

template <class T>
T DeleteBeg(nodetype<T>*node)
{
    T removed_item;
    int index;
    if(list1==-1)
        throw "Underflow";
    index=list1;
    list1=node[list1].next;
    removed_item=node[index].info;
    freenode(node,index);
    return removed_item;
}

template <class T>
T delafter(T refe,struct nodetype<T>*node)
{
    int q,i;
    T removed_item;
    if(list1==-1)
        throw "Underflow";
    i=findIndex(node,refe);
    if(i==-1)
        throw "Reference element is not present in the list";
    q=node[i].next;
    if(q==-1)//if the refe is the last element of the list
        throw "No item after the reference element\n";
    removed_item=node[q].info;
    node[i].next=node[q].next;
    freenode(node,q);
    return removed_item;
}

template <class T>
T DeleteEnd(nodetype<T>*node)
{
    T removed_item;
    if(list1==-1)
        throw "Underflow";
    int index,i=list1,q;
    while(node[i].next!=-1)
    {
        q=i;
        i=node[i].next;
    }
    index=i;
    removed_item=node[index].info;
    freenode(node,index);
    node[q].next=-1;
    return removed_item;
}

template <class T>
void Display(nodetype<T>*node)
{
    int pt;
    pt=list1;//start from first element of the list
    if(pt==-1)//empty condition
        cout<<"No items in the list\n";
    else
    {
        cout<<"List items : ";
        while(pt!=-1)//till last node
    {
        cout<<node[pt].info<<" ";
        pt=node[pt].next;
    }
    }
}

int main()
{
    nodetype<int>node[MAXSIZE];
    initialOrdering(node);
    int choice,input,first_node,reference_elem;
    cout<<"Static List\n";
    while(true)
    {
        try{
            cout<<"\n1.Insert Beg\t2.Insert after\t3.Insert end\n4.Delete Beg\t5.Delete after\t6.Delete End\t7.exit\n\n";
            Display(node);
            cout<<"\nEnter the operation to perform :";
            cin>>choice;
                switch(choice)
            {
            case 1:
                cout<<"Enter the element to insert :";
                cin>>input;
                InsertBeg(node,input);
                break;
            case 2:
                if(list1==-1)//for adding the first node of the list
                {
                    cout<<"Enter the element to insert :";
                    cin>>input;
                    InsertBeg(node,input);
                }
                else
                {
                    cout<<"Enter the element to insert :";
                    cin>>input;
                    cout<<"Enter after which element to insert :";
                    cin>>reference_elem;
                    insafter(reference_elem,input,node);
                }
                break;
            case 3:
                cout<<"Enter the element to insert :";
                cin>>input;
                InsertEnd(node,input);
                break;
            case 4:
                cout<<"Deleted item from the front is "<<DeleteBeg(node)<<endl;
                break;
            case 5:
                if(node[list1].next==-1)//if we have only the starting node in our list
                {
                    cout<<"no element after ref element";
                    //cout<<"Only one item in the list\n";
                  //  cout<<"The deleted item is "<<node[list1].info;
                   // freenode(node,list1);
                   // list1=-1;
                }
                else if(list1!=-1)//if the list is not empty
                {
                    cout<<"Enter after which element to delete : ";
                    cin>>input;
                    cout<<"The deleted item is "<<delafter(input,node)<<endl;
                }
                else
                    throw "List is empty";
                break;
            case 6:
                cout<<"Deleted item from the end is "<<DeleteEnd(node)<<endl;
                break;
            case 7:
                exit(1);
            }
        }
        catch(const char *message)
        {
            cerr<<message<<endl;
        }
    }
    return 0;
}