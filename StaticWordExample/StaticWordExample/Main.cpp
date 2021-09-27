#include <iostream>
// Example 1, see StaticWordExample.cpp file
//extern int s_Varible;
void Function() {

}


// Example 2
// you can use class here also.
struct Entity {
	static int x, y;

	//static methods can not access non-static variables
	static void Print() {
		std::cout << x << " " << y << std::endl;
	}
};

// because we declared x & y static, we have to define/declare them
int Entity::x;
int Entity::y;


// Example 3
// LOCAL static
void Function2() {
	static int i = 0; //this variable will be local to Function2, same behaviour could be achived with global variables
	i++;
	std::cout << i << std::endl;
}


// Example 4
class Singleton {
private:
	static Singleton* s_Instance;
public:
	static Singleton& Get() { return *s_Instance; }

	void Hello(){}
};

//you have to declare the instance !!!
Singleton* Singleton::s_Instance = nullptr;


// Example 5 (need to rename Singleton)
//Other WAY to do what we have in Example4
class Singleton2 {
public:
	static Singleton2& Get() 
	{ 
		static Singleton2 instance; //without static here, instance will get destroyed after the next }
		return instance;			//which will be a problem since we return by reference
	}

	void Hello() {}
};



int main(){
	// Example 2
	Entity e;
	e.x = 2;
	e.y = 3;
	
	Entity e1;
	//e1.x = 5;
	//e1.y = 8;
	//we can refer to them as (which is more correct)
	Entity::x = 5;
	Entity::y = 8;


	//e.Print(); // result: 5 8
	//e1.Print(); // result: 5 8
	Entity::Print(); //more correct to call the method like this
	Entity::Print();

	// Example 3
	//WITHOUT static, every Function2() call will create a brand new variable and initialize it to 0 and 
	//increment it by 1, which will result in 1 being printed 5 times
	//WITH static, first call to Function2() will create variable i, initialize it to 0, increment it to 1
	//and the subsequent calls will work with this variable incremented with 1 by each call
	//which result in 1 2 3 4 5 being printed
	Function2();
	Function2();
	Function2();
	Function2();
	Function2();

	// Example 4
	Singleton::Get().Hello();

	// Example 5
	Singleton2::Get().Hello();

	std::cin.get();
	return 0;
}