//String class implementation
//string.cpp
//Fall 2024
//CS 23001
//Lazuli Rogers | aroger52

#include "string.hpp"

#include <cassert>
#include <iostream>
#include <vector>

int powerOfTen(int);
//=============================================================================
//=Constructors
    
  //=Default Constructor-Empty String
    String::String() {
       //initializes an empty string
        stringSize = 1; //stringSize == 1 -> length() == 0
        str = new char[1]; 
        str[0] = NULL_CHAR; //terminate the array with '\0'
    };

  //=Int Constructor - initializes a whitespace string of the 
  //=specified integer size
  //=INV size > 0 
    String::String(const int size) {
        assert(size > 0); //const char array cannot have a size of 0
        
        if (size == 1) { //initializes an empty string
            stringSize = 1;
            str = new char[1];
            return;
        }
        
        //set stringSize to the input
        stringSize = size;

        //dynamically allocate an array of size stringSize
        str = new char[stringSize];

        //iterates and sets each element of the array to a space char
        for (int i = 0; i < (stringSize-1); i++) {
            str[i] = ' ';
        }

        //terminate the array
        str[stringSize - 1] = NULL_CHAR;

    }

  //=Char Constructor
    String::String(char ch) {

      //=initialize empty string
        if (ch == NULL_CHAR) {
            stringSize = 1;
            str = new char[1];
            str[0] = NULL_CHAR;
            return;
        };
      //=will always be a char + NULL_CHAR, thus a size of 2
        stringSize = 2;
        str = new char[2];
        str[0] = ch;
        str[1] = NULL_CHAR;  //terminate the array
    };

  //=Const Char[] Constructor
    String::String(const char newStr[]) {
      //=Empty string
        if (newStr[0] == NULL_CHAR) {
            stringSize = 1;
            str = new char[1];
            str[0] = NULL_CHAR;
            return;
        };

      //=Single char string input
        if (newStr[1] == NULL_CHAR) {
            stringSize = 2;
            str = new char[2];
            str[0] = newStr[0];
            str[1] = NULL_CHAR;
            return;
        }
        //set stringSize to 1, thus avoiding the need to increment after the loop
        stringSize = 1;

        //iterate over the input array to find the size
        for (int i = 0; newStr[i] != NULL_CHAR; i++) {
            ++stringSize;
        };

        //dynamically allocate an array of size stringSize
        str = new char[stringSize];

        //iterate over each element of the arrays
        for (int i = 0; i < length(); i++) {
            str[i] = newStr[i];
        }
};

  //=Copy Constructor
    String::String(const String& inputStr) {
      //set stringSize to that of the input
        stringSize = inputStr.stringSize;

      //allocate an array of size stringSize
        str = new char[stringSize];

      //iterate over elements
        for(int i = 0; i < stringSize; i++) {
            str[i] = inputStr[i];
        };

    };

  //=Destructor
    String::~String() {
      //deallocate the dynamic array
        delete[] str;
    };

  //=Constant time swap
    void String::swap(String& rhs) {
      //temporary array and int allow swapping values without losing data

      //swapping the char* attributes
        char* temp = str;
        str = rhs.str;
        rhs.str = temp;

      //swapping the stringSize attributes
        int i = stringSize;
        stringSize = rhs.stringSize;
        rhs.stringSize = i;
    };
  //=Assignment Overload
    String& String::operator=(String rhs) {
        if (*this != rhs) { //check to prevent self-assignment
            this->swap(rhs); //simply swap (a copy is made of rhs)
        };

        return *this;
    };

//=============================================================================
//=Overloaded operators
  //=Class Methods

  //=Overloaded equality operator
    bool String::operator==(const String& rhs) const{
        //check lengths
        if (length() != rhs.length()) return false;

        //iterate over each element 
        for (int i = 0; i < length(); i++) {
            if (str[i] != rhs.str[i]) return false;
        }
    
        //if the lengths and all elements are the same
        return true;
    };
    
  //=Overloaded less than operator
    bool String::operator<(const String& rhs) const{
        //check equality
        if (*this == rhs) return false;
        //check each individual element of the arrays
        for (int i = 0; (i < length() && i < rhs.length()); i++) {
            if (str[i] > rhs.str[i]) return false;
            if (str[i] < rhs.str[i]) return true;
        };
        //the strings are equal
        return (stringSize < rhs.stringSize);
    };


    String  String::substr(int start, int end) const{
        //if start == end, returns a single char substring
        if (start == end) {
            String result(str[start]);
            return result;
        }
        //initialize result
        String result;
        for (int i = start; i <= end; i++) {
            //concatenate result and the next element
            result+= str[i];
            
        }
        return result;
    };

    int String::findch(int start,  char target) const{
      //prevent out-of-bounds access
        if (start < 0 || start >= length()) return -1;

      //iterate over array to find the target char
        for (int i = start; i < length(); ++i) {
            if (str[i] == target) return i;
        }
        //if not found return -1
        return -1;        
    };  
    
    int String::findstr(int start,  const String& target) const{
      //prevent out-of-bounds access
        if (start < 0 || start >= length() ||target.length() > length()) return -1;

      //iterate over each character in str
        for (int i = start; i <= (length() - target.length()); ++i) {
            int j = 0;
            //iterate over sequences of chars within str to find the target substring
            while (j < target.length() && str[i + j] == target.str[j]) ++j;
            
            //if found, return the index of the first element of the substring
            if (j == target.length()) return i;
        }

        //if not found, return -1
        return -1;  
    };  

    std::vector<String> String::split(char delimiter) const {
      //a vector of Strings to hold the resultant substrings

        std::vector<String> result;
        
        int start = 0;

      //find the first occurrence of the delimiter
        int end = findch(start, delimiter);

      //if the delimiter is in the first slot, the first String is empty
        if (end == start) {
            result.push_back("");
            start = end + 1;
            end = findch(start, delimiter);
        }
        
      //until the delimiter is not found anymore
        while (end != -1) {
            
          //add the next substring to the vector
            result.push_back(substr(start, end - 1)); // Extract substring
            
          //set start to the index after end
            start = end + 1;
          //find next occurrence
            end = findch(start, delimiter);
        }
      //Add the last segment
        result.push_back(substr(start, length() - 1)); 
    
        return result;
    }    

    //print function for vector of split strings
    void String::printSplit(std::vector<String> splitStr) {
        //std::cout << std::endl;
        for (size_t i = 0; i < splitStr.size(); i++) {
            std::cout << '"' << splitStr.at(i) << '"' << ' ';
        }
        std::cout << std::endl;
    }

	//convert a String value to an int value
	int stringToInt(const String& input) {
		if (input == '-') return 0;
		int decimalPlaces = input.length()-1;
		int temp(0);
		for (int i = 0; (input[i] <= '9' && input[i] >= '0') && i < input.length(); i++) {
			if (decimalPlaces == 0) return temp += (input[i] - '0');
			temp += (input[i] - '0') * powerOfTen(decimalPlaces - i-1);			
		}
		return temp;
	}

  //convert an int value to a String value
    String String::intToString(int input) {
        String result;
        int temp, i (0);    
        while (input != 0) {
            ++result.stringSize;
            //retrieving the current ones digit
            temp = input % 10;
            //removing current ones digit
            input /= 10;
            //placing extracted ones digit in array
            char j = temp + static_cast<int>('0');
            result.str[i++] = j;
        }
        return result;
    }

	int powerOfTen(int i) {
		int result = 1;
		for (int j = i; j >=0; j--) {
			result *= 10;
		}
		return result;
	}

    //=Overloaded += concatenation operator
    String& String::operator+=    (const String& rhs){
        //calculate new total size of str
        const int totalSize = (length() + rhs.length() + 1); //add 1 for the NULL_CHAR
        
        //initialize a whitespace string of size totalSize  
        String newStr (totalSize);
    
        //iterate over newStr & str to assign the elements from str
        for(int k = 0; k < length(); k++) {
            newStr[k] = str[k];
        }

        //iterate over newStr (starting at length() & rhs.str to assign the rhs elements)
        for(int j = 0; j < rhs.length(); j++) {
            newStr[length() + j] = rhs.str[j];
        };

        //swap value of newStr with *this to be returned
        swap(newStr);
        return *this;
    };


    //=Overloaded output operator
    std::ostream& operator<<(std::ostream& out, const String& rhs) {
        //iterate over each element of the array except for the null terminator
        for (int i = 0; i< rhs.length(); i++) {
            out << rhs[i];
        }
        return out;
    };

    //overloaded input operator
    std::istream& operator>>(std::istream& in, String& rhs){
        //initialize a const char [] of max size to read into
        char *word = new char[256];
        in >> word;
        
        //initialize a string from the array
        rhs = word;

        //deallocate the memory assigned to word
        delete[] word;
        return in;
    };

            
            
//----------------------------------
    //=Externally defined functions

    //=Overloaded equality operators
    
    //const char[] == String operator
    bool operator==(const char lhsIn[], const String& rhs) {
        //initialize a string from the const char[] to compare with rhs
        String lhs(lhsIn);

        //if not equal
        if (!(lhs==rhs)) return false;
        else return true;
    };

    //char == String operator
    bool operator==(char lhsIn, const String& rhs) {                
        //initializes a string from char to compare with rhs
        String lhs(lhsIn);

        //if not true
        if (!(lhs==rhs)) return false;
        else return true;
    }; 


    //String != String
    bool operator!=(const String& lhs, const String& rhs) {
        //simply use ! (not) and the previously defined equality operator
        if (!(lhs==rhs)) return true;
        else return false;
    };

    //const char[] < String
    bool operator<(const char lhs[],  const String& rhs) {
        //initialize a String from lhs[] to compare w/ rhs
        String temp (lhs);
        //return result of lhs < rhs
        return temp < rhs;
    };
    //char < String
    bool operator< (char lhs, const String& rhs) {
        //initialize a String from char lhs
        String temp (lhs);
        //return result of lhs < rhs
        return temp < rhs;
    };

    //String <= String
    bool operator<=(const String& lhs, const String& rhs) {
        //simply use an OR operator along with the < and == operators
        return (lhs < rhs || lhs == rhs);
    };

    //String > String
    bool operator>(const String& lhs, const String& rhs) {
        //essentially lhs !> rhs
        if(lhs <= rhs) return false;
        //lhs > rhs
        else return true;
    };

    //String >= String
    bool operator>=(const String& lhs, const String& rhs){
        //essentially lhs !>= rhs
        if (lhs < rhs) return false;
        //lhs >= rhs
        else return true;
    };

    //Cap, len, & subscripts

	//get string's capacity
    int String::capacity() const{
        //return the amount of chars a String can contain
        return (stringSize - 1);
    };  

	//get string's length
    int String::length() const{
        //return the amount of chars a String currently contains
        return (stringSize - 1);
    };  

    //subscript operator
    char& String::operator[](int target){
      //returns an error if out of bounds
        if (target > length() || target < 0) std::cerr << "\nSubscript out of bounds error\n", exit(2);
      //returns the element of str at index target
        return str[target];
    }; 

	//const subscript operator
    char String::operator[](int target) const{
      //returns an error if out of bounds
        if (target > length() || target < 0) std::cerr << "\nSubscript (const) out of bounds error\n", exit(3);
      //returns the element of str at index target
        return str[target];
    };

    //External concatenation operator
    String operator+(String lhs, const String& rhs) {
        return (lhs += rhs);
    };
    
