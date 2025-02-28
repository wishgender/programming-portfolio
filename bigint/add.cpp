// File: add.cpp
//
// CS 23001 Project 1 bigint 
//
// Basics for openning a file for milestone 2
//

#include <iostream> 
#include <fstream>

#include "bigint.hpp"


void resetBigints(bigint&, bigint&);

int main() {
    std::ifstream inFile("data1-1.txt");           // Define input stream

    //+++++++++++++++++++++++++++++++++
//    std::cout << "input stream declared!\n";
    //+++++++++++++++++++++++++++++++++

    if(!inFile) {                    // Make sure file opened correctly
        std::cout << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }

    //+++++++++++++++++++++++++++++++++
//    std::cout << "file open!\n";
    //+++++++++++++++++++++++++++++++++

    bigint a, b;

    //+++++++++++++++++++++++++++++++++
//    std::cout << "BIGINTS DECLARED!" << '\n';
    //+++++++++++++++++++++++++++++++++

    
    //+++++++++++++++++++++++++++++++++
 //   a.debugPrint(std::cout);
    //+++++++++++++++++++++++++++++++++
    int iters = 1;
    while (inFile >> a >> b) {
        //+++++++++++++++++++++++++++++
       // std::cout << "INSIDE WHILE LOOP\n";
        //+++++++++++++++++++++++++++++
        std::cout << "Number " << iters++ << ": " << a << '\n';
        std::cout << "Number " << iters++ << ": " << b << '\n';
        std::cout << "Sum: " << (a + b) << '\n';
        std::cout << '\n';
        resetBigints(a, b);
    }
    
    inFile.close();
    return 0;
}



void resetBigints(bigint& lhs, bigint& rhs) {
    lhs = 0; 
    rhs = 0;
   // std::cout << "Bigints reset to " << lhs << " and " << rhs << std::endl;
}