#ifndef GUEST_HPP
#define GUEST_HPP
#include<iostream>
#include<string>
#include"persondavid.hpp"

class Guest:public Person
{
    protected:
    int vehicle_number_gst;
    int tokengst;

public:
    Guest();
    Guest(int token,const std::string first, const std::string last, int age, const std::string card, bool gen,int vehiclegst );
    void setvehiclegst(int vehiclegst);
    int getvehiclegst();
    void settokengst(int token);
    int gettokengst();
   std::string display() const override;
};
#endif // guest.hpp