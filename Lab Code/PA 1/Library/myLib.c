//
//  myLib.c
//  Lab 1
//
//  Created by Kyle Parker on 1/14/25.
//

#include <string.h>
#include <ctype.h>

#include "myLib.h"

// This is not guaranteed to work for all possible inputs by design.
bool isNumber(const char * string) {
    bool isValid = true;
    bool hitSpace = false;
    
    const unsigned long max = strlen(string);
    
    for (int i = 0; i < max && isValid; ++i) {
        char c = string[i];
        if (c != '-' && c != '.' && !isnumber(c)) {
            isValid = false;
        }
        
        if (c == ' ') {
            hitSpace = true;
        }
    }
    
    return false;
}
