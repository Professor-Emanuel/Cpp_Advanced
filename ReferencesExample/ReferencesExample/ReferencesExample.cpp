#include <iostream>

//using values
void Increment(int value) {
    value++;
}

//using pointers
void IncrementP(int* value) {
    (*value)++; //dereference -> then increment value, to actually write at that memory address
    //*value++; -> first will increment address and then dereferences it
}

//using references
void IncrementR(int& value) {
    value++;
}


int main()
{
    // you can create a void pointer or a pointer and set it to 0, NULL, nullptr
    // references are not new variables
    // references are as pointers but they need to reference something, so they can not be NULL, nullptr
    int a = 5;
    Increment(a); //function works with a copy of variable a, so after exiting, a still remains 5
    std::cout << "a = " << a << std::endl;

    IncrementP(&a); //function works with the address of variable a, so after exiting, a will be 6
    std::cout << "a = " << a << std::endl;

    IncrementR(a); //function works with the reference of variable a, so after exiting, a will be 7 (because we called IncrementP before)
    std::cout << "a = " << a << std::endl;
    
    //pointer storing address of a
    int* c = &a;

    //create a reference to a
    int& ref = a; // ref doesn't actually exit in memory, just in the source code
                    //by compiling, you won't get 2 variables, ref ,and a; just a

    ref = 2; // this will change variable a, since ref is referencing variable a;
    std::cout << "a = " << a << std::endl;

    //once you declare a reference you can not change to what it is referencing, 
    //and it can not be just declared, need to reference it to something
    //int& ref2 -> ERROR
    int b = 8;
    ref = b; // this doesn't reference to variable b, it will just make a = 8;
    std::cout << "a = " << a << std::endl;

    //workaround for changing "references"
    int* refP = &a;
    *refP = 2; //set a = 2
    refP = &b;
    *refP = 1; // set b = 1
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    return 0;
}