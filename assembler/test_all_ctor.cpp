//  Stack class test program
//
//  Tests: constructors 
//

#include "stack.hpp"
#include "../string/string.hpp"

#include <new>
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{

    std::cout << "Testing constructors...\n";

    {//Default constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "\nTesting default constructor with type int:\n\n";

        // TEST
        std::cout << "Initializing stack<int> x...\t";
        stack<int> x;
        std::cout << "\tInitialized stack<int> x!\n";

        // VERIFY
        std::cout << "Asserting x.empty()...\t";
        assert(x.empty());
        std::cout << "\tSuccess! Int test complete!\n";
    }

    {//Default constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "\nTesting default constructor with type char:\n\n";

        // TEST
        std::cout << "Initializing stack<char> x...\t";
        stack<char>  x;
        std::cout << "\tInitialized stack<char> x!\n";

        // VERIFY
        std::cout << "Asserting x.empty()...\t";
        assert(x.empty());
        std::cout << "\tSuccess! Char test complete!\n";
    };

    {//Default constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "\nTesting default constructor with type bool:\n\n";

        // TEST
        std::cout << "Initializing stack<bool> x...\t";
        stack<bool>  x;
        std::cout << "\tInitialized stack<bool> x!\n";

        // VERIFY
        std::cout << "Asserting x.empty()...\t";
        assert(x.empty());
        std::cout << "\tSuccess! Bool test complete!\n";
    }

    {//Default constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "\nTesting default constructor with type String:\n\n";

        // TEST
        std::cout << "Initializing stack<String> x...\t";
        stack<String>  x;
        std::cout << "\tInitialized stack<String> x!\n";

        // VERIFY
        std::cout << "Asserting x.empty()...\t";
        assert(x.empty());
        std::cout << "\tSuccess! String test complete!\n";
    }

    {//Default constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "\nTesting default constructor with type double:\n\n";

        // TEST
        std::cout << "Initializing stack<double> x...\t";
        stack<double>  x;
        std::cout << "\tInitialized stack<double> x!\n";

        // VERIFY
        std::cout << "Asserting x.empty()...\t";
        assert(x.empty());
        std::cout << "\tSuccess! Double test complete!\n";
    }

    {//Default constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "Testing default constructor with type float:\n\n";

        // TEST
        std::cout << "Initializing stack<float> x...\t";
        stack<float>  x;
        std::cout << "\tInitialized stack<float> x!\n";

        // VERIFY
        std::cout << "Asserting x.empty()...\t";
        assert(x.empty());
        std::cout << "\tSuccess! Float test complete!\n";
    }



    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "\nDone testing default constructor." << std::endl;


    {//T constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "\nTesting type constructor with type int:\n\n";

        // TEST
        int input = 32;
        std::cout << "int input = " << input << ";\n";
        std::cout << "Initializing stack<int> x(input)...\t";
        stack<int>  x(input);
        std::cout << "\tInitialized stack<int> x!\n";

        // VERIFY
        std::cout << "Asserting x.top() == input...\t";
        assert(x.top() == input);
        std::cout << "\tSuccess! Int test complete!\n";
    }

    {//T constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "\nTesting type constructor with type char:\n\n";

        // TEST
        char input = 'w';
        std::cout << "char input = " << input << ";\n";
        std::cout << "Initializing stack<char> x(input)...\t";
        stack<char>  x(input);
        std::cout << "\tInitialized stack<char> x!\n";

        // VERIFY
        std::cout << "Asserting x.top() == input...\t";
        assert(x.top() == input);
        std::cout << "\tSuccess! Char test complete!\n";
    }

    {//T constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "\nTesting type constructor with type bool:\n\n";

        // TEST
        bool input = true;
        std::cout << "bool input = " << input << ";\n";
        std::cout << "Initializing stack<bool> x(input)...\t";
        stack<bool> x(input);
        std::cout << "\tInitialized stack<bool> x!\n";

        // VERIFY
        std::cout << "Asserting x.top() == input...\t";
        assert(x.top() == input);
        std::cout << "\tSuccess! Bool test complete!\n";
    }

    {//T constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "\nTesting type constructor with type String:\n\n";

        // TEST
        String input = "this-is-a-String";
        std::cout << "String input = " << input << ";\n";
        std::cout << "Initializing stack<String> x(input)...\t";
        stack<String>  x(input);
        std::cout << "\tInitialized stack<String> x!\n";

        // VERIFY
        std::cout << "Asserting x.top() == input...\t";
        assert(x.top() == input);
        std::cout << "\tSuccess! String test complete!\n";
    }

    {//T constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "\nTesting type constructor with type double:\n\n";

        // TEST
        double input = 75.29;
        std::cout << "double input = " << input << ";\n";
        std::cout << "Initializing stack<double> x(input)...\t";
        stack<double>  x(input);
        std::cout << "\tInitialized stack<double> x!\n";

        // VERIFY
        std::cout << "Asserting x.top() == input...\t";
        assert(x.top() == input);
        std::cout << "\tSuccess! Double test complete!\n";
    }


    {//T constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "\nTesting type constructor with type float:\n\n";

        // TEST
        float input = 9.4f;
        std::cout << "float input = " << input << ";\n";
        std::cout << "Initializing stack<float> x(input)...\t";
        stack<float>  x(input);
        std::cout << "\tInitialized stack<float> x!\n";

        // VERIFY
        std::cout << "Asserting x.top() == input...\t";
        assert(x.top() == input);
        std::cout << "\tSuccess! Float test complete!\n";
    }

    std::cout << "\n\nDone testing T data constructor." << std::endl;

//===========================================================================//
//=Copy constructor tests


    {//Copy constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "\nTesting copy constructor with type int:\n\n";

        // TEST
        int input = 32;
        std::cout << "int input = " << input << ";\n";
        std::cout << "Initializing stack<int> x(input)...\t";
        stack<int>  x(input);
        std::cout << "\tInitialized stack<int> x!\n";

        // VERIFY
        std::cout << "Asserting x.top() == input...\t";
        assert(x.top() == input);
        std::cout << "\tSuccess! Int test complete!\n";
    }

    {//Copy constructor
        //------------------------------------------------------
        // SETUP FIXTURE
        std::cout << "\nTesting copy constructor with type int:\n\n";

        // TEST

        stack<int> A;
        std::cout << "Declared stack<int> A\n";

        int input = 12;
        A.push(12);
        std::cout << "Pushed input of " << input << " to stack A\n";
        
        std::cout << "Initialized stack<int> B from stack<int> A\n";
        stack<int> B(A);


        // VERIFY
        std::cout << "Asserting B.top() == A.top()...\t";
        assert(B.top() == A.top());
        std::cout << "Success!\n";

        input = 8;
        std::cout << "Pushing input of " << input << " to stack B...\n";
        B.push(input);

        // VERIFY
        std::cout << "Asserting B.top() != A.top()...\t";
        assert(B.top() != A.top());
        std::cout << "Success!\n";
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    return 0;
}

