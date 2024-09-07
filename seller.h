
// sab se pehly seller se login karna h
// phir login k bad  7 options dikhany hn
// phir har aik ka function likhna h

// Seller Menu:
// 1. View Vehicles
//  --->  // new ----- used ---- bikes

// 2. Add Vehicle
// 3. Remove Vehicle
// 4. Register in Auction
// 5. View Notifications
// 6. Logout

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;
class seller_vehicle
{
public:
    char name[50];
    char company[50];
    char model[50];
    char mileage[50];
    char price[50];
    char description[100];
    char sellerName[50];
    char contact[25];
    char fuelType[20];
    char engine[20];
    float rating;
    int makeYear;
    char AvailableInCity[20];
    char color[20];
};
class seller : public seller_vehicle
{

private:
    char username[50], password[50];
    char username_f[50], password_f[50];

public:
    void register_seller()
    {
        cout << "Enter the username: ";
        cin >> username;
        cout << "Enter the password: ";
        cin >> password;

        ofstream file("seller.txt", ios::app);
        if (file.is_open())
        {

            file << endl;
            file << username << " " << password;
            cout << "regestred successfully \n";
            cout << "now please login \n";
            file.close();
            login_seller();
        }
        else
        {
            cout << "File not created!";
        }
    }

    void login_seller()
    {
        ifstream file("seller.txt");

        string line;

        bool credentialsCorrect = false;

        while (!credentialsCorrect)
        {
            cout << "Enter username: ";
            cin >> username;

            cout << "Enter password: ";
            cin >> password;

            string line;
            while (getline(file, line))
            {
                istringstream read(line);
                char storedUsername[100], storedPassword[100];

                // Read username and password from the file
                read >> storedUsername >> storedPassword;

                // Compare entered credentials with stored credentials
                if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0)
                {
                    cout << "Login successful!" << endl;
                    credentialsCorrect = true;
                    menu();
                    break; // Exit the loop if credentials match
                }
            }

            if (!credentialsCorrect)
            {
                cout << "\nInvalid username or password. Please try again." << endl;
                file.clear();            // Clear the error state to allow re-reading the file
                file.seekg(0, ios::beg); // Move the file pointer back to the beginning
            }
        }
    }

    /*.............................................*/
    /*.............................................*/
    /*.............................................*/
    /*.............................................*/
    /*.............................................*/
    void menu()
    {
        cout << "\t---------WELCOME BACK---------------\n";
        cout << "\t---------WHAT DO YOU WANT TO DO---------------\n";
        cout << "\t   1.    VIEW VEHICLE          \n";
        cout << "\t   2.    ADD VEHICLE           \n";
        cout << "\t   3.    REMOVE VEHICLE         \n";
        cout << "\t   4.    REGESTER IN AUCTION     \n";
        cout << "\t   5.    VIEW NOTIFICATIONS       \n";
        cout << "\t   6.    LOGOUT                   \n";

        int choice;
        cout << "enter your choice";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "WELCOME TO VIEW VEHICLE\n";
            cout << "which vehicle do you want to see\n";
            cout << "\t------------------ 1. New Car 2. Used Cars 3. Bikes------------------ \n";

            cout << "enter choice :: ";

            cin >> choice;

            // system("cls");
            switch (choice)
            {
            case 1:

                viewnewcars();
                break;
            case 2:
                viewusedcars();
                break;
                // usedcars();
                // break;
            case 3:
                viewbikes();
                break;
                // bikes();
                // break;
            }

            break;
        case 2:
            cout << "welcome to add vehicle function \n";
            addvehicle();
            break;
        case 3:

            cout << "welcome to remove vehicle functio  \n";
            removevehicle();
            break;
        case 4:

            cout << "welcome to regester in auction";
            break;
        case 5:

            cout << "the notifications are";
            break;

        case 6:

            cout << "logout";

            break;
        }
    }

    /*----------FUNCTION FOR THE NEW CARS------------------*/

    void viewnewcars()
    {
        ifstream file("new_cars.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];

        while (file.getline(line, sizeof(line)))
        {
            istringstream iss(line);

            // Read data from the line into character arrays

            iss >> name >> company >> model >> mileage >> price;
            file.ignore();                                      // Ignore the space before the description
            iss.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            iss >> sellerName >> contact >> fuelType >> engine >> rating >> makeYear >> AvailableInCity >> color;

            // Display the data
            cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sellerName << "\nContact: " << contact << "\nFuelType Type: " << fuelType
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << makeYear << "\nAvailableInCity: " << AvailableInCity << "\nColor: " << color << "\n\n";
        }

        file.close();
    }

    /*----------FUNCTION FOR THE USED CARS------------------*/

    void viewusedcars()
    {
        ifstream file("used_cars.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];

        while (file.getline(line, sizeof(line)))
        {
            istringstream iss(line);

            // Read data from the line into character arrays
            char name[50], company[50], model[50], mileage[50], price[50], description[100], sellerName[50], contact[50], fuelType[50], engine[50], rating[10], makeYear[50], availableInCity[50], color[50];

            iss >> name >> company >> model >> mileage >> price;
            file.ignore();                                      // Ignore the space before the description
            iss.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            iss >> sellerName >> contact >> fuelType >> engine >> rating >> makeYear >> availableInCity >> color;

            // Display the data
            cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sellerName << "\nContact: " << contact << "\nFuelType Type: " << fuelType
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << makeYear << "\nAvailableInCity: " << availableInCity << "\nColor: " << color << "\n\n";
        }

        file.close();
    }

    /*function for the bikes*/

    void viewbikes()
    {
        ifstream file("bikes.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];

        while (file.getline(line, sizeof(line)))
        {
            istringstream iss(line);

            // Read data from the line into character arrays
            char name[50], company[50], model[50], mileage[50], price[50], description[100], sellerName[50], contact[50], fuelType[50], engine[50], rating[10], makeYear[50], availableInCity[50], color[50];

            iss >> name >> company >> model >> mileage >> price;
            file.ignore();                                      // Ignore the space before the description
            iss.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            iss >> sellerName >> contact >> fuelType >> engine >> rating >> makeYear >> availableInCity >> color;

            // Display the data
            cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sellerName << "\nContact: " << contact << "\nFuelType Type: " << fuelType
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << makeYear << "\nAvailableInCity: " << availableInCity << "\nColor: " << color << "\n\n";
        }

        file.close();
    }

    /*function to add the vehicle*/

    void addvehicle()
    {
        cout << "WELCOME TO ADD VEHICLE...\n";

        cout << "\n\t\tyou want to add vehicle in which \n \t \t (1) new cars (2) used cars (3) bikes :: ";
        cout << "please enter the choice ";
        int choice;
        cin >> choice;

        // Collect information from the seller

        switch (choice)
        {
        case 1:
            cout << "You have chosen to add a new car." << endl;
            cout << "Please enter the following information for the new car:" << endl;
            addnewcar();
            break;
        case 2:
            cout << "You have chosen to add a used car." << endl;
            cout << "Please enter the following information for the used car:" << endl;
            addusedcar();
            break;
        case 3:
            cout << "You have chosen to add a bike." << endl;
            cout << "Please enter the following information for the bikes:" << endl;
            addbikes();
            break;
        }
    }

    /*function to add new car */
    void addnewcar()
    {
        cout << "enter the details of the new car \n";
        // char make[50], model[50], mileage[50], price[50], description[100], name[50], contact[50], fuelType[50], engine[50], rating[50], year[10], availableInCity[50], color[50];

        cout << "enter name :";
        cin >> name;
        cout << "Enter company  ";
        cin >> company;

        cout << "Enter model: ";
        cin >> model;

        cout << "Enter mileage: ";
        cin >> mileage;

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter description: ";
        cin.ignore(); // to handle the newline character in the buffer
        cin.getline(description, sizeof(description));

        cout << "Enter name of the seller: ";
        cin >> name;

        cout << "Enter contact number of the seller: ";
        cin >> contact;

        cout << "Enter fuelType type: ";
        cin >> fuelType;

        cout << "Enter engine details: ";
        cin.ignore();
        cin.getline(engine, sizeof(engine));

        cout << "Enter rating: ";
        cin >> rating;

        cout << "Enter make year: ";
        cin >> makeYear;

        cout << "Enter availableInCity: ";
        cin >> AvailableInCity;

        cout << "Enter color: ";
        cin >> color;

        // Save the information to the file
        ofstream file("new_cars.txt", ios::app);

        if (file.is_open())
        {
            file << endl;
            file << name << company << model << mileage << price << description << sellerName << contact << fuelType << engine << rating << makeYear << AvailableInCity << color << username << endl;
            cout << "new car added successfully!\n\n";
            file.close();
        }
        else
        {
            cout << "File not created!";
        }
    }

    /*function to add used car */
    void addusedcar()
    {
        cout << "enter the details of the used car \n";
        // char make[50], model[50], mileage[50], price[50], description[100], name[50], contact[50], fuelType[50], engine[50], rating[50], year[10], availableInCity[50], color[50];

        cout << "enter name :";
        cin >> name;
        cout << "Enter company  ";
        cin >> company;

        cout << "Enter model: ";
        cin >> model;

        cout << "Enter mileage: ";
        cin >> mileage;

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter description: ";
        cin.ignore(); // to handle the newline character in the buffer
        cin.getline(description, sizeof(description));

        cout << "Enter name of the seller: ";
        cin >> name;

        cout << "Enter contact number of the seller: ";
        cin >> contact;

        cout << "Enter fuelType type: ";
        cin >> fuelType;

        cout << "Enter engine details: ";
        cin.ignore();
        cin.getline(engine, sizeof(engine));

        cout << "Enter rating: ";
        cin >> rating;

        cout << "Enter make year: ";
        cin >> makeYear;

        cout << "Enter availableInCity: ";
        cin >> AvailableInCity;

        cout << "Enter color: ";
        cin >> color;

        // Save the information to the file
        ofstream file("used_cars.txt", ios::app);

        if (file.is_open())
        {
            file << endl;
            file << name << company << model << mileage << price << description << sellerName << contact << fuelType << engine << rating << makeYear << AvailableInCity << color << username << endl;
            cout << "used car added successfully!\n\n";
            file.close();
        }
        else
        {
            cout << "File not created!";
        }
    }

    /*function to add bikes */
    void addbikes()
    {
        cout << "enter the details of the bike \n";
        // char make[50], model[50], mileage[50], price[50], description[100], name[50], contact[50], fuelType[50], engine[50], rating[50], year[10], availableInCity[50], color[50];

        cout << "enter name :";
        cin >> name;
        cout << "Enter company  ";
        cin >> company;

        cout << "Enter model: ";
        cin >> model;

        cout << "Enter mileage: ";
        cin >> mileage;

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter description: ";
        cin.ignore(); // to handle the newline character in the buffer
        cin.getline(description, sizeof(description));

        cout << "Enter name of the seller: ";
        cin >> name;

        cout << "Enter contact number of the seller: ";
        cin >> contact;

        cout << "Enter fuelType type: ";
        cin >> fuelType;

        cout << "Enter engine details: ";
        cin.ignore();
        cin.getline(engine, sizeof(engine));

        cout << "Enter rating: ";
        cin >> rating;

        cout << "Enter make year: ";
        cin >> makeYear;

        cout << "Enter availableInCity: ";
        cin >> AvailableInCity;

        cout << "Enter color: ";
        cin >> color;

        // Save the information to the file
        ofstream file("bikes.txt", ios::app);

        if (file.is_open())
        {
            file << endl;
            file << name << company << model << mileage << price << description << sellerName << contact << fuelType << engine << rating << makeYear << AvailableInCity << color << username << endl;
            cout << "bike added successfully!\n\n";
            file.close();
        }
        else
        {
            cout << "File not created!";
        }
    }

    /*function to remove the vehicle */

    void removevehicle()
    {
        cout << "\n\nwelcome \n\n";
        cout << "\t\twhich vehicle you want to remove \n\n";
        cout << "\t\t(1) new car (2) used cars (3) bikes \n\n";
        int choice;
        cout << "please enter choice ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            removenewcar();
            break;

        default:
            break;
        }
    }
    void removenewcar()
    {
    }
};