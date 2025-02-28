//  String class test program
// 
//  Tests: subscripts
//
//  Name: Lazuli Rogers | aroger52
  
#include "string.hpp"
#include <cassert>
#include <iostream> 
 
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        const String  str("");

        // TEST
        char result = str[str.length()];

        // VERIFY
        assert(result == str[0]);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        const String  str("");

        // TEST
        const char result = str[str.length()];

        // VERIFY
        assert(result == str[0]);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String    x("Lopadotemachoselachogaleokranioleipsanodrim"
                    "hypotrimmatosilphiokarabomelitokatakechymen"
                    "okichlepikossyphophattoperisteralektryonopt"
                    "ekephalliokigklopeleiolagoiosiraiobaphetrag"
                    "anopterygon");

        // TEST
        char result = x[26];

        // VERIFY
        assert(result == 'r');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String    x("Lopadotemachoselachogaleokranioleipsanodrim"
                    "hypotrimmatosilphiokarabomelitokatakechymen"
                    "okichlepikossyphophattoperisteralektryonopt"
                    "ekephalliokigklopeleiolagoiosiraiobaphetrag"
                    "anopterygon");

        // TEST
        const char result = x[182];

        // VERIFY
        assert(result == 'n');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("&");

        // TEST
        char result = str[0];

        // VERIFY
        assert(result == '&');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("&");

        // TEST
        char result = str[1];

        // VERIFY
        assert(result == '\0');
    }
    
    std::cout << "\nDone testing subscript.\n===================\n" << std::endl;
    return 0;
}

