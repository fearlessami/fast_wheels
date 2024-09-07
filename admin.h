#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

class vehicle
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
    char availableInCity[20];
    char color[20];
};

class admin : public vehicle
{
private:
    char username[50], password[50];
    char username_f[50], password_f[50];

public:
    void login_admin()
    { 
        ifstream file("admin.txt"); // Assuming credentials are stored in a file named "admin.txt"

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
                istringstream iss(line);
                char storedUsername[100], storedPassword[100];

                // Read username and password from the file
                iss >> storedUsername >> storedPassword;

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

    void menu()
    {
        cout << "Welcome back!\n";
        cout << "What do you want to do?\n";
        cout << " 1. Add Vehicle\n 2. Remove Vehicle\n 3. Manage Inspection Requests\n";
        cout << " 4. Add Notification\n 5. Remove Notification\n 6. Logout\n";

        int choice;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addVehicle();
            break;
        // Add other cases for different functionalities as needed
        case 2:
            removeVehicle();
            break;
        }
    }

    void addVehicle()
    {
        ofstream addcar("new_cars.txt", ios::app);

        if (!addcar)
        {
            cerr << "Error opening the file for writing!" << endl;
            return;
        }

        vehicle newVehicle;

        // Input details for the new vehicle
        cout << "Enter Name: ";
        cin.ignore(); // Ignore newline character in the buffer
        cin.getline(newVehicle.name, sizeof(newVehicle.name));

        // Input other details for the new vehicle
        cout << "Enter Company: ";
        cin.getline(newVehicle.company, sizeof(newVehicle.company));

        cout << "Enter Model: ";
        cin.getline(newVehicle.model, sizeof(newVehicle.model));

        cout << "Enter Mileage: ";
        cin.getline(newVehicle.mileage, sizeof(newVehicle.mileage));

        cout << "Enter Price: ";
        cin.getline(newVehicle.price, sizeof(newVehicle.price));

        cout << "Enter Description: ";
        cin.getline(newVehicle.description, sizeof(newVehicle.description));

        cout << "Enter Seller Name: ";
        cin.getline(newVehicle.sellerName, sizeof(newVehicle.sellerName));

        cout << "Enter Contact: ";
        cin.getline(newVehicle.contact, sizeof(newVehicle.contact));

        cout << "Enter Fuel Type: ";
        cin.getline(newVehicle.fuelType, sizeof(newVehicle.fuelType));

        cout << "Enter Engine: ";
        cin.getline(newVehicle.engine, sizeof(newVehicle.engine));

        cout << "Enter Rating: ";
        cin >> newVehicle.rating;
        //  while (atof(rating) > 5.0)
        // {
        //     cout << "Invalid rating! Please enter a rating not higher than 5.0: ";
        //     cin >> rating;
        // }

        cout << "Enter Make Year: ";
        cin >> newVehicle.makeYear;

        cout << "Enter Available in City: ";
        cin.ignore(); // Ignore newline character in the buffer
        cin.getline(newVehicle.availableInCity, sizeof(newVehicle.availableInCity));

        cout << "Enter Color: ";
        cin.getline(newVehicle.color, sizeof(newVehicle.color));

        // Write the new vehicle details to the file
        addcar << endl
               << newVehicle.name << " " << newVehicle.company << " " << newVehicle.model << " "
               << newVehicle.mileage << " " << newVehicle.price << " " << newVehicle.description << " "
               << newVehicle.sellerName << " " << newVehicle.contact << " " << newVehicle.fuelType << " "
               << newVehicle.engine << " " << newVehicle.rating << " " << newVehicle.makeYear << " "
               << newVehicle.availableInCity << " " << newVehicle.color << " " << username;

        cout << "Vehicle added successfully!" << endl;

        addcar.close();
    }

    // ... (Previous code)

    void removeVehicle()
    {
        ifstream inFile("new_cars.txt");
        ofstream addcar("temp.txt");

        if (!inFile || !addcar)
        {
            cerr << "Error opening files for reading or writing!" << endl;
            return;
        }

        char searchName[50];
        cout << "Enter the name of the vehicle to remove: ";
        cin.ignore(); // Ignore newline character in the buffer
        cin.getline(searchName, sizeof(searchName));

        bool found = false;
        vehicle currentVehicle;

        // Read each line from the file
        while (inFile >> currentVehicle.name >> currentVehicle.company >> currentVehicle.model >> currentVehicle.mileage >> currentVehicle.price >> currentVehicle.description >> currentVehicle.sellerName >> currentVehicle.contact >> currentVehicle.fuelType >> currentVehicle.engine >> currentVehicle.rating >> currentVehicle.makeYear >> currentVehicle.availableInCity >> currentVehicle.color)
        {
            // Check if the current line matches the vehicle to be removed
            if (strcmp(searchName, currentVehicle.name) != 0)
            {
                cout << "Vehicle found and removed!" << endl;
                found = true;
            }
            else
            {
                // Write the non-matching vehicles to the temporary file
                addcar << currentVehicle.name << " " << currentVehicle.company << " " << currentVehicle.model << " "
                       << currentVehicle.mileage << " " << currentVehicle.price << " " << currentVehicle.description << " "
                       << currentVehicle.sellerName << " " << currentVehicle.contact << " " << currentVehicle.fuelType << " "
                       << currentVehicle.engine << " " << currentVehicle.rating << " " << currentVehicle.makeYear << " "
                       << currentVehicle.availableInCity << " " << currentVehicle.color << endl;
            }
        }

        // Close the files
        inFile.close();
        addcar.close();

        // Remove the original file
        remove("new_cars.txt");

        // Rename the temporary file to the original file
        rename("temp.txt", "new_cars.txt");

        if (!found)
        {
            cout << "Vehicle not found!" << endl;
        }
    }
};