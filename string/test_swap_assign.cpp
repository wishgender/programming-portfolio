//=Swap function and overloaded assignment tests for class String
//=Lazuli Rogers | aroger52
//=Project 2 Milestones 2-3
//=10-14-2024

#include "string.hpp"
#include <iostream>
#include <cassert>

//===========================================================================

int main ()//Swap function & overloaded assignment

{
    {//SWAP

        //------------------------------------------------------

        // SETUP FIXTURE
        String x ("");
        String y ("");


        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";
        
        // TEST
        x.swap(y);
        std::cout << "Swapped x and y!\n";
        // VERIFY
        assert(x == "");
        assert(x != " ");
        assert(y == "");
        assert(y != " ");
        assert(x == y);

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n\n";


    }

    {//SWAP

        //------------------------------------------------------

        // SETUP FIXTURE
        String x ("asdfghjkl;");
        String y ("asdfghjkl;");


        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";
        
        // TEST
        x.swap(y);
        std::cout << "Swapped x and y!\n";
        // VERIFY
        assert(x == "asdfghjkl;");
        assert(x != "asdfghjkl");
        assert(y == "asdfghjkl;");
        assert(y != "asdfg");
        assert(x == y);

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";

        std::cout << "...What do you mean you can't tell?\n\n";
    }

    {//SWAP

        //------------------------------------------------------

        // SETUP FIXTURE
        String x ("");
        String y (" ");


        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";
        
        // TEST
        x.swap(y);
        std::cout << "Swapped x and y!\n";
        // VERIFY
        assert(x == " ");
        assert(x != "");
        assert(y == "");
        assert(y != " ");
        assert(x != y);

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n\n";


    }

    {//SWAP

        //------------------------------------------------------

        // SETUP FIXTURE
        String x ("");
        String y ("abc");


        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";
        
        // TEST
        x.swap(y);
        std::cout << "Swapped x and y!\n";
        // VERIFY
        assert(x == "abc");
        assert(x != "");
        assert(y == "");
        assert(y != "abc");
        assert(x != y);

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n\n";


    }

    {//SWAP

        //------------------------------------------------------

        // SETUP FIXTURE
        String x ("Hello");
        String y ("world!");


        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";
        
        // TEST
        x.swap(y);
        std::cout << "Swapped x and y!\n";
        // VERIFY
        assert(x == "world!");
        assert(x != "Hello");
        assert(y == "Hello");
        assert(y != "world!");
        assert(x != y);

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n\n";


    }

    {//SWAP

        //------------------------------------------------------

        // SETUP FIXTURE
        String x ("itself");
        


        std::cout << "String x: '" << x << "'\n";

        // TEST
        x.swap(x);
        std::cout << "Swapped x with itself!\n";
        // VERIFY
        assert(x == "itself");
        assert(x != "it");
        assert(x != "");

        std::cout << "String x: '" << x << "'\n\n";

    }

    {//SWAP

        //------------------------------------------------------

        // SETUP FIXTURE
        String x("LargeString123456789012345678901234567890");
        String y("LargeString123456789012345678901234567890");
        
        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";


        // TEST
        x.swap(y);

        std::cout << "Swapped x and y!\n";

        //VERIFY
        assert(y == x);
        assert(x == y);
        assert(x == "LargeString123456789012345678901234567890");
        assert(y == "LargeString123456789012345678901234567890");

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n\n";

    }

    {//SWAP

        //------------------------------------------------------

        // SETUP FIXTURE
        String x("LargeString123456789012345678901234567890");
        String y("String1234567");
        
        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";


        // TEST
        x.swap(y);

        std::cout << "Swapped x and y!\n";

        //VERIFY
        assert(y != x);
        assert(x != y);
        assert(x == "String1234567");
        assert(y != "String1234567");
        assert(y == "LargeString123456789012345678901234567890");
        assert(x != "LargeString123456789012345678901234567890");

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n\n";

    }

    {//ASSIGN

        //------------------------------------------------------

        // SETUP FIXTURE
        String x ("");
        String y ("");


        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";
        
        // TEST
        x = y;
        std::cout << "Assigned y to x!\n";
        // VERIFY
        assert(x == "");
        assert(x != " ");
        assert(y == "");
        assert(y != " ");
        assert(x == y);

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n\n";


    }

    {//ASSIGN

        //------------------------------------------------------

        // SETUP FIXTURE
        String x ("asdfghjkl;");
        String y ("asdfghjkl;");


        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";
        
        // TEST
        x = y;
        std::cout << "Assigned y to x!\n";
        // VERIFY
        assert(x == "asdfghjkl;");
        assert(x != "asdfghjkl");
        assert(y == "asdfghjkl;");
        assert(y != "asdfg");
        assert(x == y);

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";

        std::cout << "...What do you mean you can't tell?\n\n";
    }

    {//ASSIGN

        //------------------------------------------------------

        // SETUP FIXTURE
        String x ("");
        String y (" ");


        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";
        
        // TEST
        x = y;
        std::cout << "Assigned y to x!\n";

        // VERIFY
        assert(x == " ");
        assert(x != "");
        assert(y == " ");
        assert(y != "");
        assert(x == y);

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n\n";


    }

    {//ASSIGN

        //------------------------------------------------------

        // SETUP FIXTURE
        String x ("");
        String y ("abc");


        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";
        
        // TEST
        x = y;
        std::cout << "Assigned y to x!\n";

        // VERIFY
        assert(x == "abc");
        assert(x != "");
        assert(y == "abc");
        assert(y != "");

        assert(x == y);

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n\n";


    }

    {//ASSIGN

        //------------------------------------------------------

        // SETUP FIXTURE
        String x ("Hello");
        String y ("world!");


        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";
        
        // TEST
        x = y;
        std::cout << "Assigned y to x!\n";

        // VERIFY
        assert(x == "world!");
        assert(x != "Hello");
        assert(y == "world!");
        assert(y != "Hello");

        assert(x == y);

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n\n";


    }

    {//ASSIGN

        //------------------------------------------------------

        // SETUP FIXTURE
        String x ("itself");
        


        std::cout << "String x: '" << x << "'\n";

        // TEST
        x = x;
        std::cout << "Assigned x to itself!\n";
        // VERIFY
        assert(x == "itself");
        assert(x != "it");
        assert(x != "");

        std::cout << "String x: '" << x << "'\n\n";

    }

    {//ASSIGN

        //------------------------------------------------------

        // SETUP FIXTURE
        String x("LargeString123456789012345678901234567890");
        String y("LargeString123456789012345678901234567890");
        
        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";


        // TEST
        x = y;

        std::cout << "Assigned y to x!\n";

        //VERIFY
        assert(y == x);
        assert(x == y);
        assert(x == "LargeString123456789012345678901234567890");
        assert(y == "LargeString123456789012345678901234567890");

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n\n";

    }    
    
    {//ASSIGN

        //------------------------------------------------------

        // SETUP FIXTURE
        String x("LargeString123456789012345678901234567890");
        String y("String1234567");
        
        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n";


        // TEST
        x = y;

        std::cout << "Assigned y to x!\n";

        //VERIFY
        assert(y == x);
        assert(x == y);
        assert(x != "String123456789012345678901234567890");
        assert(y != "String123456789012345678901234567890");
        assert(y == "String1234567");
        assert(x == "String1234567");

        std::cout << "String x: '" << x << "'\n";
        std::cout << "String y: '" << y << "'\n\n";

    }

    std::cout << "\nDone testing swap function and overloaded assignment.\n===================" << std::endl;
    return 0;

}