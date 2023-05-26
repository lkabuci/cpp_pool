# cpp_pool

```sh
cmake CMakeLists.txt
cmake --build .
```

single instance of a variable in memory
reference parameter `double& value`



* Class is a template for objects, and an object is an instance of a class.

```cpp
class MyClass {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
};
```

class is a blueprint for creating objects
we can represent a class by a visual language "UML" unified modeling language

     UML
*------------*
| DialogBox  | --> Class
*------------*
| size       | 
| value      | --> Attribute
| position   |
*------------*
| resize()   |
| display()  | --> Functions
| move()     |
*------------*

Structures are simple data containers
Classes creating objects that doing things, functions that operates on data of that class
Encapsulation:
    Combining the data and functions that operate on the data into one unit

