# File Handling

Files are stored in non-volatile memory.

| VOLATILE MEMORY | NON- VOLATILE MEMORY |
|---|---|
| The data can only remain in the system while the computer's power is on. | The data remains in the program even after the computer's power is off. It gets retrieved after the system gets on again. |
| Volatile memory can only hold information when there is a constant power supply. | Non volatile memory can also hold information even in case of non constant power supply. |
| Data gets held for a short period in case of volatile memory. | Data gets held for a longer term in case of non-volatile memory. |
| RAM is an example | Hard Disk is an example. |

Note we have to declare a pointer of the file type to work with files

```c
FILE *ptr;
```

## Modes

When opening a file using `fopen()`, we have the following modes:

- r: opens a file for reading.
- w: opens a file for writing. It can also create a new file.
- a: opens a file for appending.
- r+: opens a file for both reading and writing but cannot create a new file.
- w+: opens a file for both reading and writing.

```c
FILE *ptr;
// Reading mode
ptr = fopen("example.txt", "r");
```

## Closing files

```c
fclose(ptr);
```

## Reading a file

Use `fscanf`

```c
#include <stdio.h>
int main()
{
    FILE *ptr;
    ptr = fopen("example.txt", "r");
    char str[128];
    //
    fscanf(ptr, "%s", str);
    printf("%s", str);
}
```

## Writing to a file

Use `fprintf`

```c
#include <stdio.h>
 
int main()
{
    FILE *ptr;
    ptr = fopen("example.txt", "w");
    char str[128] = "Hello World!";
    fprintf(ptr, "%s", str);
}
```

