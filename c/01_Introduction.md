# Introduction

```c
/*
 * Sum the odd and even numbers, respectively, from 1 to a given upperbound.
 * Also compute the absolute difference.
 * (SumOddEven.c)
 */
#include <stdio.h>   // Needed to use IO functions
 
int main() {
   int sumOdd  = 0; // For accumulating odd numbers, init to 0
   int sumEven = 0; // For accumulating even numbers, init to 0
   int upperbound;  // Sum from 1 to this upperbound
   int absDiff;     // The absolute difference between the two sums
 
   // Prompt user for an upperbound
   printf("Enter the upperbound: ");
   scanf("%d", &upperbound);   // Use %d to read an int
 
   // Use a while-loop to repeatedly add 1, 2, 3,..., to the upperbound
   int number = 1;
   while (number <= upperbound) {
      if (number % 2 == 0) {  // Even number
         sumEven += number;   // Add number into sumEven
      } else {                // Odd number
         sumOdd += number;    // Add number into sumOdd
      }
      ++number; // increment number by 1
   }
 
   // Compute the absolute difference between the two sums
   if (sumOdd > sumEven) {
      absDiff = sumOdd - sumEven;
   } else {
      absDiff = sumEven - sumOdd;
   }
 
   // Print the results
   printf("The sum of odd numbers is %d.\n", sumOdd);
   printf("The sum of even numbers is %d.\n", sumEven);
   printf("The absolute difference is %d.\n", absDiff);
}
```

## Basic Syntax

### Pre-processor Commands

Preprocessors are programs that process source code *before* compilation.

**Macros**

Whenever the name `token` is encountered, the compiler replaces `token` with `value`

```c
#define token value
```
where after preprocessing, the token will be expanded to its value in the program.
```c
// macro definition
#define LIMIT 5
```

**File Inclusion**

We include **standard header files** containing definitions of pre-defined functions like `printf()` and `scanf()`:

```c
#include <file_name>
```
where `file_name` is the name of the header file to be included. The `<` and `>` brackets tell the compiler to look for the file in the *standard directory*.

We can also include **user defined header files** like

```c
#include "filename"
```

The double quotes tells the compiler to search for the header file in the source file's directory.

## Tokens

A C program is made up of different tokens combined. These tokens include:

- Keywords
   - reserved words that can not be used elsewhere in the program
   - have a specific function
   - e.g. `if` `auto` etc
- Identifiers
   - names given to variables or functions
   - Should not name any identifier starting with numeric value or symbol. It should start only with underscore or alphabet. Should not contain space.
- Constants
   - A variable whose value never changes
- String Literal
   - sequence of characters enclosed in double quotation marks

## Comments

Comments are used to document and explain your codes and program logic.

- Multi-line Comment: begins with a /* and ends with a */, and can span several lines.
- End-of-line Comment: begins with // and lasts till the end of the current line.

You should use comments liberally to explain and document your codes. During program development, instead of deleting a chunk of statements permanently, you could comment-out these statements so that you could get them back later, if needed.

