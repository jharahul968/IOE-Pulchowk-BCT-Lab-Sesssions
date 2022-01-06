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
private:
    node *start;

public:
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
    void add(Equation *e1,Equation *e2)
    {
        Equation *result;
        while(e1->start->next && e2->start->next){
            if (e1->start->power>e2->start->power){
                result->start->power=e1->start->power;
                result->start->coeff=e1->start->coeff;
                e1->start=e1->start->next;
            }
            else if(e1->start->power<e2->start->power){
                result->start->power=e2->start->power;
                result->start->coeff=e2->start->coeff;
                e2->start=e2->start->next; 
            }
            else{
                result->start->power=e1->start->power;
                result->start->coeff=e1->start->coeff+e2->start->coeff;
                e1->start=e1->start->next;
                e2->start=e2->start->next;
            }
            result->start->next=new node();
            result->start=result->start->next;
            result->start->next=NULL;
        }
        while(e1->start->next || e2->start->next){
            if (e1->start->next){
            result->start->power=e1->start->power;
            result->start->coeff=e1->start->coeff;
            e1->start=e1->start->next;
            }
            if (e2->start->next){
            result->start->power=e2->start->power;
            result->start->coeff=e2->start->coeff;
            e2->start=e2->start->next;
            }
            result->start->next=new node();
            result->start=result->start->next;
            result->start->next=NULL;
        }
        result->show();
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
int main()
{
    Equation e,f,g;
    e.create(2,3);
    e.create(3,2);
    e.show();
    f.create(3,2);
    f.show();
    g.add(&e,&f);
}