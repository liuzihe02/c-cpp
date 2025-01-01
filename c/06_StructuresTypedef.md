# Structures

Used when we wish to store different data types together. Note that structure elements are always stored in contiguous memory locations.

## Creation

```c

#include <stdio.h>

struct Books
{
    char title[20];
    char author[100];
    float price;
    int pages;
};

int main()
{
    struct Books book1;
    return 0;
}
```

## Accessing struct elements

We use the dot operator `.`

```c
#include <stdio.h>
 
struct Books
{
    char title[20];
    char author[100];
    float price;
    int pages;
};
 
int main()
{
    struct Books book1 = {"C Programming", "ABC", 123.99, 300};
    printf("%s\n", book1.title);
    printf("%s\n", book1.author);
    printf("%f\n", book1.price);
    printf("%d\n", book1.pages);
    return 0;
}
```

- structures can be nested, structures can have members that are structures themselves
- Used to store large amount of data of varying data types

# C Typedef

A typedef is a keyword that is used to assign alternative names to existing datatypes. For example, we would often want to create a variable of type unsigned long. But, then it becomes a complex task if that need to declare an unsigned long comes for multiple variables.

```c
#include <stdio.h>
typedef unsigned long ul;

int main()
{
    ul a;
}
```

- Creating aliases for complex types, especially function pointers:

```c
typedef void (*CallbackFunc)(int, int);  // Makes function pointer syntax clearer
CallbackFunc handler;  // Instead of: void (*handler)(int, int);
```

- simpliflying struct declarations

```c
typedef struct Point {
    int x;
    int y;
} Point;

// Now you can use just 'Point' instead of 'struct Point'
Point p1;  // Instead of: struct Point p1;
```


- Arrays (multidimensional)
```c
typedef char String[50];
String name;  // Instead of: char name[50];
```

