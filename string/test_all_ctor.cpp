//  String class test program
//
//  Tests: constructors
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

        // TEST
        String  str;

        // VERIFY
        assert(str == NULL_CHAR);
        assert(str.length() == 0);
        std::cout << "DEFAULT CTOR TEST PASSED" << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('g');
        std::cout << str << std::endl;
        String str2("g");
        std::cout << str2 << std::endl;
        // VERIFY
        assert(str == 'g');
        assert(str != 'G');
        assert(str == "g");
        assert(str != "G");
        assert(str.length() == 1);

        std::cout << "\nchar constructor: ";
        std::cout << str << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("h");

        // VERIFY
        assert(str == 'h');
        assert(str != 'H');
        assert(str == "h");
        assert(str != "H");
        assert(str.length() == 1);
        
        std::cout << "\nconst char [] constructor: ";
        std::cout << str << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('I');

        // VERIFY
        assert(str == 'I');
        assert(str != 'i');
        assert(str == "I");
        assert(str != "i");
        assert(str.length() == 1);

        std::cout << "\nchar constructor: ";
        std::cout << str << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("J");

        // VERIFY
        assert(str == 'J');
        assert(str != 'j');
        assert(str == "J");
        assert(str != "j");
        assert(str.length() == 1);
    
        std::cout << "\nconst char [] constructor: ";
        std::cout << str << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str ("B6CkRjUMjQKKzm7PN5vdkUIuO1q3lScE4DWVFNo6iIvkoWwyT9ue8IbAlAYMu0Qz"
              "NYQyR0nU2rJqBtePtjVlJodt7gej6sCc0Dqed0mhcD6uKOqdAJRmuOHpYEZhXFJm"
              "pwveomV1aBC0RxE5Od4IqC0vWbpGTtPjwOK5pqfk8Rd8eVAaCMcN1UcxRNZ3TZos"
              "axWxKF7XtBui9nDAL80Z3pa0H8ec0Mx7fwO0KUUNC7d7uxmpzPcA4vkKxb2vDXg");
        std::cout << str << std::endl;
        // VERIFY
        assert(str == "B6CkRjUMjQKKzm7PN5vdkUIuO1q3lScE4DWVFNo6iIvkoWwyT9ue8IbAlAYMu0Qz"
                      "NYQyR0nU2rJqBtePtjVlJodt7gej6sCc0Dqed0mhcD6uKOqdAJRmuOHpYEZhXFJm"
                      "pwveomV1aBC0RxE5Od4IqC0vWbpGTtPjwOK5pqfk8Rd8eVAaCMcN1UcxRNZ3TZos"
                      "axWxKF7XtBui9nDAL80Z3pa0H8ec0Mx7fwO0KUUNC7d7uxmpzPcA4vkKxb2vDXg");

        assert(str.length() == 255);
        assert(str.length() == str.capacity());

        std::cout << "\nconst char [] constructor:\n";
        std::cout << str << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str ("B6CkRjUMjQKKzm7PN5vdkUIuO1q3lScE4DWVFNo6iIvkoWwyT9ue8IbAlAYMu0Qz"
                     "NYQyR0nU2rJqBtePtjVlJodt7gej6sCc0Dqed0mhcD6uKOqdAJRmuOHpYEZhXFJm"
                     "pwveomV1aBC0RxE5Od4IqC0vWbpGTtPjwOK5pqfk8Rd8eVAaCMcN1UcxRNZ3TZos"
                     "axWxKF7XtBui9nDAL80Z3pa0H8ec0Mx7fwO0KUUNC7d7uxmpzPcA4vkKxb2vDXg");

        // VERIFY
        assert(str == "B6CkRjUMjQKKzm7PN5vdkUIuO1q3lScE4DWVFNo6iIvkoWwyT9ue8IbAlAYMu0Qz"
                      "NYQyR0nU2rJqBtePtjVlJodt7gej6sCc0Dqed0mhcD6uKOqdAJRmuOHpYEZhXFJm"
                      "pwveomV1aBC0RxE5Od4IqC0vWbpGTtPjwOK5pqfk8Rd8eVAaCMcN1UcxRNZ3TZos"
                      "axWxKF7XtBui9nDAL80Z3pa0H8ec0Mx7fwO0KUUNC7d7uxmpzPcA4vkKxb2vDXg");

        assert(str.length() == 255);
        assert(str.length() <= str.capacity());

        std::cout << "\nconst char [] constructor:\n";
        std::cout << str << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("The quick brown fox jumps over the lazy dog.");

        // VERIFY
        assert(str == "The quick brown fox jumps over the lazy dog.");
        assert(str.length() == 44);

        std::cout << "\nconst char [] constructor:\n";
        std::cout << str << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("Sphinx of black quartz, judge my vow.");

        // VERIFY
        assert(str == "Sphinx of black quartz, judge my vow.");
        std::cout << "\nconst char [] constructor:\n";
        std::cout << str << std::endl;
    }

    {//COPY CTOR
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str;
        String str2(str);
        String str3(str2);

        std::cout << '"' << str << '"' <<'\n';
        std::cout << '"' << str2 << '"' <<'\n';
        std::cout << '"' << str3 << '"' <<'\n';


        // VERIFY
        assert(str == NULL_CHAR);
        assert(str.length() == 0);
        std::cout << "COPY CTOR TEST 1 PASSED\n" << std::endl;
    }

    {//COPY CTOR
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("catppuccin mocha");
        String str2;
        String str3 = str2 = str;

        assert(str == "catppuccin mocha");
        assert(str2 == "catppuccin mocha");
        assert(str3 == "catppuccin mocha");

        std::cout << "String str: " << '"' << str << '"' <<'\n';
        std::cout << "String str2: " << '"' << str2 << '"' <<'\n';
        std::cout << "String str3: " << '"' << str3 << '"' <<'\n';

        std::cout << "\nAssigning new values to str2 and str3!\n";

        str2 = "latte catppuccin";
        str3 = "macchiato catppuccin";

        // VERIFY
        assert(str == "catppuccin mocha");
        assert(str2 == "latte catppuccin");
        assert(str3 == "macchiato catppuccin");

        assert(str3 != str);
        assert(str3 != str2);
        assert(str2 != str);
        assert(str2 != str3);
        assert(str != str2);
        assert(str != str3);

        
        std::cout << "String str: " << '"' << str << '"' <<'\n';
        std::cout << "String str2: " << '"' << str2 << '"' <<'\n';
        std::cout << "String str3: " << '"' << str3 << '"' <<'\n';

        std::cout << "COPY CTOR TEST PASSED" << std::endl;
    }
    
    std::cout << "\nDone testing constructors.\n===================\n" << std::endl;
    return 0;
}

