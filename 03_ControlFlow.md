# Control Flow

## Conditional Statements

### If Else

The syntax is like
```cpp
if ( condition ){
statements;}
 else {
statements;}
```
and can be chained with more ifs:
```cpp
#include <iostream>
using namespace std;
int main()
{
    int age;
    cout << "Enter a number: ";
    cin >> age;
    if (age >= 50)
    {
        cout << "Input number is greater than 50!" << endl;
    }
    //else if checks for another condition here, exactly like elif in Python
    else if (age == 50)
    {
        cout << "Input number is equal to 50!" << endl;
    }
    else
    {
        cout << "Input number is less than 50!" << endl;
    }
}
```

### Switch Case
Syntax:
```cpp
switch ( integer/character expression )
{
// use a case label at the end of here
case {value 1} :  
do this ;
 
case {value 2} :  
 do this ;  
 
default :  
do this ;
 }
```
The test expression of a switch statement must be of an integer or character type and the value of the case should be an integer or character as well.
```cpp
#include <iostream>
using namespace std;
 
int main()
{
    int i = 2;
    switch (i)
    {
    case 1:
        cout << "Statement 1" << endl;
        break;
 
    case 2:
        cout << "Statement 2" << endl;
        break;
 
    default:
        cout << "Default statement!" << endl;
    }
}
```

- The `break` keyword in a case block indicates the end of a particular case.
- If we do not put the `break` in each case, then even though the specific case is executed, the switch will *continue to execute all* the cases until the end is reached.
- The default case is optional. Whenever the expression's value is not matched with any of the cases inside the switch, then the default case will be executed

## Iteration Statements

### For Loops

Syntax:
```cpp
for (initialise counter; test counter; increment / decrement counter)
{
    //set of statements
}
```

```cpp
#include <iostream>
int main() {
    // initialize counter inside
    // followed by the test condition
    //incrementing or decrementing counter
    // loop terminates when the expression is false
    for (int i = 0; i < 5; i++) {
        std::cout << "Counter value: " << i << std::endl;
    }
    return 0;
}
```

### While Loops

```cpp
#include <iostream>
using namespace std;
 
int main()
{
    int i = 5;
    while (i < 10)
    {
        cout << i << " ";
        i++;
    }
 
    return 0;
}
```

### Do While

The do-while loop executes the statements inside the body once before checking the test condition, whereas while is check first then execute.

```cpp
#include <iostream>
using namespace std;
 
int main()
{
    int i = 5;
    do
    {
        cout << i << " ";
        i++;
    } while (i < 5);
 
    return 0;
}
```

### Break Statements

Break used to break the loop and go to the next block of code after the loop/switch case it was in.

```cpp
#include <iostream>
using namespace std;
 
int main()
{
    int num = 10;
    int i;
    for (i = 0; i < num; i++)
    {
        if (i == 6)
        {
            break;
        }
        cout << i << " ";
    }
 
    return 0;
}
```

### Continue Statement

Jumps to the beginning of loop for the next iteration, skipping the after this statement.

```cpp
#include <iostream>
using namespace std;
 
int main()
{
    for (int i = 0; i <= 10; i++)
    {
        if (i < 6)
        {
            continue;
        }
        cout << i << " ";
    }
    return 0;
}
```



