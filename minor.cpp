
#include<iostream>
#include<bits/stdc++.h>
#include<string.h>

class Rider{
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
};
int main()
{
	Rider R[100];
	Passenger P[100];
	int d=0,choice,p=0;

    START:
    cout<<"Enter 1 to enter as a DRIVER"<<endl;
    cout<<"Enter 2 to enter as a PASSENGER"<<endl;
    cout<<"Enter 3 to EXIT the program"<<endl;
    cout<<"ENTER YOUR CHOICE : ";
    cin>>choice;
	switch(choice)
	{
		case 1:{
			
			R[d].input();
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

	}



