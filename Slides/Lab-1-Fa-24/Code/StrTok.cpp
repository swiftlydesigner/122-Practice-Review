//
//  StrTok.cpp
//  Lab 1
//
//  Created by Kyle Parker on 8/24/24.
//

#include "StrTok.hpp"

/// Check if the given char is in the list of delimeters.
///
/// - Precondition: delim is non-null & a proper string.
/// - Postcondition: it is determined if target is in delim.
/// - Parameter target: the character to check if it is in delim
/// - Parameter delim: The string of delimeters
/// - Returns: If target is a delimeter or not
/// - seealso: findToken(char*, const char*)
/// - version: 1.0
bool charInDelim(const char target, const char * delim) {
    /// Note: It is not required that target is const, but reccomended.
    /// Note: It is required that delim is const because it is passed into
    /// mystrtok and it is impossible to drop the const qualifier.
    
    /// Use a for loop which checks all chars in delim
    for (int i = 0; delim[i] != '\0'; ++i) {
        /// Note: I use ++i instead of i++ because is it less compution.
        /// Does it matter in the programs we write? No, but you do need to know the difference.
        /// i++ will: (1) make a copy of i (2) add 1 to i (3) return the copy of i
        /// ++i will: (1) add 1 to i (2) return i
        /// When does this matter? When we need have very constrained requirements.
        /// Think about it: You need 4 extra bytes and more cycles when you use i++
        ///     [For example, a network needs all the resources it can have. This could be too much when you call i++ frequently]
        /// Realistically, your compiler chooses what is best, so it **MAY** not matter,
        /// it entirely depends on the system. Sometimes the compiler makes efficent
        /// changes to your code without changing the behavior.
        
        /// Check if the target char is in the delim list, return true if so
        if (target == delim[i]) {
            return true;
        }
    }
    
    /// If we made it this far, this means target is not a delim
    return false;
}

/// Find the index of the token (or end of line) for a given token and delim.
///
/// - Precondition: token is a properly formed string
/// - Precondition: delim is a properly formed string
/// - Postcondition: The next delim index is found
/// - Parameter token: The string to look through
/// - Parameter delim: The string of delimeters
/// - Returns: The index of the delim or end of line
/// - seealso: mystrtok(char*,const char*), charInDelim(const char, const char *)
/// - version: 1.0
int findToken(char * token, const char * delim) {
    /// Create an index, called pos - start at the beginning of the token
    int pos = 0;
    
    /// The variable to hold the character within token.
    /// I chose this way to avoid reading in token twice.
    char c;
    
    while (
           /// Wrap c = token[pos] in (( )) to evaluate, then use 0 values
           /// (0, NULL, '\0', false) as a false condition and ANY other condition as true.
           ((c = token[pos])) &&
           /// Use ! to denote logical NOT.
           /// Check if c is a delimeter based on the string delim.
           !charInDelim(c, delim)
           
           ) {
    // All put together: while (((c = token[pos])) && !charInDelim(c, delim)) {
        
        /// Increase positons to check the next character
        ++pos;
    }
    
    /// Return the position a member of delim was found or the null character.
    return pos;
}

/// Own implementation of String Token (strtok)
///
/// - Precondition: input is a properly formed string.
/// - Precondition: delim is a properly formed string.
/// - Postcondition: a token is returned
/// - Warning: str will be changed
/// - Parameter str: The string to parse through. Put NULL to use existing value.
/// - Parameter delims: A string of delims
/// - Returns: A substring upto the first delim or null char, whichever comes first.
/// - seealso: findToken(char*, const char*)
/// - version: 1.0
char * mystrtok(char * str, const char * delim) {
    /// Delcare a static token to store str into (if needed)
    ///
    /// static will remember the value of pToken through all calls of mystrtok.
    /// This is in memory from when the process starts until the process dies.
    /// Advanced: static vars are stored in a different part of the program because
    /// they live and die with the program, not the function.
    static char * pToken;
    
    /// Check if the input string is non-null (anything but NULL will be true for this condition)
    if (str) {
        /// Since str is non-NULL, set pToken's value
        pToken = str;
    }
    
    /// Run findToken routine, get the index of the delim or end of line.
    int result = findToken(pToken, delim);
    
    /// If the result is > 0, this means there is some data.
    if (result > 0) {
        /// Set the index of a delim or null ptr to null ptr.
        /// This allows for the string to be terminated properly.
        pToken[result] = '\0';
        
        /// Take a copy of where pToken is pointing now, this is the token we found
        char * oldToken = pToken;
        
        /// Offset token by the index the delim was at and add one.
        ///     If we do not add 1, then we will be AT the null char, so any future calls
        ///     will always terminate here, even if there is more data.
        pToken += result + 1;
        
        /// Return the old token because pToken now points to the rest of the string.
        /// We now have a token termianted by the null character!
        return oldToken;
    }
    
    /// There is no data to parse.
    return NULL;
}
