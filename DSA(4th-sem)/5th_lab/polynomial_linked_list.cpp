// SINGLY LINKED LIST(CONTD..)
// WRITE AN ALGORITHM AND PROGRAM FOR THE FOLLOWING:
// 1. IMPLEMENT STACK AS LINKED LIST
// 2. IMPLEMENT QUEUE AS LINKED LIST
// 3. REPRESENT THE POLYNOMIAL EQUATION USING LINKED LIST TO PERFORM
// ADDITION OF TWO POLYNOMIALS.

#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct node
{
    int coeff, power;
    struct node *next;
};
class Equation
{
public:
    node *start;
    Equation()
    {
        start = NULL;
    }
    void create(int a, int b)
    {
        node *temp = start;
        if (temp == NULL)
        {
            temp = new node();
            start = temp;
        }
        else
        {
            while (temp->next != NULL)
                temp = temp->next;
        }
        temp->coeff = a;
        temp->power = b;
        temp->next = new node();
        temp = temp->next;
        temp->next = NULL;
    }
    void show()
    {
        node *temp = start;
        while (temp->next != NULL)
        {
                cout << temp->coeff << "x^" << temp->power;
                temp = temp->next;
                if (temp->coeff >= 0)
                {
                    if (temp->next != NULL)
                        cout << "+";
                }
        }
    }
};
    void add(Equation *e1,Equation *e2,Equation *result)
    {
        node *temp1=e1->start;
        node *temp2=e2->start;
        while(temp1->next && temp2->next){
            if (temp1->power > temp2->power){
                result->create(temp1->coeff,temp1->power);
                temp1=temp1->next;
            }
            else if(temp1->power<temp2->power){
                result->create(temp2->coeff,temp2->power);
                temp2=temp2->next; 
            }
            else{
                result->create(temp1->coeff+temp2->coeff,temp1->power);
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        while(temp1->next || temp2->next){
            if (temp1->next){
            result->create(temp1->coeff,temp1->power);
            temp1=temp1->next;
            }
            if (temp2->next){
            result->create(temp2->coeff,temp2->power);
            temp2=temp2->next;
            }
        }
        // result->show();
    }

int main()
{
    // Equation e,f,g;
    // e.create(2,3);
    // e.create(3,2);
    // f.create(3,2);
    // add(&e,&f,&g);
    // g.show();
    Equation e1,e2,e;
    bool flag=0;
    while(!flag){
        int choice,c,p;
    cout<<"Enter 1 to add coefficient and power to first polynomial equation."<<endl;
    cout<<"Enter 2 to add coefficient and power to second polynomial equation."<<endl;
    cout<<"Enter 3 to view first polynomial equation."<<endl;
    cout<<"Enter 4 to view second polynomial equation."<<endl;
    cout<<"Enter 5 to add first and second polynomial equations."<<endl;
    cout<<"Enter 6 to view resulting polynomial equation after addition."<<endl;
    cout<<"Enter any other key to terminate the program."<<endl;
    cout<<"Note: Enter the equation's roots strictly in descending order."<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter the coefficient: "<<endl;
        cin>>c;
        cout<<"Enter the power: "<<endl;
        cin>>p;
        e1.create(c,p);
        break;
        case 2:
        cout<<"Enter the coefficient: "<<endl;
        cin>>c;
        cout<<"Enter the power: "<<endl;
        cin>>p;
        e2.create(c,p);
        break;
        case 3:
        cout<<"First Polynomial Equation: "<<endl;
        e1.show();
        cout<<endl;
        break;
        case 4:
        cout<<"Second Polynomial Equation: "<<endl;
        e2.show();
        cout<<endl;
        break;
        case 5:
        cout<<"Addition in process..."<<endl;
        add(&e1,&e2,&e);
        cout<<"Addition finished."<<endl;
        break;
        case 6:
        cout<<"Resulting Polynomial Equation: "<<endl;
        e.show();
        cout<<endl;
        break;
        default:
        cout<<"Program terminated."<<endl;
        flag=1;
        break;
    }
}
}