//assembler.cpp
//convert infix expression to postfix & evaluate
//print corresponding assembly code to file or terminal
//Lazuli Rogers | aroger52
//due 11/12/24

#include <vector>
#include <cassert>
#include <iostream>
#include <fstream>

#include "./stack.hpp"
#include "./utilities.hpp"
#include "../string/string.hpp"


//INV: OPERANDS IN INFIX EXPRESSION ARE NO MORE THAN 6 CHARACTERS
//IN LENGTH.
//ALL OPERANDS AND OPERATORS ARE SEPARATED BY A SINGLE WHITESPACE
//CHARACTER
//THE END OF EACH INFIX EXPRESSION IS DENOTED BY A SEMICOLON ';'
//ALSO PRECEDED BY A SPACE CHARACTER

int main(int argc, char *argv[]) {

    // Error and quit if there are not 3 things on the command line
    if (argc != 2 && argc != 3) {      
        std::cerr << "Syntax Error: Usage is " << std::endl;
        std::cerr << argv[0] << " input-file [output-file] " << std::endl;
        exit(1);         // Exit with error
    }  

    // Open file, quit if open fails
    std::ifstream in(argv[1]);     
    if (!in.is_open()) {
        std::cerr << "Error: Cannot open " << argv[1] << std::endl;
        exit(1);         // Exit with error
    }

    //vector of strings of each infix expression
    std::vector<String> infOutput(getInfix(in));
    //done obtaining infix
    std::cout << "GOT INFIX\n";
    //close ifstream
    in.close();
    //ensure ifstream is properly closed
    assert(!in.is_open());

    //now getting infix for output
    //reopen ifstream
    in.open(argv[1]);
    //ensure ifstream is open & exit with error if not
    if (!in.is_open()) {
        std::cerr << "Error: Cannot open " << argv[1] << std::endl;
        exit(1);         
    }

    //vector of strings of each converted postfix statement
    std::vector<String> postOutput(in2post(in));
    //done obtaining postfix
    std::cout << "GOT POSTFIX\n";

    //close ifstream again
    in.close();
    //ensure ifstream is properly closed
    assert(!in.is_open());

    //output to standard output/terminal
    if (argc == 2) {      
        for (size_t i = 1; i < postOutput.size(); ++i) {
            std::cout << "Infix Expression:" << infOutput[i] << std::endl; 
            std::cout << "Postfix Expression: " << postOutput[i] << std::endl;
            std::cout << std::endl;
            post2assembly(postOutput[i], std::cout);
            std::cout << std::endl 
            << "//=============================================================//"
            << std::endl << std::endl;
        }
    }
    //output to specified file
    else if (argc == 3) {
        //initialize ofstream from argv[2]
        std::ofstream out(argv[2]);
        //ensure ofstream is open
        assert(out.is_open());

        for (size_t i = 0; i < postOutput.size(); ++i) {
            out << "Infix Expression:" << infOutput[i] << std::endl; 
            out << "Postfix Expression: " << postOutput[i] << std::endl;
            out << std::endl;
            post2assembly(postOutput[i], out);
            out << std::endl 
            << "//=============================================================//\n"
            << std::endl;
        }
        //close ofstream
        out.close();
        //ensure ofstream is closed
        assert(!out.is_open());
    }
    return 0;
}
