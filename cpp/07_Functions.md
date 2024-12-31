# Functions

## Function Prototype

This is like a method signature in Java:
```cpp
return_type function_name(parameter_type1, parameter_type2, ...);
```

> Note that unlike Python, you cannot declare a C++ function within another function

## Function Parameters

```cpp
int sum(int a, int b);

int main()
{
    int num1 = 5;
    int num2 = 6;
    sum(num1, num2);//actual parameters
}
```

## Returning from `main`

We `return 0;` from `main()` if successful, and `return 1` to indicate failure or error of `main()`

## Function Calling Methods

There are multiple ways parameters are passed to functions.

### Call by Value

We pass the values to the function arguments. In the case of call by value, the copies of actual parameters are sent to the formal parameter, which means that if we change the values inside the function, that will not affect the actual values.

Input:
```cpp
#include <iostream>
using namespace std;
 
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
 
int main()
{
    int x = 5, y = 6;
    cout << "The value of x is " << x << " and the value of y is " << y << endl;
    swap(x, y);
    cout << "The value of x is " << x << " and the value of y is " << y << endl;
}
```

Output:
```cpp
The value of x is 5 and the value of y is 6
The value of x is 5 and the value of y is 6
```

### Call by Pointer in C++

In the case of call by pointer, the *address* of actual parameters is sent to the formal parameter, which means that if we change the values inside the function that *will affect the actual values*. 

Input:
```cpp
#include <iostream>
using namespace std;
 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
int main()
{
    int x = 5, y = 6;
    cout << "The value of x is " << x << " and the value of y is " << y << endl;
    swap(&x, &y);
    cout << "The value of x is " << x << " and the value of y is " << y << endl;
}
```

Output:
```cpp
The value of x is 5 and the value of y is 6
The value of x is 6 and the value of y is 5
```

### Call by Reference

The reference of actual parameters is sent to the formal parameter, which means that if we change the values inside the function that *will affect the actual values.*

Input:
```cpp
#include <iostream>
using namespace std;
//this means a is reference to the actual integer object
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
 
int main()
{
    int x = 5, y = 6;
    cout << "The value of x is " << x << " and the value of y is " << y << endl;
    swap(x, y);
    cout << "The value of x is " << x << " and the value of y is " << y << endl;
}
```

Output:
```cpp
The value of x is 5 and the value of y is 6
The value of x is 6 and the value of y is 5
```

### Default Arguments

Defaults args are those used by the function if we don't input our value as parameters.
```cpp
int sum(int a = 5, int b);
```

> Note that default arguments must always come last, after required parameters

### Constant Arguments

Constant arguments are used when you don’t want your values to be changed or modified by the function. With the `const` keyword, we can read the variable but not modify it.

```cpp
void print(const long &x){//pass by reference avoids overhead of copying large number
    cout<<x;
}
```

> This is particularly useful when we are passing values by reference to a function, but don’t want to allow the function to make any changes to the original value
>
> If you know a value shouldn't be changing, particularly a function argument, you should declare it as constant

## Function Overloading

In both Java and C++, a unique method signature is defined by the same name, and parameter types (order of parameters matters).

> In C++, a constant qualifier also differentiates a unique method signature from one without the constant qualifier

**Same name, diff types of parameters**
```cpp
float sum(int a, int b);
float sum(float a, float b);
```

**Same name, diff number of parameters**
```cpp
float sum(int a, int b);
float sum(int a, int b, int c);
```

**Same name, diff parameter sequence**
```cpp
float sum(int a, float b);
float sum(float a, int b);
```

> Note that if we have 2 functions: `sum(int a, int b=0)` and `sum(int a, int b)`, and we pass in 2 integers, the compiler will raise an error because there is disambiguity in which function to call