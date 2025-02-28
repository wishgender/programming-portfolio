//a class to represent positive integers larger than the computational limit of a x64 processor
//Lazuli Rogers
//CS23001

//milestone 1 due 9-8-24

#include <iostream>
#include <fstream>

#include "bigint.hpp"

void bigint::initialize() {
    // Streamline setting all digits to 0
    for (int i = 0; i < CAPACITY; ++i) {
        _digits[i] = 0;
    } 
    _length = 0;  
}

//default constructor
bigint::bigint() {
    initialize();
    //set length to 1
    _length = 1;
    // std::cout << "INITIALIZED BY DEFAULT CONSTRUCTOR: ";
    // debugPrint(std::cout);
    // std::cout << "\nLENGTH: " << _length << '\n';
};

//constructor to initialize from an integer
bigint::bigint(int newValue) {
    initialize();
    //special case for int value of zero
    if (newValue == 0) {
        _length = 1;
     //   std::cout << "INITIALIZED BY INTEGER CONSTRUCTOR: ";
     //   debugPrint(std::cout);
     //   std::cout << "\nLENGTH: " << _length << '\n';
        return;
    }

    int index =  0;
    int temp = newValue;
  
    while (newValue != 0) {
        _length++;
        //retrieving the current ones digit
        temp = newValue % 10;
        //removing current ones digit
        newValue /= 10;
        //placing extracted ones digit in array
        _digits[index++] = temp;
    }
    
   // std::cout << "INITIALIZED BY INTEGER CONSTRUCTOR: ";
  //  debugPrint(std::cout);
  //  std::cout << "\nLENGTH: " << _length << '\n';
};

//constructor to initialize from a char array
bigint::bigint(const char newValue[]){
    initialize();
    //special case for value of zero
    if (newValue[0] == '0' && newValue [1] == '\0') {
        _length = 1;
        // std::cout << "INITIALIZED BY CONST CHAR [] CONSTRUCTOR: ";
        // debugPrint(std::cout);
        // std::cout << "\nLENGTH: " << _length << '\n';
        return;
    }

    //iterating through char array to obtain the length    
    while (newValue[_length] != '\0') {_length++;}
    int n = 0;

    //iterating through the char array and peeling
    //away each digit to place in the bigint array
    for (int i = _length - 1; i >= 0 && n  < CAPACITY; --i, n++) {
        //placing in the bigint array
        _digits[i] = newValue[n] - '0';
    }
    
    // std::cout << "INITIALIZED BY CONST CHAR [] CONSTRUCTOR: ";
    // debugPrint(std::cout);
    // std::cout << "\nLENGTH: " << _length << '\n';

};
//=============================================================//
//=                  overloaded operators                     =//
//=============================================================//


    //overloaded output operator
    std::ostream& operator<<(std::ostream& out, const bigint& num) {
        //initializing leading zero flag
        bool leadingZero = true;
        //iterating to find digits to print
        int iters = 1;
        

        for (int i = CAPACITY - 1; i >= 0; i--) {
            //if the current digit is not zero, there is not a leading zero
            if (num._digits[i] != 0) leadingZero = false;
            if (!leadingZero) {
                out << num._digits[i];
                

                //add new line when line limit is hit
                if (iters % LINE_LIMIT == 0) {
                    out << '\n';
                }
                iters++;
            }
            
        }
        //if iteration does not disover a digit other than zero
        if (leadingZero) out << '0';
        return out;
    };

    //overloaded input operator
    std::istream& operator>>(std::istream& in, bigint& num) {
        char ch;
        num.initialize();  

        // Iterate over each character in the input stream until ';'
        int i = 0;
        while (in.get(ch) && ch != ';') {
            // If character is an Arabic numeral and there's still space in the array
            if (ch >= '0' && ch <= '9' && i < CAPACITY) {
                // Shift the digits already in the array to the right
                for (int j = CAPACITY - 1; j > 0; --j) {
                    num._digits[j] = num._digits[j - 1];
                }
                // Convert character to digit and place in the first position
                num._digits[0] = ch - '0';
                i++;
            }
        }
        num._length = i;
        return in;
    }


    // Overloaded equality operator
    bool bigint::operator==(const bigint& rhs) const {
        //int to hold higher length
        int biggerLength = 0;
        //setting biggerLength for same or lhs higher
        if (_length >= rhs._length) {
            biggerLength = _length;
        }
        //setting biggerLength for rhs higher
        else {
            biggerLength = rhs._length;
        }
        
        
        //iterates over both bigints
        for (int i = biggerLength - 1; i >= 0; --i) {
            //checks every corresponding pair for equality
            if (_digits[i] != rhs._digits[i]) return false;
        }
        return true;
    }

    //overloaded addition operator
    bigint bigint::operator+(const bigint& rhs) {
        bigint result;
        int carrier = 0;
        for(int i = 0; i < CAPACITY; ++i) {
            //adds the current ones digits and the carry
            int sum = _digits[i] + rhs._digits[i] + carrier;
            //place in result array, ensuring it is less than 10
            result._digits[i] = sum % 10;
            //sets the carry if necessary
            carrier = sum / 10;
        }
        return result;
    }

    //overloaded subscript operator
    int bigint::operator[](int index) const {
        if (index >= 0 && index < CAPACITY) {
            return _digits[index];
        }
        //in the case of out of range numbers
       std::cout << "Out of range\n";
       return -1; 
    }

    //overloaded multiplication operator
    bigint bigint::operator*(const bigint& other) {
        //the result to be eventually returned
        bigint product;
        
        int j = 0;
        //execute multiplication using timesDigit and times10
        for (int i = 0; i < CAPACITY; i++, j++) {
            bigint temp = this->timesDigit(other[i]);
            temp = temp.times10(i);
            product = product + temp;
        }
        product._length = CAPACITY - j;
        
        //product.debugPrint(std::cout);

        return product;

    }

//===================================//
//=   Functions to be used within   =//
//=      overloaded operators       =//
//===================================//

    //multiply bigint by a single-digit int
    bigint bigint::timesDigit(int num) const {

        bigint product;
        product._length  = 0;
        int carry        = 0;

        if (num == 0) {
            return 0;
        }
        for (int i = 0; i < _length; i++) {
            product._digits[i] = (_digits[i] * num) + carry;

            carry = 0; 
            product._length++;

            if (product._digits[i] >= 10) {
            carry = product._digits[i] / 10;
            product._digits[i] %= 10;
            }
        }

        if (carry != 0) {
            product._digits[product._length++] += carry;
        }
        return product;
    }

    //multiply bigint by a multiple of 10
    bigint bigint::times10(int num) const {
        bigint product;
       
        //std::cout << "PRODUCT DIGITS: ";
        for (int i = 0; i < _length; ++i) {
            product._digits[i + num] = _digits[i];
           // std::cout << product._digits[i + num] << " ";
        }
        product._length = _length + num;



        return product;

    }

    //printing method for use during debugging
    void bigint::debugPrint(std::ostream& out) const {
        //iterates over the array to print each element to the ostream
        for (int i = _length - 1; i >= 0; --i) {
            out << _digits[i];
            if (i > 0) out << " | ";
        };
};