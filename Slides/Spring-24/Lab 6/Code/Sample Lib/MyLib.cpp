//
//  MyLib.cpp
//  122 Lab 6
//
//  Created by main on 2/20/24.
//

#include "MyLib.hpp"

string & getUserInput(string &str) {
    cin >> str;
    return str;
}

template <typename T>
bool validateInput(const string &str, T min, T max) {
    if (!isnumber(0)) {
        return false;
    }
    
    bool success = true;
    for (auto ch : str) {
        T value = static_cast<T>(ch);
        
        if (value <= max && value >= min) {
            success = false;
        }
    }
    return success;
}

bool validateInput(const string &str, string contains) {
    
    return false;
}

bool getYesNo(void) {
    string input;
    getUserInput(input);
    return false;
}

bool isnumber(const string &str) {
    return false;
}

string strToLower(string &str) {
    string lower = "";
    for (char ch : str) {
        lower += tolower(ch);
    }
    return lower;
}

string strToUpper(string &str) {
    string upper = "";
    for (char ch : str) {
        upper += toupper(ch);
    }
    return upper;
}

string convertStrLU(string &str, func f) {
    string converted = "";
    
    return converted;
}
