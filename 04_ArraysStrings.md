# Arrays and Strings

## Arrays

Stored as contiguous memory locations. C++ places no limits on the number of dimensions in an array.

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

## Strings

```cpp
//declaring only
string string_name ;
//declaring and initialization
string string_name = "CodeWithHarry";
```

A string is basically a one dimensional array of characters, and can be initialized as such:
```cpp
char helloworld[] = “Hello, world!”
```