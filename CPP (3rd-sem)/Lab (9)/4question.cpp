/*
Write any program that demonstrates the use of multiple catch handling, re-throwing
an exception, and catching all exception.
*/
#include <iostream>
using namespace std;
class ans_in_minus{};
class ans_invalid{};
int main(){
    int x,y;
    float ans;
    try{
        cout<<"x: ";
        cin>>x;
        cout<<"y: ";
        cin>>y;
        try{
            if (y<0)
            throw ans_in_minus();
            if (y==0)
            throw ans_invalid();
            ans=x/y;
        }
        catch (ans_in_minus){
            cerr <<"Answer in minus."<<endl;
            throw;
        }
        catch (ans_invalid){
            cerr<<"Dividing by zero invalid."<<endl;
            throw;
        }

    }
    catch (...){
        cerr<<"Exception.";
    }
    cout<<ans;
    return 0;
}