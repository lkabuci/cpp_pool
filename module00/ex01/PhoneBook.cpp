#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    PhoneBook::_index = 0;
    PhoneBook::_size = 0;
}

PhoneBook::~PhoneBook() {
}

void    PhoneBook::displayContacts() {
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;
    for (int i = 0; i < this->_size; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncateString(this->_contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncateString(this->_contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncateString(this->_contacts[i].getNickName()) << std::endl;
    }
}

void PhoneBook::add() {
    std::string firstName = getInput("first name:");
    std::string lastName = getInput("last name:");
    std::string nickName = getInput("nickname:");
    std::string phoneNumber = getInput("phone number:");
    phoneNumber = getInput("phone number:");
    if (isValidPhoneNumber(phoneNumber) == false) {
        std::cerr << "invalid phone number" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string darkSecret = getInput("dark secret:");
    this->_contacts[this->_index].setContact(
            firstName,
            lastName,
            nickName,
            phoneNumber,
            darkSecret
    );
    if (this->_size < MAX_CONTACTS) {
		this->_size++;
	}
	this->_index++;
    this->_index %= MAX_CONTACTS;
}

void    PhoneBook::search() {
    if (this->_size == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    this->displayContacts();
    std::string index;
    while (true) {
        index = getInput("index:");
        if (isAllDigit(index) && atoi(index.c_str()) < this->_size && atoi(index.c_str()) >= 0)
            break;
        std::cout << "Wrong index." << std::endl;
    }
    this->_contacts[atoi(index.c_str())].printContact();
}
