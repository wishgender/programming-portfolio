// bigint Test Program
//
// Tests:  int constructor, uses ==
// 
// NEED TO IMPLEMENT
//
#include <iostream> 
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

      //------------------------------------------------------
      // Setup fixture
      bigint left(0);
      bigint right(0);
      bigint result;

      // Test 
      result = left + right;

      // Verify
      assert(left   == 0);
      assert(right  == 0);
      assert(result == 0);

      //Printing to check
      //std::cout << left << '+' << right << '=' << result << "\n\n";

    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);

      //Printing to check
      //std::cout << left << '+' << right << '=' << result << "\n\n";

    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);

      //Printing to check
      //std::cout << left << '+' << right << '=' << result << "\n\n";

    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(289754550);
      bigint right("34");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "289754550");
      assert(right  == 34);
      assert(result == "289754584");
      
      //Printing to check
      //std::cout << left << '+' << right << '=' << result << "\n\n";

    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("12894082");
      bigint right(165247);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 12894082);
      assert(right  == "165247");
      assert(result == 13059329);

      //Printing to check
      //std::cout << left << '+' << right << '=' << result << "\n\n";

    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("99999999999999999999999999999999999999999999999999999999999999"
      "99999999999999999999999999999999999999999999999999999999999999999999999999"
      "99999999999999999999999999999999999999999999999999999999999999999999999999"
      "999999999999999999999999999999999999999999999");
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "999999999999999999999999999999999999999999999999999999999"
      "99999999999999999999999999999999999999999999999999999999999999999999999999"
      "99999999999999999999999999999999999999999999999999999999999999999999999999"
      "99999999999999999999999999999999999999999999999999");
      assert(right  == 1);
      assert(result == "100000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000");

      //Printing to check
//      std::cout << left << '\n' << '+' << '\n' << right << '\n';
//      std::cout << '=' << '\n';
//      std::cout << result << "\n\n";

    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("10000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000000000");
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      // assert(left   == "100000000000000000000000000000000000000000000000000000000"
      // "00000000000000000000000000000000000000000000000000000000000000000000000000"
      // "00000000000000000000000000000000000000000000000000000000000000000000000000"
      // "000000000000000000000000000000000000000000000000000");
      // assert(right  == 0);
      assert(result == "100000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000");

      //Printing to check
//      std::cout << left << '\n' << '+' << '\n' << right << '\n';
//      std::cout << '=' << '\n';
//      std::cout << result << "\n\n";

    }
    {//for the sake of making checking less of a headache, these strings
     //extend farther to the right in the code than I'd usually choose to 
      bigint left( "23456789087654322345678987654323820472075085745784750845784311428487548564976496" 
      "756456497645958940854905840927003140134874587676" );
      bigint right("42848754856497649675645649764595894085490584092700314013487458767623456789087654"
      "322345678987654323820472075085745784750845784311");
      bigint result;

      result = left + right;
      assert(result == "66305543944151972021324637418919714557565669838485064859271770196111005354064151"
      "078802176633613264675377916012748924885720371987");
      //accuracy checked by multiple calculators designed
      //to compute large numbers

      //Printing to check
//      std::cout << left << '\n' << '+' << '\n' << right << '\n';
//      std::cout << '=' << '\n';
//      std::cout << result << "\n\n"; 
    }

      bigint left("4723801");
      bigint right(128905432);
      bigint result;

      result = left + right;
      assert(result == 133629233);  
    //Add test cases as needed.
    
    
    std::cout << "Done with testing addition." << std::endl;
    return 0;
}