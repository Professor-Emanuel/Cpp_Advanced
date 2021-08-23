//C++ Templates
/*
A template is a blueprint or formula for creating a generic class or a function.
The library containers like iterators and algorithms are examples
of generic programming and have been developed using template concept.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

//Function Template
template <typename S> inline S const& Max(S const &a, S const &b){
    return a < b ? b:a;
}

//Class Template
template<class T> class Stack{
private:
    std::vector<T> elements;

public:
    void push(T const &); // push element
    void pop(); // pop element
    T top() const; // return top element
    bool empty() const{
        return elements.empty(); // return true if empty.
    }

};

template<class T> void Stack<T>::push(T const &element){
    // append copy of passed element
    elements.push_back(element);
}

template<class T> void Stack<T>::pop(){
    if(elements.empty()){
        throw std::out_of_range("Stack<>::pop(): empty stack!\n");
    }

    //remove last element
    elements.pop_back();
}

template<class T> T Stack<T>::top() const{
    if(elements.empty()){
        throw std::out_of_range("Stack<>::top(): empty stack!\n");
    }

    //return copy of last element
    return elements.back();
}

int main()
{
    //FOR function template
    int i = 10;
    int j = 29;
    std::cout<< "Max(i, j) = " << Max(i, j) << std::endl;

    double f = 20.19;
    double g = 29.21;
    std::cout<< "Max(f, g) = " << Max(f, g) << std::endl;

    std::string s = "Hello";
    std::string w = "AWorld";
    std::cout<< "Max(s, w) = " << Max(s, w) << std::endl;


    //FOR class template
    try{
        Stack<int> intStack; //Stack of ints;
        Stack<std::string> stringStack; //Stack of strings;

        //manipulate int stack
        intStack.push(7);
        std::cout<< intStack.top() << std::endl;

        //manipulate string stack
        stringStack.push("Hello");
        std::cout<< stringStack.top() << std::endl;

        stringStack.pop();
        stringStack.pop();

        //intStack.pop();
        //intStack.top();

    } catch(std::exception const &ex){
        std::cerr <<"Exception: " << ex.what() << std::endl;
        return -1;
    }

    return 0;
}
