#include <iostream>
#include <exception>
//C++ Exception Handling
//The following is an example, which throws a division by zero exception and we catch it in catch block.

double division(int a, int b){
    if(b==0){
        throw "Division by zero condition!";
    }
    return (a/b);
}

//You can define your own exceptions by inheriting and overriding exception class functionality.
//Following is the example, which shows how you can use std::exception class to implement your own exception in standard way

struct MyException: public std::exception{
    const char* what() const throw (){
        return "C++ Exception";
    }
};

int main()
{
    int x = 50, y = 0;
    double z = 0;

    try{
        z = division(x, y);
        std::cout<< z << std::endl;
    } catch( const char* msg){
        std::cerr << msg << std::endl;
    }

    try{
        throw MyException();
    } catch(MyException &e){
        std::cout << "MyException caught"<< std::endl;
        std::cout << e.what() <<std::endl;
    } catch(std::exception &e){
        //Other errors
    }

    //Here, what() is a public method provided by exception class and it has been overridden
    //by all the child exception classes. This returns the cause of an exception.

    return 0;
}
