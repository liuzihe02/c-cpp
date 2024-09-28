#include <iostream>
#include <cassert>
using namespace std;

int lengthString(char *myString)
{
    int length = 0;
    while (*(myString + length) != '\0')
    {
        length += 1;
    }
    return length;
}

void swapValues(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swapPointers(int *x, int *y)
{
    // dereference x and set temp to the actual value
    int temp = *x;
    *x = *y;
    *y = temp;
}

void longSeq(const char *myStringPtr)
{
    const char *nthCharPtr = myStringPtr + 5;
    nthCharPtr -= 2;
    cout << "the 4th element should be " << *nthCharPtr << endl;
    // create a pointer that points to the pointer
    const char **pointerPtr = &nthCharPtr;
    cout << "the value (which is an address) stored in this weird pointer-to-pointer is: (these are equivalent)   " << pointerPtr << "   " << &nthCharPtr << endl;
    cout << "this is weird, dont do this " << *pointerPtr << endl;
    cout << "the actual value (not an address) stored in this weird pointer-to-pointer is   " << **pointerPtr << endl;
    nthCharPtr += 1;

    int far = 0;
    while (*nthCharPtr != '\0')
    {
        nthCharPtr -= 1;
        far += 1;
    };
    cout << "the distance is " << far << endl;
}

// the args after program name must be integers
int main(int argc, char *argv[])
{
    char nonEmptyString[] = "thisstring";
    cout << "Testing length of string function" << lengthString(nonEmptyString) << endl;

    // testing my swapping functions
    int a = 5, b = 10;
    // pass in the actual values, which is a reference to the real thing
    swapValues(a, b);
    assert(a == 10 && b == 5);
    cout << "swapValues test passed" << endl;

    // testing my swapping functions
    int g = 5, h = 10;
    // pass in the addresses, which are the pointers
    swapPointers(&g, &h);
    assert(g == 10 && h == 5);
    cout << "swapPointers test passed" << endl;

    // testing problem 7.5
    const char *oddOrEven = "Never odd or even ";
    longSeq(oddOrEven);
}