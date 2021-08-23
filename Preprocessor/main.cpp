//C++ Preprocessor
/*
There are number of preprocessor directives supported by C++ like #include, #define, #if, #else, #line, etc.
*/

#include <iostream>

#define DEBUG
#define PI 3.14159
#define MIN(a, b) ( a < b ? a:b )
#define Area(a, b) ( a * b )
#define Area2(a, b) ( (a) * (b) )

int main()
{
    std::cout << "Value of PI: " << PI << std::endl;

    int i = 100, j = 30;
    std::cout << "Min(i, j): " << MIN(i, j) << std::endl;
    std::cout << "Area(i, j): " << Area(i - 90 , j) << std::endl;

    //more correct
    std::cout << "Area2(i, j): " << Area2(i - 90 , j) << std::endl;


    #ifdef DEBUG
        std::cerr <<"Trace: Inside main function\n";
    #endif // DEBUG

    #if 0
        std::cout<< MKSTR(HELLO C++)<< std::endl;
    #endif // 0

    i = -10;
    j = 5;
    std::cout << "Min(i, j): " << MIN(i, j) << std::endl;

    #ifdef DEBUG
        std::cerr<< "Trace: Coming out of main function\n";
    #endif // DEBUG

    return 0;
}
