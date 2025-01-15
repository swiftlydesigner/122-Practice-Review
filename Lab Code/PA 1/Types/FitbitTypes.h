//
//  FitbitTypes.h
//  Lab 1
//
//  Created by Kyle Parker on 1/14/25.
//

#ifndef FitbitTypes_h
#define FitbitTypes_h

#include "myLib.h"

typedef struct _fitbitUInt {
    unsigned int value;
    bool isValid;
} FitbitUInt;

typedef struct _fitbitDouble {
    double value;
    bool isValid;
} FitbitDouble;

typedef enum _sleep {
    NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct _fitbitData {
    char patient[10];
    char minute[9];
    FitbitDouble calories;
    FitbitDouble distance;
    FitbitUInt floors;
    FitbitUInt heartRate;
    FitbitUInt steps;
    Sleep sleepLevel;
} FitbitData;

void setFitbitInt(const char * newValue, FitbitUInt * intField);
void setFitbitDouble(const char * newValue, FitbitDouble * doubleField);

#endif /* FitbitTypes_h */
