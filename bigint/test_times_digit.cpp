// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
     //======================================================
        //Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 3);
    }
    {
     //======================================================
        // Setup fixture
        bigint bi;

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 0);
    } 
    {
     //======================================================
        // Setup fixture
        bigint bi;

        // Test 
        bi = bi.timesDigit(0);

        // Verify
        assert(bi == 0);
    }   
    {
     //======================================================
        // Setup fixture
        bigint bi(20);

        // Test 
        bi = bi.timesDigit(0);

        // Verify
        assert(bi == 0);
    }   
    {
     //======================================================
        // Setup fixture
        bigint bi("20");

        // Test 
        bi = bi.timesDigit(0);

        // Verify
        assert(bi == 0);
    }   
    {
     //======================================================
        // Setup fixture
        bigint bi("69420");

        // Test 
        bi = bi.timesDigit(7);

        // Verify
        assert(bi == 485940);
    }   
    {
     //======================================================
        // Setup fixture
        bigint bi(69420);

        // Test 
        bi = bi.timesDigit(7);

        // Verify
        assert(bi == 485940);
    }   
    {
     //======================================================
        // Setup fixture
        bigint bi("250");

        // Test 
        bi = bi.timesDigit(4);

        // Verify
        assert(bi == 1000);
    }    
    {
     //======================================================
        // Setup fixture
        bigint bi(250);

        // Test 
        bi = bi.timesDigit(4);

        // Verify
        assert(bi == 1000);
    }   

    //Add test cases as needed.
    
    std::cout << "Done testing bigint * digit" << std::endl;
    return 0;
}
