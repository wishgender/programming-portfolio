//  String class test program
// 
//  Tests: concatenation
//
//  Name: Lazuli Rogers | aroger52
  
#include "string.hpp"
#include <cassert>
#include <iostream> 
 
//===========================================================================
int main ()
{// CONCATENATION
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String    x("Lopadotemachoselachogaleokranioleipsanodrim"
                    "hypotrimmatosilphiokarabomelitokatakechymen"
                    "okichlepikossyphophattoperisteralektryonopt"
                    "ekephalliokigklopeleiolagoiosiraiobaphetrag"
                    "anopterygon");

        String y ("Llanfairpwllgwyngyllgogerychwyrndrobwllllantysiliogogogoch cabbageworms");

        String z(x+y);
        std::cout << '\n' << x << "\n+=\n" << y << "\n=\n"; 

        // TEST
        x += y;
        std::cout << z << std::endl;

        // VERIFY
        assert(x          == z);
        assert(x.length() <= x.capacity());
 
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str1("cerulean");
        String  str2(" crayons");

        // TEST
        std::cout << "\n'" << str1 << "' += '" << str2 << "' = '"; 
        str1+=str2;
        std::cout << str1 << "'\n";
        // VERIFY
        assert(str1 == "cerulean crayons");

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("");

        // TEST
        String result = str + "";

        // VERIFY
        assert(str    == "");
        assert(result == "");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str1("testing");
        String  str2("testing");
        // TEST
        String result = str1 + str2;

        // VERIFY
        // assert(str    == "");
        assert(result == "testingtesting");
        std::cout << '\n' << str1 << " + " << str2 << " = " << result << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("OOOO");

        // TEST
        std::cout << "\n'" << str << "' += ' 1832:fha4892fh2' = '"; 
        str += " 1832:fha4892fh2";
        std::cout << str << "'\n";

        // VERIFY
        assert(str == "OOOO 1832:fha4892fh2");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String    x("Lopadotemachoselachogaleokranioleipsanodrim"
                    "hypotrimmatosilphiokarabomelitokatakechymen"
                    "okichlepikossyphophattoperisteralektryonopt"
                    "ekephalliokigklopeleiolagoiosiraiobaphetrag"
                    "anopterygon");

        String    y("Lopadotemachoselachogaleokranioleipsanodrim"
                    "hypotrimmatosilphiokarabomelitokatakechymen"
                    "okichlepikossyphophattoperisteralektryonopt"
                    "ekephalliokigklopeleiolagoiosiraiobaphetrag"
                    "anopterygon");

        // TEST
        String z = x + y;

        std::cout << "\n" << x << "\n+\n" << y << "\n=\n" << z << std::endl;

        // VERIFY
        assert(z.length() <= z.capacity());
        assert(x == y);

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str('9');
        std::cout << "\n'" << str;
        // TEST
        str+="fjaoeiw09";
        std::cout << "' += 'fjaoeiw09' = '" << str << "'\n";
        // VERIFY
        assert(str == "9fjaoeiw09");
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "\nDone testing concatenation.\n===================\n" << std::endl;
    return 0;
}

