#All is done using Code::Blocks 20

# Cpp_Advanced
Independent Programs showcasing Advanced C++ Principles!

https://www.tutorialspoint.com/cplusplus/cpp_files_streams.htm

https://www.learncpp.com/

https://www.learncpp.com/cpp-tutorial/



#C++ Files and Streams



Reading and writing from a file requires the standard C++ library called fstream, which defines three new data types −


Data Type & Description


    1	ofstream - This data type represents the output file stream and is used to create files and to write information to files.


    2   ifstream - This data type represents the input file stream and is used to read information from files.

    3	fstream - This data type represents the file stream generally, and has the capabilities of both ofstream and ifstream 
    which means it can create files, write information to files, and read information from files.
    
    
To perform file processing in C++, header files <iostream> and <fstream> must be included in your C++ source file.

  
Opening a File
  
  
A file must be opened before you can read from it or write to it. Either ofstream or fstream object may be used to open a file for writing. And ifstream object is used to open a file for reading purpose only.

  
Following is the standard syntax for open() function, which is a member of fstream, ifstream, and ofstream objects.

  
         void open(const char *filename, ios::openmode mode);
  
  
Here, the first argument specifies the name and location of the file to be opened and the second argument of the open() member function defines the mode in which the file should be opened.

  
Mode Flag & Description
  
  
      1	ios::app - Append mode. All output to that file to be appended to the end.

      2	ios::ate - Open a file for output and move the read/write control to the end of the file.

      3	ios::in - Open a file for reading.

      4	ios::out - Open a file for writing.

      5	ios::trunc - If the file already exists, its contents will be truncated before opening the file.

  
You can combine two or more of these values by ORing them together. For example if you want to open a file in write mode and want to truncate it in case that already exists, following will be the syntax −

  
    ofstream outfile;
    outfile.open("file.dat", ios::out | ios::trunc );

  
Similar way, you can open a file for reading and writing purpose as follows −

  
    fstream  afile;
    afile.open("file.dat", ios::out | ios::in );

  
Closing a File


When a C++ program terminates it automatically flushes all the streams, release all the allocated memory and close all the opened files. But it is always a good practice that a programmer should close all the opened files before program termination.

  
Following is the standard syntax for close() function, which is a member of fstream, ifstream, and ofstream objects.

  
    void close();
  
  
Writing to a File

  
While doing C++ programming, you write information to a file from your program using the stream insertion operator (<<) just as you use that operator to output information to the screen. The only difference is that you use an ofstream or fstream object instead of the cout object.

  
Reading from a File

  
You read information from a file into your program using the stream extraction operator (>>) just as you use that operator to input information from the keyboard. The only difference is that you use an ifstream or fstream object instead of the cin object.
  
  
File Position Pointers
  
  
Both istream and ostream provide member functions for repositioning the file-position pointer. These member functions are seekg ("seek get") for istream and seekp ("seek put") for ostream.
  

The argument to seekg and seekp normally is a long integer. A second argument can be specified to indicate the seek direction. The seek direction can be ios::beg (the default) for positioning relative to the beginning of a stream, ios::cur for positioning relative to the current position in a stream or ios::end for positioning relative to the end of a stream.

  
The file-position pointer is an integer value that specifies the location in the file as a number of bytes from the file's starting location. Some examples of positioning the "get" file-position pointer are −

  
      // position to the nth byte of fileObject (assumes ios::beg)
      fileObject.seekg( n );

      // position n bytes forward in fileObject
      fileObject.seekg( n, ios::cur );

      // position n bytes back from end of fileObject
      fileObject.seekg( n, ios::end );

      // position at end of fileObject
      fileObject.seekg( 0, ios::end );

  

#C++ Exception Handling
  
  
  
An exception is a problem that arises during the execution of a program. A C++ exception is a response to an exceptional circumstance that arises while a program is running, such as an attempt to divide by zero.

  
Exceptions provide a way to transfer control from one part of a program to another. C++ exception handling is built upon three keywords: try, catch, and throw.

  
throw − A program throws an exception when a problem shows up. This is done using a throw keyword.

  
catch − A program catches an exception with an exception handler at the place in a program where you want to handle the problem. The catch keyword indicates the catching of an exception.

  
try − A try block identifies a block of code for which particular exceptions will be activated. It's followed by one or more catch blocks.

  
Assuming a block will raise an exception, a method catches an exception using a combination of the try and catch keywords. A try/catch block is placed around the code that might generate an exception. Code within a try/catch block is referred to as protected code, and the syntax for using try/catch as follows −


      try {
         // protected code
      } catch( ExceptionName e1 ) {
         // catch block
      } catch( ExceptionName e2 ) {
         // catch block
      } catch( ExceptionName eN ) {
         // catch block
      }
  
  
You can list down multiple catch statements to catch different type of exceptions in case your try block raises more than one exception in different situations.

  
Throwing Exceptions
  
  
Exceptions can be thrown anywhere within a code block using throw statement. The operand of the throw statement determines a type for the exception and can be any expression and the type of the result of the expression determines the type of exception thrown.

  
Following is an example of throwing an exception when dividing by zero condition occurs −


      double division(int a, int b) {
         if( b == 0 ) {
            throw "Division by zero condition!";
         }
         return (a/b);
      }

  
Catching Exceptions
  
  
The catch block following the try block catches any exception. You can specify what type of exception you want to catch and this is determined by the exception declaration that appears in parentheses following the keyword catch.

  
      try {
         // protected code
      } catch( ExceptionName e ) {
        // code to handle ExceptionName exception
      }
  
  
Above code will catch an exception of ExceptionName type. If you want to specify that a catch block should handle any type of exception that is thrown in a try block, you must put an ellipsis, ..., between the parentheses enclosing the exception declaration as follows −

  
      try {
         // protected code
      } catch(...) {
        // code to handle any exception
      }
  
  
C++ Standard Exceptions
  
  
C++ provides a list of standard exceptions defined in <exception> which we can use in our programs:  https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
  

You can define your own exceptions by inheriting and overriding exception class functionality.
  
  

#C++ Dynamic Memory
  


A good understanding of how dynamic memory really works in C++ is essential to becoming a good C++ programmer. Memory in your C++ program is divided into two parts −

  
      The stack − All variables declared inside the function will take up memory from the stack.

  
      The heap − This is unused memory of the program and can be used to allocate the memory dynamically when program runs.

  
Many times, you are not aware in advance how much memory you will need to store particular information in a defined variable and the size of required memory can be determined at run time.

  
You can allocate memory at run time within the heap for the variable of a given type using a special operator in C++ which returns the address of the space allocated. This operator is called new operator.

  
If you are not in need of dynamically allocated memory anymore, you can use delete operator, which de-allocates memory that was previously allocated by new operator.

  
new and delete Operators
  
  
The following syntax is the generic syntax to use new operator to allocate memory dynamically for any data-type.  
  
  
      new data-type;
  
  
Here, data-type could be any built-in data type including an array or any user defined data types including class or structure. Let us start with built-in data types. For example we can define a pointer to type double and then request that the memory be allocated at execution time. We can do this using the new operator with the following statements −

  
      double* pvalue  = NULL; // Pointer initialized with null
      pvalue  = new double;   // Request memory for the variable

  
The memory may not have been allocated successfully, if the free store had been used up. So it is good practice to check if new operator is returning the NULL pointer and take appropriate action as below −

  
      double* pvalue  = NULL;
      if( !(pvalue  = new double )) {
         cout << "Error: out of memory." <<endl;
         exit(1);
      }
  
  
The malloc() function from C, still exists in C++, but it is recommended to avoid using malloc() function. The main advantage of new over malloc() is that new doesn't just allocate memory, it constructs objects which is the prime purpose of C++.

  
At any point, when you feel a variable that has been dynamically allocated is not anymore required, you can free up the memory that it occupies in the free store with the ‘delete’ operator as follows −

  
      delete pvalue;        // Release memory pointed to by pvalue  
  
  
https://en.cppreference.com/w/c/types/NULL

  
https://en.cppreference.com/w/cpp/types/NULL
  

https://dzone.com/articles/what-exactly-nullptr-is-in-c
  
  
Dynamic Memory Allocation for Arrays
  
  
Consider you want to allocate memory for an array of characters, i.e., string of 20 characters. Using the same syntax what we have used above we can allocate memory dynamically as shown below.

  
      char* pvalue  = NULL;         // Pointer initialized with null
      pvalue  = new char[20];       // Request memory for the variable
  
  
To remove the array that we have just created the statement would look like this −

  
      delete [] pvalue;             // Delete array pointed to by pvalue
  
  
Following the similar generic syntax of new operator, you can allocate for a multi-dimensional array as follows −

  
     /* INVALID, read:  https://stackoverflow.com/questions/50312128/cannot-convert-double-4-to-double-in-assignment
      double** matr = NULL;
      matr = new double [5][3]; //memory allocation 2-d array
    */
  
  
However, the syntax to release the memory for multi-dimensional array will still remain same as above −

  
      delete [] pvalue;            // Delete array pointed to by pvalue
  
  
Dynamic Memory Allocation for Objects - Objects are no different from simple data types.
  

  
#C++ Namespaces
    
  
  
Consider a situation, when we have two persons with the same name, Zara, in the same class. Whenever we need to differentiate them definitely we would have to use some additional information along with their name, like either the area, if they live in different area or their mother’s or father’s name, etc.

    
Same situation can arise in your C++ applications. For example, you might be writing some code that has a function called xyz() and there is another library available which is also having same function xyz(). Now the compiler has no way of knowing which version of xyz() function you are referring to within your code.

    
A namespace is designed to overcome this difficulty and is used as additional information to differentiate similar functions, classes, variables etc. with the same name available in different libraries. Using namespace, you can define the context in which names are defined. In essence, a namespace defines a scope.

    
Defining a Namespace - A namespace definition begins with the keyword namespace followed by the namespace name as follows −

    
            namespace namespace_name {
               // code declarations
            }

    
To call the namespace-enabled version of either function or variable, prepend (::) the namespace name as follows −


            name::code;  // code could be variable or function.  
  
    
The using directive
    
    
You can also avoid prepending of namespaces with the using namespace directive. This directive tells the compiler that the subsequent code is making use of names in the specified namespace. The namespace is thus implied for the following code   
    
Example:
    
            using namespace std;
            cout<<"Text";
    
    
    Instead of
    
            
            std::cout<<"Text";
  
  
The ‘using’ directive can also be used to refer to a particular item within a namespace. For example, if the only part of the std namespace that you intend to use is cout, you can refer to it as follows −

    
            using std::cout;
    

Names introduced in a using directive obey normal scope rules. The name is visible from the point of the using directive to the end of the scope in which the directive is found. Entities with the same name defined in an outer scope are hidden.

    
Discontiguous Namespaces - A namespace can be defined in several parts and so a namespace is made up of the sum of its separately defined parts. The separate parts of a namespace can be spread over multiple files.
    

So, if one part of the namespace requires a name defined in another file, that name must still be declared. Writing a following namespace definition either defines a new namespace or adds new elements to an existing one −


            namespace namespace_name {
               // code declarations
            }
    
    
Nested Namespaces - Namespaces can be nested where you can define one namespace inside another name space as follows −

    
            namespace namespace_name1 {
               // code declarations
               namespace namespace_name2 {
                  // code declarations
               }
            }
    
    
You can access members of nested namespace by using resolution operators as follows −

    
            // to access members of namespace_name2
            using namespace namespace_name1::namespace_name2;


            // to access members of namespace:name1
            using namespace namespace_name1;
    
    
In the above statements if you are using namespace_name1, then it will make elements of namespace_name2 available in the scope
    
    
    
#C++ Templates
    
    
    
Templates are the foundation of generic programming, which involves writing code in a way that is independent of any particular type.

    
A template is a blueprint or formula for creating a generic class or a function. The library containers like iterators and algorithms are examples of generic programming and have been developed using template concept.

    
There is a single definition of each container, such as vector, but we can define many different kinds of vectors for example, vector <int> or vector <string>.

    
You can use templates to define functions as well as classes, let us see how they work −

    
Function Template - The general form of a template function definition is shown here −


            template <class type> ret-type func-name(parameter list) {
               // body of function
            } 
    
    
Here, type is a placeholder name for a data type used by the function. This name can be used within the function definition.
    
    
Class Template - Just as we can define function templates, we can also define class templates. The general form of a generic class declaration is shown here −

    
            template <class type> class class-name {
               .
               .
               .
            }
    
    
Here, type is the placeholder type name, which will be specified when a class is instantiated. You can define more than one generic data type by using a comma-separated list.    
    
    
More on templates: https://docs.microsoft.com/en-us/cpp/cpp/templates-cpp?view=msvc-160
    

A template is a simple and yet very powerful tool in C++. The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need sort() for different data types. Rather than writing and maintaining the multiple codes, we can write one sort() and pass data type as a parameter. 
    
    
C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second keyword can always be replaced by keyword ‘class’.
    
    
How do templates work? 

    
Templates are expanded at compiler time. This is like macros. The difference is, the compiler does type checking before template expansion. The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of same function/class.     

    
More on generics in C++:  https://www.geeksforgeeks.org/generics-in-c/
    
    
Class Templates Like function templates, class templates are useful when a class defines something that is independent of the data type. Can be useful for classes like LinkedList, BinaryTree, Stack, Queue, Array, etc. 
    

There is no semantic difference between class and typename in a template-parameter. typename however is possible in another context when using templates - to hint at the compiler that you are referring to a dependent type. ... Without typename the compiler can't tell in general whether you are referring to a type or not.
    
    
Read more at:    https://newbedev.com/difference-of-keywords-typename-and-class-in-templates
    
    
What is the difference between function overloading and templates? 
    
    
Both function overloading and templates are examples of polymorphism feature of OOP. Function overloading is used when multiple functions do similar operations, templates are used when multiple functions do identical operations.
    
    
What happens when there is a static member in a template class/function? 
    
    
Each instance of a template contains its own static variable. See Templates and Static variables for more details:    https://www.geeksforgeeks.org/templates-and-static-variables-in-c/
    
    
What is template specialization? 
    
    
Template specialization allows us to have different code for a particular data type. See Template Specialization for more details:    https://www.geeksforgeeks.org/template-specialization-c/
    
    
Can we pass nontype parameters to templates? 
    
    
We can pass non-type arguments to templates. Non-type parameters are mainly used for specifying max or min values or any other constant value for a particular instance of a template. The important thing to note about non-type parameters is, they must be const. The compiler must know the value of non-type parameters at compile time. Because the compiler needs to create functions/classes for a specified non-type value at compile time. 
    
    
More on templates:    https://en.cppreference.com/w/cpp/language/templates
    
    
https://www.mygreatlearning.com/blog/templates-in-cpp/
    
    
https://www.programiz.com/cpp-programming/templates
    
    

    
#C++ Preprocessor
    
    
    
The preprocessors are the directives, which give instructions to the compiler to preprocess the information before actual compilation starts.

    
All preprocessor directives begin with #, and only white-space characters may appear before a preprocessor directive on a line. Preprocessor directives are not C++ statements, so they do not end in a semicolon (;).

    
You already have seen a #include directive in all the examples. This macro is used to include a header file into the source file.

    
There are number of preprocessor directives supported by C++ like #include, #define, #if, #else, #line, etc.

    
The #define Preprocessor - The #define preprocessor directive creates symbolic constants. The symbolic constant is called a macro and the general form of the directive is −

    
            #define macro-name replacement-text 
    
    
When this line appears in a file, all subsequent occurrences of macro in that file will be replaced by replacement-text before the program is compiled.
    
    
Function-Like Macros - You can use #define to define a macro which will take arguments.    
    
    
Conditional Compilation
    
    
There are several directives, which can be used to compile selective portions of your program's source code. This process is called conditional compilation.

    
The conditional preprocessor construct is much like the ‘if’ selection structure. Consider the following preprocessor code −

    
            #ifndef NULL
               #define NULL 0
            #endif
    
    
You can compile a program for debugging purpose. You can also turn on or off the debugging using a single macro as follows −

    
            #ifdef DEBUG
               cerr <<"Variable x = " << x << endl;
            #endif
    
    
This causes the cerr statement to be compiled in the program if the symbolic constant DEBUG has been defined before directive #ifdef DEBUG. You can use #if 0 statment to comment out a portion of the program as follows −

    
            #if 0
               code prevented from compiling
            #endif   
    
    
The # and ## Operators - The # and ## preprocessor operators are available in C++ and ANSI/ISO C. The # operator causes a replacement-text token to be converted to a string surrounded by quotes.    
    
    
    
    
    
    
    
    
    
    
    
    
