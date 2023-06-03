cmake_minimum_required(VERSION 3.25)
project(pool)
set(CMAKE_CXX_STANDARD 98)

# CPP 00
add_executable(megaphone CPP00/ex00/megaphone.cpp)
add_executable(contact CPP00/ex01/Contact.cpp CPP00/ex01/main.cpp CPP00/ex01/Phonebook.cpp CPP00/ex01/utils.cpp)
# add_executable(test CPP00/ex02/Account.cpp module00/ex02/tests.cpp)

# CPP 01
add_executable(m1_e0 CPP01/ex00/main.cpp CPP01/ex00/newZombie.cpp CPP01/ex00/randomChump.cpp CPP01/ex00/Zombie.cpp CPP01/ex00/main.cpp)
add_executable(m1_e1 CPP01/ex01/main.cpp CPP01/ex01/Zombie.cpp CPP01/ex01/zombieHorde.cpp)
add_executable(m1_e3 CPP01/ex03/main.cpp CPP01/ex03/HumanB.cpp CPP01/ex03/HumanA.cpp CPP01/ex03/Weapon.cpp)
add_executable(m1_e4 CPP01/ex04/main.cpp)
add_executable(m1_e5 CPP01/ex05/main.cpp CPP01/ex05/main.cpp CPP01/ex05/Harl.cpp CPP01/ex05/Harl.hpp)
# add_executable(m1_e5 )

set(targets m1_e0 m1_e3 m1_e4 )

foreach(target ${targets})
    target_compile_options(${target} PRIVATE -Wall -Wextra -Werror -std=c++98 -g)
endforeach()
