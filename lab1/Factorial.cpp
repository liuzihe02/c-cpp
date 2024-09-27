#include <iostream>

using namespace std;

int main()
{
    short number;
    cout << "Enter a number: ";
    cin >> number;

    if (number<0){
        cout<< "No Negative Numbers allowed!";
        return 1;
    }

    if (number>18){
        // you can also use \n to have a newline
        cout<<"Your program probably cannot handle this code \n";
        return 1;
        
    }

    cout << "The factorial of " << number << " is ";

    int accumulator = 1;
    for (; number > 0; accumulator *= number--);
    cout << accumulator << ".\n";

    return 0;
}