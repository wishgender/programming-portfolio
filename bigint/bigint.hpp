//contains capacity and other information about bigint
//8-29-2024
//Lazuli Rogers

//Milestone 1 due 9-9-24

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

//maximum digits possible to contain
const int CAPACITY = 256;

//max characters to print on one line 
const int LINE_LIMIT = 80;

class bigint{
    private:
        //array of digits representing the bigint
        int _digits[CAPACITY];

        //number of digits in bigint
        int _length;

        //initialization function
        void initialize();
        
    public:
        //default constructor
        bigint();

        //constructor to initialize from an integer
        bigint(int newValue);
        
        //constructor to initialize from a char array
        bigint(const char newValue[]);

        //overloaded equality operator
        bool operator==(const bigint& rhs) const;

        //overloaded addition operator
        bigint operator+(const bigint& rhs);

        //overloaded subscript operator
        int operator[] (int index) const;

        //overloaded multiplication operator
        bigint operator*(const bigint& other);

        //multiply bigint by single digit integer
        bigint timesDigit(int num) const;

        //multiply bigint by 10 (shift left)
        bigint times10(int num) const;
        
        
        //for use debugging print function
        void debugPrint(std::ostream& out) const;

     //=========================================================================//
     //==// friend function definitions

        //overloaded output operator
        friend std::ostream& operator<<(std::ostream& out, const bigint& num);

        //overloaded input operator 
        friend std::istream& operator>>(std::istream& in, bigint& num);
   

};


#endif