#include <iostream>
#include <string>
#include "Guest.hpp"
Guest::Guest() {}
Guest::Guest(int token,const std::string first, const std::string last, int age, const std::string card, bool gen, int vehiclegst)
    : Person(first, last, age, card, gen)
{
    setvehiclegst(vehiclegst);
    settokengst(token);
}
void Guest::setvehiclegst(int vehiclegst)
{
    vehicle_number_gst = vehiclegst;
}
int Guest::getvehiclegst()
{
    return vehicle_number_gst;
}
void Guest::settokengst(int token)
{
    tokengst = token;
}
int Guest::gettokengst()
{
    return tokengst;
}
std::string Guest::display() const
{
    // Assuming Student::display() is the base class's display function you want to call
    std::string basedisplaygst = Person::display(); // Call the base class's display function
    std::cout << basedisplaygst;
    // std::cout << "Student Card : " << teacher_card << std::endl;
    std::cout << "\n Your Vehicle Number is: " << vehicle_number_gst << std::endl;
    std::cout << "Your Token Number is: " << tokengst << std::endl;
    return "Display function executed successfully.";
}
