# Arrays and Strings

## Arrays

Built-in C-style arrays are stored as **contiguous** memory locations - each element's address is one after the previous element. C++ places no limits on the number of dimensions in an array.

- Data of the same type stored in an array
- Accessing any random item at any random position in a given array is very fast in an array.
- There is no case of memory shortage or overflow in the case of arrays since the size is fixed and elements are stored in contiguous memory locations.

**Defining an array**

Without specifying size of an array:
```cpp
int arr[] = {1, 2, 3};
```

Specifying the size:
```cpp
int arr[3];
arr[0] = 1, arr[1] = 2, arr[2] = 3;
```

Multidimensional array:
```
type arrayName[dimension1][dimension2];
```

Note that dimensions must be specified for multidimensional arrays, otherwise its impossible for compiler to determine what intended partitioning is. 

**Accessing and modifying array**

Very similar to Python, where we do `arr[2]=8` etc.

### Array Methods

In C++, built-in arrays like `int arr[]` are NOT objects and don't have member functions. That's why we can't do `array.size()`; this functionality is only for C++ STL containers like `std::array` or `std::vector`, but not for C-style arrays.

**Arrays passed as functions**

When you pass an array to a function, it decays to a pointer, and you lose the size information. Hence we often pass the size as a *separate* parameter:

```cpp
void function(int arr[], int size) {
    // Use 'size' here
}
```

**Using STL**

```cpp
#include <array>

std::array<int, 5> arr = {1, 2, 3, 4, 5};
size_t size = arr.size();
```

## Strings

The built-in string is `char*` or  `char[]` which is unwieldy. The std library includes `string` class that's much more powerful.

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s = "Hello";
    s += " world!";
    if (s == "Hello world!") {
        std::cout << "Success!" << std::endl;
    }
    std::cout << s.substr(6, 6) << std::endl; // Prints "world!"
    std::cout << s.find("world") << std::endl; // (prints "6")
    std::cout << s.find('l', 5) << std::endl; // (prints "9")

    return 0;
}
```

A string can also be a one dimensional array of characters, and can be initialized as such:
```cpp
char helloworld[] = “Hello, world!”
```