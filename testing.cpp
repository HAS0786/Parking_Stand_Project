#include <iostream>    // basic Input/Output file
#include <string>      // for string
#include "Student.hpp" // define by us
#include "Teacher.hpp" // define by us
#include "Guest.hpp"   // define by us
#include <vector>      // use for vector which is the latest version of Array
#include <fstream>     // for file
// using namespace is used when we not use std:: for each like cout, cin , endl;
using namespace std;

// function prototypes:

// delete studentsRecord from file using this function
void deleteStudentRecord(int cardNumber);

// we can count how many data are enter/present in file
int countTotalRecords(const std::string &filename);

// we use this function to check that token number not to be duplicate
bool isTokenNumberUnique(int tokenNumber, const std::string &filename);

// this function is used to search the data through token number from file
void token_recordread(int searchtokenNumber);

int flagforcount = 0;
// now main function is start
int main()
{
    // variables declare:
    cout << "#####*****************************************#####" << endl;
    cout << "\n\t WELCOME IN GCG PARKING MANAGEMENT \n " << endl;
    cout << "#####*****************************************##### \n\n"
         << endl;

    // variables are declare to take data and to send data to class (data-function/data-members)
    string fname;
    string lname;
    string idcard;
    int age;
    bool gender;
    char phone[12];
    int rollno;
    char department[25];
    int semester;
    string rank;
    int stdcard;
    int tchcard;
    int vehiclenum;
    int tokenNumber;
    char menuChoice;
    // we use vector instead of Array as Vector is dynamic form of array as it push data when we enter new entry

    // The angle brackets <> are used to specify the type of elements that the vector will hold.
    //  the vector is designed to store objects of the Students class.
    vector<Students> students;
    // here it only declare the vector of Student(class) that is capable of storing data by using push.back() function of it:
    vector<Teachers> teachers;
    vector<Guest> guests;

    // do-while loop start
    do
    {
        // Ask the user for Input M for the menu (First-menu)
        std::cout << "Enter 'M' for Menu: " << endl;
        std::cin >> menuChoice;
        // cin.ignore is a function in iostream that free-up the buffer as when we take input through cin it might left the some data in memory-buffer:
        cin.ignore();

        // condition that if user enter M/m it show menu otherwise no:(it is not case-sensitive)
        if (menuChoice == 'M' || menuChoice == 'm')
        {
            // first option request:
            int option; // variable that store the entry in 1st switch:
            std::cout << "1) Enter data" << std::endl;
            std::cout << "2) Remove Parking Car/Bike data " << std::endl;
            std::cout << "3) Total Vehicles Space remain in Parking Stand out of \" 50 \" " << std::endl;
            // as the user to chose from above choices
            std::cout << "Enter the number to select an option: ";
            std::cin >> option;
            //    now switch work here as according to the choice of user:
            switch (option)
            {
            case 1:
            {
                // 1st option request:
                do
                {
                    int typeOption; // inner choice when user press 1 for input
                    std::cout << "1) Teacher Data" << std::endl;
                    std::cout << "2) Student Data" << std::endl;
                    std::cout << "3) Guest/Visit person Data" << std::endl;
                    // ask the user to input number he/she want {student, teacher,guest}
                    std::cout << "Enter the number to select the data type: ";
                    std::cin >> typeOption;

                    switch (typeOption)
                    {

                    case 1:
                    {
                        flagforcount++;
                        cout << "\" Enter the Data Of Respected Teacher :  \"" << endl;
                        // take input from user and store in variable we declare above:
                        cout << "Enter the First-name :" << endl;
                        cin.ignore();
                        getline(cin, fname);
                        cout << "Enter the Last-name :" << endl;
                        getline(cin, lname);
                        cout << "Enter the ID-Card number (max-15) :" << endl;
                        cin >> idcard;
                        cout << "Enter the Age (18-70) :" << endl;
                        cin >> age;
                        cout << "Enter the Gender (1 for Male & 0 for Female) :" << endl;
                        cin >> gender;
                        cout << "Enter the Phone Number :" << endl;
                        cin >> phone;
                        cout << "Enter the Department :" << endl;
                        cin >> department;
                        cout << "Enter the Rank :" << endl;
                        cin >> rank;
                        cout << "Enter the Teacher Card :" << endl;
                        cin >> tchcard;
                        cout << "Enter the Vehicle Number :" << endl;
                        cin >> vehiclenum;

                        // Loop to get a unique token number
                        bool isUnique = false; // here flag is used to identify:
                        while (!isUnique)      // loop run till unique flag is "true" as it check the unique token number :
                        {
                            // ask the user to enter token number
                            cout << "Enter token Number" << endl;
                            cin >> tokenNumber;

                            // Check if the token number is unique before adding the new person
                            if (isTokenNumberUnique(tokenNumber, "data.txt")) // here it check the tokennumber from file data.txt that no same number are present if "no" then it assign the tokennumber to new person  and flag become true then next work done to input data in file or also to vector which have an object of Class according to the entrance:
                            {
                                isUnique = true; // Set the flag to true to exit the loop

                                // Add the new guest to the vector
                                //  here teachers is the object of class which is made according to requirement(according to data entry) { Teachers is the class name }
                                // all these arguments goes to our made class and then their they store their relevant members-functions
                                teachers.push_back(Teachers(tokenNumber, fname, lname, age, idcard, gender, phone, department, rank, tchcard, vehiclenum));

                                // file handling Start:
                                // "ostringstream" function that change all data into string
                                ostringstream output; // output is the object of stringconversion

                                // data goes to file
                                // here we made a instances of Class:
                                // the word Teacher is like as we made objects of teachers name but here its function is different as it convert all the data in string as we make objects above (output)
                                Teachers Teacher(tokenNumber, fname, lname, age, idcard, gender, phone, department, rank, tchcard, vehiclenum);
                                // object of string that take data of Teacher in it as in String form
                                output << Teacher;
                                // ofstream is used to write in file this function is that if file not exist it create a new file name which is enter in our parameters and if find then write data on it
                                // here ios::app is used (append) which enter data next to existing data no to overwrite data
                                // ios::ate (atend) is used to send the cursor at the end of last entry:
                                // "|" this is used to tell the compiler that it write the data at the end or also point the curson at the end:
                                // parkingstand is the name of object we made for ofstream class
                                ofstream parkingstand("data.txt", ios::app | ios::ate);
                                // if file found then do these function (is.open() is the function in fstream)
                                if (parkingstand.is_open())
                                {
                                    // Write the output string to the file
                                    // we write seperately those data which is for specific formating:
                                    parkingstand << "Token :" << tokenNumber << "\n";
                                    parkingstand << "Teacher card:" << tchcard << "\n";
                                    parkingstand << output.str();
                                    parkingstand << "Vehicle_numer:" << vehiclenum << "\n";
                                    parkingstand << "----------- " << std::endl;
                                    parkingstand.close(); // Close the file
                                }
                                else
                                {
                                    // error show when not find the file
                                    std::cerr << "Unable to open file";
                                }
                            }
                            else
                            {
                                // this condition do when we have same number in file:
                                cout << "Token number " << tokenNumber << " is already in use. Please enter a different token number." << endl;
                            }
                        }

                        break;
                    }
                    case 2:
                    {
                        flagforcount++;
                        //  as I explained for Teacher it is same no need of further explanation
                        cout << "\" Enter the Data of Talented Student : \"" << endl;

                        cout << "Enter the First-name :" << endl;
                        cin.ignore();
                        getline(cin, fname);
                        cout << "Enter the Last-name :" << endl;
                        getline(cin, lname);
                        cout << "Enter the ID-Card number (max-15) :" << endl;
                        cin >> idcard;
                        cout << "Enter the Age (18-70):" << endl;
                        cin >> age;
                        cout << "Enter the Gender  (1 for Male & 0 for Female) :" << endl;
                        cin >> gender;
                        cout << "Enter the Phone Number :" << endl;
                        cin >> phone;
                        cout << "Enter the Department :" << endl;
                        cin >> department;
                        cout << "Enter the Semester :" << endl;
                        cin >> semester;
                        cout << "Enter the Roll no" << endl;
                        cin >> rollno;
                        cout << "Enter the Student Card :" << endl;
                        cin >> stdcard;
                        cout << "Enter the Vehicle Number :" << endl;
                        cin >> vehiclenum;

                        // Loop to get a unique token number
                        bool isUnique = false;
                        while (!isUnique)
                        {
                            cout << "Enter token Number" << endl;
                            cin >> tokenNumber;

                            // Check if the token number is unique before adding the new guest
                            if (isTokenNumberUnique(tokenNumber, "data.txt"))
                            {
                                isUnique = true; // Set the flag to true to exit the loop

                                // Add the new guest to the vector
                                students.push_back(Students(tokenNumber, fname, lname, age, idcard, gender, rollno, phone, department, semester, stdcard, vehiclenum));

                                // Your existing code to write the new guest to the file
                                std::ostringstream output;
                                Students Student(tokenNumber, fname, lname, age, idcard, gender, rollno, phone, department, semester, stdcard, vehiclenum);
                                output << Student; // Assuming you have overloaded the << operator for the Guest class

                                ofstream parkingstand("data.txt", ios::app | ios::ate);
                                if (parkingstand.is_open())
                                {
                                    // Write the output string to the file
                                    parkingstand << "Token :" << tokenNumber << "\n";
                                    parkingstand << "Student card:" << stdcard << "\n";

                                    parkingstand << output.str();
                                    parkingstand << "Vehical_numer:" << vehiclenum << "\n";
                                    parkingstand << "----------- " << std::endl;
                                    parkingstand.close(); // Close the file
                                }
                                else
                                {
                                    std::cerr << "Unable to open file";
                                }
                            }
                            else
                            {
                                std::cout << "Token number " << tokenNumber << " is already in use. Please enter a different token number." << std::endl;
                            }
                        }

                        break;
                    }
                    case 3:
                    {
                        flagforcount++;
                        //  as same as teacher so no need to explain again
                        cout << "\" Enter the Data of Honourable Guest : \"" << endl;

                        // Your existing code to get guest details...
                        cout << "Enter the First-name :" << endl;
                        cin.ignore();
                        getline(cin, fname);
                        cout << "Enter the Last-name :" << endl;
                        getline(cin, lname);
                        cout << "Enter the ID-Card number (max-15) :" << endl;
                        cin >> idcard;
                        cout << "Enter the Age (18-70) :" << endl;
                        cin >> age;
                        cout << "Enter the Gender (1 for Male & 0 for Female) :" << endl;
                        cin >> gender;
                        cout << "Enter the Vehicle Number :" << endl;
                        cin >> vehiclenum;

                        // Loop to get a unique token number
                        bool isUnique = false;
                        while (!isUnique)
                        {
                            cout << "Enter token Number" << endl;
                            cin >> tokenNumber;

                            // Check if the token number is unique before adding the new guest
                            if (isTokenNumberUnique(tokenNumber, "data.txt"))
                            {
                                isUnique = true; // Set the flag to true to exit the loop

                                // Add the new guest to the vector
                                guests.push_back(Guest(tokenNumber, fname, lname, age, idcard, gender, vehiclenum));

                                // Your existing code to write the new guest to the file
                                std::ostringstream output;
                                Guest guest(tokenNumber, fname, lname, age, idcard, gender, vehiclenum);
                                output << guest; // Assuming you have overloaded the << operator for the Guest class

                                ofstream parkingstand("data.txt", ios::app | ios::ate);
                                if (parkingstand.is_open())
                                {
                                    // Write the output string to the file
                                    parkingstand << "Token :" << tokenNumber << "\n";
                                    parkingstand << output.str();
                                    parkingstand << "Vehicle_numer:" << vehiclenum << "\n";
                                    parkingstand << "----------- " << std::endl;
                                    parkingstand.close(); // Close the file
                                }
                                else
                                {
                                    cerr << "Unable to open file" << endl;
                                }
                            }
                            else
                            {
                                std::cout << "Token number " << tokenNumber << " is already in use. Please enter a different token number." << std::endl;
                            }
                        }

                        break;
                    }
                    default:
                    {
                        // this is the default option if user enter different entry:

                        std::cout << "Invalid option." << std::endl;
                    }
                    }

                    // Function to display token information

                    // for student:
                    // student is the temporary variable that represents each Students objects
                    // & is used with student variable that it not copy the data(objects data ) it only take the access of the Students class objects and then show data without making any copy
                    // it show data till the students (vector) end
                    // range of vector is all the objects of Students so it run till it reach at the end of the vector(object of Students)
                    for (const auto &student : students)
                    {
                        // here display() is the function define in Class Student(we made) which have virtually link with other 2-files
                        cout << "Student Detail" << student.display() << endl;
                    }

                    // range-base for loop:

                    // for teacher
                    // auto is used to find out the type of data in vector
                    // &
                    //
                    for (const auto &teacher : teachers)
                    {
                        cout << "Teacher Detail" << teacher.display() << endl;
                    }
                    // for guest
                    for (const auto &guest : guests)
                    {
                        cout << "Guest Detail" << guest.display() << endl;
                        // displayTokenInfo("Guest", tokenNumber++, guest);
                    }

// limit that only 50 entry is entered in it:
                    if (flagforcount == 50)
                    {
                        cerr << "You exceed the limit" << endl;
                        cout << flagforcount << endl;

                        break;
                    }
                    else
                    {
                        char continueChoice;
                        cout << "Do you want to enter more data? (Y/N): ";
                        cin >> continueChoice;
                        cin.ignore(); // Ignore the rest of the line

                        if (continueChoice != 'Y' && continueChoice != 'y')
                        {

                            break;
                        }
                    }
                } while (true);
                break; // outer switch-cases end
            }
            case 2:
            {

                // ask the user to enter the choice when case2 select which show the token detail (we enter token number then it show all the detail of that number)
                int valueinput;
                cout << "Enter your Choice " << endl;
                cout << "1) Show Token Detail :" << endl;
                // 2nd option is used to delete the data from file:
                cout << "2) Delete Token Record :" << endl;
                cin >> valueinput;
                switch (valueinput)
                {
                case 1:
                { /* code */
                    //  here code to show detail
                    int tokennumberchecker; // variable to store the token number user enter to show the detail
                    std::cout << "Enter the Token Card number you are looking for: ";
                    std::cin >> tokennumberchecker;

                    // Call token_recordread() which is define at last of the main
                    token_recordread(tokennumberchecker);
                    break;
                }
                case 2:
                {
                    int tokens; // store token number user want to delete
                    cout << "Enter the Token Number " << endl;
                    cin >> tokens;
                    // it is define at the end of the main so it delete that token when call
                    deleteStudentRecord(tokens);
                    break;
                }
                default:
                    cout << "You Enter wrong Choice" << endl;
                    break;
                }
                break;
            }
            case 3:
            {
                // here we check only the space we

                int remain;
                // function call  that give us space used in Parking so we subtract from total:
                remain = 50 - countTotalRecords("data.txt");
                // it show the remaining space of parking
                cout << "Total Space in the file: " << remain << endl;
                break;
            }
            default:
                std::cout << "Invalid option." << std::endl;
                break;
            }
        } // end switch:
        else
        {
            std::cout << "Invalid input. Please enter 'M' for the menu." << std::endl;
        }
        // condition to eliminate the

    } while (menuChoice == 'M' || menuChoice == 'm'); // loop end:

    return 0;
}

// Helper function to print out common token info
// Function to display token information
// void displayTokenInfo(const std::string &role, const Person &person)
// {

//         cout << "Person Detail" << person.display() << endl;

// }

// function that delete the student record:

void deleteStudentRecord(int tokenNumber)
{
    string line; // make a variable that store the data comes fromfile:
    ifstream file("data.txt"); // ifstream used for input (read from file)
    ofstream tempFile("temp.txt"); // to write on file

    bool found = false;
    bool skip = false;

    if (file.is_open() && tempFile.is_open())
    {
        // we take a line by line data from file and store in line varaible:
        while (getline(file, line))
        {
            // Check if the line contains the student card number
            // find is the function of string :

            //  search npos on internet:


// here important conditon that when line find the word Token : and also the number user enter then if condition true it remove the data from file


// When you use the find function on a std::string object to search for a substring, it returns the position of the first character of the first match. If the substring is not found, find returns string::npos.
// nopos=> no-position or no-found
// find function is used to find the substring in main string(whole-data):

// to_string is used to convert our input-number in string to find it:
// it like the loop that if find() not found the it returns npos
            if (line.find("Token :" + std::to_string(tokenNumber)) != string::npos)
            {
                found = true;
                skip = true; // Start skipping lines related to this student {skips writing the lines related to that token number to a temporary file}
            }
// program write the line to temporary file if it found  then it delete the data.txt file and remane the temporary file to data.txt
            if (!skip)
            {
                tempFile << line << std::endl; // Write the line to the temporary file
            }
            else if (line.find("-----------") != std::string::npos)
            {
                skip = false; // Stop skipping lines when the separator is found
            }
        }
        file.close();
        tempFile.close();

        // Replace the original file with the temporary file
        remove("data.txt");
        rename("temp.txt", "data.txt");
    }
    else
    {
        std::cerr << "Unable to open file";
    }

    if (!found)
    {
        std::cout << "Student card number " << tokenNumber << " not found." << std::endl;
    }
    else
    {
        std::cout << "Student card number " << tokenNumber << " has been deleted." << std::endl;
        flagforcount--;
    }
}

// function to count the line (---------)

int countTotalRecords(const std::string &filename)
{
    ifstream file(filename);
    string line;
    int recordCount = 0;
    bool inRecord = false;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            // Check if the line is the start of a new record
            if (line.find("-----------") != std::string::npos)
            {
                inRecord = true;
                recordCount++; // Increment the record count
            }
            // If we're in a record and encounter a separator, it's the end of the record
            else if (inRecord && line.find("-----------") != std::string::npos)
            {
                inRecord = false;
            }
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file";
    }

    return recordCount;
}

// check that token number assign to person is unique or not:

bool isTokenNumberUnique(int tokenNumber, const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;
    bool isUnique = true;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            // Assuming each record starts with "Token :" followed by the token number
            if (line.find("Token :" + std::to_string(tokenNumber)) != std::string::npos)
            {
                isUnique = false;
                break;
            }
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open file";
    }

    return isUnique;
}

// record Show:

void token_recordread(int tokennumberdata)
{
    std::string line;
    std::ifstream file("data.txt");
    bool found = false;

    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            // Check if the line contains the token number
            if (line.find("Token :" + std::to_string(tokennumberdata)) != std::string::npos)
            {
                // change the condition
                found = true;
                std::cout << "Found record with Token number " << tokennumberdata << ":\n"
                          << line << std::endl;

                // Continue reading and displaying lines until the "-----------" separator is found
                while (std::getline(file, line) && line.find("-----------") == std::string::npos)
                {
                    std::cout << line << std::endl;
                }
                break; // Exit the loop once the record's data is fully displayed
            }
        }

        file.close();
// if condition remain same(false) so it not found (npos show then it not founde)
        if (!found)
        {
            std::cout << "Record with Token number " << tokennumberdata << " not found." << std::endl;
        }
    }
    else
    {
        std::cerr << "Unable to open file";
    }
}
