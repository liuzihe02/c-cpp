#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    // Print the first argument (program name)
    std::cout << "argv[0]: " << argv[0] << std::endl;

    // Print each character of argv[0] individually
    std::cout << "Characters of argv[0]: ";
    for (int i = 0; argv[0][i] != '\0'; i++)
    {
        std::cout << argv[0][i] << " ";
    }
    std::cout << std::endl;

    // Demonstrate that it's a pointer to char
    std::cout << "First char of argv[0]: " << *argv[0] << std::endl;

    // Show the length of the string
    std::cout << "Length of argv[0]: " << strlen(argv[0]) << std::endl;

    // Demonstrate that it's a pointer to char
    std::cout << "First char of argv[1]: " << *argv[1] << std::endl;

    // Show the length of the string
    std::cout << "Length of argv[1]: " << strlen(argv[1]) << std::endl;

    return 0;
}