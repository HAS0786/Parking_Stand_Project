// This file consist of definition of class 'Teacher'. It inherit publically from class 'Person'. It provide default and argumented constructor. It also provide 'display' functions to return all data of teacher as a record. It also have overloaded stream insertion and stream extraction operator. Try to carefully understand their definition before using them.

#ifndef TEACHER_HPP
#define TEACHER_HPP

// preprocessor directives
#include <string>
#include <exception>
#include "persondavid.hpp"

class Teacher : public Person
{
    friend std::ostream& operator<<(std::ostream&, const Teacher&); // overloaded stream extraction operator
    friend std::istream& operator>>(std::istream&, Teacher&); // overloaded stream insertion operator
public:
    Teacher() = default; // default constructor
    Teacher(const std::string first, const std::string last, int age, const std::string card, bool gen, const std::string phone, const std::string department, const std::string rank) // constructor with arguments
        : Person(first, last, age, card, gen) {
            // calling respective set functions
            setPhoneNumber(phone);
            setDepartment(department);
            setRank(rank);
    }

    const int PHONE_LENGTH{12}; // size of 'phoneNumber'
    const int DEPARTMENT_LENGTH{25}; // size of 'department'
    const int RANK_LENGTH{15}; // size of 'rank'

    // for phone number
    void setPhoneNumber(const std::string phone)
    {
        size_t length = phone.size(); // getting size of 'phone'
        length = length < PHONE_LENGTH ? length : (PHONE_LENGTH - 1); // length must be one less than 'phoneNumber' length
        phone.copy(phoneNumber, length); // copy one less than length in 'phoneNumber'
        phoneNumber[length] = '\0'; // add null character at end of 'phoneNumber;
    }
    std::string getPhoneNumber() const
    {
        std::string number{phoneNumber}; // create string of 'phoneNumber'
        return number; // return as string
    }

    // for department name
    void setDepartment(const std::string depart)
    {
        size_t length = depart.size(); // getting size of 'depart'
        length = length < DEPARTMENT_LENGTH ? length : (DEPARTMENT_LENGTH - 1); // length must be one less than 'department' lengthh
        depart.copy(department, length); // copy one less than length in 'department'
        department[length] = '\0'; // add null character at end of 'department'
    }
    std::string getDepartment() const
    {
        std::string depart{department}; // create string of 'department'
        return depart; // return as string
    }

    // for rank
    void setRank(const std::string rankV)
    {
        size_t length = rankV.size(); // getting size of 'rankV'
        length = length < RANK_LENGTH ? length : (RANK_LENGTH - 1); // length must be one less than 'rank' length
        rankV.copy(rank, length); // copy one less than length in 'rank'
        rank[length] = '\0'; // add null character at end of 'rank'
    }
    std::string getRank() const
    {
        std::string rankV{rank}; // create string for 'rank' array
        return rankV; // return semester
    }

    // 'display' return as a concatenated record of all data members
    virtual std::string display() const
    {
        std::ostringstream output; // creating object of class 'ostringstream'
        output << Person::display() << " \n Phone-Number:" << ' ' << getPhoneNumber() << " \nDepartment:" << getDepartment() << "\n Rank: " << getRank(); // concatenate all data members with spaces in between

        return output.str(); // return it as string
    }
private:
    // it uses c-type strings to hold string data
    // as it helps to write fixed length records
    char phoneNumber[12];
    char department[25];
    char rank[15];
};


inline std::ostream& operator<<(std::ostream& output, const Teacher& teacher)
{
    output << "First Name: " << teacher.getFirstName() << "\nLast Name: " << teacher.getLastName() <<  "\nAge: " << teacher.getAge() << "\nID Card Number: " << teacher.getIdCard() << "\nGender: " << (teacher.getGender() ? "Male" : "Female") << "\nPhone Number: " << teacher.getPhoneNumber() << "\nDepartment: " << teacher.getDepartment() << "\nRank: " << teacher.getRank() << "\n"; // display in a fixed format

    return output; // enablea cout << a << b << c
}
inline std::istream& operator>>(std::istream& input, Teacher& teacher)
{
    std::string first, last, idCard, phone, department, rank;
    int age, gender;
    
    input >> first >> last >> age >> idCard >> gender >> phone; // input all data members
    getline(input, department);
    input >> rank;

    // calling set functions to ensure our c-type strings proper handling
    teacher.setFirstName(first);
    teacher.setLastName(last);
    teacher.setAge(age);
    teacher.setIdCard(idCard);
    teacher.setGender(gender);
    teacher.setPhoneNumber(phone);
    teacher.setDepartment(department);
    teacher.setRank(rank);

    return input; // enables cin >> a >> b >> c
}

#endif