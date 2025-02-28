//header file for class to keep track of truncated Strings
//Lazuli Rogers | aroger52
//11-11-2024
//for use with assembler.cpp

#ifndef TRUNCID_HPP
#define TRUNCID_HPP

#include "../string/string.hpp"

const int MAX_ID_SIZE = 5;

class truncID {

public:
    //default constructor, initializes to zero
    truncID();

    //copy constructor
    truncID (const truncID&);

    //swap function
    void swap(truncID& rhs);

    //overloaded assignment operator
    truncID& operator=(truncID& rhs) {if (*this!=rhs) this->swap(rhs); return *this; }

    //destructor
    ~truncID();

    //overloaded increment operator
    truncID& operator++();

    //overloaded equality operator
    bool operator==(const truncID& rhs);
    //overloaded inequality operator
    bool operator!=(const truncID& rhs);

    int getVecSize() {return static_cast<int>(truncVec.size());}

    String getID() {return IDnum;}

    void push(const String& trunc);

    String operator[](int) const;

    friend std::ostream& operator<<(std::ostream&, truncID& rhs);



private:
    String IDnum;
    int IDnumInt;
    
    int truncVecSize;
    std::vector<String> truncVec;

    void setVecSize();

};


//default constructor
truncID::truncID() {
    IDnum = String(MAX_ID_SIZE);
    IDnum[0] = '1';
    IDnumInt = 1;
    truncVec.push_back(" ");
    truncVecSize = 0;
} 

//copy constructor
truncID::truncID(const truncID& copy){ 
    if(*this!=copy) {
        IDnum = copy.IDnum;
        IDnumInt = copy.IDnumInt;
        truncVec = copy.truncVec;
        setVecSize();
    }
}

//constant time swap
void truncID::swap(truncID& rhs) {
    String tempIDnum = IDnum;
    IDnum = rhs.IDnum;
    rhs.IDnum = tempIDnum;

    int tempIDnumInt = IDnumInt;
    IDnumInt = rhs.IDnumInt;
    rhs.IDnumInt = tempIDnumInt;

    std::vector<String> tempTruncVec = truncVec;
    truncVec = rhs.truncVec;
    rhs.truncVec = tempTruncVec;

    
}

//destructor
truncID::~truncID() {
    
}

//overloaded increment operator
truncID& truncID::operator++() {
    int temp = stringToInt(IDnum);
    temp++;
    String result(String::intToString(temp));
    IDnum = result;
    ++IDnumInt;
    return *this;
}

void truncID::push(const String& trunc) {
    bool present (0);
    for (size_t i = 0; i < truncVec.size(); ++i) {
        if (trunc == truncVec[i]) present = true;
    }
    if (!present) {
        truncVec.push_back(trunc);
        setVecSize();
    }
}

bool truncID::operator==(const truncID& rhs) {
    return  ((IDnum == rhs.IDnum) && (IDnumInt == rhs.IDnumInt));
}

bool truncID::operator!=(const truncID& rhs) {
    return !((IDnum == rhs.IDnum) && (IDnumInt == rhs.IDnumInt)); 
}

std::ostream& operator<<(std::ostream& out, truncID& rhs) {
    out << rhs.IDnumInt;
    return out;
}

String truncID::operator[](int i) const {
    if(i < truncVecSize) {
        return truncVec[i];
    }
    else return "";
}

void truncID::setVecSize() {
    truncVecSize = static_cast<int>(truncVec.size());
}
#endif //TRUNCID_HPP