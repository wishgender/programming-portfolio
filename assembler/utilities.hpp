//header file for stack/assembler utility functions
//Lazuli Rogers | aroger52
//due 11-12-2024

#ifndef CS2_UTILITIES_HPP
#define CS2_UTILITIES_HPP

#include "./stack.hpp"
#include "../string/string.hpp"

#include <iostream>
#include <fstream>
#include <vector>

//input and output conversion
std::vector<String> getInfix(std::ifstream&);
std::vector<String> in2post(std::ifstream&);
std::ostream& post2assembly(String, std::ostream&);
std::ostream& evaluatePost(stack<String>&, std::ostream&, String&, int&); 
std::ostream& evaluatePre(stack<String>&, std::ostream&, String&, int&); 

std::vector<String> in2pre(std::ifstream&);
std::ostream& pre2assembly(String, std::ostream&);

//operator check
bool checkIfOp(String&);
//check which operator
String opID(String&);
//vector of operators to check against
const std::vector<String> ops { "+", "-", "*", "/" }; 


#endif //CS2_UTILITIES_HPP