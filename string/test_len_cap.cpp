//  String class test program
// 
//  Tests: length and capacity
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
        String  str("");

        // TEST
        int len = str.length();

        int cap = str.capacity();

        // VERIFY
        assert(len    ==   0);
        assert(len    ==   0);
        assert(cap    == len);
        std::cout << "\nString: '" << str << "'\nlength: ";
        std::cout << len << "\ncapacity: " << cap << std::endl;
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("haiurehy439876thyf34q9pngnth43");

        // TEST
        int len = str.length();

        int cap = str.capacity();

        // VERIFY
        assert(len    ==  30);
        assert(len    ==  30);
        assert(cap    == len);
        std::cout << "\nString: '" << str << "'\nlength: ";
        std::cout << len << "\ncapacity: " << cap << std::endl;
    }    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("9");

        // TEST
        int len = str.length();

        int cap = str.capacity();

        // VERIFY
        assert(len    == 1);
        assert(cap    == 1);
        assert(cap    == len);
        std::cout << "\nString: '" << str << "'\nlength: ";
        std::cout << len << "\ncapacity: " << cap << std::endl;
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str('1');

        // TEST
        int len = str.length();

        int cap = str.capacity();

        // VERIFY
        assert(len    == 1);
        assert(cap    == 1);
        assert(cap    == len);
        std::cout << "\nString: '" << str << "'\nlength: ";
        std::cout << len << "\ncapacity: " << cap << std::endl;
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("hn40839qnh43214390857(*&(Fhnt53tuj0%))");

        // TEST
        int len = str.length();

        int cap = str.capacity();

        // VERIFY
        assert(len    == 38);
        assert(cap    == 38);
        assert(cap    == len);
        std::cout << "\nString: '" << str << "'\nlength: ";
        std::cout << len << "\ncapacity: " << cap << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String    str("Lopadotemachoselachogaleokranioleipsanodrim"
                      "hypotrimmatosilphiokarabomelitokatakechymen"
                      "okichlepikossyphophattoperisteralektryonopt"
                      "ekephalliokigklopeleiolagoiosiraiobaphetrag"
                      "anopterygonLopadotemachoselachogaleokraniol"
                      "eipsanodrimhypotrimmatosilphiokarabomeli");
        // TEST
        int len = str.length();

        int cap = str.capacity();
        // VERIFY
        assert(len    == 255);
        assert(cap    == 255);
        assert(cap    == len);
        std::cout << "\nString: '" << str << "'\nlength: ";
        std::cout << len << "\ncapacity: " << cap << std::endl;
    }

    
    std::cout << "\nDone testing length and capacity.\n===================\n" << std::endl;
    return 0;
}

