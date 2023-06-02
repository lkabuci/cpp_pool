#include "PhoneBook.hpp"

int main(int ac, char *av[])
{
    (void)ac;
    (void)av;
    Contact     contact;
    PhoneBook   phoneBook;
    std::string input;
    while (true)
    {
        std::cout << "Enter a command: ";
        std::getline(std::cin, input);
        if (std::cin.fail() || input == "EXIT")
            break;
        else if (input == "ADD")
            phoneBook.add();
        else if (input == "SEARCH")
            phoneBook.search();
    }
    return (0);
}
