#include <iostream>
#include <string>
using namespace std;

int sum(const int a)
{
    return a;
};

// this allows use to take anywhere between 2 and 4 integers
int sum(const int a, const int b, const int c = 0, const int d = 0)
{
    return a + b + c + d;
}

// this function uses iteration to take any number of integers
int sumIterative(int integerList[], int size)
{
    int out = 0;
    for (int i = 0; i < size; i++)
    {
        out += integerList[i];
    };
    return out;
}

int sumRecursive(int integerList[], int size)
{
    // base case
    if (size == 0)
    {
        return 0;
    }
    else
    {
        // integerList[0] returns the actual value, while &integerList[1] gives the address of the next subarray
        return integerList[0] + sumRecursive(&integerList[1], size - 1);
    }
}

// argc is the number of CLI args (including program name), while argv are the values, as an array of C-style strings
//  each element is a char pointer
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Please provide at least one integer argument." << endl;
        return 1;
    }

    int size = argc - 1;
    int *integerArray = new int[size];

    for (int i = 0; i < size; i++)
    {
        integerArray[i] = stoi(argv[i + 1]);
    }

    cout << sumRecursive(integerArray, size) << endl;
    return 0;
}