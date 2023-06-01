cmake_minimum_required(VERSION 3.25)
project(pool)
set(CMAKE_CXX_STANDARD 98)

add_executable(megaphone module00/ex00/megaphone.cpp)
add_executable(contact module00/ex01/Contact.cpp module00/ex01/main.cpp module00/ex01/Phonebook.cpp module00/ex01/utils.cpp)
add_executable(test module00/ex02/Account.cpp module00/ex02/tests.cpp)

set(targets megaphone contact test)

foreach(target ${targets})
    target_compile_options(${target} PRIVATE -Wall -Wextra -Werror -std=c++98 -g)
endforeach()
