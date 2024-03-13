// Students.cpp
#include <iostream>
#include <string>

#include "Student.hpp"

Students::Students() {}

Students::Students(int token,const std::string first, const std::string last, int age, const std::string card, bool gen, int roll, const std::string phone, const std::string department, int sem, int cardstd, int vehiclestd)
    : Student(first, last, age, card, gen, roll, phone, department, sem)
{
    setcardstd(cardstd);
    setvehiclestd(vehiclestd);
    settokenstd(token);
}

void Students::setcardstd(int cardstd)
{
    student_card = cardstd;
}
void Students::setvehiclestd(int vehiclestd)
{
    vehicle_number = vehiclestd;
}
void Students::settokenstd(int token)
{
    tokenstd = token;
}

int Students::getcardstd()
{
    return student_card;
}
int Students::gettokenstd()
{
    return tokenstd;
}

int Students::getvehiclestd()
{
    return vehicle_number;
}

std::string Students::display() const
{
    // Assuming Student::display() is the base class's display function you want to call
    std::string basedisplaystd = Student::display();
    std::cout << basedisplaystd; // Call the base class's display function
    std::cout << "Student Card : " << student_card << std::endl;
    std::cout << "Your Vehicle Number is: " << vehicle_number << std::endl;
    std::cout << "Your Token Number is: " << tokenstd << std::endl;
    return "Display function executed successfully.";
}
