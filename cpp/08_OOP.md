# Object Orientated Programming

**Elements of OOP**
- Classes - Basic template for creating objects. This is the building block of object-oriented programming.
- Objects – Basic run-time entities and instances of a class.
- Data Abstraction & Encapsulation – Wrapping data and functions into a single unit
- Inheritance – Properties of one class can be inherited into others
- Polymorphism – Ability to take more than one form
- Dynamic Binding – Code which will execute is not known until the program runs
- Message Passing – message (Information) call format

## Basic Syntax

```cpp
//declare class
class class_name
{
    //body of the class
};

int main()
{
    class_name object_name; //instantiate object
}
```

## Class Attributes and Methods

We use class members and static members interchangeably. Static members have the same properties as global variables, but they can only be referenced via the class: either in class methods, via a class instance (`someObject.staticVariable`, or via `className::variable`)

### Class Attributes

```cpp
#include <iostream>
using namespace std;

class Employee
{
    //these 2 are class attributes, but are not accessibly as they aren't public!
    int eID;
    string eName;
    public:
};
int main()
{
    Employee Harry;
}
```

These class attributes are not accessible to Harry unless they are made public:

```cpp
class Employee
{
//public attributes
public:
    int eID;
    string eName;
};

int main()
{
    Employee Harry;
    Harry.eID = 5;
    Harry.eName = "Harry";
    cout << "Employee having ID " << Harry.eID << " is " << Harry.eName << endl;
}
```

### Class Methods

Defining method inside class:
```cpp
class Employee
{
public:
    int eID;
    string eName;

    void printName()
    {
        cout << eName << endl;
    }
};
```

Defining outside class:
```cpp
class Employee
{
public:
    int eID;
    string eName;
    //only defined outside class
    //this is the FUNCTION PROTOTYPE
    void printName();
};
//must use scope operator :: here, if u wanna define outside the class
void Employee::printName()
{
    cout << eName << endl;
}
```
This separates interface and implementation, and is actually good practice.

## Objects Memory Allocation

Memory for variables is allocated only at instantiation; instance variables have different attributes distinct to each instance. However, for methods, all instances share the same function code and memory.

### Class Variables

For static data members, there is only a single copy shared among all the instances of the class.
> Static members are not defined by any object of the class. They are exclusively defined outside any function using the scope resolution operator `::`

```cpp
class Employee
{
 
public:
    static int count; //returns number of employees
    string eName;
 
    void setName(string name)
    {
        eName = name;
        count++;
    }
};
 
int Employee::count = 0; //defining the value of count
```

### Class Methods

When a static method is created, they become independent of any object. Static methods can only access static data members and static methods. These can only be accessed using `::` operator:

```cpp
class Employee
{
 
public:
    static int count; //static variable
    string eName;
 
    void setName(string name)
    {
        eName = name;
        count++;
    }
 
    static int getCount()//static method
    {
        return count;
    }
};
 
int Employee::count = 0; //defining the value of count
 
int main()
{
    Employee Harry;
    Harry.setName("Harry");
    cout << Employee::getCount() << endl;
}
```

## Constructors

A constructor is a special member function with the same name as the class. The constructor doesn’t have a return type. Constructors are used to initialize the objects of their class.

**C++ Constructors**
- Should be declared in the public section
- Automatically invoked upon object creation
- No return types
- Can have default args

```cpp
class Employee
{
 
public:
    static int count; //returns number of employees
    string eName;
 
    //Constructor
    Employee()
    {
        count++; //increases employee count (class variable) every time an object is defined
    }
 
    void setName(string name)
    {
        eName = name;
    }
 
    static int getCount()
    {
        return count;
    }
};
 
int Employee::count = 0; //defining the value of count
 
int main()
{
    Employee Harry1;
    Employee Harry2;
    Employee Harry3;
    cout << Employee::getCount() << endl;
}
```

### Constructor Overloading

Here, one class can have multiple constructors with different parameters. At instatiation, the constructor, which will match the number/type/order of arguments, will get executed.

### Constructors with default arguments

```cpp
class Employee
{
 
public:
    Employee(int a, int b = 9);
};
```

### Copy Constructors

Used when you want to initialize a new object with the values of another object of the same class. If no copy constructor is written in the program compiler will supply its own copy constructor. 

```cpp
class class_name
{
    //default acces here is private, when no access is stated at the beginning of class declaration
    int a;
public:
    // Default constructor
    class_name(int val=0) 
    {
        a = val;
    }

    // Copy constructor, make &obj constant to be safe
    class_name(const class_name &obj)
    {
        a = obj.a;
    }
};
```

Initialize a copy:
```cpp
class_name original{100};  // Create an original object
class_name copy{original};  // This calls the copy constructor
```


### Member Initialization List

Used when initializing the data members of a class

```cpp
#include <iostream>
using namespace std;

class Point {
private:
	int x;
	int y;

public:
	Point(int i = 0, int j = 0): x(i), y(j) {}
	/* The above use of Initializer list is optional as the
		constructor can also be written as:
		Point(int i = 0, int j = 0) {
			x = i;
			y = j;
		}
	*/

	int getX() const { return x; }
	int getY() const { return y; }
};

int main()
{
	Point t1(10, 15);
	cout << "x = " << t1.getX() << ", ";
	cout << "y = " << t1.getY();
	return 0;
}
```

## Destructors

The default destructor calls the destructor of each of the instance members. If this is not good enough, we need to write a custom destructor. The most common use case is allocating a pointer with `new`. A pointer (to any type) is a primitive, and the destructor just makes the pointer itself go away, without touching the pointed to memory. So the default destructor of a pointer does not have the right behavior for us (it will leak memory), hence we need a delete call in the destructor.

Syntax:
```cpp
class_name {
public:
     ~class_name();
}

class_name :: ~class_name() {
    // some instructions
}
```

### `delete`

- `delete` is used to free memory allocated for a single object using `new`, like `newInteger = new int`
- `delete[]` is used to free memory allocated for an array of objects using `new[]`, like `newArray = new int[size]`. Deletes all objects in the array

If you use `delete` without `[]` on an array, this typically only destroys the first object, which causes memory leaks.


## Encapsulation

Encapsulation is considered a good practice where one should always *make attributes private* for them to become non-modifiable until needed. Once members are made private, methods to access them or change them should be declared.

```cpp
class class_name
{
private:
    int a;
 
public:
    void setA(int num)
    {
        a = num;
    }
 
    int getA()
    {
        return a;
    }
};
 
int main()
{
    class_name obj;
    obj.setA(5);
    cout << obj.getA() << endl;
}
```

## Inheritance

Syntax:
```cpp
// Derived Class syntax
class derived_class_name : access_modifier base_class_name
{
    // body of the derived class
}
```

## Types of Inheritance

### Single Inheritance

<image src="images/single.png" width=300>

```cpp
class ClassA
{
    //body of ClassA
};
//derived from ClassA
class ClassB : public ClassA
{
    //body of ClassB
};
```

### Multiple Inheritance

<image src="images/multiple.png" width=300>


```cpp
class ClassA
{
    //body of ClassA
};
 
class ClassB
{
    //body of ClassB
};
 
//derived from ClassB and Class C
class ClassC : public ClassA, public ClassB
{
    //body of ClassC
};
```

### Hierarchical Inheritance

<image src="images/hierarchical.png" width=300>

More than one derived class is created from a single base class.

### Multilevel Inheritance

<image src="images/multilevel.png" width=300>

A class is derived from another class, which itself is derived from another class.

### Hybrid Inheritance

<image src="images/hybrid.png" width=300>

Combining any type of inheritance.

## Access Modifiers

- Public
  - All variables and functions declared with public will be available for everyone. Can be accessed within and outside class. `.` operator used to acess public class members
- Private
  - All variables and functions declared with private can only be used *inside* the class
- Protected
  - Similar to private modifier, but protected access members can be accessed in *derived classes* whereas private cannot be accessed in derived classes.

This table shows the behaviour of access modifiers when they are derived from public, private and protected members.

|                 | Public derivation | Private Derivation | Protected Derivation |
| --------------- | ----------------- | ------------------ | -------------------- |
| Private Class   | Not inherited     | Not inherited      | Not inherited        |
| Protected Class | Protected         | Private            | Protected            |
| Public Class    | Public            | Private            | Protected            |

For example, when a derived class is protected, the public members of the base class become protected in the derived class.

## Polymorphism

Same object displays different behaviour in different contexts.

### Compile Time Polymorphism

Also called early binding - you're already bound to the function call and know which function is going to run.

- **Function Overloading**
  - We can have multiple of the same function names but different parameters. During compilation, the compiler knows which program to actually execute
- **Operator Overloading**
  - `+` operator can also do different things for strings and integers

### Run-time Polymorphism

Late binding. Compiler doesn't know which function will run when code is executed. Function calls are decided at runtime.

## Arrays of Objects

To create an array of 4 `Point` objects, we declare

```cpp
Point parray[4];
```

To access the object at position `i`, we write `parray[i]` and also do `parray[i].methodName(arg1,arg2)` to call methods on it.

We can also initialize an array of objects, where all these objects are instantiated at compile time:
```cpp
Point parray[4] = {Point(0,1), Point(1,2), Point(3,5), Point(8,13)};
```
or we can use the `new` operator to call the default constructor for each new `Point`:
```cpp
Point* parray = new Point[4];
```

## `const` member functions

To specify to the compiler that a given member function is safe to call on `const` objects, you can declare the function with the `const` keyword. This specifies that the function is a “read-only” function that does not modify the object on which it is called.

```cpp
const string &Person::getName() const {
    return name;
}
```
- Place the `const` keyword after the closing parenthesis of argument list
- `const` keyword required in both prototype and definition
- `const` function cannot modify any members or call any member functions that aren't also `const`
- if an object instantiated with `const`, only `const` member functions can operate on it