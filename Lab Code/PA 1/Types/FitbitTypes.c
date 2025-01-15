//
//  FitbitTypes.c
//  Lab 1
//
//  Created by Kyle Parker on 1/14/25.
//

#include <stdlib.h>
#include "FitbitTypes.h"

void setFitbitInt(const char * newValue, FitbitUInt * intField) {
    // Here, we need to validate newValue.
    // If valid, set intField's validity to true and literal value
    // If invalid, set intField's validity to false
    if (isNumber(newValue)) {
        intField->value = atoi(newValue);
        intField->isValid = true;
    }
}

void setFitbitDouble(const char * newValue, FitbitDouble * doubleField) {
    // Here, we need to validate newValue.
    // If valid, set doubleField's validity to true and literal value
    // If invalid, set doubleField's validity to false
    if (isNumber(newValue)) {
        doubleField->value = atof(newValue);
        doubleField->isValid = true;
    }
}
