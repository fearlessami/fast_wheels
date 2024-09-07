#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <conio.h>
#include <windows.h>
#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define YELLOW_TEXT "\033[1;33m"
#define RESET_TEXT "\033[0m"
using namespace std;
class Car {
    public:
    string name, company, model, mileage, price, description, sell_name, contact, fuel, engine, rating, make_year, city, color;
    const int MAX_CARS = 100;
};
class buyer:public Car
{
protected:
    char username[50], password[50];
    char storedUsername[100], storedPassword[100];

public:
    void register_buyer()
    {
        cout << "Enter the username: ";
        cin >> username;
        cout << "Enter the password: ";
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode = 0;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
        cin >> password;
        printf("\x1B[36mTexting\033[0m\t\t");

        ofstream file("buyer.txt", ios::app);
        if (file.is_open())
        {

            file << endl;
            file << username << " " << password;
            cout << "File opened successfully! and data successfully stored! \n\n";
            file.close();
        }
        else
        {
            cout << "File not created!";
        }
    }

    void login_buyer()
    {
        ifstream file("buyer.txt");

        string line;

        bool credentialsCorrect = false;

        while (!credentialsCorrect)
        {
            // cout << "Enter username: ";
            // YELLOW_TEXT << "Enter username:" << RESET_TEXT;
            cout << "\033[32m" << "enter the username" << endl;
            cin >> username;

            cout  << "enter the password" <<endl;
            cin >> password;
            cout<< "\033[0m"<<endl;
            // HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

            // DWORD mode = 0;

            // GetConsoleMode(hStdin, &mode);

            // SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

            string line;
            while (getline(file, line))
            {
                istringstream read(line);

                // Read username and password from the file
                read >> storedUsername >> storedPassword;

                // Compare entered credentials with stored credentials
                if (strcmp(username, storedUsername) == 0 && strcmp(password, storedPassword) == 0)
                {
                    cout << "Login successful!\n\n\n"
                         << endl;

                    credentialsCorrect = true;

                    menu(); // calling the menu function if the credentials are correct

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

    /*-----------------------*/
    /*-----------------------*/
    /*-----------------------*/
    /*-----------------------*/

    void menu()
    {
        cout << " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. \n";
        cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n";
        cout << "| | _____  _____ | || |  _________   | || |   _____      | || |     ______   | || |     ____     | || | ____    ____ | || |  _________   | |\n";
        cout << "| ||_   _||_   _|| || | |_   ___  |  | || |  |_   _|     | || |   .' ___  |  | || |   .'    `.   | || ||_   \\  /   _|| || | |_   ___  |  | |\n";
        cout << "| |  | | /\\ | |  | || |   | |_  \\_|  | || |    | |       | || |  / .'   \\_|  | || |  /  .--.  \\  | || |  |   \\/   |  | || |   | |_  \\_|  | |\n";
        cout << "| |  | |/  \\| |  | || |   |  _|  _   | || |    | |   _   | || |  | |         | || |  | |    | |  | || |  | |\\  /| |  | || |   |  _|  _   | |\n";
        cout << "| |  |   /\\   |  | || |  _| |___/ |  | || |   _| |__/ |  | || |  \\ `.___.'\\  | || |  \\  `--'  /  | || | _| |_\\/_| |_ | || |  _| |___/ |  | |\n";
        cout << "| |  |__/  \\__|  | || | |_________|  | || |  |________|  | || |   `._____.'  | || |   `.____.'   | || ||_____||_____|| || | |_________|  | |\n";
        cout << "| |              | || |              | || |              | || |              | || |              | || |              | || |              | |\n";
        cout << "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n";
        cout << " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n";

        cout << "\t\tplease select an option to continue\n\n";

        cout << "   1.    \t\tView Vehicles\n\n";

        cout << "   2.    \t\tView Auction\n\n";

        cout << "   3.    \t\tRequest Inspection Report\n\n";

        cout << "   4.    \t\tContact Seller\n\n";

        cout << "   5.    \t\tView Notifications\n\n";

        cout << "   6.    \t\tAdd a comment on car\n\n";

        cout << "   7.    \t\tLogout \n\n";

        cout << "please enter your choice  :: ";

        int choice;

        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << R"(
                           ____  _              __  __      _   _               _____      _       
                          / ___|| |_   ___  ___|  \/  | ___| |_| |_ ___ _ __   | ____|_  _| |_ ___ 
                         | |    | \ \ / / |/ _ \ |\/| |/ _ \ __| __/ _ \ '__|  |  _| \ \/ / __/ __|
                         | |___ | |\ V /| |  __/ |  | |  __/ |_| ||  __/ |     | |___ >  <| |_\__ \
                          \____||_| \_/ |_|\___|_|  |_|\___|\__|\__\___|_|     |_____/_/\_\\__|___/
                        )";

            /*FOR THE VIEW VEHICLE*/

            cout << "\n\n\t------------------WELCOME TO VIEW VEHICLE------------------\n";

            cout << "\t------------------which vehicle you want to see------------------ \n";

            cout << "\t------------------ 1. New Car 2. Used Cars 3. Bikes------------------ \n";

            cout << "enter choice :: ";

            cin >> choice;

            // system("cls");
            switch (choice)
            {
            case 1:

                newcars();
                break;
            case 2:
                usedcars();
                break;
            case 3:
                bikes();
                break;
            }

            break;

        case 2:
            cout << "                           ,--,                                                    " << std::endl;
            cout << "                        ,---.'|                ,----..            ____            " << std::endl;
            cout << "           .---.   ,---,|   | :    ,----..    /   /   \\         ,'  , `.   ,---,. " << std::endl;
            cout << "          /. ./| ,'  .' :   : |   /   /   \\  /   .     :     ,-+-,.' _ | ,'  .' | " << std::endl;
            cout << "      .--'.  ' ,---.'   |   ' :  |   :     :.   /   ;.  \\ ,-+-. ;   , |,---.'   | " << std::endl;
            cout << "     /__./ \\ : |   |   .;   ; '  .   |  ;. .   ;   /  ` ;,--.'|'   |  ;|   |   .' " << std::endl;
            cout << " .--'.  '   \\'. :   :  |-'   | |__.   ; /--`;   |  ; \\ ; |   |  ,', |  ':   :  |-, " << std::endl;
            cout << "/___/ \\ |    ' ' :   :  ;/|   | :.';   | ;   |   :  | ; | |   | /  | |  |:   |  ;/| " << std::endl;
            cout << ";   \\  \\;      |   :   .'   :    |   : |   .   |  ' ' ' '   | :  | :  ||   :   .' " << std::endl;
            cout << " \\   ;  `      |   |  |-|   |  ./.   | '___'   ;  \\; /  ;   . |  ; |--'|   |  |-, " << std::endl;
            cout << "  .   \\    .\\  '   :  ;/;   : ;  '   ; : .'|\\   \\  ',  /|   : |  | ,   '   :  ;/| " << std::endl;
            cout << "   \\   \\   ' \\ |   |    |   ,/   '   | '/  : ;   :    / |   : '  |/    |   |    \\ " << std::endl;
            cout << "    :   '  |--\"|   :   .'   :    |   :    /   \\   \\ .'  ;   | |`-'     |   :   .' " << std::endl;
            cout << "     \\   \\ ;   |   | ,'           \\   \\ .'     `---`    |   ;/         |   | ,'   " << std::endl;
            cout << "      '---\"    `----'              `---`                '---'          `----'     " << std::endl;

            cout << "\n\n\t------------------WELCOME TO AUCTION------------------\n";

            cout << "\t------------------which vehicle you want to see------------------ \n";

            cout << "\t------------------ 1. New Car 2. Used Cars 3. Bikes------------------ \n";

            cin >> choice;

            switch (choice)
            {
            case 1:
                auction_new();
                break;
            case 2:
                auction_used();
                break;
            case 3:
                auction_bikes();
                break;
            }

            break;

        case 5:
            cout << "\n\n\t------------------WELCOME TO VIEW NOTIFICATION------------------\n";
            cout << "\n\n\t------------------F------------------\n";
            cout << "\n\n\t------------------WELCOME TO VIEW NOTIFICATION------------------\n";
            break;
        }
    }

    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/

    // FUNCTIONS FOR THE VIEW VEHICLE

    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/

    /*----------FUNCTION FOR THE NEW CARS------------------*/

    void newcars()
    {
        int choice;
        int minPrice, maxPrice;
        char targetCompany[50], targetname[50];
        ifstream file("new_cars.txt");
        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        int count = 1;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            // Read data from the line into character arrays
            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            // Display the data
            cout << count << " "
                 << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
            count++;
        }

        file.close();

        cout << "ON WHICH BASIS YOU WANT TO SEARCH :: (1) COMPANY || (2) NAMAE \n\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            /*FOR COMPANY BASES*/ // Ask the user for company search
            cout << "\nEnter the company to search for: ";

            cin >> targetCompany;

            searchCarsByCompany(targetCompany); // calling the searchbycompany function
            break;
        case 2:
            /*FOR PRICE BASES*/ // Ask the user for price search
            cout << "Enter the price range (minimum and maximum): ";

            cin >> targetname;
            searchbyname(targetname);
            break;
        }
    }

    /*function for searching on the basis of compnay*/

    void searchCarsByCompany(const char *targetCompany)
    {
        ifstream file("new_cars.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        bool found = false;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            if (strcmp(company, targetCompany) == 0) // if both match
            {
                found = true;
                cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                     << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                     << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
            }
        }

        file.close();
        char targetname[50];
        cout << "\n\n\t\tNOW YOU CAN SEARCH FOR ANY CAR BY HIS NAME :: ";
        cout << "\n\n\t\tEnter the name of the car you want\n";
        cout << "\n\t\tEnter '0' to go back to the main";
        cin >> targetname;
        searchbyname(targetname);

        if (!found)
        {
            cout << "No cars from the company '" << targetCompany << "' found." << endl;
        }
    }

    void searchbyname(const char *targetname)
    {
        ifstream file("new_cars.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        bool found = false;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            if (strcmp(name, targetname) == 0) // if both match
            {
                found = true;
                cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                     << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                     << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
            }
        }

        file.close();
        const int MAX_CARS = 100; // Assuming a maximum of 100 cars
    Car cars[MAX_CARS];
    int numCars = 0;
readCarsFromFile(cars, numCars);

        if (!found)
        {
            cout << "No cars from that specific name  '" << targetname << "' found." << endl;
        }
    }





void readCarsFromFile(Car cars[], int& numCars) {
    ifstream file("new_cars.txt");

    if (!file.is_open()) {
        cout << "File not found!" << endl;
        return;
    }

    char line[500];
    numCars = 0;

    while (file.getline(line, sizeof(line))) {
        if (numCars < MAX_CARS) {
            istringstream iss(line);

            iss >> cars[numCars].name >> cars[numCars].company >> cars[numCars].model >> cars[numCars].mileage >> cars[numCars].price;
            iss.ignore();                                       // Ignore the space before the description
            getline(iss, cars[numCars].description, '$');      // Read until '$' to get the entire description
            iss >> cars[numCars].sell_name >> cars[numCars].contact >> cars[numCars].fuel >> cars[numCars].engine >> cars[numCars].rating >> cars[numCars].make_year >> cars[numCars].city >> cars[numCars].color;

            ++numCars;
        } else {
            cerr << "Maximum number of cars reached. Ignoring additional entries." << endl;
            break;
        }
    

    file.close();
}


    file.close();
      selectCar(cars, numCars);
      
}

void selectCar(const Car cars[], int numCars) {
    if (numCars == 0) {
        cout << "No cars available." << endl;
        return;
    }

    cout << "Enter the index of the car you want to select: ";
    int index;

    while (!(cin >> index) || index < 1 || index > numCars) {
        cout << "Invalid input. Please enter a valid index: ";
        cin.clear();
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    const Car& selectedCar = cars[index - 1];
    cout << "You selected the following car:\n";
    cout << "Name: " << selectedCar.name << "\nCompany: " << selectedCar.company << "\nModel: " << selectedCar.model << "\nMileage: " << selectedCar.mileage
         << "\nPrice: " << selectedCar.price << "\nDescription: " << selectedCar.description << "\nSeller Name: " << selectedCar.sell_name << "\nContact: " << selectedCar.contact
         << "\nFuel Type: " << selectedCar.fuel << "\nEngine: " << selectedCar.engine << "\nRating: " << selectedCar.rating << "\nMake Year: " << selectedCar.make_year << "\nCity: "
         << selectedCar.city << "\nColor: " << selectedCar.color << "\n\n";
    cout << "Contact the seller at: " << selectedCar.contact << endl;


    displayCars(cars, numCars);
}

void displayCars(const Car cars[], int numCars) {
    for (int i = 0; i < numCars; ++i) {
        const Car& car = cars[i];
        cout << "Index: " << i + 1 << "\nName: " << car.name << "\nCompany: " << car.company << "\nModel: " << car.model << "\nMileage: " << car.mileage
             << "\nPrice: " << car.price << "\nDescription: " << car.description << "\nSeller Name: " << car.sell_name << "\nContact: " << car.contact
             << "\nFuel Type: " << car.fuel << "\nEngine: " << car.engine << "\nRating: " << car.rating << "\nMake Year: " << car.make_year << "\nCity: " << car.city
             << "\nColor: " << car.color << "\n\n";
    }
}



















    /*function for price searching */
    void searchCarsByPriceRange(int minPrice, int maxPrice)
    {
        ifstream file("new_cars.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        bool found = false;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            // Check if the price is a valid integer
            bool isNumeric = true;
            for (char c : price)
            {
                if (!isdigit(c))
                {
                    isNumeric = false;
                    break;
                }
            }

            if (isNumeric)
            {
                int carPrice = atoi(price);

                if (carPrice >= minPrice && carPrice <= maxPrice)
                {
                    found = true;
                    cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                         << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                         << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
                }
            }
            else
            {
                cerr << "Invalid price format. Skipping this entry." << endl;
            }
        }

        file.close();

        if (!found)
        {
            cout << "No cars found within the specified price range." << endl;
        }
    }

    /*----------FUNCTION FOR THE USED CARS------------------*/

    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/
    /*................................................................................................*/

    void usedcars()
    {
        int choice;
        int minPrice, maxPrice;
        char targetCompany[50], targetname[50];
        ifstream file("used_cars.txt");
        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        int count = 1;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            // Read data from the line into character arrays
            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            // Display the data
            cout << count << " "
                 << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
            count++;
        }

        file.close();

        cout << "ON WHICH BASIS YOU WANT TO SEARCH :: (1) COMPANY || (2) NAMAE \n\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
            /*FOR COMPANY BASES*/ // Ask the user for company search
            cout << "\nEnter the company to search for: ";

            cin >> targetCompany;

            searchusedCarsByCompany(targetCompany); // calling the searchbycompany function
            break;
        case 2:
            /*FOR PRICE BASES*/ // Ask the user for price search
            cout << "Enter the price range (minimum and maximum): ";

            cin >> targetname;
            searchusedbyname(targetname);
            break;
        }
    }
void searchusedCarsByCompany(const char *targetCompany)
    {
        ifstream file("used_cars.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        bool found = false;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            if (strcmp(company, targetCompany) == 0) // if both match
            {
                found = true;
                cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                     << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                     << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
            }
        }

        file.close();
        char targetname[50];
        cout << "\n\n\t\tNOW YOU CAN SEARCH FOR ANY CAR BY HIS NAME :: ";
        cout << "\n\n\t\tEnter the name of the car you want\n";
        cout << "\n\t\tEnter '0' to go back to the main";
        cin >> targetname;
        searchusedbyname(targetname);

        if (!found)
        {
            cout << "No cars from the company '" << targetCompany << "' found." << endl;
        }
    }

    void searchusedbyname(const char *targetname)
    {
        ifstream file("used_cars.txt");

        if (!file.is_open())
        {
            cout << "File not found!" << endl;
            return;
        }

        char line[500];
        bool found = false;

        while (file.getline(line, sizeof(line)))
        {
            istringstream read(line);

            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            // Use getline to correctly read the entire name
            read >> name >> company >> model >> mileage >> price;
            read.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            if (strcmp(name, targetname) == 0) // if both match
            {
                found = true;
                cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                     << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                     << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
            }
        }

        file.close();
        const int MAX_CARS = 100; // Assuming a maximum of 100 cars
    Car cars[MAX_CARS];
    int numCars = 0;
readusedCarsFromFile(cars, numCars);

        if (!found)
        {
            cout << "No cars from that specific name  '" << targetname << "' found." << endl;
        }
    }





void readusedCarsFromFile(Car cars[], int& numCars) {
    ifstream file("used_cars.txt");

    if (!file.is_open()) {
        cout << "File not found!" << endl;
        return;
    }

    char line[500];
    numCars = 0;

    while (file.getline(line, sizeof(line))) {
        if (numCars < MAX_CARS) {
            istringstream iss(line);

            iss >> cars[numCars].name >> cars[numCars].company >> cars[numCars].model >> cars[numCars].mileage >> cars[numCars].price;
            iss.ignore();                                       // Ignore the space before the description
            getline(iss, cars[numCars].description, '$');      // Read until '$' to get the entire description
            iss >> cars[numCars].sell_name >> cars[numCars].contact >> cars[numCars].fuel >> cars[numCars].engine >> cars[numCars].rating >> cars[numCars].make_year >> cars[numCars].city >> cars[numCars].color;

            ++numCars;
        } else {
            cerr << "Maximum number of cars reached. Ignoring additional entries." << endl;
            break;
        }
    

    file.close();
}


    file.close();
      selectusedCar(cars, numCars);
      
}

void selectusedCar(const Car cars[], int numCars) {
    if (numCars == 0) {
        cout << "No cars available." << endl;
        return;
    }

    cout << "Enter the index of the car you want to select: ";
    int index;

    while (!(cin >> index) || index < 1 || index > numCars) {
        cout << "Invalid input. Please enter a valid index: ";
        cin.clear();
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    const Car& selectedCar = cars[index - 1];
    cout << "You selected the following car:\n";
    cout << "Name: " << selectedCar.name << "\nCompany: " << selectedCar.company << "\nModel: " << selectedCar.model << "\nMileage: " << selectedCar.mileage
         << "\nPrice: " << selectedCar.price << "\nDescription: " << selectedCar.description << "\nSeller Name: " << selectedCar.sell_name << "\nContact: " << selectedCar.contact
         << "\nFuel Type: " << selectedCar.fuel << "\nEngine: " << selectedCar.engine << "\nRating: " << selectedCar.rating << "\nMake Year: " << selectedCar.make_year << "\nCity: "
         << selectedCar.city << "\nColor: " << selectedCar.color << "\n\n";
    cout << "Contact the seller at: " << selectedCar.contact << endl;


    displayusedCars(cars, numCars);
}

void displayusedCars(const Car cars[], int numCars) {
    for (int i = 0; i < numCars; ++i) {
        const Car& car = cars[i];
        cout << "Index: " << i + 1 << "\nName: " << car.name << "\nCompany: " << car.company << "\nModel: " << car.model << "\nMileage: " << car.mileage
             << "\nPrice: " << car.price << "\nDescription: " << car.description << "\nSeller Name: " << car.sell_name << "\nContact: " << car.contact
             << "\nFuel Type: " << car.fuel << "\nEngine: " << car.engine << "\nRating: " << car.rating << "\nMake Year: " << car.make_year << "\nCity: " << car.city
             << "\nColor: " << car.color << "\n\n";
    }
}
    /*----------FUNCTION FOR THE BIKES------------------*/

    void bikes()
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
            istringstream read(line);

            // Read data from the line into character arrays
            char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

            read >> name >> company >> model >> mileage >> price;
            file.ignore();                                       // Ignore the space before the description
            read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
            read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

            // Display the data
            cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                 << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                 << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
        }

        file.close();
    }

    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/

    // FUNCTIONS FOR THE  AUCTION VEHICLE

    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/
    /*---------------------------------*/

    void auction_new()
    {
        ifstream new_auc;
        new_auc.open("new_auction.txt");
        string line;
        if (!new_auc)
        {
            cout << "new auction file is not present \n";
        }
        else
        {
            cout << "we are now in the file and reading the cars details \n ";
            string line;
            while (new_auc.good())
            {
                getline(new_auc, line);
                cout << line << endl;
            }
        }
    }

    void auction_used()
    {
        ifstream used_auc;
        used_auc.open("used_auction.txt");
        string line;
        if (!used_auc)
        {
            cout << "used auction file is not present \n";
        }
        else
        {
            cout << "we are now in the file and reading the cars details \n ";
            string line;
            while (used_auc.good())
            {
                getline(used_auc, line);
                cout << line << endl;
            }
        }
    }

    void auction_bikes()
    {
        char make[50];
        char model[50];
        char trim[50];
        int mpg;
        double price;
        char description[100];
        char dealer[50];
        char fuel_type[50];
        double engine_size;
        double rating;
        int year;
        char city[50];
        char color[50];
    }

    void sort()
    {
        cout << "you want to sort on which bases?";
        cout << ":: (1) on the bases of company :: (2) on the bases of price ::  (3) on the bases of model \n";
        int choice;
        string company;
        cout << "enter choice ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "you want to sort on the basis of compamy ";
            cin >> company;
            ifstream file("new_cars.txt");

            if (!file.is_open())
            {
                cout << "File not found!" << endl;
                return;
            }

            char line[500];

            while (file.getline(line, sizeof(line)))
            {
                istringstream read(line);

                // Read data from the line into character arrays
                char name[50], company[50], model[50], mileage[50], price[50], description[100], sell_name[50], contact[50], fuel[50], engine[50], rating[10], make_year[50], city[50], color[50];

                read >> name >> company >> model >> mileage >> price;
                file.ignore();                                       // Ignore the space before the description
                read.getline(description, sizeof(description), '$'); // Read until '$' to get the entire description
                read >> sell_name >> contact >> fuel >> engine >> rating >> make_year >> city >> color;

                // Display the data
                cout << "Name: " << name << "\nCompany: " << company << "\nModel: " << model << "\nMileage: " << mileage << "\nPrice: " << price
                     << "\nDescription: " << description << "\nSeller Name: " << sell_name << "\nContact: " << contact << "\nFuel Type: " << fuel
                     << "\nEngine: " << engine << "\nRating: " << rating << "\nMake Year: " << make_year << "\nCity: " << city << "\nColor: " << color << "\n\n";
            }

            file.close();

            break;
        }
    }
};

// #include <algorithm> // Add this include for sorting

// // Function to compare prices for sorting
// bool compareByPrice(const char* car1, const char* car2) {
//     return atof(car1 + 33) < atof(car2 + 33); // Skip the initial fields and compare prices
// }

// void newcars()
// {
//     ifstream file("new_cars.txt");

//     if (!file.is_open())
//     {
//         cout << "File not found!" << endl;
//         return;
//     }

//     const int maxCars = 100; // Maximum number of cars
//     const int maxFields = 15; // Maximum number of fields in each line
//     char carsData[maxCars][500]; // 2D array to store car data

//     int carCount = 0;

//     while (file.getline(carsData[carCount], sizeof(carsData[carCount])) && carCount < maxCars)
//     {
//         carCount++;
//     }

//     file.close();

//     // Display the data
//     for (int i = 0; i < carCount; ++i)
//     {
//         cout << carsData[i] << "\n";
//     }

//     // Ask the user if they want to sort the data based on price
//     char sortChoice;
//     cout << "Do you want to sort the data based on price? (y/n): ";
//     cin >> sortChoice;

//     // If the user wants to sort, sort the data by price
//     if (tolower(sortChoice) == 'y')
//     {
//         // Sort the data based on price using the compareByPrice function
//         sort(carsData, carsData + carCount, compareByPrice);

//         // Display the sorted data
//         cout << "\nSorted Data:\n";
//         for (int i = 0; i < carCount; ++i)
//         {
//             cout << carsData[i] << "\n";
//         }
//     }
// }
