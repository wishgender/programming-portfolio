//  String class test program
// 
//  Tests: input
//
//  Lazuli Rogers | aroger52
  
#include "string.hpp"
#include <cassert>
#include <iostream> 
#include <fstream>

//===========================================================================
int main ()
{
    std::cout << std::endl;
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;
        std::ifstream inFile("log_1_tiny.txt");
        if (!inFile.is_open()) {
            std::cout << "Unable to open log_1_tiny.txt" << std::endl;
            exit(1);
        }
        // TEST
        while(inFile >> str) {
            std::cout << str << ' ';
        }

        // VERIFY
        std::cout << "\ndone with log 1\n" << std::endl;

        inFile.close();
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;
        std::ifstream inFile("log_2_small.txt");
        if (!inFile.is_open()) {
            std::cout << "Unable to open log_2_small.txt" << std::endl;
            exit(1);
        }
        // TEST
        while(inFile >> str) {
            std::cout << str << ' ';
        }
        // VERIFY
        std::cout << "\ndone with log 2\n" << std::endl;

        inFile.close();
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str;
        std::ifstream inFile("lorem_ipsum.txt");
        if (!inFile.is_open()) {
            std::cout << "Unable to open lorem_ipsum.txt" << std::endl;
            exit(1);
        }
        // TEST
        while(inFile >> str) {
            std::cout << str << ' ';
        }
        // VERIFY
        std::cout << "\ndone with lorem ipsum\n" << std::endl;
        
        inFile.close();
    }
    
    std::cout << "\nDone testing input.\n===================\n" << std::endl;
    return 0;
}

