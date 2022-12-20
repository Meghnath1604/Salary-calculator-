#include<iostream>
#include<fstream>
#include<string>
#include<bits/stdc++.h>
#include</home/bucky/Codes/Basic Project/calclass.cpp>
using namespace std;
void logo(){
    
 cout<<"VIATRIX";
 cout<<endl;
 cout<<endl;
 cout<<endl;
 cout<<endl;

}
float tcalculate(float basesal,float hrsworked,float overtimehrs,float overtimesal, float bonus){
    overtimesal=overtimesal/100;
    float reghrs=hrsworked-overtimehrs;
    float mbase=reghrs*basesal;
    bonus=(bonus/100)*mbase;
    float tsal=reghrs*basesal+(overtimehrs*(overtimesal*basesal)+bonus);
    return tsal;
}
float gcalculate(float pf,float tsal){
    float gsal=tsal+tsal*pf;
    return gsal;
}
void takeinput(){
    string Name,id;
    cout<<"Employ ID:"<<endl;
    cin>>id;
    cout<<"Name:"<<endl;
    cin.get();
    getline(cin,Name);
    salary sal;
    cout<<"Enter number of hours worked in a month: "<<endl;
    cin>>sal.hrsworked;
    cout<<"Base Salary perhour: "<<endl;
    cin>>sal.basesal;
    cout<<"Overtime hours:"<<endl;
    cin>>sal.overtimehrs;
    if (sal.overtimehrs)
    {
        cout<<"Overtime rate in %:"<<endl;
        cin>>sal.overtimesal;
    }
    cout<<"Monthly bonus in %..."<<endl;
    cin>>sal.bonus;
    sal.pf=0.125;
    float totalsal=tcalculate(sal.basesal,sal.hrsworked,sal.overtimehrs,sal.overtimesal,sal.bonus);
    float grossSal= gcalculate(sal.pf,totalsal);
    cout<<"Your required record"<<endl<<endl;
    cout<<"Employee ID:"<<id<<endl<<endl;
    cout<<"Name:"<<Name<<endl<<endl;
    cout<<"Total Salary; "<<totalsal<<endl<<endl;
    cout<<"Provident Fund: "<<sal.pf*totalsal<<endl<<endl;
    cout<<"Gross Salary: "<<grossSal<<endl<<endl;
    float reghrs=sal.hrsworked-sal.overtimehrs;
    ofstream sout;
    sout.open("sal.txt", ios::app);
    sout<<endl;
    sout<<" Emplyee ID: "+id<<endl;
    sout<<" Name: "+Name<<endl;
    sout<<"Total working hours: "<<sal.hrsworked<<endl;
    sout<<"Overtime hours: "<<sal.overtimehrs<<endl;
    sout<<"Base salary per month: "<<reghrs*sal.basesal<<endl;
    sout<<"Total salary: "<<totalsal<<endl;
    sout<<"Provident fund: "<<sal.pf*totalsal<<endl;
    sout<<"Gross salary: "<<grossSal<<endl;
    sout<<endl;
    sout.close();
    cout <<endl;
    cout<<"     "<<"Your Data has been saved to file...."<<endl;

}
void displayall(){
    salary sal;
    string name,id,thrs,ohrs,msal,tsal,gsal,pf;
    ifstream sin;
    sin.open("sal.txt");
    while (!sin.eof())
    {
        sin.get();
        sin.ignore();
        getline(sin,id);
        getline(sin,name);
        getline(sin,thrs);
        getline(sin,ohrs);
        getline(sin,msal);
        getline(sin,tsal);
        getline(sin,pf);
        getline(sin,gsal);
        sin.ignore();
        
        cout<<endl;
        cout<<id<<endl;
        cout<<name<<endl;
        cout<<thrs<<endl;
        cout<<ohrs<<endl;
        cout<<msal<<endl;
        cout<<tsal<<endl;
        cout<<pf<<endl;
        cout<<gsal<<endl;
    }
    sin.close();
}
int main()
{
    logo();
    cout<<"     "<<"Welcome to Salary Calculator"<<endl<<endl<<endl;
        cout<<" "<<"-> 1. Calculate Salary..."<<endl<<endl;
        cout<<" "<<"-> 2. Display whole record..."<<endl<<endl;
        cout<<" "<<"-> 3. Exit..."<<endl<<endl;

    while (1)
    {
        int ch;
        cout<<"   "<<"Please enter your option(1-3)"<<endl;
        cout<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            takeinput();
            break;
        case 2:
            displayall();
            break;
        case 3:
            cout<<"   "<<"Good Bye!!!.."<<endl;
            exit(0);
        default:
            cout<<"You entered invalid option!!!!..."<<endl;
        }
    }
    
    return 0;
}
