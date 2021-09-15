#include <iostream>

// Example 1
/*
The # and ## preprocessor operators are available in C++ and ANSI/ISO C.
The # operator causes a replacement-text token to be converted to a string surrounded by quotes.
*/
#define MKSTR(x) #x

// Example 2
// The ## operator is used to concatenate two tokens.
/*
When CONCAT appears in the program, its arguments are concatenated and used
to replace the macro. For example, CONCAT(HELLO, C++) is replaced by "HELLO C++" in the program as follows.
*/
#define CONCAT(x, y) x##y

// Example 3
// Predefined MACROS

int main()
{
    // Example 1
    std::cout << MKSTR(Hello man!) << std::endl;

    // Example 2
    int xy = 100;
    std::string ab = "Ana is blind!";
    std::cout << CONCAT(x, y) << std::endl; // std::cout << xy <<std::endl;
    std::cout << CONCAT(a, b) <<std::endl; // std::cout << ab <<std::endl;
    std::CONCAT(c, out) << "COOL!" <<std::endl; // std::cout << "COOL!" <<std::endl;

    // Example 3
    std::cout << "Value of __LINE__ : " << __LINE__ << std::endl;
    std::cout << "Value of __FILE__ : " << __FILE__ << std::endl;
    std::cout << "Value of __DATE__ : " << __DATE__ << std::endl;
    std::cout << "Value of __TIME__ : " << __TIME__ << std::endl;

    return 0;
}
