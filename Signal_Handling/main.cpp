#include <iostream>
#include <csignal>
// for sleep() function!
#include <unistd.h>
// Example 1
void signalHandler(int signum){
    std::cout << "Interrupt signal (" << signum << ") received.\n";
    // cleanup and close up stuff here
    // terminate program
    exit(signum);
}

int main()
{
    // Example 1
    // register signal SIGINT and signal handler
    // compile + run the program and at some point
    // press Ctrl+c to interrupt the program and you will see that your
    // program will catch the signal and would come out by printing the signalHandler() message
    // CTRL+c on WINDOWS doesn't work?!
    /*
    signal(SIGINT, signalHandler);
    while(1){
        std::cout << " Going to sleep..." << std::endl;
        sleep(1);
    }
    */

    // Example 2
    int i = 0;
    // register signal SIGINT and signal handler
    signal(SIGINT, signalHandler);

    while(++i){
        std::cout <<"GOING to sleep!" << std::endl;
        if(i == 3){
            raise(SIGINT);
        }
        sleep(1);
    }
    return 0;
}
