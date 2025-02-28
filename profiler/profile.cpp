//
//  profile.cpp
//
//  Created by Jonathan Maletic.
//  Copyright 2024 Kent State University. All rights reserved.
//  Fall  2024
//  Modified by: Lazuli Rogers | aroger52
//

#include "profile.hpp"

// Prints out the profile.
//
// TODO: Very basic, need to make it print neat columns with headings
// 
std::ostream& operator<< (std::ostream& out, const profile& p) {
    
    out << "File: " << p.filename << std::endl;
    out << "|   Line   |   Function (if applicable)   |   Times Executed   |" << std::endl;
    
    for(std::map<std::string, int>::const_iterator i = p.stmt.begin(); i != p.stmt.end(); ++i) {
        std::string output, output1st, output2nd;

        if(i->first.find('!') <= 255){
            size_t space(i->first.find('!'));

            std::string outputLine(i->first.substr(0, space));
            std::string outputFunc(i->first.substr(space+1, i->first.size()));
            
            while(outputLine.length() < 8){
                outputLine += ' ';
            }

            while(outputFunc.length() < 28){
                outputFunc+= ' ';
            }
            
            output1st = "| "+outputLine+" | "+outputFunc + " | ";
        }else {
            std::string outputLine = i->first;
            while(outputLine.length() < 8) {
                outputLine += ' ';
            }

            output1st = "| "+outputLine+" |            (N/A)             | ";
        }
        output2nd = intToString(i->second);
        while(output2nd.length() < 18) {
            output2nd+=' ';
        }

        output= output1st + output2nd + " |";
        out << output << std::endl;   
    }
    return out;
}



// REQUIRES:  n >= 0
// ENSURES: Returns a text version of a positive integer long
//
std::string intToString(int n) {
    assert(n >= 0);
    std::string result;
    
    if (n == 0) return "0";
    while (n > 0) {
        result = char(int('0') + (n % 10)) + result;
        n = n / 10;
    }  
    return result;
}
