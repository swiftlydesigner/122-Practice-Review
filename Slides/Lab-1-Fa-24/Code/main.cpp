//
//  main.cpp
//  Lab 1
//
//  Created by Kyle Parker on 8/24/24.
//

/// Note: The systems header files are first
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

/// Note: We include the user-defined header files second
#include "Recursive.hpp"
#include "StrTok.hpp"

/// This is for C++ (note how these are after all include statements)
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    
    /// Notice: I am using C++ as it is easier to write in my mind.
    /// Notice: Feel free to use C++ iff you ahve prior knowledge of it for tests only. If you do not know C++, stay with C.
    
    /// Begin Tests for Rev String
    
    char * test = (char*) malloc(5);
    strcpy(test, "Test!");
    printf("Test:%s", revString(test));
    
    strcpy(test, "Test");
    printf("Test:%s", revString(test));
    
    
    free(test);
    
    /// Begin Tests for StrTok

    // The line to parse
    char * line = new char[40];
    strcpy(line, "word,and,other.end");
    char * line2 = new char[40];
    strcpy(line2, "word,and,other.end");
    char * delims = new char[3];
    strcpy(delims, ",.");
    
    cout << "INPUT: " << line << "; DELIMS: " << delims << endl;
    
    char * strTokResult1 = strtok(line, delims);
    char * MYStrTokResult1 = mystrtok(line2, delims);
    
    cout << "STR TOK: " << strTokResult1 <<
        "; MY STR TOK: " << MYStrTokResult1 << endl;
    
    char * strTokResult2 = strtok(NULL, delims);
    char * MYStrTokResult2 = mystrtok(NULL, delims);
    
    cout << "STR TOK 2: " << strTokResult2 <<
        "; MY STR TOK 2: " << MYStrTokResult2 << endl;
    
    char * strTokResult3 = strtok(NULL, delims);
    char * MYStrTokResult3 = mystrtok(NULL, delims);
    
    cout << "STR TOK 3: " << strTokResult3 <<
        "; MY STR TOK 3: " << MYStrTokResult3 << endl;
    
    char * strTokResult4 = strtok(NULL, delims);
    char * MYStrTokResult4 = mystrtok(NULL, delims);
    
    cout << "STR TOK 4: " << strTokResult4 <<
    "; MY STR TOK 4: " << MYStrTokResult4 << endl;
    
    char * strTokResult5 = strtok(NULL, delims);
    char * MYStrTokResult5 = mystrtok(NULL, delims);
    
    cout << "STR TOK 5: " << (strTokResult5 == NULL ? "NULL" : strTokResult5) <<
    "; MY STR TOK 5: " << (MYStrTokResult5 == NULL ? "NULL" : MYStrTokResult5) << endl;
    
    delete[] line;
    delete[] line2;
    delete[] delims;
    
    return 0;
}
