//
//  PA 1 Help.c
//  Lab 1
//
//  Created by Kyle Parker on 1/14/25.
//

#include <stdlib.h>
#include <string.h>

#include "PA 1 Help.h"


void cleanLine(char * line, const char * invalidStr) {
    // You have many ways of cleaning a line. This a very dynamic way of cleaning a line.
    // It allows you to pass in a string you want to place in contexts where commas are
    // adjacent. For simplicity, you can remove the invalidStr and use a literal character
    // (or multiple; -1 is '-' and '1', NOT '-1').
    
    // 1. You can look through the line and search for ,,. You will need an int to keep count
    // (consider cases where you may need to reset lines).
    // 2. When you find ,, do you need to shift? **if so, make sure you shift correctly** Hint: yes!
    // 3. You can start at the front or end of the array, depending on the direction you shift.
    // 4. Break these down into functions as needed! Shifting should probably not occur in the same
    // function as your checks for ,,
    // 5. Did you consider situations where there is ,,, or ,,,,,,,,,,,,,,,,,,, ?
    
    // After you call this function, consider using the next function, seperateLine.
    
}

// Created by Kyle Parker.
// Students should be able to add a comment block to this function indicating their understanding.
// Further, credit should be given to Kyle Parker if this is used. It is reccomended to change this
// up a little. Also note this is not a fully functioning function. Students need to use functions
// in the alloc family and determine how to terminate a dynamic list. They can also improve understanding
// of this function by applying data structures learned in CptS 122 so far.
char ** seperateLine(char * line, const char * delim) {
    int count = 0;
    char ** array = NULL;
    
    char * token = strtok(line, delim);
    
    while (token != NULL) {
        ++count;
        
        /// TODO: You need to reallocate something
        
        // Add a token to the array
        array[count - 1] = malloc(sizeof(token + 1));
        strcpy(array[count - 1], token);
        array[count - 1][sizeof(token)] = '\0';
    }
    
    // Now we have processed all tokens, we need to add a null node (or some indication we are at the end)
    /// TODO: Add end indicator
    
    return array;
}

// This is a function for the above function.
void destroyList(char ** list) {
    if (list != NULL) {
        int i = 0;
        
        while (list[i]) {
            free(list[i]);
        }
        
        free(list);
    }
}
