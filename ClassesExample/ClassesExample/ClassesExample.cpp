#include <iostream>
#define LOG(x) std::cout<< x << std::endl


// Example 1
class Player {
public:
    int x, y;
    int speed;

    //if we move the function inside, we call it a method and we don't need to pass player as a reference (&)
    void Move(int xa, int ya) {
        x += xa * speed;
        y += ya * speed;
    }
};

/* EXTERNAL FUNCTION
Have to pass a player by reference (&), if the function is outside the class
void Move(Player& player, int xa, int ya) {
    player.x += xa * player.speed;
    player.y += ya * player.speed;
}
*/


// Example 2
/* Everything is PUBLIC by default in STRUCTs
Use structures whenever possible:
1. when you deal with plain old data (POD), example plain math vector, 
2. when you don't have to handle a lot of functionality (won't contain too many functions/methods)
3. when there is no massive manipulation needed, no massive complications
4. when you need to use inheritance, never use a STRUCT, because it add another level of complexity

Otherwise use CLASSES!
*/
struct Vec2 {
    float x, y;

    void Add(const Vec2& other) {
        x += other.x;
        y += other.y;
    }
};


// Example 3
class Log {
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;
private:
    int m_LogLevel = LogLevelInfo; // m_ is for knowing it is a member variable

public:
        void SetLevel(int level) {
            m_LogLevel = level;
        }

        void Error(const char* message) {
            if(m_LogLevel >= LogLevelError)
                std::cout << "[ERROR]: " << message << std::endl;
        }

        void Warn(const char* message) {
            if (m_LogLevel >= LogLevelWarning)
                std::cout << "[WARNING]: " << message << std::endl;
        }

        void Info(const char* message) {
            if (m_LogLevel >= LogLevelInfo)
                std::cout << "[INFO]: " << message << std::endl;
        }

};


int main()
{
    // Example 1
    Player player;
    player.x = 5;

    // EXTERNAL FUNCTION
    //Move(player, 1, -1);

    // using the class method Move; every player created will have access to this method
    player.Move(1, -1);

    // Example 2
    Vec2 vec2, vec2a;
    vec2.x = 5.0;
    vec2.y = 6.0;
    vec2a.x = 2.0;
    vec2a.y = 3.0;
    vec2.Add(vec2a);

    // Example 3
    Log log;
    log.SetLevel(log.LogLevelWarning);
    log.Warn("Hello!");
    log.Error("Dead");
    log.Info("Info");

    Log log2;
    log2.SetLevel(log.LogLevelError);
    log2.Warn("Hello!");
    log2.Error("Dead");
    log2.Info("Info");


    std::cin.get();
    return 0;
}