//
//  StrTok.hpp
//  Lab 1
//
//  Created by Kyle Parker on 8/24/24.
//

#ifndef StrTok_hpp
#define StrTok_hpp

#include <stdbool.h>
#include <stdio.h>
 
bool charInDelim(const char target, const char * delim);
int findToken(char * token, const char * delim);
char * mystrtok(char * str, const char * delim);

#endif /* StrTok_hpp */
