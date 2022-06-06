//concept to be used is namespace
#include <iostream>
using namespace std;
namespace Square
{
    int num;
    int fun(int x)
    {
        return x*x;
    }
} // namespace Square
namespace Cube
{
    int num;
    int fun(int x)
    {
        return x*x*x;
    }
} // namespace Cube
int main()
{
    Square::num=12;
    Cube::num=13;
    cout<<"Square of num of cube function: "<<Square::fun(Cube::num)<<endl;
    cout<<"Cube of num of square function: "<<Cube::fun(Square::num)<<endl;    
return 0;
}

