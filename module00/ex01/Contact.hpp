#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "utils.h"

class Contact {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkSecret;
public:
    Contact();

    ~Contact();

    void setContact(
            std::string firstName,
            std::string lastName,
            std::string nickName,
            std::string phoneNumber,
            std::string darkSecret);

    std::string getFirstName(void);

    std::string getLastName(void);

    std::string getNickName(void);

    std::string getPhoneNumber(void);

    std::string getDarkSecret(void);

    void printContact(void);
};


#endif // CONTACT_HPP
