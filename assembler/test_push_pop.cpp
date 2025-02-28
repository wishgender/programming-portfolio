//  Stack class test program
//
//  Tests: push, pop 
//

#include "stack.hpp"
#include <cassert>
#include <iostream>


void testInt();
void testChar();
void testBool();
void printDivider();

//===========================================================================
int main ()
{
    testInt();
    testChar();
    testBool();
    return 0;
};  

void testInt() {
    std::cout << "testing int values\n";
    printDivider();
    //------------------------------------------------------
    // SETUP FIXTURE 
    
    /*TEST MULTIPUSH-POP*/
    stack<int>  aa;
    // TEST
    aa.push(2);
    assert(aa.top() == 2);
    
    aa.push(4);
    assert(aa.top() == 4);

    aa.push(6);
    assert(aa.top() == 6);

    aa.push(8);
    assert(aa.top() == 8);

    aa.push(10);
    assert(aa.top() == 10);
    
    int a = aa.pop();

    assert(a == 10 && aa.top() == 8);
    
    
    a = aa.pop();
    
    assert(a == 8 && aa.top() == 6);
    
    
    a = aa.pop();
    
    assert(a == 6 && aa.top() == 4);
    
    
    a = aa.pop();
    
    assert(a == 4 && aa.top() == 2);
    
    a = aa.pop();
    
    assert(a == 2 && aa.empty());

    //------------------------------------------------------
    // SETUP FIXTURE
    stack<int>  bb;

    // TEST
    bb.push(5);


    int b = bb.pop();
    assert(b == 5 && bb.empty());


    //------------------------------------------------------
    // SETUP FIXTURE
    stack<int>  cc;

    // TEST
    cc.push(0);
    assert(cc.top() == 0);

    std::cout << "--done pushing--\n";

    int c = cc.pop();

    // VERIFY
    assert(c == 0 && cc.empty());
        


    
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<int>  dd;
    
    // TEST
    dd.push(0);

    dd.push(1);

    dd.push(0);

    int d = dd.pop();

    assert(d == 0 && dd.top() == 1);

     
    dd.push(0);
     
    assert(dd.top() == 0);

     
    dd.push(1);
     
    assert(dd.top() == 1);

     
    dd.push(0);
     
    assert(dd.top() == 0);
    
    std::cout << "--done pushing--\n";
    
     
    d = dd.pop();
     
    assert(d == 0);
    
     
    d = dd.pop();
     
    assert(d == 1);
    
     
    d = dd.pop();
     
    assert(d == 0);
    
     
    d = dd.pop();
     
    assert(d == 1);

     
    d = dd.pop();
     
    assert(d == 0 && dd.empty());
    
    std::cout << std::endl;
    std::cout << "Done testing int values\n";
    printDivider();
};


void testChar() {
        {
            std::cout << "now testing char values\n";
        //------------------------------------------------------
        // SETUP FIXTURE
            //multiple
            stack<char>  ee;

            // TEST
            
            ee.push('a');
            
            
            
            ee.push('b');
            

            
            ee.push('c');
            

            
            ee.push('d');
            

            
            ee.push('e');
            

            
            char e = ee.pop();
            
            assert(e == 'e');
            
            
            e = ee.pop();
            
            assert(e == 'd');

            
            e = ee.pop();
            
            assert(e == 'c');

            
            e = ee.pop();
            
            assert(e == 'b');

            
            e = ee.pop();
            
            assert(e == 'a' && ee.empty());
        }    

        {
        //------------------------------------------------------
        // SETUP FIXTURE
            //SINGLE
            stack<char>  ff;

        // TEST
            
            ff.push('m');
            

            std::cout << "--done pushing--\n";

        // VERIFY
            assert(ff.pop() == 'm' && ff.empty());

        }
        std::cout << "\ntesting edge cases\n\n";
        {
        //------------------------------------------------------
        // SETUP FIXTURE
            //multiple
            stack<char>  ee;
            // TEST
            std::cout << "(\'\\b\'|backspace)\n";
            
            ee.push('\b');
            

            std::cout << "(\'\\a\'|audible bell)\n";
            
            ee.push('\a');
            

            std::cout << "(\'\\f\'|form feed)\n";
            
            ee.push('\f');
            

            std::cout << "(\'\\t\'|horizontal tab)\n";
            
            ee.push('\t');
            

            std::cout << "(\'\\v\'|vertical tab)\n";
            
            ee.push('\v');
            

            std::cout << "(\'\\n\'|new line)\n";
            
            ee.push('\n');
            

            std::cout << "(\'\\0\'|null character)\n";
            
            ee.push('\0');
            

            std::cout << "('0')\n";
            
            ee.push('0');
            

            std::cout << "(0)\n";
            
            ee.push(0);
            

            std::cout << "--done pushing--\n";

            std::cout << "(0)\n";
            
            char zero = ee.pop();
            
            assert(zero == 0);

            std::cout << "('0')\n";
            
            char zeroChar = ee.pop();
            
            assert(zeroChar == '0');

            std::cout << "(\'\\0\'|null character)\n";
            
            char nullchar = ee.pop();
            
            assert(nullchar == '\0');
            assert(zero == nullchar && (zero != zeroChar && zeroChar != nullchar));

            std::cout << "0 == '\\0' && 0 != '0' && '\\0' != '0'\n\n";

            std::cout << "(\'\\n\'|new line)\n";
            
            char newLine = ee.pop();
            
            assert(newLine == '\n');

            std::cout << "(\'\\v\'|vertical tab)\n";
            
            char vertTab = ee.pop();
            
            assert(vertTab == '\v');

            
            char tab = ee.pop();
            
            assert(tab == '\t');

            
            char formFeed = ee.pop();
            
            assert(formFeed == '\f');

            
            char audBell = ee.pop();
            
            assert(audBell == '\a');

            
            char backspace = ee.pop();
            
            assert(backspace == '\b' && ee.empty());
            
            
        }

        {
    std::cout << std::endl;
    
    std::cout << "\n//===========================================================================//\n";
        }

        {
        //------------------------------------------------------
        // SETUP FIXTURE
            //SINGLE
            stack<char>  ff;

        // TEST
            ff.push('m');

            std::cout << "--done pushing--\n";

            assert(ff.pop() == 'm');

        // VERIFY
            assert(ff.empty());
        }
    std::cout << std::endl;

    std::cout << "\n//===========================================================================//\n";

};


void testBool() {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<bool>  gg;

    // TEST
    
    gg.push(true);
    
    assert(gg.top() == true);

    
    gg.push(false);
    
    assert(gg.top() == false);
    
    
    gg.push(false);
    
    assert(gg.top() == false);

    
    gg.push(true);
    
    assert(gg.top() == true);

    
    gg.push(false);
    
    assert(gg.top() == false);

    std::cout << "--done pushing--\n";
    
    
    bool g = gg.pop();
    
    assert(g == 0);

    
    g = gg.pop();
    
    assert(g == 1);
    
    
    g = gg.pop();
    
    assert(g == 0);
    
    
    g = gg.pop();
    
    assert(g == 0);
    
    
    g = gg.pop();
    
    assert(g == 1 && gg.empty());

    std::cout << std::endl;
    
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<bool>  hh;

    // TEST
    
    hh.push(true);
    

    
    assert(hh.pop() == 1);
    

    
    hh.push(false);
    

    
    assert(hh.pop() == 0 && hh.empty());
    


    std::cout << std::endl;
    printDivider();
};


void testDouble() {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<double>  ii;

    // TEST
    ii.push(1.25);
    ii.push(76.24);
    ii.push(8.45);
    ii.push(0.91);
    ii.push(6.90);

    std::cout << "--done pushing--\n";

    double i = ii.pop();
    assert(i == 6.90);
    i = ii.pop();
    assert(i == 0.91);
    i = ii.pop();
    assert(i == 8.45);
    i = ii.pop();
    assert(i == 76.24);
    i = ii.pop();
    assert(i == 1.25 && ii.empty());
    
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<double>  jj;

    // TEST
    jj.push(7.62);

    std::cout << "--done pushing--\n";

    assert(jj.pop() == 7.62);

    // VERIFY
    assert(jj.empty());
    std::cout << std::endl;
    printDivider();
}


void testFloat() {
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<float>  kk;

    // TEST
    kk.push(6.9f);
    kk.push(37.1f);
    kk.push(99.3f);
    kk.push(617.2f);
    kk.push(0.1f);

    std::cout << "--done pushing--\n";

    float k = kk.pop();
    assert(k == 0.1f);
    k = kk.pop();
    assert(k == 617.2f);
    k = kk.pop();
    assert(k == 99.3f);
    k = kk.pop();
    assert(k == 37.1f);
    k = kk.pop();
    assert(k == 6.9f && kk.empty());
    
    //------------------------------------------------------
    // SETUP FIXTURE
    stack<float>  ll;

    // TEST
    ll.push(99.3f);

    std::cout << "--done pushing--\n";

    float l = ll.pop();
    assert(l == 99.3f && ll.empty());

    std::cout << std::endl;


    };

void testString() {



    
    


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing push and pop." << std::endl;


}

void printDivider() {
    std::cout << "\n//===========================================================================//\n";
}