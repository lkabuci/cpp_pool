cmake_minimum_required(VERSION 3.25)
project(pool)
set(CMAKE_CXX_STANDARD 98)

# Module 00
add_executable(megaphone module00/ex00/megaphone.cpp)
add_executable(contact module00/ex01/Contact.cpp module00/ex01/main.cpp module00/ex01/Phonebook.cpp module00/ex01/utils.cpp)
# add_executable(test module00/ex02/Account.cpp module00/ex02/tests.cpp)

# Module 01
add_executable(m1_e0 module01/ex00/main.cpp module01/ex00/newZombie.cpp module01/ex00/randomChump.cpp module01/ex00/Zombie.cpp module01/ex00/main.cpp)
add_executable(m1_e1 module01/ex01/main.cpp module01/ex01/Zombie.cpp module01/ex01/zombieHorde.cpp)

set(targets megaphone contact m1_e0)

foreach(target ${targets})
    target_compile_options(${target} PRIVATE -Wall -Wextra -Werror -std=c++98 -g)
endforeach()
