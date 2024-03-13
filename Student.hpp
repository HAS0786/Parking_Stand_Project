
#ifndef STUDENTS_HPP
#define STUDENTS_HPP
#include <iostream>
#include <string>
#include"persondavid.hpp"
#include "studentdavid.hpp"
class Students : public Student {
protected:
    int student_card;
    int vehicle_number;
    int tokenstd;
public:
    Students();
    Students(int token,const std::string first, const std::string last, int age, const std::string card, bool gen, int roll, const std::string phone, const std::string department, int sem, int cardstd, int vehiclestd);
    void setcardstd(int cardstd);
    void setvehiclestd(int vehiclestd);
    void settokenstd(int token);
    int gettokenstd();
    int getcardstd();
    int getvehiclestd();
    std::string display() const override;
};
#endif // STUDENT_HPP
