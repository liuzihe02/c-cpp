# Data Types, Operators and User I/O

## Data Types

**Built-in Types**
- C++ adds `bool` type and `wchar_t` for wide characters, while C requires using integers for boolean values

**User-Defined Types**
- C++ adds `class` type with inheritance, polymorphism, and encapsulation
- C++ supports operator overloading for user-defined types
- C structs can have member functions and access specifiers in C++

**References**
- C++ adds reference types (`Type&`), providing safer alternatives to pointers
- References must be initialized and cannot be null or reassigned

**Type Safety**
- C++ has stricter type checking and conversion rules
- C++ requires explicit type casting through `static_cast`, `dynamic_cast`, etc.
- C allows implicit conversion between incompatible pointer types

**Constants**
- C++ adds `const` member functions and objects
- C++ constants can be initialized at runtime
- C constants must be initialized at *compile* time


## Operators

Arithmetic Operators (`+`,`%`) relational operators (`>`,`!=`), logical operators (`&&`,`!`), bitwise operators (`&`,`>>`) are the same.

**New Operators in C++**
- `::` - Scope resolution 
- `.*` - Pointer to member through object
- `->*` - Pointer to member through pointer
- `new` - Dynamic memory allocation
- `delete` - Dynamic memory deallocation
- `dynamic_cast` - Safe downcasting
- `static_cast` - Compile-time type conversion

**Memory Operators**
- C: malloc()/free()
- C++: new/delete with constructors/destructors

**References**
- C++: & operator for references
- C: only pointer operations

## Format specifiers

Whenever we write a program in C, we have to use format specifiers to *define the variable type* in, when printing variables or mixing different data type formats.

```C
#include <stdio.h>
 
int main()
{
    char c[100] = "CodeWithHarry";
    printf("Printing a string, %s.", c);
}
```

| Format Specifier | Type |
|-----------------|------|
| %c | Used to print a character |
| %d | Used to print the signed integer |
| %f | Used to print the float values |
| %i | Used to print the unsigned integer |
| %l | Used to print the long integer |
| %lf | Used to print the double values |
| %lu | Used to print the unsigned integer or unsigned long integer |
| %s | Used to print the string |
| %u | Used to print the unsigned integer |

## Escape Sequences

| Escape Sequence | Description |
|-----------------|-------------|
| \t | Inserts a tab space |
| \b | Inserts a backspace |
| \n | Inserts a new line |
| \r | Inserts a carriage return |
| \f | Inserts a form feed |
| \' | Inserts a single quote character |
| \" | Inserts a double quote character |
| \\ | Inserts a backslash character |

## User I/O

`printf()` is used to output values in C, while `scanf()` is used to get user input.

```
scanf("format spacifier", &myObj)
```

```C
#include <stdio.h>
 
int main()
{
    int marks;
    char name[30];
    printf("Enter student's name: ");
    scanf("%s", name); // dont have to specify & for strings if we already specify the size of strings. this is exception
    printf("Enter marks in Maths: ");
    scanf("%d", &marks);
 
    printf("Hello %s! You have scored %d in Maths!", name, marks);
    return 0;
}
```