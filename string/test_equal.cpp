//  String class test program
// 
//  Name:  Lazuli Rogers | aroger52
//  Tests: equality operators 
//
 
#include "string.hpp"
#include <cassert>
#include <iostream> 

//===========================================================================
int main ()
{   
    std::cout << std::endl;
    // equality operator
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left('a');
        String  right('a');

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == true);
        assert(left   == right);
        assert(right  == left);
        assert(left   == 'a');
        assert(right  == 'a');     
        assert(left   != '_');
        assert(right  != '_');
        
        std::cout << '\n' << left << " == " << right << std::endl;

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left('\0');
        String  right('\0');

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == true);
        assert(left   == right);
        assert(right  == left);
        assert(left   == '\0');
        assert(right  == '\0');
        assert(left   != '0');
        assert(right  != '0');   

        std::cout << "\n[null] == [null]" << std::endl;
  
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left('a');
        String  right('A');

        String  x("a");
        String  y("A");

        // TEST
        bool result = (left != right);

        // VERIFY
        assert(result == true);
        assert(left   == 'a');
        assert(left   == x);
        assert(right  == 'A');
        assert(right  == y);
        std::cout << '\n' << left << " != " << right << std::endl;
       
    }

    {//testing after reassignment
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("Sphinx of black quartz, judge my vow.");
        String  right("B6CkRjUMjQKKzm7PN5vdkUIuO1q3lScE4DWVFNo6iIvkoWwyT9ue8IbAlAYMu0Qz"
                      "NYQyR0nU2rJqBtePtjVlJodt7gej6sCc0Dqed0mhcD6uKOqdAJRmuOHpYEZhXFJm"
                      "pwveomV1aBC0RxE5Od4IqC0vWbpGTtPjwOK5pqfk8Rd8eVAaCMcN1UcxRNZ3TZos"
                      "axWxKF7XtBui9nDAL80Z3pa0H8ec0Mx7fwO0KUUNC7d7uxmpzPcA4vkKxb2vDXg");
        right = "Sphinx of black quartz, judge my vow.";

        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == true);
        assert(left   == "Sphinx of black quartz, judge my vow.");
        assert(right  == left);
       
        std::cout << '\n' << left << "\n==\n" << right << std::endl;

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("B6CkRjUMjQKKzm7PN5vdkUIuO1q3lScE4DWVFNo6iIvkoWwyT9ue8IbAlAYMu0Qz"
                      "NYQyR0nU2rJqBtePtjVlJodt7gej6sCc0Dqed0mhcD6uKOqdAJRmuOHpYEZhXFJm"
                      "pwveomV1aBC0RxE5Od4IqC0vWbpGTtPjwOK5pqfk8Rd8eVAaCMcN1UcxRNZ3TZos"
                      "axWxKF7XtBui9nDAL80Z3pa0H8ec0Mx7fwO0KUUNC7d7uxmpzPcA4vkKxb2vDXg");
        String  right("B6CkRjUMjQKKzm7PN5vdkUIuO1q3lScE4DWVFNo6iIvkoWwyT9ue8IbAlAYMu0Qz"
                      "NYQyR0nU2rJqBtePtjVlJodt7gej6sCc0Dqed0mhcD6uKOqdAJRmuOHpYEZhXFJm"
                      "pwveomV1aBC0RxE5Od4IqC0vWbpGTtPjwOK5pqfk8Rd8eVAaCMcN1UcxRNZ3TZos"
                      "axWxKF7XtBui9nDAL80Z3pa0H8ec0Mx7fwO0KUUNC7d7uxmpzPcA4vkKxb2vDXg");
        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == true);
        assert(left.length()   == right.length());
        assert(right  == left);

        std::cout << '\n' << left << "\n==\n" << right << std::endl;
   
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left;
        String  right("a bunch of letters, spaces, and other common punctuation symbols_can be? found in *this 5tr1n6, d0n't y0u kn<w?");

        std::cout << left << std::endl << right << std::endl;

        left = right;
        std::cout << "assigned value of right to left\n";
        // TEST
        bool result = (left == right);

        // VERIFY
        assert(result == true);
        assert(left   == right);
        assert(right  == left);
        
        std::cout << '\n' << left << "\n==\n" << right << std::endl;
    }
        
    std::cout << "\nDone testing equality.\n===================\n" << std::endl;
    return 0;
}
