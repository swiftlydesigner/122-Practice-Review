//
//  MyLib.hpp
//  122 Lab 6
//
//  Created by main on 2/20/24.
//

#ifndef MyLib_hpp
#define MyLib_hpp

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

// following macros definitons were found at https://sourceforge.net/p/predef/wiki/OperatingSystems/

/// Define MACROS

#if defined(_WIN32) || defined(_WIN64) // If Windows
// import Windows-specific libraries as needed
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS // disable secure warnings
#endif
#define CLEAR_SCREEN "cls"
#define RETURN_KEY_UPPER "ENTER"
#define RETURN_KEY_LOWER "enter"

#elif defined(__APPLE__) || defined(__MACH__) // If macOS or OSX
// import macOS-specific libraries as needed.
#define CLEAR_SCREEN "clear"
#define RETURN_KEY_UPPER "RETURN"
#define RETURN_KEY_LOWER "return"

#elif defined(__linux__) || defined(linux) || defined(__linux) // Linux distro
// import Linux-specific libraries as needed.
#define CLEAR_SCREEN "clear"
#define RETURN_KEY_UPPER "RETURN"
#define RETURN_KEY_LOWER "return"

#else
#define UNSUPPORTED_OS // was not caught by one of the above cases.
#endif

/// Define function prototypes
// MARK: - Get User Input
string & getUserInput(string &str);

// MARK: - Input validation
template <typename T>
bool validateInput(const string &str, T min, T max);
bool validateInput(const string &str, string contains);
bool getYesNo(void);
bool isnumber(const string &str);

// MARK: - Mutate Strings
typedef int func(int);
string convertStrLU(string &str, func f);
string strToLower(string &str);
string strToUpper(string &str);

/// Define inline functions
inline void clearScreen(void) {
    system(CLEAR_SCREEN);
}


#endif /* MyLib_hpp */
