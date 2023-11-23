#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class Driver
{
public:
    string name, cno;
    long long int ano;
    int nos, age, price;
    string origin, destination;
    int stdr, destdr;

    void input()
    {
        // Accepting details of drivers
        cout << "Enter the required details..." << endl;
        cout << "NAME : ";
        cin >> name;
        cout << "AGE : ";
        cin >> age;
        cout << "AADHAR CARD NUMBER : ";
        cin >> ano;
        cout << "CAR NUMBER : ";
        cin >> cno;
        cout << "ORIGIN : ";
        cin >> origin;
        transform(origin.begin(), origin.end(), origin.begin(), ::toupper);
        cout << "DESTINATION : ";
        cin >> destination;
        transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
        cout << "SEATS AVAILABLE : ";
        cin >> nos;
        cout << "PRICE (per Km) : ";
        cin >> price;
        cout << endl;
        cout << "************************************************" << endl;
    }

    void display()
    {
        // Display details of drivers
        cout << "NAME : " << name << endl;
        cout << "AGE : " << age << endl;
        cout << "ORIGIN : " << origin << endl;
        cout << "DESTINATION : " << destination << endl;
        cout << "AVAILABLE SEATS : " << nos << endl;
        cout << "PRICE (per Km) : " << price << endl;
        cout << endl;
        cout << "************************************************" << endl;
    }

    // New method for writing data to a file
    void writeToFile(const string &fileName)
    {
        ofstream outFile(fileName, ios::app); // Open file in append mode

        if (outFile.is_open())
        {
            outFile << name << "," << age << "," << ano << "," << cno << "," << origin << "," << destination
                    << "," << nos << "," << price << "," << stdr << "," << destdr << endl;

            outFile.close();
        }
        else
        {
            cout << "Error opening file for writing: " << fileName << endl;
        }
    }

    // New method for reading data from a file
    void readFromFile(const string &fileName)
    {
        ifstream inFile(fileName);

        if (inFile.is_open())
        {
            inFile >> name >> age >> ano >> cno >> origin >> destination >> nos >> price >> stdr >> destdr;

            inFile.close();
        }
        else
        {
            cout << "Error opening file for reading: " << fileName << endl;
        }
    }
};

class Passenger
{
public:
    string pname;
    long long int ano;
    int nop, age, price;
    string origin, destination;
    int stp, destp;

    void input()
    {
        // Accepting details of passengers
        cout << "Enter the required details..." << endl;
        cout << "NAME : ";
        cin >> pname;
        cout << "AGE : ";
        cin >> age;
        cout << "AADHAR CARD NUMBER : ";
        cin >> ano;
        cout << "ORIGIN : ";
        cin >> origin;
        transform(origin.begin(), origin.end(), origin.begin(), ::toupper);
        cout << "DESTINATION : ";
        cin >> destination;
        transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
        cout << "TOTAL PASSENGERS : ";
        cin >> nop;
        cout << endl;
        cout << "*************************************************" << endl;
    }

    void display()
    {
        // Display details of passengers
        cout << "NAME : " << pname << endl;
        cout << "AGE : " << age << endl;
        cout << "ORIGIN : " << origin << endl;
        cout << "DESTINATION : " << destination << endl;
        cout << "TOTAL PASSENGERS : " << nop << endl;
        cout << endl;
        cout << "*************************************************" << endl;
    }

    // New method for writing data to a file
    void writeToFile(const string &fileName)
    {
        ofstream outFile(fileName, ios::app); // Open file in append mode

        if (outFile.is_open())
        {
            outFile << pname << "," << age << "," << ano << "," << origin << "," << destination
                    << "," << nop << "," << stp << "," << destp << endl;

            outFile.close();
        }
        else
        {
            cout << "Error opening file for writing: " << fileName << endl;
        }
    }

    // New method for reading data from a file
    void readFromFile(const string &fileName)
    {
        ifstream inFile(fileName);

        if (inFile.is_open())
        {
            inFile >> pname >> age >> ano >> origin >> destination >> nop >> stp >> destp;

            inFile.close();
        }
        else
        {
            cout << "Error opening file for reading: " << fileName << endl;
        }
    }
};

int main()
{
    Driver D[100];
    Passenger P[100];
    string Loc[] = {"COLLEGE", "PONDA", "NANDA_KI_CHAUKI", "PREMNAGAR", "BALLUPUR", "CLOCK_TOWER", "BUDDHA_CHOCK", "DWARIKA", "SURVEY_CHOCK", "SHASTRADHARA CROSSING", "RING_ROAD"};
    int choice, d = 0, p = 0, confirmchoice;
    int flag = 0;

    cout << ":::<====WELCOME TO THE RIDE SHARE====>:::" << endl;

    do
    {
        confirmchoice = 0, flag = 0;

        cout << "Enter 1 to enter as a DRIVER" << endl;
        cout << "Enter 2 to enter as a PASSENGER" << endl;
        cout << "Enter 3 to EXIT the program" << endl;
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;
        cout << "***********************************************" << endl;
        cout << endl;

        switch (choice)
        {
        case 1:
        {
            cout << "Are you a new user? (1 for Yes / 0 for No): ";
            int newUser;
            cin >> newUser;

            if (newUser == 1)
            {
                D[d].input();
                for (int i = 0; i < 11; i++)
                {
                    if (D[d].origin.compare(Loc[i]) == 0)
                    {
                        D[d].stdr = i;
                    }
                    if (D[d].destination.compare(Loc[i]) == 0)
                    {
                        D[d].destdr = i;
                    }
                }
                D[d].writeToFile("driver_details.txt"); // Write driver details to file
                d++;
            }
            else if (newUser == 0)
            {
                // For an old user, ask for name, source, and destination only
                cout << "Enter your name: ";
                cin >> D[d].name;
                cout << "Enter your source: ";
                cin >> D[d].origin;
                transform(D[d].origin.begin(), D[d].origin.end(), D[d].origin.begin(), ::toupper);
                cout << "Enter your destination: ";
                cin >> D[d].destination;
                transform(D[d].destination.begin(), D[d].destination.end(), D[d].destination.begin(), ::toupper);

                // Find index of source and destination in Loc array
                D[d].stdr = find(begin(Loc), end(Loc), D[d].origin) - begin(Loc);
                D[d].destdr = find(begin(Loc), end(Loc), D[d].destination) - begin(Loc);

                D[d].readFromFile("driver_details.txt"); // Read existing data from file

                d++;
            }

            break;
        }

        case 2:
        {
            cout << "Are you a new user? (1 for Yes / 0 for No): ";
            int newUser;
            cin >> newUser;

            if (newUser == 1)
            {
                P[p].input();
                for (int i = 0; i < 11; i++)
                {
                    if (P[p].origin.compare(Loc[i]) == 0)
                    {
                        P[p].stp = i;
                    }
                    if (P[p].destination.compare(Loc[i]) == 0)
                    {
                        P[p].destp = i;
                    }
                }
                P[p].writeToFile("passenger_details.txt"); // Write passenger details to file
                p++;
            }
            else if (newUser == 0)
            {
                // For an old user, ask for name, source, and destination only
                cout << "Enter your name: ";
                cin >> P[p].pname;
                cout << "Enter your source: ";
                cin >> P[p].origin;
                transform(P[p].origin.begin(), P[p].origin.end(), P[p].origin.begin(), ::toupper);
                cout << "Enter your destination: ";
                cin >> P[p].destination;
                transform(P[p].destination.begin(), P[p].destination.end(), P[p].destination.begin(), ::toupper);

                // Find index of source and destination in Loc array
                P[p].stp = find(begin(Loc), end(Loc), P[p].origin) - begin(Loc);
                P[p].destp = find(begin(Loc), end(Loc), P[p].destination) - begin(Loc);

                P[p].readFromFile("passenger_details.txt"); // Read existing data from file

                p++;
            }

            // Check if multiple rides are available for the passenger
            // If yes, prompt the passenger to choose which ride to book
            int availableRides = 0;
            for (int i = 0; i < d; i++)
            {
                if (P[p].stp > P[p].destp && D[i].stdr > D[i].destdr && D[i].nos != 0)
                {
                    if (P[p].stp <= D[i].stdr && P[p].destp >= D[i].destdr && P[p].nop <= D[i].nos)
                    {
                        availableRides++;
                        cout << "Ride " << availableRides << ":" << endl;
                        D[i].display();
                    }
                }
                else if (P[p].stp < P[p].destp && D[i].stdr < D[i].destdr && D[i].nos != 0)
                {
                    if (P[p].stp >= D[i].stdr && P[p].destp <= D[i].destdr && P[p].nop <= D[i].nos)
                    {
                        availableRides++;
                        cout << "Ride " << availableRides << ":" << endl;
                        D[i].display();
                    }
                }
            }

            if (availableRides > 1)
            {
                cout << "Enter the number of the ride you want to book: ";
                int rideChoice;
                cin >> rideChoice;

                if (rideChoice >= 1 && rideChoice <= availableRides)
                {
                    confirmchoice = rideChoice;
                }
                else
                {
                    cout << "Invalid ride choice. Booking not confirmed." << endl;
                    confirmchoice = 0;
                }
            }
            else if (availableRides == 1)
            {
                confirmchoice = 1;
            }
            else
            {
                confirmchoice = 0;
            }

            break;
        }

        case 3:
        {
            cout << "Exiting the program..." << endl;
            break;
        }

        default:
        {
            cout << "INVALID CHOICE" << endl;
            break;
        }
        }

        if (choice == 1 || choice == 2)
        {
            if (confirmchoice != 0)
            {
                D[confirmchoice - 1].nos = D[confirmchoice - 1].nos - P[p].nop;
                cout << "************************************************" << endl;
                cout << "YOUR RIDE WITH " << D[confirmchoice - 1].name << " HAS BEEN CONFIRMED" << endl;
                cout << "THANK YOU FOR USING RIDESHARE. HAVE A SAFE JOURNEY" << endl;
                cout << "                 DO VISIT AGAIN                 " << endl;
                cout << "************************************************" << endl;
            }
            else
            {
                cout << "************************************************" << endl;
                cout << "         THANK YOU FOR USING RIDESHARE.          " << endl;
                cout << "                 DO VISIT AGAIN                 " << endl;
                cout << "************************************************" << endl;
            }
        }

    } while (choice != 3);

    return 0;
}
