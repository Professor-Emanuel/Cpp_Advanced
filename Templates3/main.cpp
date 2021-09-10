#include <iostream>

//Example 1
//Swap data using function templates
template<typename T> void Swap(T &n1, T &n2){
    T temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

//Example 2
template<typename T> T Operation(T a, T b){
    if(a != 0){
        a = b/a + 3*a;
    }else{
        a = b*10;
    }
    return a;
}

//Example 3
//Program to add, subtract, multiply and divide two numbers using class template
template<typename T> class Calculator{
private:
    T num1;
    T num2;
public:
    Calculator(T n1, T n2){
        num1 = n1;
        num2 = n2;
    }

    void DisplayResults(){
        std::cout<< "Numbers are: " << num1 << " and " << num2 << "." << std::endl;
        std::cout<< "Sum = " << sum() << std::endl;
        std::cout<< "Subtraction = " << subtraction() << std::endl;
        std::cout<< "Product = " << product() << std::endl;
        std::cout<< "Division = " << division() << std::endl;
    }

    T sum(){
        return num1 + num2;
    }
    T subtraction(){
        return num1 - num2;
    }
    T product(){
        return num1 * num2;
    }
    T division(){
        if(num2 != 0){
            return num1 / num2;
        } else{
            std::cout<< "The denominator was 0! Shame!\n";
            return 0;
        }
    }
};

int main()
{
    //Example 1
    int i1 = 1, i2 = 0;
    float f1 = 1.1, f2 = 20.2;
    char c1 = 'a', c2 = 'f';

    std::cout << "Before passing data to function template.\n";
    std::cout << "i1 = " << i1 << "\ni2 = " << i2;
    std::cout << "\nf1 =" << f1 << "\nf2 = " << f2;
    std::cout << "\nc1 = " << c1 << "\nc2 = " << c2;

    Swap<int>(i1, i2);
    Swap(f1, f2);
    Swap(c1, c2);

    std::cout << "\n\nAfter passing data to function template.\n";
    std::cout << "i1 = " << i1 << "\ni2 = " << i2;
    std::cout << "\nf1 =" << f1 << "\nf2 = " << f2;
    std::cout << "\nc1 = " << c1 << "\nc2 = " << c2;
    std::cout <<"\n\n";

    //Example 2
    std::cout << "Operation(i1, i2) = " << Operation(i1, i2);
    std::cout << "\nOperation(f1, f2) = " << Operation(f1, f2);

    //Example 3
    Calculator intCalc(20, 5); //Calculator<int> intCalc(20, 5);
    std::cout<<"\n\nUsing ints\n";
    intCalc.DisplayResults();

    Calculator<float> floatCalc(20.50, 5.0);
    std::cout<<"\n\nUsing floats\n";
    floatCalc.DisplayResults();

    return 0;
}
