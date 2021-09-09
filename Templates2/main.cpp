#include <iostream>

// Example 1
// A template function to implement bubble sort.
// We can use this for any data type that supports
// comparison operator < and swap works for it.
template <class T> void BubbleSort(T a[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = n-1; i < j; j--){
            if(a[j] < a[j-1]){
                std::swap(a[j], a[j-1]);
            }
        }
    }
}

// Example 2
// Following is a simple example of template Array class.
template<typename T> class Array{
private:
    T *ptr;
    int size;
public:
    Array(T arr[], int s);
    void print();
};

template<typename T> Array<T>::Array(T arr[], int s){
    ptr = new T[s];
    size = s;
    for(int i = 0; i < size; i++){
        ptr[i] = arr[i];
    }
}

template<typename T> void Array<T>::print(){
    for(int i = 0; i < size; i++){
        std::cout<<*(ptr + i)<<"  ";
    }
    std::cout<<std::endl;
}

// Example 3
// Passing more than one argument to templates
template<class T, class S> class A{
private:
    T x;
    S y;
public:
    A(){
        std::cout << "Constructor A called!" << std::endl;
    }
};

// Example 4
// Passing more than one argument to templates & specify default types
template<class T, class S = char> class B{
private:
    T x;
    S y;
public:
    B(){
        std::cout << "Constructor B called!" << std::endl;
    }
};

// Example 5
// A C++ program to demonstrate working of non-type
// parameters to templates in C++.
template<class T, int max> int arrMin(T arr[], int n){
    int m = max;
    for(int i = 0; i < n; i++){
        if(arr[i] < m){
            m = arr[i];
        }
    }
    return m;
}

int main()
{
    // Example 1
    int a[5] = {10, 50, 30, 40, 20};
    char b[5] = {'a', 'q', 'b', 'm', 'p'};
    int n = sizeof(a)/sizeof(a[0]);

    //call template function
    BubbleSort<int>(a, n); //BubbleSort(a, n);
    std::cout<<"Sorted array: ";
    for(int i = 0; i < n; i++){
        std::cout<<a[i] <<"  ";
    }
    std::cout<<std::endl;

    BubbleSort<char>(b, n); //BubbleSort(b, n);
    std::cout<<"Sorted array: ";
    for(int i = 0; i < n; i++){
        std::cout<<b[i] <<"  ";
    }
    std::cout<<std::endl;

    // Example 2
    int arr[5] = {1, 2, 3, 4, 5};
    Array<int> c(arr, 5);
    c.print();

    // Example 3
    A<char, char> d;
    A<int, double> e;
    A<char, float> f;

    // Example 4
    B<int> g; //this calls B<int, char>
    B<int, float> h;

    // Example 5
    int arr1[] = {101, 20, 15, 12};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    char arr2[] = {22, 11, 5, 3};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    // Second template parameter to arrMin must be a constant
    std::cout<< arrMin<int, 1000>(arr1, n1) << std::endl;
    std::cout<< arrMin<char, 100>(arr2, n2) << std::endl;

    return 0;
}
