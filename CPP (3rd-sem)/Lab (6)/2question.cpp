/*
2. Write two classes to store distances in meter-centimeter and feet-inch system respectively.
Write conversions functions so that the program can convert objects of both types.
*/

#include <iostream>
using namespace std;

#define meter_to_feet 3.281
#define feet_to_meter 0.3048

class m_cm;
class ft_in{
    private:
    float ft, in;
    public:
    ft_in(float ft, float in):ft(ft),in(in){};
    ft_in(float ft){
        ft=int(ft);
        in=int((ft-int(ft))*12);
    }
    float toFt_only(){
        return(ft+(in/12));
    }
    float toM_Cm(ft_in feet){
        float ft=feet.toFt_only();
        float metric(ft*feet_to_meter);
        return metric;
    }
    void display(){
        cout<<ft<<" feets "<<in<<" inches."<<endl;
    }
};

class m_cm{
    private:
    float m,cm;
    public:
    m_cm(float m, float cm):m(m),cm(cm){};
    m_cm(float m){
        m=int(m);
        cm=int((m-int(m))*100);
    }
    float toM_only(){
        return(m+(cm/100));
    }
    float toF_In(m_cm metric){
        float m=metric.toM_only();
        float feet=(m*meter_to_feet);
        return feet;
    }
    void display(){
        cout<<m<<" meters "<<cm<<" centimeters."<<endl;
    }
};

int main(){
    cout<<"Metric System: "<<endl;
    m_cm metric(23,32);
    cout<<"The data is: ";
    metric.display();
    cout<<"Data in only meters is: "<<metric.toM_only()<<" meters."<<endl;
    cout<<"Data in fps system is: "<<metric.toF_In(metric)<<" feets."<<endl;
    cout<<"FPS System: "<<endl;
    ft_in feet(23,32);
    cout<<"The data is: ";
    feet.display();
    cout<<"Data in only feets is: "<<feet.toFt_only()<<" feets."<<endl;
    cout<<"Data in metric system is: "<<feet.toM_Cm(feet)<<" meters."<<endl;
    return 0;
}