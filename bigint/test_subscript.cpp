// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 4);
    }

    {
        //Setup
        bigint bi("80788021766336132646753779160127489248857820371987");

        // Test
        int digit = bi[48];

        //Verify
        assert(bi   == "80788021766336132646753779160127489248857820371987");
        assert(digit == 0);
    }
    {
        //Setup
        bigint bi("2120653894116");

        // Test
        int digit = bi[6];

        //Verify
        assert(bi   == "2120653894116");
        assert(digit == 3);
    }
    {
        //Setup
        bigint bi("4339381115477");

        // Test
        int digit = bi[7];

        //Verify
        assert(bi   == "4339381115477");
        assert(digit == 8);
    }
    {
        //Setup
        bigint bi(81304);

        // Test
        int digit = bi[3];

        //Verify
        assert(bi   == 81304);
        assert(digit == 1);
    } 
    {
        //Setup
        bigint bi("1199478432");

        // Test
        int digit = bi[5];

        //Verify
        assert(bi   == "1199478432");
        assert(digit == 4);
    }
    {
        //Setup
        bigint bi(7663083);

        // Test
        int digit = bi[4];

        //Verify
        assert(bi   == 7663083);
        assert(digit == 6);
    }
    {
        //Setup
        bigint bi("3569210374848");

        // Test
        int digit = bi[11];

        //Verify
        assert(bi   == "3569210374848");
        assert(digit == 5);
    }
    {
        //Setup
        bigint bi("30027998983");

        // Test
        int digit = bi[0];

        //Verify
        assert(bi   == "30027998983");
        assert(digit == 3);
    }              
    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

