# C Memory Management

## Variables

**1. Local Variables**

Local variables are variables that are declared inside a function or a block of code. These variables cannot be accessed outside the function they are declared in.


**2. Global Variables**
Global variables are variables that are defined outside of all the functions.

If cases where we have both the local and global variables with the same name declared, the local variable takes preference.

 

**3. Static Variables**
A static variable is a variable that retains its value even after the program exits the scope it was declared in. Static variables retain their value and are not initialized again in the new scope. The memory assigned to a static variable stays until the end of the program is reached, whereas a normal variable is destroyed when a function it was declared in gets exited. They can be defined inside or outside the function. Static variables are local to the block. The default value of a static variable is zero.

```c
static datatype variable_name = variable_value;
```

### Difference between static local and static global variables
- Static global variable
    - Any variable declared outside a function with a static keyword is known as a static global variable. This variable will be accessible within the source file where they're declared
- Static local variable
    - Any variable declared inside of a function with a static keyword is known as a static local variable. The scope of a static local variable will be the same as that of a local variable, but its memory will be available throughout the execution of the program.

 
- A static variable will retain the value even after the program exits the scope it was declared in.
- Memory allocated to a static variable is available throughout the program execution.
- If we do not initialize a static variable, then the default value  for numeric types will be `0`, and NULL for pointers.

## C Memory Layout

```
High Address
+------------------+
|       Stack      | <- Function calls, local variables, grows downward
|         ↓        |
|                  |
|         ↑        |
|       Heap       | <- Dynamic memory allocation, grows upward
+------------------+
|   Static/Global  | <- Global variables, static variables
+------------------+
|    Text/Code     | <- Program instructions, constants
Low Address
```

1. Text/Code Segment - Static Memory
    - Contains the actual program instructions
    - Read-only
    - Shared among processes running the same program


2. Data Segment (Static/Global variables) - Static Memory
    - Contains global and static variables
    - Fixed size throughout program execution


3. Heap - Dynamic Memory
    - Dynamic memory allocation (malloc, calloc, realloc)
    - Grows upward toward higher addresses
    - Memory must be explicitly freed
    - Can cause fragmentation
    - Size can change during execution


4. Stack - Static Memory
    - Automatic variables (local variables)
    - Function parameters
    - Return addresses
    - Grows downward toward lower addresses
    - Automatically managed
    - Fixed maximum size (stack overflow if exceeded)

| Static | Dynamic |
|--------|---------|
| Allocation of memory before execution | Allocation of memory at run time |
| Non-reusable memory | Reusable memory |
| Less optimal way | More optimal way |

## Memory Allocation

**1. `malloc()`**

Memory allocation. Requests memory from the heap and returns a pointer to the memory. The pointer is of the void type.

All the values at the allocation time are initialized to garbage values. The function expects the memory space along with the size we want in bytes at the time it is used.

```c
int *ptr;
ptr = (int *)malloc(5 *sizeof(int));
```

**2.`calloc()`**
Contiguous memory allocation. Similar to `malloc`, but we need to send in as parameters the number of blocks of memory, and the values at allocation time are initialized to 0 instead of garbage value in `malloc`

```c
int *ptr;
ptr = (int *)calloc(5, sizeof(int));
```

**3.`realloc`**

Reallocation of memory. Used in cases where the dynamic memory allocated previously is insufficient and there is a need of increasing the already allocated memory to store more data.

We also pass the previously declared memory address, and the new size of the memory in bytes while calling the function.

```c
ptr = (int *)realloc(ptr,10* sizeof(int));
```
**4.`free`**

No automatic deletion of dynamically allocated memory when the pointer gets overwritten. So, to manually do it, we use the free() function to free up the allocated memory space.

We just have to pass the pointer as a parameter inside the function and the address being pointed gets freed.

```c
free(ptr);
```