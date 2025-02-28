//  String class test program
// 
//  Name:  Lazuli Rogers | aroger52
//
//  Tests: less than operators
 
#include "string.hpp"
#include <cassert>
#include <iostream> 

//===========================================================================
int main ()
{
    // less than operator
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("autism");
        String  right("employment");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true); //letters at the start of the
                                //alphabet have lower ASCII values
                                //than those at the end
        std::cout << "\n'" << left << "' < '" << right << "'\n";

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("autism");
        String  right("autism spectrum");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);//a shorter string that is the
                                //prefix of a longer string is 
                                //considered to be smaller

        std::cout << "\n'" << left << "' < '" << right << "'\n";
   
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("video");
        String  right("videos");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true); //a shorter string that is the
                                //prefix of a longer string is 
                                //considered to be smaller
        std::cout << "\n'" << left << "' < '" << right << "'\n";
  
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("videography");
        String  right("videography");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false); //identical strings should be equal
        std::cout << "\n'" << left << "' > '" << right << "'\n";
  
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("");
        String  right("not an empty string");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true); //an empty string is smaller than non-empty
        std::cout << "\n[null]" << left << " < '" << right << "'\n";
  
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("");
        String  right("");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false); // two empty strings should be equal
        std::cout << "\n[null] !< [null]" << std::endl;

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("Cassette");
        String  right("cassette");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true); //capital letters have lower ASCII values
        std::cout << "\n'" << left << "' < '" << right << "'\n";
    
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("optical disc");
        String  right("optical Disc");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false); //capital letters have lower ASCII values
       
        std::cout << "\n'" << left << "' > '" << right << "'\n";
 
    }

    {   //= Testing single letters and different initialization
        //= methods, as well as case sensitivity
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left('A');
        String  right('a');

        String  x("A");
        String  y("a");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true);
        assert(left   <  y);
        assert(left   == x);
        assert(x      <  right);
        assert(x      == left);
        std::cout << "\n'" << left << "' < '" << right << "'\n";
       
    }

    {   //= Testing reassignment 
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("Sphinx of black quartz, judge my vow.");
        String  right("B6CkRjUMjQKKzm7PN5vdkUIuO1q3lScE4DWVFNo6iIvkoWwyT9ue8IbAlAYMu0Qz"
                      "NYQyR0nU2rJqBtePtjVlJodt7gej6sCc0Dqed0mhcD6uKOqdAJRmuOHpYEZhXFJm"
                      "pwveomV1aBC0RxE5Od4IqC0vWbpGTtPjwOK5pqfk8Rd8eVAaCMcN1UcxRNZ3TZos"
                      "axWxKF7XtBui9nDAL80Z3pa0H8ec0Mx7fwO0KUUNC7d7uxmpzPcA4vkKxb2vDXg");
        right = "1234567890";

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == false); //Arabic numerals have lower ASCII
                                 //the Latin alphabet
        assert(right  == "1234567890");
 
        std::cout << "\n'" << left << "' > '" << right << "'\n";

    }

    {   //= testing maximum capacity strings with mixed alphanumeric characters
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
        bool result = (left < right);

        // VERIFY
        assert(result == false); //the strings are identical
        assert(left.length()   == right.length());
        assert(left.length()   <= right.capacity());
        assert(right.length()  <= left.capacity());

        std::cout << '\n' << left << "\n==\n" << right << "\n\n";
  
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  left("grape");
        String  right("grape ");

        // TEST
        bool result = (left < right);

        // VERIFY
        assert(result == true); //space comes after all latin letters
                                //in the ASCII table
        assert(left   < right);
        assert(!(right  < left));
        
        std::cout << "\n'" << left << "' < '" << right << "'\n";

    }
    
    std::cout << "\nDone testing less than.\n===================\n" << std::endl;
    return 0;
}
