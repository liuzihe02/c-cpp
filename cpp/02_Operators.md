# Data Types, Operators, User I/O

## Data Types and Constants

- **Built-in data types**: `int`, `float`,`double`,`char` representing a single character, `boolean`
- **User defined data types**
- **Derived data types**: derived from primitive data types, like arrays or pointers
- **Constants**: constants are unmodifiable after initialization
  - `const float PI = 3.14;`

### Type Conversions

Type conversions are implicit when changing from a smaller datatype to a larger datatype (e.g. `float` to `double`), but must be explicitly stated when moving from larger to smaller datatype
```cpp
int x = (int) 5.0 //float must be explicitly cast to int
```

## Operators

**Arithmetic Operators**

Standard ones like `a/b` and `a-b` but also with `a++` which is post increments by 1 and `++a` which is pre increments by 1
```cpp
#include <iostream>
using namespace std;
int main()
{
    int a = 4, b = 5;
    cout << "The value of a + b is " << a + b << endl;
    cout << "The value of a % b is " << a % b << endl;
    cout << "The value of a++ is " << a++ << endl;
    cout << "The value of a-- is " << a-- << endl;
    cout << "The value of ++a is " << ++a << endl;
    cout << "The value of --a is " << --a << endl;
}
```
output:
```
The value of a + b is 9 
The value of a % b is 4 
The value of a++ is 4   
The value of a-- is 5
The value of ++a is 5
The value of --a is 4
```

**Relational Operators**

Standard ones like `==` and `!=`

**Logical Operators**

AND `&&`, OR `||`, NOT `!`

**Bitwise Operators**

| Operator | Description |
|:--------:|-------------|
| &        | Bitwise AND |
| \|       | Bitwise OR  |
| ^        | Bitwise XOR |
| ~        | Bitwise Complement |
| >>       | Shift Right |
| <<       | Shift Left  |

Input
```cpp
#include <iostream>
using namespace std;
int main()
{
    int a = 13; //1101
    int b = 5;  //101
    cout << "The value of a & b is " << (a & b) << endl;
    cout << "The value of a | b is " << (a | b) << endl;
    cout << "The value of a ^ b is " << (a ^ b) << endl;
    cout << "The value of ~a is " << (~a) << endl;
    cout << "The value of a >> 2 is " << (a >> 2) << endl;
    cout << "The value of a << 2 is " << (a << 2) << endl;
}
```
Output:
```cpp
The value of a & b is 5
The value of a | b is 13
The value of a ^ b is 8
The value of ~a is -14
The value of a >> 2 is 3
The value of a << 2 is 52
```

**Assignment Operators**

Standards ones like `=` and `+=` and `/=`. These do the operation (using the right expression) on the left expression, then assign it to the left expression.

## Manipulators

language manipulators are used in the formatting of output. These are helpful in modifying the input and the output stream. They make use of the insertion and extraction operators to modify the output.
```cpp
#include <iostream>
#include <iomanip>
using namespace std;
 
int main()
{
    float PI = 3.14;
    int num = 100;

    //enter a new line with a flush
    cout << "Entering a new line." << endl;

    //specify width of output, first few characs are whitespaces
    cout << setw(10) << "Output" << endl;

    //set precision of floating point numbers
    cout << setprecision(10) << PI << endl;

    //changes the base of a numerical number
    cout << setbase(16) << num << endl; //sets base to 16
}
```
Output:
```
Entering a new line.
    Output
3.140000105
64
```

## Basic I/O

In the output stream, the direction of flow of bytes occurs from the main memory to the output device (for ex-display).
- `<<` is the insertion operator
- `>>` is the extraction operator
- `cout` used to print
- `cin` used to take input at runtime

```cpp
#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;                        // Getting input from the user
    cout << "Your number is: " << num; // Displaying the input value
    return 0;
}
```
Input:
```
Enter a number: 10
```
Output:
```
Your number is: 10
```

