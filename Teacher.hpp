#ifndef TEACHERS_HPP
#define TEACHERS_HPP
#include<iostream>
#include<string>
#include"teacherdavid.hpp"

class Teachers: public Teacher
{
    protected:
    // data-members
    int teacher_card;
    int vehicle_number_tch;
    int tokentch;

public:
    Teachers();  // default constructor 
// parameterized constructor:
    Teachers(int token,const std::string first, const std::string last, int age, const std::string card, bool gen, const std::string phone, const std::string department, const std::string rank, int cardtch, int vehicletch);
    // member functions
    void setcardtch(int cardtch);
    void settokentch(int token);
    void setvehicletch(int vehicletch);
    int getcardtch();
    int gettokentch();
    int getvehicletch();
   std::string display() const override;
};
#endif // techer.hpp