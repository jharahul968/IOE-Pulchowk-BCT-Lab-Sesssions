/*
5. Write base class that ask the user to enter a complex number and make a derived class that adds
the complex number of its own with the base. Finally make third class that is friend
of derived and calculate the difference of base complex number and its own complex number.
*/
#include <iostream>
using namespace std;

class complex
{
public:
    float real;
    float imag;
    void askReal()
    {
        cout << "Enter the real part of complex number: " << endl;
        cin >> real;
    }
    void askImag()
    {
        cout << "Enter the imaginary part of complex number: " << endl;
        cin >> imag;
    }
    void display()
    {
        cout << "The complex number is: " << real << " + i" << imag << endl;
    }
};

class complexInherited : public complex
{
public:
friend class complexFriend;
    void add(complex a)
    {
        cout << "The sum of complex numbers from base and inherited class is: " << a.real + real << " + i" << a.imag + imag << endl;
    }
};
class complexFriend
{
private:
    float real, imag;

public:
    void diff(complex a)
    {
        cout << "The difference of complex numbers from base and friend class is: " << a.real - real << " + i" << a.imag - imag << endl;
    }
    void askReal()
    {
        cout << "Enter the real part of complex number: " << endl;
        cin >> real;
    }
    void askImag()
    {
        cout << "Enter the imaginary part of complex number: " << endl;
        cin >> imag;
    }
    void display()
    {
        cout << "The complex number is: " << real << " + i" << imag << endl;
    }
};
int main()
{
    complex a;
    cout << "For base class: " << endl;
    a.askReal();
    a.askImag();
    a.display();
    complexInherited b;
    cout << "For inherited class: " << endl;
    b.askReal();
    b.askImag();
    b.display();
    b.add(a);
    complexFriend c;
    cout << "For friend class: " << endl;
    c.askReal();
    c.askImag();
    c.display();
    c.diff(a);
    return 0;
}