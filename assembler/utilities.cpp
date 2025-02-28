//utilities.cpp
//free functions for assembler
//due 11-12-2024
//Lazuli Rogers | aroger52

#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>

#include "./utilities.hpp"
#include "./stack.hpp"
#include "../string/string.hpp"

//INV: ifstream contains properly formatted, fully parenthesized
//     infix expression
//ENSURES: returns a vector of strings, each of which being a line 
//         from the input file converted into postfix notation
std::vector<String> in2post(std::ifstream& in) {

    //ensure ifstream is open
    assert(in.is_open());

    //String to hold the current token, 
    String token;
    //stack to hold each token in order,
    stack<String> S;
    //vector of Strings to hold results
    std::vector<String> result;

    do {
        //input the first token
        in >> token;
        //each token is 6 characters or less
        if (token.length() >= 7) token = token.substr(0,5);
        
        //loop until semicolon is reached
        while(token != ';') {
            if (token == ")") {
                String rhs = S.pop() + ' ';
                String op  = S.pop();
                String lhs = S.pop() + ' ';
                S.push(lhs + rhs + op);
            }
            else {
                if(token != "(") {
                    S.push(token);
                }
            }

            //next token
            in >> token;

            //again, ensure length is within limit
            if (token.length() >= 7) token = token.substr(0,5);
            
            //if it is the end of the expression, add the current 
            //top of stack to the vector
            if (token == ";") result.push_back(" " + (S.top()));
            else if (in.eof()) return result;
        }//end while

    } while(!in.eof() && (token!="\r"&&token!="\r\n")); //end do while

    //return final result
    return result;
}

//INV: ifstream contains properly formatted, fully parenthesized
//     infix expression
//ENSURES: returns a vector of strings, each of which being a line 
//         from the input file, minus the ending semicolon
std::vector<String> getInfix(std::ifstream& in) {
    //vector to hold result
    std::vector<String> infix;
    //String object to hold initial input
    String token;
    //temporary String object to concatenate all tokens
    String temp;

    //input tokens to the String one at a time
    while(in >> token) {
        //concatenate tokens
        temp+=(" " + token);
    };

    //split temp at each semicolon, creating a vector
    //with each line as an element
    infix = temp.split(';');

    //return the resultant vector
    return infix;
}

//INV: postExpr contains a properly formatted postfix expression
//     complete with spaces and no parentheses
//     out is a valid ostream reference
//ENSURES: returns an ostream reference containing the postfix 
//         expression properly converted into assembly
std::ostream& post2assembly(String postExpr, std::ostream& out) {
    //vector of tokens by splitting the input String
    std::vector<String> tokens(postExpr.split(' '));
    //String to hold current token
    String nextToken; 
    //stack to order the tokens properly
    stack<String> S;
    //String to contain the name of any temporary identifiers
    String TEMPn;
    //int to keep track of how many temporary identifiers
    int nCount(1);
    
    //iterate over the vector of tokens
    for (size_t i = 0; i < tokens.size(); ++i) {
        nextToken = tokens[i];

        //check if the current token is an operator
        if (!(checkIfOp(nextToken))) { 
            //if not, push to stack
            S.push(nextToken);
        }

        
        else { //if the current token is an operator
            evaluate(S,out, nextToken, nCount);
        }

    }
    //return ostream&
    return out;
}

//INV: input the stack, ostream, operator, and temporary variable count
//ENSURES: returns an ostream reference containing input converted to 
//         assembly code
std::ostream& evaluate(stack<String>& S, std::ostream& out, String& opr, int& nCount) {
    //right operand
    String rhs = S.pop();
    //left operand
    String lhs = S.pop();

    out << "   LD     " << lhs << std::endl;
    //get the opcode for the operator
    out << "   " << opID(opr) << "     " << rhs << std::endl;

    //push temporary variable to stack
    S.push("TMP" + String::intToString(nCount++));

    //save temporary variable
    out << "   ST     " << S.top() << std::endl;

    return out;
}

//return true if input token is a valid operator
bool checkIfOp(String& token) {
    if ((token == "+") || (token == "-") || 
    (token == '*') || (token == "/")) return true;
    else return false;
}

//identify the operator and return the 
//appropriate assembly code identifier
String opID(String& op) {
    if (op == ops[0]) return "AD";
    else if (op == ops[1]) return "SB";
    else if (op == ops[2]) return "MU";
    else if (op == ops[3]) return "DV";
    else return "?";
}