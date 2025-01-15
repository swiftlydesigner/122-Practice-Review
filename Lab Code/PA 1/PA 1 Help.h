//
//  PA 1 Help.h
//  Lab 1
//
//  Created by Kyle Parker on 1/14/25.
//

#ifndef PA1Help_h
#define PA1Help_h

#include <stdio.h>

#include "FitbitTypes.h"

void cleanLine(char* line, const char * invalidStr);

char ** seperateLine(char * line, const char * delim);

void destroyList(char ** list);

#endif /* PA1Help_h */
