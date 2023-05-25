#ifndef CPP_POOL_PHONEBOOK_HPP
#define CPP_POOL_PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact _contacts[MAX_CONTACTS];
    int _nbContacts;
    int _index;

public:
    PhoneBook();
    ~PhoneBook();
    std::string getInput(std::string prompt);
    void addContact();
    void searchContact() const;
    void printContact(int index) const;
    void printAllContacts() const;
    int getNbContacts() const;
};

#endif //CPP_POOL_PHONEBOOK_HPP
