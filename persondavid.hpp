// This file consist of definition of class 'Person'. It consist of basic attributes of a person such as first name, last name, age, id card number, and gender. Class provide default constructor, so you don't need to provide arguments at the time of object instantiation. It also provide function 'display' that return all data of an object as a record. Class can also use cout and cin operator for output and input its data.

#ifndef PERSON_HPP
#define PERSON_HPP

// preprocessor directives
#include <iostream>
#include <string>
#include <exception>
#include <sstream>

class Person
{
    // take data (name , age , ID-card,gender)
    friend std::ostream& operator<<(std::ostream&, const Person&); // overloaded stream extraction operator
    friend std::istream& operator>>(std::istream&, Person&); // overloaded stream insertion operator
public:
    Person() = default; // default constructor
    Person(const std::string first, const std::string last, int age, const std::string card, bool gen) // constructor with arguments
        : gender{gen} {
            // calling respective functions to set each data member
            setFirstName(first);
            setLastName(last);
            setAge(age);
            setIdCard(card);
    }

    const int SIZE_OF_DATA_MEMBERS{15}; // this is size of 'firstName', 'lastName', and 'idCard'

    // for first name
    void setFirstName(const std::string name)
    {
        size_t length = name.size(); // getting size of string 'name'
        length = length < SIZE_OF_DATA_MEMBERS ? length : (SIZE_OF_DATA_MEMBERS - 1); // size must be one less than size of data member 'firstName'
        name.copy(firstName, length); // copy in 'firstName' one less than its size
        firstName[length] = '\0'; // add null character at end of array
    }
    std::string getFirstName() const
    {
        std::string name{firstName}; // create string object of array 'firstName'
        return name; // return string
    }

    // for last name
    void setLastName(const std::string name)
    {
        size_t length = name.size(); // getting size of string 'name'
        length = length < SIZE_OF_DATA_MEMBERS ? length : (SIZE_OF_DATA_MEMBERS - 1); // size must be one less than size of data member 'lastName'
        name.copy(lastName, length); // copy in 'lastName' one less than its size
        lastName[length] = '\0'; // add null character at end of array
    }
    std::string getLastName() const
    {
        std::string name{lastName}; // create string object of array 'lastName'
        return name; // return string
    }

    // for id card number
    void setIdCard(const std::string num)
    {
        size_t length = num.size(); // getting size of string 'num'
        length = length < SIZE_OF_DATA_MEMBERS ? length : (SIZE_OF_DATA_MEMBERS - 1); // size must be one less than size of data member 'idCard'
        num.copy(idCard, length); // copy in 'idCard' one less than its size
        idCard[length] = '\0'; // ass null character at end of array
    }
    std::string getIdCard() const
    {
        std::string card{idCard}; // create string object of array 'idCard'
        return card; // return string
    }

    // for age
    void setAge(int age)
    {
        // if age is not between 18-60
        if(age < 18 || age > 70) {
            throw std::invalid_argument{"age must be between 18-60"}; // throw error
        }

        this->age = age; // otherwise store age in data member 'age'
    }
    int getAge() const
    {
        return age; // return 'age'
    }

    // for gender
    void setGender(bool gen)
    {
        gender = gen; // 1 is for male, 0 is for female
    }
    bool getGender() const
    {
        return gender; // return 'gender'
    }

    // 'display' return as a concatenated record of all data members 
    //  i make small  changes to the original function so it can work with my class as make it virtual(polymorphism)
    virtual std::string display() const
    {
        std::ostringstream output; // creating object of class 'ostringstream'
        output<<"First-Name: " << getFirstName() << "\nLast-Name: " << getLastName() << " \nAge: " << getAge() << "\nID-Card: " << getIdCard() << "\nGender: " << getGender(); // concatenate all data members with spaces in between

        return output.str(); // return it as string
    }
private:
    // c-type strings are used for string data memeber, so they will be fixed in length and can be written in binary file
    char firstName[15]; // to hold first name
    char lastName[15]; // to hold last name
    int age; // to hold age
    char idCard[15]; // to hold id card number
    bool gender; // to hold gender (1 for male, 0 for female)
};


// overloaded stream insertion and stream extraction operators cannot be member functions, is we would like to invoke them with cout << somePerson and cin >> somePerson

inline std::ostream& operator<<(std::ostream& output, const Person& person)
{
    output << "First Name: " << person.getFirstName() << "\nLast Name: " << person.getLastName() <<  "\nAge: " << person.getAge() << "\nID Card Number: " << person.getIdCard() << "\nGender: " << (person.getGender() ? "Male" : "Female") << '\n'; // display in a fixed format

    return output; // enablea cout << a << b << c
}
inline std::istream& operator>>(std::istream& input, Person& person)
{
    std::string first, last, idCard;
    
    input >> first >> last >> person.age >> idCard >> person.gender; // input all data members

    // calling set functions to ensure our c-type strings proper handling
    person.setFirstName(first);
    person.setLastName(last);
    person.setIdCard(idCard);

    return input; // enables cin >> a >> b >> c
}

#endif