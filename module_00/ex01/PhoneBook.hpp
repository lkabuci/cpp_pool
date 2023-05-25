#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

using namespace std;

class Car {
	public:
		string name;
		string model_name;
		int model_year;
		Car ();	// constructure
};

void Car::out(string name, string model_name, int model_year) {
	cout << "this is the " << name + " " + model_name
		 << " has been released in" << model_year << endl;
}

#endif // !PHONEBOOK_HPP

