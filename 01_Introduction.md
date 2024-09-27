# Introduction

## Hello World

```cpp
// this indicates a comment
#include <iostream>
int main()
{
    std::cout << "Hello World";
    return 0;
}
```

### Explanation

- Lines beginning with `#` are preprocessor commands, which usually change what code is actually being compiled. `#include` tells thepreprocessor to dump in the contents of another file, here the `iostream` file, which defines the procedures for input/output.
- `cout<<` outputs some text to the screen

### Tokens
Tokens are the minimal chunks of language that has meaning to the compiler

- Keywords: words with special meaning, like `int` `for`
- Identifiers: names of things not built into the language like `cout` `std` `myFunction`
- Literals: values specified directly to the source code like `"myString"` `24.3`
- Operators: `+` `-`
- Punctuation/Separation: `{}` `;`
- Whitespace: ignored by the compiler, like spaces and newlines

## Variables and Scope

```cpp
#include <iostream>
using namespace std;
int a = 5; //global variable, accessible throughout the entire program!
void func()
{
    cout << a << endl;
}
int main()
{
    int a = 10; //local variable, this shadows the global a within the scope of main
    cout << a << endl;
    func();
    return 0;
}
```

Output:
```
10
5
```
A local variable was first declared - within the body of a function, a local variable takes precedence over a global variable with the same name. But once we go into `func` call stack, it considers the global variable `a` which is 5

- Unlike python where the inner function variables can access outside its scope, in C++ variables can only access local variables, global variables, and params passed to it
- global variables are accessible everywhere unless shadowed by a local variable; functions can access this directly if theres's no local variable with the same name