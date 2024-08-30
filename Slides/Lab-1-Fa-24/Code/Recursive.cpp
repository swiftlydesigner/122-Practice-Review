//
//  Recursive.cpp
//  Lab 1
//
//  Created by Kyle Parker on 8/24/24.
//

#include "Recursive.hpp"
#include <string.h>

/// Helper to handle recursive step and swaping of a reverse string function.
///
/// - Precondition: input is a properly formed string.
/// - Postcondition: input is reversed
/// - Warning: the original string will be reversed.
/// - Parameter input: Points to the beginning of string S
/// - Parameter end: Points to the end of string S
/// - Returns: Nothing
/// - seealso: char* revString(char*)
/// - version: 1.0
void revStringHelper(char * input, char * end) {
    
    /// You must put >= here.
    /// == will only for odd strlen(input). When we have even lengthed input, input > end will occur.
    /// Explained:
    /// CALL 1: input = 0x01 ; end = 0x04
    /// CALL 2: input = 0x02 ; end = 0x03
    /// CALL 3: input = 0x03 ; end = 0x02 <<< Now, input > end. Problem!
    /// CALL 4: input = 0x04 ; end = 0x01 /// String is now reversed 2x (aka, in the original order)
    /// CALL N: Crash! Either we read or write to memory we do not have access to, so our system kills our program!
    if (input >= end) {
        /// We do not need to return a value, so I have a statement to stop execution.
        /// If you do not like return statements in the middle of a block, inverse the if, then put everything below in the block.
        /// Since we have >=, we would need to use <.
        return;
    }
    
    /// Swap function!
    /// Generically, we want:
    /// TYPE tmp = first;
    /// first = last;
    /// last = tmp;
    /// When we get to CPP, I will teach you how to create a generic swap function which will work for ANY type!
    char tmp = *input;
    *input = *end;
    *end = tmp;
    
    /// Recursively call itself. We need to move towards the center of the string, thus we need to increase input and decrease end.
    revStringHelper(input + 1, end - 1);
}

/// Reverse a string
///
/// - Precondition: input is a properly formed string.
/// - Postcondition: input is reversed.
/// - Warning: the original string will be reversed.
/// - Parameter input: Points to the beginning of a string, S.
/// - Returns: The reversed string
/// - seealso: revStringHelper(char*, char*)
/// - version: 1.0
char * revString(char * input) {
    /// verify input is non-null and that input's first char is non-null
    if (input && *input != '\0') {
        /// Call the helper routine.
        revStringHelper(input, input + strlen(input) - 1);
    }
    
    /// Return the reversed string.
    /// Note: If the above condition is false, then it will be returned as-is.
    return input;
}
