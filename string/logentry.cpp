//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        10/19/24
// Author:      Lazuli Rogers | aroger52
//
// Description: Class implementation for a log entry in the Apache Common Log Format
//
//

#include "string.hpp"
#include "logentry.hpp"
#include <iostream>
#include <vector>

//number of lines displayed on your terminal at once
const int terminalHeight = 10;

const String emptyDate = "  /  /    ";
const String emptyTime = "  :  :  ";
const String emptyHost = "               ";
const String emptyRequest = "                                                                                 ";
const String emptyStatus = "";
const int emptyBytes = 0;

//=============================================================================
//=Empty Log Tracking
    std::vector<String> emptylogs;
    std::vector<int> emptyLogPos;
    int lineNum;

//=============================================================================
//=Constructors

    //=Default ctor for Date
    Date::Date() {
        day = "";
        month = "";
        year = "";
        dayMonthYear = emptyDate;
    }

    //=Date constructor from String
    Date::Date(const String& input) {
        int slash = input.findch(0,'/');
        day = input.substr(0, slash-1);
        int nextSlash;
        nextSlash = input.findch(slash+1, '/');
        month = input.substr(slash+1, nextSlash-1);
        year = input.substr(nextSlash+1, (input.length()-1));
        dayMonthYear = day + '/' + month + '/' + year;
    }

    //=Default ctor for Time
    Time::Time() {
        hour = "";
        minute = "";
        second = "";
        hrMinSec = emptyTime;
    }

    //=Time constructor from String
    Time::Time(const String& input) {
        hour = input.substr(1, 2);
        minute = input.substr(4, 5);
        second = input.substr (7, 8);
        hrMinSec = hour + ':' + minute + ':' + second;
    }

    //=default ctor for LogEntry
    LogEntry::LogEntry() {
        host = emptyHost;
        time = Time();
        date = Date();
        request = emptyRequest;
        status = emptyStatus;
        number_of_bytes = emptyBytes;
        timeZoneOffset = "";
        isEmpty = true;
        return;
    }

    //LogEntry ctor from String
    // REQUIRES: input value is a valid log in the Apache Common Log Format
    // ENSURES: LogEntry contains each part of the log in its corresponding member
    LogEntry::LogEntry(const String& line) {
        
        //Use split to create the substrings for LogEntry
        std::vector<String> logEntryParts = line.split(' ');
        lineNum++;

        //If there are not 10 substrings, return a blank LogEntry
        if (logEntryParts.size() != 10) {
            LogEntry emptyLog;
            int s = stringToInt(logEntryParts[logEntryParts.size() - 1]);
            if (s > 0) {
                number_of_bytes = s;
            }
            else number_of_bytes = 0;

            *this = emptyLog;
            this->isEmpty = true;
            //add log and line number to emptylogs
            emptylogs.push_back(line);
            emptyLogPos.push_back(lineNum);
            return;
        }
        //initialize each part of the LogEntry from its corresponding part
        host = logEntryParts[0];
        if (host.length() < 16) {
            String buffer(16 - host.length());
            host += buffer;
        }


        int dateTimeBarrier;
        dateTimeBarrier = logEntryParts[3].findch(0, ':');

        date = logEntryParts[3].substr(1,11);
        time = logEntryParts[3].substr(dateTimeBarrier, logEntryParts[3].length()-1);
        timeZoneOffset = logEntryParts[4].substr(0, logEntryParts[4].length()-2);

        //concatenate split substrings
        request = logEntryParts[5] + logEntryParts[6] + logEntryParts[7];
        if (request.length() < 82) {
            String buffer(82 - request.length());
            request += buffer;
        }


        status = logEntryParts[8];
        if (status.length() < 3) {
            String buffer(3 - status.length());
            status += buffer;
        }

        //convert string to integer via string method
        number_of_bytes = stringToInt(logEntryParts[logEntryParts.size() - 1]);
        isEmpty = false;
    }


//=============================================================================
//=print functions

    //overloaded output operator for objects of class Date
    std::ostream& operator<<(std::ostream& out, const Date& date)  {
        out << date.dayMonthYear;
        return out;
    };

    //overloaded output operator for objects of class Time
    std::ostream& operator<<(std::ostream& out, const Time& time) {
        out << time.hrMinSec;
        return out;
    };

    //overloaded output operator for objects of class LogEntry
    std::ostream& operator<<(std::ostream& out, const LogEntry& entry) {
        if (!entry.isEmpty) {
            out << entry.host << " | " << entry.date.dayMonthYear << " | ";
            out << entry.time.hrMinSec << " | " << entry.request << " |  ";
            out << entry.status << "| " << entry.number_of_bytes << '\n';
        };
        if (entry.isEmpty) out << std::endl;
        return out;
    }

    //prints an entry formatted with each line and section being the same length
    void printEntry(const LogEntry& entry) {
        std::cout << " " << entry.host;
        
        //host string 
        if (entry.host.length() < 16) {
            String buffer(16 - entry.host.length());
            std::cout << buffer;
        }

        //date strings
        std::cout << " | " << entry.date;
        if (entry.date.getDay().length() < 2) { std::cout << ' '; }

        //time and request strings
        std::cout << " | " << entry.time << " | " << entry.request;

        
        //status string
        std::cout << " | " << entry.status;


        //byte count string
        std::cout << "   | " << entry.number_of_bytes << '\n';
    }

    //Print all entries with each line and section being the same size
    void printAllEntries(std::vector<LogEntry>& entries) {
        
        //iterate over each entry in the vector
        for (int i = 0; i < static_cast<int>(entries.size()); i++) {
            //column title indicators every 8 rows
            if (i % terminalHeight == 0) {
                std::cout << "\n   HOST              |DATE         |TIME";
                std::cout << "      |REQUEST                     ";
                std::cout << "                                   ";
                std::cout << "                    |STATUS |BYTES\n";
            };
            //print entry
            if (i <= 8) std::cout << i+1 << ". |";
            else std::cout << i+1 << ".|";
            if (!entries[i].isEmpty) printEntry(entries[i]);
            if (entries[i].isEmpty) std::cout << std::endl;
        }
        std::cout << "Time zone offset from Greenwich Mean Time: " << entries[0].timeZoneOffset << std::endl;
        
        //=Empty/invalid log locations
        std::cout << '\n' << emptylogs.size() << " empty/invalid logs at line(s):\n";
        for (size_t i = 0; i < emptylogs.size(); ++i) {
            
            std::cout << emptyLogPos[i] << " : " << emptylogs[i] << std::endl;
        }
    }



    // REQUIRES: properly initialized vector of class LogEntry
    // ENSURES:  returns an ostream that outputs each entry on its own line
    std::ostream& output_all(std::ostream& out, const std::vector<LogEntry>& entry) {
        //cast size_t to int for comparison & iterate over each entry
        size_t j = entry.size();
        for (int i = 0; i < static_cast <int>(j); ++i) {
            //output one entry per line
            if (i % 10 == 0) {
                std::cout << "     HOST              |DATE       ";
                std::cout << "  |TIME      |REQUEST              ";
                std::cout << "                                   ";
                std::cout << "                           |STATUS ";
                std::cout << "|BYTES\n";
            };
            out << i << " | "<< entry[i] << '\n';
        }
        return out;
    }

// REQUIRES: open ifstream containing log entries in the Apache CLF, one per line
// ENSURES:  assembles a vector of class LogEntry from istream
std::vector<LogEntry> parse(std::istream& in) {

    //initialize a new vector of type LogEntry 
    std::vector<LogEntry> result;
    
    //char array of size 500
    char temp[500];
    
    while (in.getline(temp, 500)) {
        //initialize a String from a line of istream
        String s(temp);

        //return if the string is empty
        if (s == "") {
            emptyLogPos.push_back(in.tellg());
            emptylogs.push_back(temp);
            return result;
        }
        //initialize a LogEntry from the string
        LogEntry newLog (temp);

        //add the LogEntry to the vector
        result.push_back(newLog);
    }
    return result;
}

//accessor for host
const String& LogEntry::getHost() const {
    return host;
}

const String& LogEntry::getHost() {
    return host;
}

// REQUIRES: properly initialized ostream and vector of class LogEntry
// ENSURES:  outputs the host attribute of each element of the vector 
void by_host(std::ostream& out, const std::vector<LogEntry>& entries) {
    //iterates over each entry
    for (size_t i = 0; i < entries.size(); i++) {
        //output one host per line
        out << i << " | " << entries[i].getHost() << std::endl;
    }
    return;
}

//accessor for number_of_bytes
int LogEntry::getBytes() const {
    return number_of_bytes;
}

// REQUIRES: properly initialized vector of class LogEntry
// ENSURES:  returns an int value representing the total number
//      of bytes transferred across all entries in the vector
int byte_count(const std::vector<LogEntry>& entry) {
    int bytes = 0;
    //iterates over each entry in the vector
    for (size_t i = 0; i < entry.size(); i++) {
        //retrieve and add byte count to running total
        bytes += entry[i].getBytes();
    }
    return bytes;
}

bool isUnique(String IP, std::vector<String> addresses) {
    //iterate over the vector of addresses
    for (size_t i = 0; i < addresses.size(); i++) {
        //check if the input IP is already in the vector
        if (IP == addresses[i]) return false;
    }
    //not found in the vector, so it is unique at this point
    return true;
}

void reportIP(std::vector<LogEntry>& logs) {
    //initialize vector to hold the unique addresses
    std::vector<String> addresses;

    //uniqueness check is not necessary for the first address
    addresses.push_back(logs[0].getHost());

    //iterate over the vector of logs
    for (size_t i = 1; i < logs.size(); i++) {
        //check each log's host for uniqueness
        if (isUnique(logs[i].getHost(), addresses)) {
            //add to vector of unique IPs if unique
            addresses.push_back(logs[i].getHost());
        }  
    }
    //print out each IP address
    int j = 0;
    while (j < static_cast<int>(addresses.size())) {
         std::cout << addresses[j++] << std::endl;
    }
    //Total number is size of vector
    std::cout << "Number of unique IP addresses: " << addresses.size() << std::endl;
}