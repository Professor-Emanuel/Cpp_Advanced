#include <iostream>
// Constructors, Destructors, Inheritance

// Example 1
class Entity {
public:
    float x, y;

    void Init() {
        x = 0.0f;
        y = 0.0f;
    }

    //constructor
    Entity() {
        std::cout << "Constructor Called!" << std::endl;
        x = 0.0f;
        y = 0.0f;
    }

    //custom constructor
    Entity(float xp, float yp) {
        std::cout << "Custom Constructor Called!" << std::endl;
        x = xp;
        y = yp;
    }

    //destructor
    ~Entity() {
        std::cout << "Destructor Called!" << std::endl;
    }

    void Print() {
        std::cout << x << " & " << y << std::endl;
    }
};


// Example 2
class Log {
    //Log() {}
    Log() = delete;
public:
    static void Write() {

    }
};


// Example 3
// Inheritance
class Thing {
public:
    float x, y; // each will have 4 bytes of memory on a 32-bit application
    
    void Move(float xa, float ya) {
        x += xa;
        y += ya;
    }

};

//class Player inherits from class Thing
class Player:public Thing {
public:
    const char* name; // 4 bytes of memory on a 32-bit application

    void PrintName() {
        std::cout << name << std::endl;
    }
};


int main()
{
    // Example 1
    //cpp makes default constructor if one is not defined, but variables will not be initialized, but contain junk
    Entity e; // calls the constructor, no matter if we use Init() or not or if we have a constructor
    e.Init(); //this call is not needed anymore, since we have the no parameters constructor
    std::cout << e.x << std::endl; //-> ERROR if memory is not initialized, using a function or constructor or manually

    e.Print(); //this function works but x & y contain junk values

    Entity e2; // calls the constructor
    e2.Print();

    Entity e3(2.2f, 4.4f); // calls the custom constructor
    e3.Print();


    // Example 2, class with only STATIC methods
    Log::Write();
    //we don't want the user to be able to instantiate the class
    //Log l; //this is allowed, unless we make the constructor private or delete it (see class Log!) -> resulting in ERROR

    // Example 3
    std::cout << sizeof(Thing) << std::endl;
    std::cout << sizeof(Player) << std::endl;

    Player player; //player can access all members and methods of Thing class (because they are public!)
    player.x = 2.2f;
    player.y = 2.2f;
    player.name = "Manu";
    player.Move(5.0f, 5.0f);
    player.PrintName();

    std::cin.get();
    //destructor will be called after the main function finished

    return 0;
}
