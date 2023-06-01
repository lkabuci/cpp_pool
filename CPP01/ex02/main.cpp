#include <string>
#include <iostream>

int main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "memory address of string   \t\t" << &str << std::endl;
	std::cout << "memory address of stringPTR\t\t" << stringPTR << std::endl;
	std::cout << "memory address of stringREF\t\t" << &stringREF << std::endl;

	std::cout << "-----------" << std::endl;

	std::cout << "value of string\t\t\t" << str << std::endl;
	std::cout << "value pointed to by stringPTR\t" << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF\t" << stringREF << std::endl;
	return 0;
}
