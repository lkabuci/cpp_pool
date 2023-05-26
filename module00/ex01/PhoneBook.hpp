#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
private:
	int _size;
	int _index;
	Contact _contacts[MAX_CONTACTS];


public:
	PhoneBook();

	~PhoneBook();

	void add(void);

	void displayContacts(void);

	void search(void);
};


#endif // PHONEBOOK_HPP
