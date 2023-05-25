#ifndef CPP_POOL_CONTACT_HPP
#define CPP_POOL_CONTACT_HPP

#include <string>
#include <iomanip>
#include <iostream>

#define MAX_CONTACTS 8

class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkSecret;
public:
    Contact();
    ~Contact();
    void setContact(
            std::string firstName,
            std::string lastName,
            std::string nickname,
            std::string phoneNumber,
            std::string darkSecret
            );
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkSecret() const;
    void printContact() const;
};

#endif //CPP_POOL_CONTACT_HPP
