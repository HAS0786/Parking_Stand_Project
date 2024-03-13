// Students.cpp
#include <iostream>
#include <string>
#include "Teacher.hpp"

Teachers::Teachers() {}

Teachers::Teachers(int token,const std::string first, const std::string last, int age, const std::string card, bool gen, const std::string phone, const std::string department, const std::string rank, int cardtch, int vehicletch)
    : Teacher(first, last, age, card, gen, phone, department, rank)
{
    setcardtch(cardtch);
    setvehicletch(vehicletch);
    settokentch(token);
}

void Teachers::setcardtch(int cardtch)
{
    teacher_card = cardtch;
}
void Teachers::setvehicletch(int vehicletch)
{
    vehicle_number_tch = vehicletch;
}
void Teachers::settokentch(int token)
{
    tokentch = token;
}

int Teachers::getcardtch()
{
    return teacher_card;
}

int Teachers::getvehicletch()
{
    return vehicle_number_tch;
}
int Teachers::gettokentch()
{
    return tokentch;
}

std::string Teachers::display() const 
{
    // Assuming Student::display() is the base class's display function you want to call
    std::string basedisplaytch=Teacher::display(); // Call the base class's display function
    std::cout<<basedisplaytch;
    std::cout << "Student Card : " << teacher_card << std::endl;
    std::cout << "Your Vehicle Number is: " << vehicle_number_tch << std::endl;
    std::cout << "Your Token Number is: " << tokentch << std::endl;
    return "Display function executed successfully.";
}
