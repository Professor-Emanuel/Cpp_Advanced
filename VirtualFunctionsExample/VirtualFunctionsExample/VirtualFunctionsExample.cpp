//Virtual & Pure Virtual Functions
//Virtual functions come with additional run-time cost, they use additional memory and additional performance time
#include <iostream>

class Entity {
public:
    virtual std::string GetName() { return "Entity"; }
};

class Player:public Entity {
private:
    std::string m_Name;

public:
    Player(const std::string& name):m_Name(name) {}

    std::string GetName() override { return m_Name; }
};

void PrintName(Entity* entity) {
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    Entity* e = new Entity();
    std::cout << e->GetName() << std::endl;
    PrintName(e); //uses the GetName() from Entity class, unless we make the function VIRTUAL

    Player* p = new Player("Emanuel");
    std::cout << p->GetName() << std::endl; //uses the GetName() from Player class, because we specifically instantiated a Player
    PrintName(p); //uses the GetName() from Entity class, unless we make the function VIRTUAL

    Entity* entity = p; // entity is an instance of class Player (because of the = p);
    std::cout << entity->GetName() << std::endl; //uses the GetName() from Entity class, unless we make the function VIRTUAL

    std::cin.get();
    return 0;
}