// This file consist of definition of class 'Student'. It inherit publically from class 'Person'. It provide default and argumented constructor. It also provide 'display' functions to return all data of student as a record. It also have overloaded stream insertion and stream extraction operator. Try to carefully understand their definition before using them.

#ifndef STUDENT_HPP
#define STUDENT_HPP

// preprocessor directives
#include <string>
#include <exception>
#include "persondavid.hpp"

class Student : public Person
{
    friend std::ostream &operator<<(std::ostream &, const Student &); // overloaded stream extraction operator
    friend std::istream &operator>>(std::istream &, Student &);       // overloaded stream insertion operator
public:
    Student() = default;                                                                                                                                                          // default constructor
    Student(const std::string first, const std::string last, int age, const std::string card, bool gen, int roll, const std::string phone, const std::string department, int sem) // constructor with arguments

    // these arguments go to Person Class:

        : Person(first, last, age, card, gen)
    {
        // calling respective set functions
        //  take roll , phone, department , sem in this class:
        setRollNo(roll);
        setPhoneNumber(phone);
        setDepartment(department);
        setSemester(sem);
    }

    const int PHONE_LENGTH{12};      // size of 'phoneNumber'
    const int DEPARTMENT_LENGTH{25}; // size of 'department'

    // for roll no
    void setRollNo(int roll)
    {
        // roll no must not be zero or negative
        if (roll <= 0)
        {
            throw std::invalid_argument{"roll no must be >= 1"};
        }

        rollNo = roll; // else store in 'rollNo'
    }
    int getRollNo() const
    {
        return rollNo; // returning 'rollNo'
    }

    // for phone number
    void setPhoneNumber(const std::string phone)
    {
        size_t length = phone.size();                                 // getting size of 'phone'
        length = length < PHONE_LENGTH ? length : (PHONE_LENGTH - 1); // length must be one less than 'phoneNumber' length
        phone.copy(phoneNumber, length);                              // copy one less than length in 'phoneNumber'
        phoneNumber[length] = '\0';                                   // add null character at end of 'phoneNumber;
    }
    std::string getPhoneNumber() const
    {
        std::string number{phoneNumber}; // create string of 'phoneNumber'
        return number;                   // return as string
    }

    // for department name
    void setDepartment(const std::string depart)
    {
        size_t length = depart.size();                                          // getting size of 'depart'
        length = length < DEPARTMENT_LENGTH ? length : (DEPARTMENT_LENGTH - 1); // length must be one less than 'department' lengthh
        depart.copy(department, length);                                        // copy one less than length in 'department'
        department[length] = '\0';                                              // add null character at end of 'department'
    }
    std::string getDepartment() const
    {
        std::string depart{department}; // create string of 'department'
        return depart;                  // return as string
    }

    // for semester number
    void setSemester(int sem)
    {
        // semester must be 1-8
        if (sem <= 0 || sem > 8)
        {
            throw std::invalid_argument{"semester must be 1-8"};
        }

        semester = sem; // else store in semester
    }
    int getSemester() const
    {
        return semester; // return semester
    }

    // 'display' return as a concatenated record of all data members
    // I make it virtual to use the same name in My-made file Student.cpp to also display those data-members in that file:
    virtual std::string display() const
    {
        std::ostringstream output;                                                                                                      // creating object of class 'ostringstream'
        output << Person::display() << "\n Roll-no: " << getRollNo() << "\n Phone-Number: " << getPhoneNumber() << "\n Department: " << getDepartment() << "\n Semester: " << getSemester(); // concatenate all data members with spaces in between

        return output.str(); // return it as string
    }

private:
    // it uses c-type strings to hold string data
    // as it helps to write fixed length records
    int rollNo;
    char phoneNumber[12];
    char department[25];
    int semester;
};

inline std::ostream &operator<<(std::ostream &output, const Student &student)
{
    output << "First Name: " << student.getFirstName() << "\nLast Name: " << student.getLastName() << "\nAge: " << student.getAge() << "\nID Card Number: " << student.getIdCard() << "\nGender: " << (student.getGender() ? "Male" : "Female") << "\nRoll No: " << student.getRollNo() << "\nPhone Number: " << student.getPhoneNumber() << "\nDepartment: " << student.getDepartment() << "\nSemester: " << student.getSemester() << "\n"; // display in a fixed format

    return output; // enablea cout << a << b << c
}
inline std::istream &operator>>(std::istream &input, Student &student)
{
    std::string first, last, idCard, phone, department;
    int age, gender, roll, sem;

    input >> first >> last >> age >> idCard >> gender >> roll >> phone; // input all data members
    getline(input, department);
    input >> sem;

    // calling set functions to ensure our c-type strings proper handling
    student.setFirstName(first);
    student.setLastName(last);
    student.setAge(age);
    student.setIdCard(idCard);
    student.setGender(gender);
    student.setRollNo(roll);
    student.setPhoneNumber(phone);
    student.setDepartment(department);
    student.setSemester(sem);

    return input; // enables cin >> a >> b >> c
}

#endif
