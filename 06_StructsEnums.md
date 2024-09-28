# Structures and Enums

## Structures

Structures a collection of objects with different data types, stored in contiguous memory.

**Features:**
- We can assign the values of a structure variable to another structure variable of the same type using the assignment operator.

- Structure can be nested within another structure

- We can pass the structure variable to a function. We can pass the individual structure elements or the entire structure variable into the function as an argument. And functions can also return a structure variable. 

- We can have a pointer pointing to a struct like a regular variable

**Using structures**
```cpp
#include <iostream>
using namespace std;
 
struct employee
{
    /* data */
    int eId;
    char favChar;
    int salary;
};
int main()
{
    struct employee Harry;
    Harry.eId = 1;
    Harry.favChar = 'c';
    Harry.salary = 120000000;
    cout << "eID of Harry is " << Harry.eId << endl;
    cout << "favChar of Harry is " << Harry.favChar << endl;
    cout << "salary of Harry is " << Harry.salary << endl;
    return 0;
}
```

## Enums

Enums are used for defining a set of fixed constants, often used for representing states or categories.

```cpp
enum Color {
    RED,
    GREEN,
    BLUE
};

Color myColor = GREEN;
```

Enums also get associated default integer values.

```cpp
#include <iostream>
using namespace std;
 
enum Meal
{
    breakfast,
    lunch,
    dinner
};
int main()
{
    Meal m1 = dinner;
    if (m1 == 2)
    {
        cout << "The value of dinner is " << dinner << endl;
    }
}
```