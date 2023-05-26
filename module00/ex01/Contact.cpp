#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

std::string Contact::getFirstName(void) {
    return Contact::_firstName;
}

std::string Contact::getLastName(void) {
    return Contact::_lastName;
}

std::string Contact::getNickName(void) {
    return Contact::_nickName;
}

std::string Contact::getPhoneNumber(void) {
    return Contact::_phoneNumber;
}

std::string Contact::getDarkSecret(void) {
    return Contact::_darkSecret;
}

void Contact::setContact(
        std::string firsName,
        std::string lastName,
        std::string nickName,
        std::string phoneNumber,
        std::string darkSecret) {
    this->_firstName = firsName;
    this->_lastName = lastName;
    this->_nickName = nickName;
    this->_phoneNumber = phoneNumber;
    this->_darkSecret = darkSecret;
}

void Contact::printContact() {
    std::cout << std::string(13, '-') << std::endl;
    std::cout << std::left << std::setw(13) << "First Name" << ": " << this->getFirstName() << std::endl;
    std::cout << std::left << std::setw(13) << "Last Name" << ": " << this->getLastName() << std::endl;
    std::cout << std::left << std::setw(13) << "Nick Name" << ": " << this->getNickName() << std::endl;
    std::cout << std::left << std::setw(13) << "Phone Number" << ": " << this->getPhoneNumber() << std::endl;
    std::cout << std::left << std::setw(13) << "Dark Secret" << ": " << this->getDarkSecret() << std::endl;
    std::cout << std::string(13, '-') << std::endl;
}
