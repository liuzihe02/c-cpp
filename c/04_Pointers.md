# Pointers

Pointer is a variable that stores the memory address of another variable.

## Address Operator (Referencing Operator) `&`

 - gives the address of an existing variable

 ```c
 #include <stdio.h>
int main()
{
    int a = 100;
    printf("%d\n", a);
    printf("Address of variable a is %d", &a);
    return 0;
}
```

## Indirection Operator (Dereferencing Operator)

- Takes an address and returns the content of the address

```c
#include <stdio.h>
 
int main()
{
    int a = 100;
    printf("Value of variable a stored at address %d is %d.", &a, *(&a));
    //Value of variable a stored at address 6422220 is 100.
    return 0;
}
```

## VOID Pointer

Functions that are not returning anything are given the type void. Now, in  the case of pointers that are given the datatype of a void, they can be typecasted into any other data type according to the necessity - they can be addressed as *general purpose pointer variables*

```c
int var = 1;
//gets typecasted into int
void *voidPointer = &var;
```

**Void pointers cannot be dereferenced**

```c
int a = 10;
void *voidPointer;
voidPointer = &a;
//will raise a compile time error'
printf("%d", *voidPointer);
// need to typecast first
printf("%d", *(int *)voidPointer);
```

## NULL Pointer

A pointer that is not assigned any value or memory address is a NULL pointer; does not point to any object.

```c
int *ptr = NULL;
```

**NULL pointer vs. Uninitialized pointer**
NULL pointers and uninitialised pointers are different, as a Null pointer does not occupy any memory location. That means, it points to nowhere but to a zeroth location. In contrast, an uninitialized pointer means that the pointer occupies a garbage value address. The garbage value address is still a real memory location and hence not a NULL value. So to be on the safe side, NULL pointers are preferred.

**NULL pointer vs. Void pointer**
NULL pointers and void pointers very much sound similar just because oif their nomenclatures, but they are very different as a NULL pointer is a pointer with a NULL value address, and a void pointer is a pointer of void data type.

**Uses**

- Safe default initialization value for pointers, when no valid memory address
- Error handling: serves as a known invalid value, functions can return NULL to indicate failure
- NULL can indicate no value in function parameters

## Dangling Pointers

Dangling pointers are pointers that are pointing to a memory location that has been already freed or deleted. Often during object destruction. It happens when an object with an incoming reference is deleted or de-allocated, without modifying the value of the pointer. The pointer still points to the memory location of the deallocated memory. 

```c
#include <stdio.h>
int *myvalue()
{
    int a = 10;
    //returning the address of a local variable a
    //stored on the stack and destroyed when the function returns
    return &a;
}

int main()
{
    int *ptr = myvalue();
    //now points to invalid memory
    // undefined behaviour, may crash program
    // possibly appear to work correctly (but actually wrong)
    printf("%d", *ptr);
    return 0;
}
```

## Wild Poitners

Uninitialized pointers are known as wild pointers because they point to some arbitrary memory location while they are not assigned to any other memory location. This may even cause a program to crash or behave unpredictably at times.

```c
int *ptr;
```

Will store garbage value in it (random location in memory).

> Dereferencing a wild pointer can be problematic, so we convert it to a NULL pointer