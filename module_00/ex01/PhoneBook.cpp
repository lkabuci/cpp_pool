#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "PhoneBook created" << std::endl;
    _nbContacts = 0;
    _index = 0;
}

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook destroyed" << std::endl;
}

std::string    PhoneBook::getInput(std::string prompt) {
    std::string input;
    std::cout << prompt << "\t";
    std::getline(std::cin, input);
    if (std::cin.eof())
        return NULL;
    return input;
}

void    PhoneBook::addContact() {
    std::string firstName = getInput("First name");
    std::string lastName = getInput("Last name");
    std::string nickname = getInput("Nickname");
    std::string phoneNumber = getInput("Phone number");
    std::string darkestSecret = getInput("Darkest secret");

    _contacts[_index].setContact(
            firstName,
            lastName,
            nickname,
            phoneNumber,
            darkestSecret
            );
    if (_nbContacts < MAX_CONTACTS)
        _nbContacts++;
    _index++;
    _index %= MAX_CONTACTS;
}

void    PhoneBook::searchContact() const {

}

void    PhoneBook::printContact(int index) const {
    _contacts[index].printContact();
}

void    PhoneBook::printAllContacts() const {
    if (_nbContacts == 0) {
        std::cout << "No contacts" << std::endl;
        return;
    }
    for (int i = 0; i < _nbContacts; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << _contacts[i].getFirstName() << "|";
        std::cout << std::setw(10) << _contacts[i].getLastName() << "|";
        std::cout << std::setw(10) << _contacts[i].getNickname() << std::endl;
    }
}

int     PhoneBook::getNbContacts() const {
    return _nbContacts;
}

