/*
Write a program for transaction processing that write and read object randomly to and
from a random access file so that user can add, update, delete and display the
account information (account-number, last-name, first-name, total-balance).
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Transaction{
    private:
    int account_number,total_balance;
    string first_name,last_name;
    public:
    Transaction(){};
    Transaction(int an,string ln,string fn,int tb):account_number(an),last_name(ln),first_name(fn),total_balance(tb){};
    friend ostream& operator<<(ostream &out,Transaction &t);
    friend istream& operator>>(istream &in,Transaction &t);
};
istream& operator>>(istream& in,Transaction &tr){
    cout<<"Enter information about transactions: "<<endl;
    cout<<"Enter account number: ";
    in>>tr.account_number;
    cout<<"Enter last name: ";
    in>>tr.last_name;
    cout<<"Enter first name: ";
    in>>tr.first_name;
    cout<<"Enter total balance: ";
    in>>tr.total_balance;
    return in;
}
ostream& operator<<(ostream& out,Transaction &tr){
    cout<<endl<<"The account information is: "<<endl;
    cout<<"Account number: ";
    out<<tr.account_number;
    cout<<"Last name: ";
    out<<tr.last_name;
    cout<<"First name: ";
    out<<tr.first_name;
    cout<<"Total balance: ";
    out<<tr.total_balance;
    return out;
}
int main(){
    int root_ans;
    char root_ans1;
    do{
    fstream file;
    cout<<"The operations which can be performed are: "<<endl;
    cout<<"1. Add account information."<<endl;
    cout<<"2. Update account information."<<endl;
    cout<<"3. Delete account information."<<endl;
    cout<<"3. Edit account information."<<endl;
    cout<<"5. Display account information."<<endl;
    int ans;
    cout<<"Choose an operation you want to perform from above: (1/2/3/4/5) ";
    cin>>ans;
    if (ans==1){
        char ans;
        file.open("transaction.dat",ios::binary|ios::out);
        do{
            Transaction tr;
            cin>>tr;
            file.write(reinterpret_cast<char *>(&tr),sizeof(tr));
            if (!file)
            cerr<<"Cannot write in the file."<<endl;
            return 1;
            cout<<"Do you want to enter more data? (y/n)"<<endl;
            cin>>ans;
        }while(ans=='y' || ans=='Y');
        file.close();
    }
    else if (ans==2){
        char ans;
        file.open("transaction.dat",ios::binary|ios::out|ios::app);
        do{
            Transaction tr;
            cin>>tr;
            file.write(reinterpret_cast<char *>(&tr),sizeof(tr));
            if (!file)
            cerr<<"Cannot modify in the file."<<endl;
            return 2;
            cout<<"Do you want to modify more data? (y/n)"<<endl;
            cin>>ans;
        }while(ans=='y' || ans=='Y');
        file.close();
    }
    else if (ans==3){

        do{
        char ans;
        Transaction tr;
        file.open("transaction.dat",ios::binary|ios::in);
        fstream new_file;
        new_file.open("new_transaction.dat",ios::binary|ios::in);
        if (!new_file)
        cerr<<"Cannot create in the file."<<endl;
        while (!file.eof()){
            file.read(reinterpret_cast<char *>(&tr),sizeof(tr));
            if (file){
                cout<<tr;
                cout<<"Do you want to delete this record? (y/n)"<<endl;
                cin>>ans;
                if (ans!='y' || ans!='Y'){
                    new_file.write(reinterpret_cast<char *>(&tr),sizeof(tr));
                    if (!new_file){
                        cerr<<"Cannot write in temp file.";
                        return 3;
                    }
                }
                else{
                    cout<<"Record Deleted."<<endl;
                }

            }
        }
        file.close();
        new_file.close();
        remove("transaction.dat");
        rename("new_transaction.dat","transaction.dat");
            cout<<"Do you want to delete more data? (y/n)"<<endl;
            cin>>ans;
        }while(ans=='y' || ans=='Y');
    }
    else if(ans==4){
        char ans;
        file.open("transaction.dat",ios::in|ios::binary|ios::out);
        while(!file.eof()){
            Transaction tr;
            int pos=file.tellg();
            file.read(reinterpret_cast<char *>(&tr),sizeof(tr));
            if (file){
                cout<<tr;
                cout<<"Do you want to edit the data? (y/n)"<<endl;
                cin>>ans;
                if (ans=='y' || ans=='Y'){
                    cin>>tr;
                    file.seekp(pos);
                    file.write(reinterpret_cast<char *>(&tr),sizeof(tr));
                    if (file){
                        cout<<"Data edited successfully."<<endl;
                    }
                    else{
                        cerr<<"Cannot edit the data.";
                        return 4;
                    }
                }
            }
        }
        file.close();
    }
    else if(ans==5){
        file.open("transaction.dat",ios::in|ios::binary);
        while(!file.eof()){
            Transaction tr;
            file.read(reinterpret_cast<char *>(&tr),sizeof(tr));
            if (file){
                cout<<tr;
            }
            else{
                cerr<<"Cannot display the file.";
                return 5;
            }
        }
        file.close();
    }
    cout<<"Do you want to continue operations? (y/n)"<<endl;
    cin>>root_ans1;
    }
    while(root_ans<=5 && root_ans>0 && (root_ans1!='y' || root_ans1!='Y'));
    return 0;
}