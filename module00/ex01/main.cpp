#include "PhoneBook.hpp"

 int main(int ac, char *av[])
 {
     (void)ac;
     (void)av;
     std::string input;
     Contact contact;
     PhoneBook phoneBook;
     while (true) {
         std::cout << "Enter a command: ";
         std::getline(std::cin, input);
         if (std::cin.eof() || input == "EXIT")
             break;
         else if (input == "ADD")
             phoneBook.add();
         else if (input == "SEARCH") {
             phoneBook.search();
         }
         else {
             std::cout << "Invalid input" << std::endl;
         }
     }
     return (0);
 }
