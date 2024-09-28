#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Element" << i << " is " << arr[i];
        if (i < size - 1)
        {
            cout << ", \n";
        }
        else
        {
            cout << "\n";
        }
    }
}

// this returns a pointer to an array, basically the same as returning an array directly
// we reverse it in place
int *reverseArray(int arr[], int size)
{
    // we stop in the middle to avoid swapping twice!
    int stop = size / 2;
    for (int i = 0; i < stop; i++)
    {
        // store the old value
        int temp = arr[size - i - 1];
        arr[size - i - 1] = arr[i];
        arr[i] = temp;
    };
    return arr;
}

// using pointer notation
int *reverseArrayPointer(int arr[], int size)
{
    // Initialize two pointers:
    // 'start' points to the beginning of the array
    // 'end' points to the last element of the array
    int *start = arr;
    int *end = arr + size - 1;

    // Continue swapping until the pointers meet in the middle
    while (start < end)
    {
        // Swap the elements that start and end point to

        // temp is the actual value
        int temp = *start;
        // the value of start is being set to the value of end
        *start = *end;
        // update end with the old value of start
        *end = temp;

        // Move start forward and end backward
        start++;
        end--;
    }
    return arr;
}

// global variables, make sure these makes sense with the test files
const int WIDTH = 3;
const int LENGTH = 3;

void transpose(int input[LENGTH][WIDTH])
{
    for (int i = 0; i < LENGTH; i++)
    {
        // this ensure we only consider elems where the column j is more than row i, to avoid double swaps
        for (int j = i + 1; j < WIDTH; j++)
        {
            // Swap elements across the main diagonal
            int temp = input[i][j];
            input[i][j] = input[j][i];
            input[j][i] = temp;
        }
    }
}

// the args after program name must be integers
int main(int argc, char *argv[])
{
    int size = argc - 1;
    int *integerArray = new int[size];

    for (int i = 0; i < size; i++)
    {
        integerArray[i] = stoi(argv[i + 1]);
    }
    cout << "Printing all the elements in this array: \n";
    printArray(integerArray, size);

    cout << "Now reversing the array. This is \n";
    reverseArrayPointer(integerArray, size);
    printArray(integerArray, size);

    // Test for transpose function
    cout << "\nTesting transpose function:\n";
    int testMatrix[LENGTH][WIDTH] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "Original matrix:\n";
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            cout << testMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    transpose(testMatrix);

    cout << "\nTransposed matrix:\n";
    for (int i = 0; i < LENGTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            cout << testMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}