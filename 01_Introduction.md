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