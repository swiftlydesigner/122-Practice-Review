//
//  myStrTokTests.h
//  122 Lab Sample Code
//
//  Created by Kyle Parker on 1/14/24.
//

#ifndef myStrTokTests_h
#define myStrTokTests_h

#include <stdio.h> // printf
#include <string.h> // strcmp, strtok
#include <stdbool.h> // true, false, bool

extern char * mystrtok(char * str, const char * delims);

bool printStrCmpRes(int result, char * inputE,
                    char * inputA, char * expected,
                    char * actual);

void testMyStrTok1(void);
void testMyStrTok2(void);
void testMyStrTok3(void);

#endif /* myStrTokTests_h */
