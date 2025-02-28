// File: multiply.cpp
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
    std::ifstream input("data1-2.txt");           // Define input stream

    //+++++++++++++++++++++++++++++++++
//    std::cout << "input stream declared!\n";
    //+++++++++++++++++++++++++++++++++

    if(!input) {                    // Make sure file opened correctly
        std::cout << "File not found: data1-2.txt" << std::endl;
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
    while (input >> a >> b) {
        //+++++++++++++++++++++++++++++
       // std::cout << "INSIDE WHILE LOOP\n";
        //+++++++++++++++++++++++++++++
        bigint prod = (a * b);
        std::cout << "Number " << iters++ << ":\n" << a << "\n\n";
        std::cout << "Number " << iters++ << ":\n" << b << "\n\n";
        std::cout << "Product: \n" << (prod) << '\n';
        std::cout << "\n\n";
        resetBigints(a, b);
    }
    
    input.close();
    return 0;
}



void resetBigints(bigint& lhs, bigint& rhs) {
    lhs = 0; 
    rhs = 0;
    
   // std::cout << "Bigints reset to " << lhs << " and " << rhs << std::endl;
}