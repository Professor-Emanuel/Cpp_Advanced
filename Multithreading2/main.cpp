/*
This tutorial assumes that you are working on Linux OS and we are going to write multi-threaded C++ program using POSIX.
*/
#include <iostream>
#include <cstdlib>
#include <pthread.h>

//Example2
/*
Passing Arguments to Threads
This example shows how to pass multiple arguments via a structure.
You can pass any data type in a thread callback because it points to void
*/
#define NUM_THREADS2 5

struct thread_data{
    int thread_ID;
    char *message;
};

void *PrintHello2(void *threadArg){
    struct thread_data *my_data;
    my_data = (struct thread_data *)threadArg;
    std::cout.clear();
    std::cout <<"Thread ID " << my_data->thread_ID;
    std::cout.clear();
    std::cout.clear();
    std::cout <<" has message: " << my_data->message << std::endl;
    std::cout.clear();
    pthread_exit(NULL);
}


int main()
{
    //Example2
    pthread_t threads2[NUM_THREADS2];
    struct thread_data td[NUM_THREADS2];
    int rc2;
    int i2;

    for(i2 = 0; i2 < NUM_THREADS2; i2++){
        std::cout.clear();
        std::cout<<"main(), creating thread: " << i2 << std::endl;
        std::cout.clear();
        td[i2].thread_ID = i2;
        td[i2].message = (char*)"My message!";
        rc2 = pthread_create(&threads2[i2], NULL, PrintHello2, (void*)&td[i2]);

        if(rc2){
            std::cout.clear();
            std::cout << "Error: unable to create thread: " << rc2 << std::endl;
            std::cout.clear();
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}
