/*
3. Create a class called Musicians to contain three methods string ( ), wind ( ) and perc ( ).
Each of these methods should initialize a string array to contain the following instruments
   -  veena, guitar, sitar, sarod and mandolin under string ( )
   -  flute, clarinet saxophone, nadhaswaram and piccolo under wind ( )
   -  tabla, mridangam, bangos, drums and tambour under perc ( )
It should also display the contents of the arrays that are initialized.
Create a derived class called TypeIns to contain a method called get ( ) and show ( ).
The get ( ) method must display a  menu as follows
Type of instruments to be displayed
a. String instruments
b. Wind instruments
c. Percussion instruments
The show ( ) method should display the relevant detail according to our choice. The base class variables
must be accessible only to its derived classes.
*/
#include <iostream>
#include <cstring>
using namespace std;
class Musicians{
   private:
   string string_[5];
   string wind[5];
   string perc[5];
   public:
   void string(){      //veena, guitar, sitar, sarod and mandolin
      string_[0]="veena";
      string_[1]="guitar";
      string_[2]="sitar";
      string_[3]="sarod";
      string_[4]="mandolin";
      cout<<"String Instruments: "<<endl;
      for (int i=0;i<5;i++){
         cout<<string_[i]<<endl;
      }
   }
   void winds(){        //flute, clarinet saxophone, nadhaswaram and piccolo
      wind[0]="flute";
      wind[1]="clarinet";
      wind[2]="saxophone";
      wind[3]="nadhaswaram";
      wind[4]="piccolo";
      cout<<"Wind Instruments: "<<endl;
      for (int i=0;i<5;i++){
         cout<<wind[i]<<endl;
      }
   }
   void percs(){         //tabla, mridangam, bangos, drums and tambour
      perc[0]="tabla";
      perc[1]="mridangam";
      perc[2]="bangos";
      perc[3]="drums";
      perc[4]="tambour";
      cout<<"Percussion Instruments: "<<endl;
      for (int i=0;i<5;i++){
         cout<<perc[i]<<endl;
      }
   }
};
class TypeIns:Musicians{
   public:
   void get(){
      cout<<"Type of instruments to be displayed: "<<endl;
      cout<<"a. String instruments"<<endl;
      cout<<"b. Wind instruments"<<endl;
      cout<<"c. Percussion instruments"<<endl;
   }
   void show(){
      string();
      winds();
      percs();
   }
};
int main(){
   TypeIns TI;
   TI.get();
   TI.show();
   return 0;
}