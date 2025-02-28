//
// File:        logentry.hpp
//
// Version:     1.0
// Date:
// Author:      Lazuli Rogers | aroger52
//
// Description: Class definition for a log entry.
//
// See the bottom of this file for the IP address explanation
//

#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

#include "string.hpp"
#include <iostream>
#include <vector>




//DD/Mmm/YYYY format
class Date {
public:
            Date();
            Date(const String&);
    friend  std::ostream& operator<<(std::ostream&, const Date&);
            String getDay() const{return day;};
           
            //concatenated for easy output
            String dayMonthYear;
private:
    String  day, month, year;
};

//HH:MM:SS format
//offset from GMT 
class Time {
    public:
            Time();
            Time(const String&);
        
        friend  std::ostream& operator<<(std::ostream&, const Time&);

        //concatenated for easy output
        String hrMinSec;

    private:
        String  hour, minute, second;

};


// A single log entry
class LogEntry {
public:
            LogEntry();
            LogEntry(const String&);
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);
    friend  void      printEntry(const LogEntry&);
    friend  void      printAllEntries(std::vector<LogEntry>&);


    const String&  getHost() const;
    const String&  getHost();
    int           getBytes() const;

private:
    String  host;
    Date    date;
    Time    time;
    String  timeZoneOffset;
    String  request;
    String  status;
    int     number_of_bytes = 0;
    bool    isEmpty = true;


};



//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
std::ostream&                    output_all  (std::ostream&, const std::vector<LogEntry>&);
void                    by_host     (std::ostream&, const std::vector<LogEntry>&);
int                     byte_count  (const std::vector<LogEntry>&);

bool isUnique(String, std::vector<String>);
void reportIP(std::vector<LogEntry>&);

#endif


//=============================================================================
//=IP Address Extra Credit
//=In order to retrieve the number of unique IP addresses in the file, I wrote
//=a function that iterates over the vector of logs, checking each address for 
//=uniqueness and extracting those that are unique to a vector of Strings 
//=(which itself was iterated through when checking if the IP was unique).
//=============================================================================