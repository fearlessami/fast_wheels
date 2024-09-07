// #include<iostream>
// #include<fstream>
// #include"buyer.h"


// class view_vehicle : public buyer
// {
//     public:

//     void newcars()
//     {
//         ifstream carsnew;
//         carsnew.open("new_cars.txt");
//         string line;
//         if (!carsnew)
//         {
//             cout << "new cars file is not present \n";
//         }
//         else
//         {
//             cout << "we are now in the file and reading the cars details \n ";

//                         string line;
//             int i = 1;
//             while (carsnew.good())
//             {
//                 getline(carsnew, line);

//                 cout << i << " " << line << endl;

//                 i++;
//             }
//         }
//     }
// };