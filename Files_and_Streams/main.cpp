#include <iostream>
#include <fstream>

//Either ofstream or fstream object may be used to open a file for writing.
//And ifstream object is used to open a file for reading purpose only.

/*
Read and Write Example
Following is the C++ program which opens a file in reading and writing mode.
After writing information entered by the user to a file named aFile.dat,
the program reads information from the file and outputs it onto the screen.
*/

int main()
{
    char data[100];

    //open a file in write mode
    std::ofstream outfile;
    outfile.open("aFile.dat", std::ios::out);

    std::cout<<"Write in the file: "<< std::endl;
    std::cout<<"Enter your name: ";
    std::cin.getline(data, 100);

    //write inputed data into the file
    outfile << data << std::endl;

    std::cout<<"Enter your age: ";
    std::cin>> data;
    std::cin.ignore();
    //again write inputed data into the file
    outfile << data << std::endl;

    // close the opened file.
    outfile.close();

    //open a file in write mode
    std::ifstream infile;
    infile.open("aFile.dat", std::ios::in);
    std::cout<<"Read from the file: "<< std::endl;
    //infile >> data;

    while(infile>>data){
        std::cout << data << std::endl;
    }

    /*
    //write the data to the screen
    std::cout << data << std::endl;

    // again read the data from the file and display it.
    infile >> data;
    std::cout << data << std::endl;
    */

    // close the opened file.
    infile.close();

    return 0;
}
