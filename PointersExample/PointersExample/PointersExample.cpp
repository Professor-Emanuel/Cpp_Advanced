#include <iostream>

int main()
{
    //a POINTER is just an INTEGER that holds an address -> that address can point to int, float, user defined data type, etc
    int var = 8; //variables created on the STACK memory
    void* ptr = NULL; // or 0 or nullptr (added since cpp11)
    void* ptrI = &var; //debug and see what address of ptrI contains, you should see 08 00 00 00 -> 4 bytes and the value 8
                        // if var = 10 -> you should see 0a 00 00 00, since in hexadecimal 10 = a
    
    //the type of the POINTER doesn't really MATTER
    //but are useful for manipulation of memory
    //the above can be
    int* ptrJ = &var;// ptrI, ptrJ, ptrD point to the same memory address that contains 08 00 00 00
    double* ptrD = (double*)&var; // ptrD point to the same memory address as the other pointers but contains some junk value

    std::cout << "Address of var: " << &var << " with value: " << var << std::endl;
    std::cout << "Address of var: " << ptrI << " with value: " << var << std::endl; // *ptrI -> ERROR, because it has VOID type
    std::cout << "Address of var: " << ptrJ << " with value: " << *ptrJ << std::endl;
    std::cout << "Address of var: " << ptrD << " with value: " << *ptrD << std::endl;

    std::cout << "Address of ptrI: " << &ptrI << " with value: " << ptrI << std::endl;
    std::cout << "Address of ptrJ: " << &ptrJ << " with value: " << ptrJ << std::endl;
    std::cout << "Address of ptrD: " << &ptrD << " with value: " << ptrD << std::endl;

    char* buffer = new char[8]; // 8 bytes allocated, with the pointer pointing to the begining of that memory
    memset(buffer, 0, 8); // 00 00 00 00 00 00 00 00 -> 8 bytes of zeros
    char** ptrC = &buffer;

    delete[] buffer; // deallocate memory

    return 0;
}
