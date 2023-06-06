cmake_minimum_required(VERSION 3.25)
project(pool)
set(CMAKE_CXX_STANDARD 98)

# CPP 00
add_executable(cpp0_ex0 CPP00/ex00/megaphone.cpp)
add_executable(cpp0_ex1 CPP00/ex01/Contact.cpp CPP00/ex01/main.cpp CPP00/ex01/Phonebook.cpp CPP00/ex01/utils.cpp)
add_executable(cpp0_ex2 CPP00/ex02/Account.cpp CPP00/ex02/tests.cpp)

# CPP 01
add_executable(cpp1_ex0 CPP01/ex00/main.cpp CPP01/ex00/newZombie.cpp CPP01/ex00/randomChump.cpp CPP01/ex00/Zombie.cpp CPP01/ex00/main.cpp)
add_executable(cpp1_ex1 CPP01/ex01/main.cpp CPP01/ex01/Zombie.cpp CPP01/ex01/zombieHorde.cpp)
add_executable(cpp1_ex2 CPP01/ex02/main.cpp)
add_executable(cpp1_ex3 CPP01/ex03/main.cpp CPP01/ex03/HumanB.cpp CPP01/ex03/HumanA.cpp CPP01/ex03/Weapon.cpp)
add_executable(cpp1_ex4 CPP01/ex04/main.cpp)
add_executable(cpp1_ex5 CPP01/ex05/main.cpp CPP01/ex05/main.cpp CPP01/ex05/Harl.cpp CPP01/ex05/Harl.hpp)
add_executable(cpp1_ex6 CPP01/ex06/main.cpp CPP01/ex06/Harl.cpp CPP01/ex06/Harl.hpp )

# CPP 02
add_executable(cpp2_ex0 CPP02/ex00/main.cpp CPP02/ex00/Fixed.cpp CPP02/ex00/Fixed.hpp CPP02/ex00/Fixed.cpp)
add_executable(cpp2_ex1 CPP02/ex01/main.cpp CPP02/ex01/Fixed.cpp CPP02/ex01/Fixed.hpp)
add_executable(cpp2_ex2 CPP02/ex02/main.cpp CPP02/ex02/Fixed.cpp CPP02/ex02/Fixed.hpp)

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
	cpp2_ex2)

foreach(target ${targets})
    target_compile_options(${target} PRIVATE -Wall -Wextra -std=c++98 -g)
endforeach()
