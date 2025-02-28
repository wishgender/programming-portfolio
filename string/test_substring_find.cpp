//  String class test program
// 
//  Tests: substring method, find methods
//
//  Name: Lazuli Rogers | aroger52
  
#include "string.hpp"
#include <cassert>
#include <iostream> 
 
//===========================================================================
int main ()
{
    //FIND CHAR
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        String x ("Llanfairpwllgwyngyllgogerychwyrndrobwllllantysiliogogogoch");

        // TEST
        int z = x.findch(0, 'L');
        int y = x.findch(0, 'q');
        int w = x.findch(50, 'p');
        int v = x.findch(10, 'c');
        int u = x.findch(0, 'f');
        int t = x.findch(0, NULL_CHAR);

        // VERIFY
        assert(z          ==  0);
        assert(y          == -1);
        assert(w          == -1);
        assert(v          == 26);
        assert(u          ==  4);
        assert(t          == -1);

        std::cout << "\nString x: " << x << std::endl;
        std::cout << "Starting from 0, the character 'g' is first found at index " << z << std::endl;
        std::cout << "Starting from 0, the character 'q' is found nowhere in this string" << std::endl;
        std::cout << "Starting from 50, the character 'p' is found nowhere in this string" << std::endl;
        std::cout << "Starting from 10, the character 'c' is first found at index " << v << std::endl;
        std::cout << "Starting from 0, the character 'f' is first found at index " << u << std::endl;
        std::cout << "Starting from 0, the null character is found nowhere in this string" << std::endl;

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        String emptyStr;

        // TEST
        int z = emptyStr.findch(0, 'j');
        int y = emptyStr.findstr(0, "jk");        
        int x = emptyStr.findch(2, 'j');
        int w = emptyStr.findstr(2, "jk");
        int v = emptyStr.findch(0, NULL_CHAR);
        // VERIFY
        assert(z == -1);
        assert(y == -1);
        assert(x == -1);
        assert(w == -1);
        assert(v == -1);
        std::cout << "\nCharacters cannot be found in an empty string. Error " << z << std::endl;
        std::cout << "\nSubstrings cannot be found in an empty string. Error " << z << std::endl;
    }

    //FIND SUBSTRING
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        String x ("Llanfairpwllgwyngyllgogerychwyrndrobwllllantysiliogogogoch");

        // TEST
        int z = x.findstr(0, "Llanfairpwllgwyngyll");
        int y = x.findstr(0, "siliogogogoch");
        int w = x.findstr(40, "ogogog");
        int v = x.findstr(10, "drobwllll");
        int u = x.findstr(0, "pizza");
        int t = x.findstr(0, "Llanchair");

        // VERIFY
        assert(z          ==  0);
        assert(y          == 45);
        assert(w          == 49);
        assert(v          == 32);
        assert(u          == -1);
        assert(t          == -1);

        std::cout << "\nString x: " << x << std::endl;
        std::cout << "Starting from 0, the substring ''Llanfairpwllgwyngyll'' is first found at index " << z << std::endl;
        std::cout << "Starting from 0, the substring ''siliogogogoch'' is first found at index " << y << std::endl;
        std::cout << "Starting from 40, the substring ''ogogog'' is first found at index " << w << std::endl;
        std::cout << "Starting from 10, the substring ''drobwllll'' is first found at index " << v << std:: endl;
        std::cout << "Starting from 0, the substring ''pizza'' is found nowhere in this string" << std::endl;
        std::cout << "Starting from 0, the substring ''Llanchair'' is found nowhere in this string" << std::endl;
    }

    
    // SUBSTRING
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        String x ("Llanfairpwllgwyngyllgogerychwyrndrobwllllantysiliogogogoch");
        // TEST
        String y;
        y = x.substr(0, 19);
        // VERIFY
        assert(y          == "Llanfairpwllgwyngyll");
        assert(y.length() == 20);
        std::cout << "\nThe village of " << x << " is also known by its shorter nickname, " << y << "\n\n";
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  x = "B6CkRjUMjQKKzm7PN5vdkUIuO1q3lScE4DWVFNo6iIvkoWwyT9ue8IbAlAYMu0QzNYQyR0nU2rJqBtePtjVlJodt7gej6sCc0Dqed0mhcD6uKOqdAJRmuOHpYEZhXFJmpwveomV1aBC0RxE5Od4IqC0vWbpGTtPjwOK5pqfk8Rd8eVAaCMcN1UcxRNZ3TZosaxWxKF7XtBui9nDAL80Z3pa0H8ec0Mx7fwO0KUUNC7d7uxmpzPcA4vkKxb2vDXg";
        // TEST
        String y(x.substr(128, x.capacity()-1));
        std::cout << y;
        // VERIFY       
        assert(y    == "pwveomV1aBC0RxE5Od4IqC0vWbpGTtPjwOK5pqfk8Rd8eVAaCMcN1UcxRNZ3TZosaxWxKF7XtBui9nDAL80Z3pa0H8ec0Mx7fwO0KUUNC7d7uxmpzPcA4vkKxb2vDXg");
        assert(y    !=  x);
        std::cout << y << '\n' << "is a substring of\n" <<  x << '\n' << std::endl;
    }
    {
        String str("Hello, World!");
        assert(str.substr(0, 4) == "Hello");  // Beginning substring
        assert(str.substr(7, 11) == "World"); // Middle substring
        assert(str.substr(12, 12) == "!");    // Single character substring

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  x("O");

        // TEST
        String y;
        y = x.substr(0,0);


        // VERIFY
        assert(y == "O");
        assert(y == x);
        std::cout << y << " is a substring of " << x << '\n';

    }    
    
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  x("O");

        // TEST
        String y("OO");
        String z(x.substr(0,0));


        // VERIFY
        assert(y == "OO");
        assert(y != x);
        assert(y != z);
        assert(z == x);
        std::cout << y << " is not a substring of " << x << '\n';

    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String    x("Lorem ipsum dolor sit amet");

        // TEST
        int z = x.findstr(0, "dolor");
        int y = x.findch(z, ' ');

        // VERIFY
        assert(z == 12);
        assert(y == 17);

        std::cout << "\nIn string x, '" << x << "'\n";
        std::cout << "Starting from 0, the substring 'dolor' is first found at index " << z << '\n';
        std::cout << "Starting from " << z << ", the space character ' ' is first found at index " << y << std::endl;

    }
   
    std::cout << "\nDone testing substring and find functions.\n===================" << std::endl;
    return 0;
}

