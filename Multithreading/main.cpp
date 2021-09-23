/*
This tutorial assumes that you are working on Linux OS and we are going to write multi-threaded C++ program using POSIX.
*/
#include <iostream>
#include <cstdlib>
#include <pthread.h>

//Example1
/*
This simple example code creates 5 threads with the pthread_create() routine.
Each thread prints a "Hello World!" message, and then terminates with a call to pthread_exit().
*/
#define NUM_THREADS 5

void *PrintHello(void *threadID){
    long* tID;
    tID = (long*)threadID;
    std::cout << "Hello World! Thread ID: " << tID << std::endl;
    //pthread_exit (status)
    pthread_exit(NULL);
}

int main()
{
    //Example1
    pthread_t threads[NUM_THREADS];
    int rc;
    long long int i;

    for(i = 0; i < NUM_THREADS; i++){
        std::cout << "main(), creating thread: " << i << std::endl;

        //pthread_create (thread, attr, start_routine, arg)
        //thread - An opaque, unique identifier for the new thread returned by the subroutine.
        //attr - An opaque attribute object that may be used to set thread attributes. You can specify a thread attributes object, or NULL for the default values.
        //start_routine - The C++ routine that the thread will execute once it is created.
        //arg - A single argument that may be passed to start_routine. It must be passed by reference as a pointer cast of type void. NULL may be used if no argument is to be passed.
        rc = pthread_create(&threads[i], NULL, PrintHello, (void*)i);

        if(rc){
            std::cout << "Error: unable to create thread: " << rc << std::endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}
