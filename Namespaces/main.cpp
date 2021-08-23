//C++ Namespaces
/*
A namespace is designed to overcome this difficulty and is used as additional information to differentiate
similar functions, classes, variables etc. with the same name available in different libraries. Using
namespace, you can define the context in which names are defined. In essence, a namespace defines a scope.
*/
#include <iostream>

/*
The using directive
You can also avoid prepending of namespaces with the using namespace directive.
This directive tells the compiler that the subsequent code is making use of names
in the specified namespace. The namespace is thus implied for the following code

EXAMPLE:
    using namespace std;
    cout<<"Text";

INSTEAD of:
    std::cout<<"Text";

Same with any user defined namespace
*/

namespace firstNamespace{
    void func(){
        using std::cout;
        std::cout << "Inside firstNamespace" << std::endl;
    }
}

namespace secondNamespace{
    void func(){
        std::cout << "Inside secondNamespace" << std::endl;
    }
}

namespace thirdNamespace{
    void func(){
        std::cout << "Inside thirdNamespace" << std::endl;
    }

    namespace fourthNamespace{
        void func(){
            std::cout << "Inside fourthNamespace, which is inside thirdNamespace. (nested namespaces)!" << std::endl;
        }
    }
}

using namespace thirdNamespace::fourthNamespace;

int main()
{
    // Calls function from first name space.
    firstNamespace::func();

    // Calls function from second name space.
    secondNamespace::func();

    func();
    return 0;
}
