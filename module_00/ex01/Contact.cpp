#include "Contact.hpp"

void    Contact::setContact( std::string firstName, std::string lastName,
        std::string nickname, std::string phoneNumber, std::string darkSecret
    )
{
    _firstName = firstName;
    _lastName = lastName;
    _nickname = nickname;
    _phoneNumber = phoneNumber;
    _darkSecret = darkSecret;
}

void    Contact::printContact() const
{
    std::cout << "First name: " << _firstName << std::endl;
    std::cout << "Last name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone number: " << _phoneNumber << std::endl;
    std::cout << "Darkest secret: " << _darkSecret << std::endl;
}

std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickname() const {
    return _nickname;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

std::string Contact::getDarkSecret() const {
    return _darkSecret;
}

Contact::Contact() {

}

Contact::~Contact() {
}