#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
class Driver
{
public:
    string name,cno;
    long long int ano;
    int nos,age,price;
    string origin,destination;
    int stdr,destdr;

    void input()
    {
        //Accepting details of customers
        cout<<"Enter the required details..."<<endl;
        cout<<"NAME : ";
        cin>>name;
        cout<<"AGE : ";
        cin>>age;
        cout<<"AADHAR CARD NUMBER : ";
        cin>>ano;
        cout<<"CAR NUMBER : ";
        cin>>cno;
        cout<<"ORIGIN : ";
        cin>>origin;
        transform(origin.begin(), origin.end(), origin.begin(), ::toupper);
        cout<<"DESTINATION : ";
        cin>>destination;
        transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
        cout<<"SEATS AVAILABLE : ";
        cin>>nos;
        cout<<"PRICE (per Km) : ";
        cin>>price;
        cout<<endl;
        cout<<"************************************************"<<endl;
    }
    void display()
    {
        //Details displayed
        cout<<"NAME : "<<name<<endl;
        cout<<"AGE : "<<age<<endl;
        cout<<"ORIGIN : "<<origin<<endl;
        cout<<"DESTINATION : "<<destination<<endl;
        cout<<"AVAILABLE SEATS : "<<nos<<endl;
        cout<<"PRICE (per Km) : "<<price<<endl;
        cout<<endl;
        cout<<"************************************************"<<endl;
    }
};

class Passenger
{
public:
    string pname;
    long long int ano;
    int nop,age,price;
    string origin,destination;
    int stp,destp;

    void input()
    {
        cout<<"Enter the required details..."<<endl;
        cout<<"NAME : ";
        cin>>pname;
        cout<<"AGE : ";
        cin>>age;
        cout<<"AADHAR CARD NUMBER : ";
        cin>>ano;
        cout<<"ORIGIN : ";
        cin>>origin;
        transform(origin.begin(), origin.end(), origin.begin(), ::toupper);
        cout<<"DESTINATION : ";
        cin>>destination;
        transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
        cout<<"TOTAL PASSENGERS : ";
        cin>>nop;
        cout<<endl;
        cout<<"*************************************************"<<endl;

    }
    void display()
    {
        cout<<"NAME : "<<pname<<endl;
        cout<<"AGE : "<<age<<endl;
        cout<<"ORIGIN : "<<origin<<endl;
        cout<<"DESTINATION : "<<destination<<endl;
        cout<<"TOTAL PASSENGERS : "<<nop<<endl;
        cout<<endl;
        cout<<"*************************************************"<<endl;
    }
};
int main()
{
    Driver D[100];
    Passenger P[100];
    string Loc[] = {"COLLEDGE","PONDA","NANDA_KI_CHAUKI","PREMNAGAR","BALLUPUR","CLOCK_TOWER","BUDDHA_CHOCK","DWARIKA","SURVEY_CHOCK","SHASTRADHARA CROSSING","RING_ROAD"};
    int choice,d=0,p=0,confirmchoice;
    // d is serial of driver and p is for passenger
    int flag=0;
    // flag we are using to check wheather a ride confirm or not


    cout<<":::<====WELCOME TO THE RIDE SHARE====>:::"<<endl;
    START:
        confirmchoice=0,flag=0;
    cout<<"Enter 1 to enter as a DRIVER"<<endl;
    cout<<"Enter 2 to enter as a PASSENGER"<<endl;
    cout<<"Enter 3 to EXIT the program"<<endl;
    cout<<"ENTER YOUR CHOICE : ";
    cin>>choice;
    cout<<"***********************************************"<<endl;
    cout<<endl;

    switch(choice)
    {
    case 1:
            {
                D[d].input();
                    for(int i=0;i<11;i++)
                    {
                         if(D[d].origin.compare(Loc[i]) == 0)
                            {
                                D[d].stdr = i;
                            }
                        if(D[d].destination.compare(Loc[i]) == 0)
                            {
                                D[d].destdr = i;
                            }
                    }
                d++;
                goto START;
            }

    case 2:
            {
                P[p].input();
                    for(int i=0;i<11;i++)
                    {
                         if(P[p].origin.compare(Loc[i]) == 0)
                            {
                                P[p].stp = i;
                            }
                        if(P[p].destination.compare(Loc[i]) == 0)
                            {
                                P[p].destp = i;
                            }

                    }

                break;
            }
    case 3:
        {
            goto EXIT;
        }

    default:
            {
                cout<<"INVALID CHOICE"<<endl;
                goto START;
            }
    }
    cout<<"==========> AVAILABLE RIDES <=========="<<endl;
    if(P[p].stp>P[p].destp)
    {
        for(int i=0;i<d;i++)
        {
            if(D[i].stdr > D[i].destdr && D[i].nos!=0)
            {
                if(P[p].stp<=D[i].stdr && P[p].destp>=D[i].destdr && P[p].nop<=D[i].nos )
                {
                    D[i].display();
                    cout<<"ENTER "<<i+1<<" TO CONFIRM YOUR RIDE WITH "<<D[i].name<<" OR 0 TO TO NOT CONFIRM IT"<<endl;
                    cout<<"*************************************************"<<endl;
                    D[i].display();
                    flag = 1;

                }
            }

        }
    }
    else
    {
        if(P[p].stp<P[p].destp)
        {
            for(int i=0;i<d;i++)
            {
                if(D[i].stdr < D[i].destdr && D[i].nos!=0)
                {
                    if(P[p].stp>=D[i].stdr && P[p].destp<=D[i].destdr && P[p].nop<=D[i].nos )
                    {
                        D[i].display();
                        cout<<"ENTER "<<i+1<<" TO CONFIRM YOUR RIDE WITH "<<D[i].name<<" OR 0 TO TO NOT CONFIRM IT"<<endl;
                        cout<<"*************************************************"<<endl;
                        flag = 1;

                    }

                }
            }
        }
    }
    if(flag == 1)
    {
        cin>>confirmchoice;
        if(confirmchoice != 0)
        {
            D[confirmchoice - 1].nos = D[confirmchoice - 1].nos - P[p].nop;
            cout<<"************************************************"<<endl;
            cout<<"YOUR RIDE WITH "<<D[confirmchoice-1].name<<" HAS BEN CONFIRMED"<<endl;
            cout<<"THANK YOU FOR USING RIDESHARE.HAVE A SAFE JOURNEY"<<endl;
            cout<<"                 DO VISIT AGAIN                 "<<endl;
            cout<<"************************************************"<<endl;
        }
        else
        {
            cout<<"************************************************"<<endl;
            cout<<"         THANK YOU FOR USING RIDESHARE.          "<<endl;
            cout<<"                 DO VISIT AGAIN                 "<<endl;
            cout<<"************************************************"<<endl;
        }

    }
    else
    {
        cout<<"SORRY...!!!!!NO RIDES AVAILABLE"<<endl;
        cout<<"PLEASE TRY AGIAN";
        cout<<"*************************************************"<<endl<<endl;
    }

    goto START;
    EXIT:
        cout<<"";
}








