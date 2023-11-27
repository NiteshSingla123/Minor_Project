#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class User
{
public:
    string username, password;

    void inputCredentials()
    {
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
    }

    // New method for writing login credentials to a file
    void writeCredentialsToFile(const string &fileName)
    {
        ofstream outFile(fileName, ios::app); // Open file in append mode

        if (outFile.is_open())
        {
            outFile << username << "," << password << endl;

            outFile.close();
        }
        else
        {
            cout << "Error opening file for writing: " << fileName << endl;
        }
    }

    // New method for checking if credentials exist in a file
    bool checkCredentials(const string &fileName)
    {
        ifstream inFile(fileName);

        if (inFile.is_open())
        {
            string storedUsername, storedPassword;
            while (inFile >> storedUsername >> storedPassword)
            {
                if (storedUsername == username && storedPassword == password)
                {
                    inFile.close();
                    return true;
                }
            }

            inFile.close();
        }
        return false;
    }
};

class Driver : public User
{
public:
    // Existing driver class code...
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

class Passenger : public User
{
public:
    // Existing passenger class code...
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

            D[d].inputCredentials(); // Get username and password

            if (newUser == 1)
            {
                D[d].input();
                // ... rest of the existing code
                D[d].writeCredentialsToFile("driver_credentials.txt"); // Write driver credentials to file
                d++;
            }
            else if (newUser == 0 && D[d].checkCredentials("driver_credentials.txt"))
            {
                // For an old user, ask for name, source, and destination only
                // ... rest of the existing code
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
                
                D[d].readFromFile("driver_details.txt"); // Read existing data from file
                d++;
            }
            else
            {
                cout << "Invalid username or password." << endl;
            }

            break;
        }

        case 2:
        {
            cout << "Are you a new user? (1 for Yes / 0 for No): ";
            int newUser;
            cin >> newUser;

            P[p].inputCredentials(); // Get username and password

            if (newUser == 1)
            {
                P[p].input();
                // ... rest of the existing code
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
                P[p].writeCredentialsToFile("passenger_credentials.txt"); // Write passenger credentials to file
                p++;
            }
            else if (newUser == 0 && P[p].checkCredentials("passenger_credentials.txt"))
            {
                // For an old user, ask for name, source, and destination only
                // ... rest of the existing code
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
            else
            {
                cout << "Invalid username or password." << endl;
            }

            // ... rest of the existing code
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

        // ... rest of the existing code
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

         // end switch

    } while (choice != 3);

    return 0;
}
