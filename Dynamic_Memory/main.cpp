#include <iostream>
#include <iomanip>
//C++ Dynamic Memory Allocation

class Box{
public:
    Box(){
        std::cout<< "Constructor!" << std::endl;
    }
    ~Box(){
        std::cout<< "Destructor!" << std::endl;
    }
};

int main()
{
    double* pvalue = NULL; // Pointer initialized with null
    pvalue = new double; // Request memory for the variable

    *pvalue = 34251.9912;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "Value: " << *pvalue << std::endl;

    delete pvalue; // free up the memory.

    double* arr = new double[5]; //memory allocation 1-d array
    /* INVALID, read:  https://stackoverflow.com/questions/50312128/cannot-convert-double-4-to-double-in-assignment
    double** matr = NULL;
    matr = new double [5][3]; //memory allocation 2-d array
    */

    for(int i=0; i<5; i++){
        arr[i] = i;
    }

    for(int i=0; i<5; i++){
        std::cout << arr[i] << std::endl;
    }

    Box* myBoxArray = new Box[4]; //calls constructor 4 times
    delete [] myBoxArray; //calls destructor 4 times
    return 0;
}
