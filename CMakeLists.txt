cmake_minimum_required(VERSION 3.25)
project(pool)
set(CMAKE_CXX_STANDARD 98)

# CPP 00
add_executable(cpp0_ex0 CPP00/ex00/megaphone.cpp)
add_executable(cpp0_ex1 CPP00/ex01/Contact.cpp CPP00/ex01/main.cpp CPP00/ex01/PhoneBook.cpp CPP00/ex01/utils.cpp)
add_executable(cpp0_ex2 CPP00/ex02/Account.cpp CPP00/ex02/tests.cpp)

# CPP 01
add_executable(cpp1_ex0 CPP01/ex00/main.cpp CPP01/ex00/newZombie.cpp CPP01/ex00/randomChump.cpp CPP01/ex00/Zombie.cpp CPP01/ex00/main.cpp)
add_executable(cpp1_ex1 CPP01/ex01/main.cpp CPP01/ex01/Zombie.cpp CPP01/ex01/zombieHorde.cpp)
add_executable(cpp1_ex2 CPP01/ex02/main.cpp)
add_executable(cpp1_ex3 CPP01/ex03/main.cpp CPP01/ex03/HumanB.cpp CPP01/ex03/HumanA.cpp CPP01/ex03/Weapon.cpp)
add_executable(cpp1_ex4 CPP01/ex04/main.cpp)
add_executable(cpp1_ex5 CPP01/ex05/main.cpp CPP01/ex05/main.cpp CPP01/ex05/Harl.cpp CPP01/ex05/Harl.hpp)
add_executable(cpp1_ex6 CPP01/ex06/main.cpp CPP01/ex06/Harl.cpp CPP01/ex06/Harl.hpp)

# CPP 02
add_executable(cpp2_ex0 CPP02/ex00/main.cpp CPP02/ex00/Fixed.cpp CPP02/ex00/Fixed.hpp)
add_executable(cpp2_ex1 CPP02/ex01/main.cpp CPP02/ex01/Fixed.cpp CPP02/ex01/Fixed.hpp CPP02/ex01/Fixed.cpp CPP02/ex01/Fixed.hpp CPP02/ex01/main.cpp)
add_executable(cpp2_ex2 CPP02/ex02/main.cpp CPP02/ex02/Fixed.cpp CPP02/ex02/Fixed.hpp)
add_executable(cpp2_ex3 CPP02/ex03/main.cpp CPP02/ex03/Point.cpp CPP02/ex03/bsp.cpp CPP02/ex03/Fixed.cpp)

# CPP 03
add_executable(cpp3_ex0 CPP03/ex00/ClapTrap.cpp CPP03/ex00/ClapTrap.hpp CPP03/ex00/main.cpp)
add_executable(cpp3_ex1 CPP03/ex01/ClapTrap.cpp CPP03/ex01/main.cpp CPP03/ex01/ScavTrap.cpp CPP03/ex01/ScavTrap.hpp)
add_executable(cpp3_ex2 CPP03/ex02/ClapTrap.cpp CPP03/ex02/main.cpp CPP03/ex02/ScavTrap.cpp CPP03/ex02/FragTrap.cpp CPP03/ex02/FragTrap.hpp)
add_executable(cpp3_ex3 CPP03/ex03/ClapTrap.cpp CPP03/ex03/main.cpp CPP03/ex03/ScavTrap.cpp CPP03/ex03/FragTrap.cpp CPP03/ex03/DiamondTrap.cpp CPP03/ex03/DiamondTrap.hpp)

# CPP 04
add_executable(cpp4_ex0 CPP04/ex00/main.cpp CPP04/ex00/Animal.hpp CPP04/ex00/Animal.cpp CPP04/ex00/Dog.cpp CPP04/ex00/Dog.hpp CPP04/ex00/Cat.cpp CPP04/ex00/Cat.hpp)
add_executable(cpp4_ex1 CPP04/ex01/main.cpp CPP04/ex01/Animal.cpp CPP04/ex01/Cat.cpp CPP04/ex01/Dog.cpp CPP04/ex01/Brain.cpp CPP04/ex01/Brain.hpp)
add_executable(cpp4_ex2 CPP04/ex02/main.cpp CPP04/ex02/Dog.cpp CPP04/ex02/Cat.cpp CPP04/ex02/Brain.cpp CPP04/ex02/Animal.cpp)
add_executable(cpp4_ex3 CPP04/ex03/main.cpp CPP04/ex03/AMateria.cpp CPP04/ex03/ICharacter.hpp CPP04/ex03/IMateriaSource.hpp CPP04/ex03/Ice.cpp CPP04/ex03/Ice.hpp CPP04/ex03/Cure.cpp CPP04/ex03/Cure.hpp CPP04/ex03/Character.cpp CPP04/ex03/Character.hpp CPP04/ex03/MateriaSource.cpp CPP04/ex03/MateriaSource.hpp)

# CPP 05
add_executable(cpp5_ex0 CPP05/ex00/Bureaucrat.cpp CPP05/ex00/Bureaucrat.hpp CPP05/ex00/main.cpp)
add_executable(cpp5_ex1 CPP05/ex01/Form.cpp CPP05/ex01/Bureaucrat.cpp CPP05/ex01/main.cpp)
add_executable(cpp5_ex2 CPP05/ex02/RobotomyRequestForm.cpp CPP05/ex02/ShrubberyCreationForm.cpp CPP05/ex02/ShrubberyCreationForm.hpp CPP05/ex02/PresidentialPardonForm.cpp CPP05/ex02/PresidentialPardonForm.hpp CPP05/ex02/main.cpp CPP05/ex02/Bureaucrat.cpp CPP05/ex02/AForm.cpp)
add_executable(cpp5_ex3 CPP05/ex03/ShrubberyCreationForm.cpp CPP05/ex03/AForm.cpp CPP05/ex03/Bureaucrat.cpp CPP05/ex03/main.cpp CPP05/ex03/PresidentialPardonForm.cpp CPP05/ex03/RobotomyRequestForm.cpp CPP05/ex03/Intern.cpp CPP05/ex03/Intern.hpp)

set(targets
        cpp0_ex0
        cpp0_ex1
        cpp0_ex2

        cpp1_ex1
        cpp1_ex2
        cpp1_ex3
        cpp1_ex4
        cpp1_ex5

        cpp2_ex0
        cpp2_ex1
        cpp2_ex2
        cpp2_ex3

        cpp3_ex0
        cpp3_ex1
        cpp3_ex2
        cpp3_ex3

        cpp4_ex0
        cpp4_ex1
        cpp4_ex2
        cpp4_ex3

        cpp5_ex0
        cpp5_ex1
        cpp5_ex2
        cpp5_ex3
        )

foreach (target ${targets})
    target_compile_options(${target} PRIVATE -Wall -Wextra -Werror -std=c++98)
endforeach ()
