//  String class test program
//  Tests: split method
//  Fall 2024 | 10-13-24
//  Name: Lazuli Rogers | aroger52
  
#include "string.hpp"
#include <cassert>
#include <vector>
#include <iostream> 

//===========================================================================
int main ()
{
    //SPLIT
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str("The quick brown fox jumps over the lazy dog.");

        std::cout << str << std::endl;
        // TEST
        std::vector<String> splitStr(str.split(' '));
        // VERIFY
        assert (splitStr[0] == "The");
        assert (splitStr[1] == "quick");
        assert (splitStr[2] == "brown");
        assert (splitStr[3] == "fox");
        assert (splitStr[4] == "jumps");
        assert (splitStr[5] == "over");
        assert (splitStr[6] == "the");
        assert (splitStr[7] == "lazy");
        assert (splitStr[8] == "dog.");
        String::printSplit(splitStr);
    };   

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str(" this is an example string! ");
        std::cout << str << std::endl;
        // TEST
        std::vector<String> splitStr(str.split(' '));
        // VERIFY
        assert (splitStr[0]  == "");
        assert (splitStr[1]  == "this");
        assert (splitStr[2]  == "is");
        assert (splitStr[3]  == "an");
        assert (splitStr[4]  == "example");
        assert (splitStr[5]  == "string!");
        assert (splitStr[6] == "");
        String::printSplit(splitStr);
    };

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str(" test cases  for days  and  days ");
        // TEST
        std::vector<String> splitStr(str.split(' '));
        // VERIFY
        assert(splitStr[0]  == "");
        assert(splitStr[1]  == "test");
        assert(splitStr[2]  == "cases");
        assert(splitStr[3]  == "");
        assert(splitStr[4]  == "for");
        assert(splitStr[5]  == "days");
        assert(splitStr[6]  == "");
        assert(splitStr[7]  == "and");
        assert(splitStr[8]  == "");
        assert(splitStr[9]  == "days");
        assert(splitStr[10] == "");
        String::printSplit(splitStr);
    };

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str;
        // TEST
        std::vector<String> splitStr(str.split(' '));
        std::vector<String> splitStr2(str.split('-'));
        // VERIFY
        assert(splitStr[0]=="");
        assert(splitStr2[0]=="");
        String::printSplit(splitStr);
    };

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str("asdfghjkl;");
        // TEST
        std::vector<String> splitStr(str.split(' '));
        // VERIFY
        assert(splitStr[0] == "asdfghjkl;");
        assert(splitStr[0] != "asdf");
        String::printSplit(splitStr);
    };

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str(" ");
        // TEST
        std::vector<String> splitStr(str.split(' '));
        // VERIFY
        assert(splitStr[0] == "");
        assert(splitStr[1] == "");
        String::printSplit(splitStr);
    };

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str("  ");
        // TEST
        std::vector<String> splitStr(str.split(' '));
        // VERIFY
        assert(splitStr[0] == "");
        assert(splitStr[1] == "");
        assert(splitStr[2] == "");
        String::printSplit(splitStr);
    };

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str("-");
        // TEST
        std::vector<String> splitStr(str.split('-'));
        // VERIFY
        assert(splitStr[0] == "");
        assert(splitStr[1] == "");
        String::printSplit(splitStr);
    };

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str("--");
        // TEST
        std::vector<String> splitStr(str.split('-'));
        // VERIFY
        assert(splitStr[0] == "");
        assert(splitStr[1] == "");
        assert(splitStr[2] == "");
        String::printSplit(splitStr);
    };

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String str("aaaaaaaaaaaaaaa");
        // TEST
        std::vector<String> splitStr(str.split('b'));
        // VERIFY
        assert(splitStr[0] == "aaaaaaaaaaaaaaa");
        String::printSplit(splitStr);
    };

    std::cout << "\nDone testing split method.\n===================\n" << std::endl;
    return 0;

};