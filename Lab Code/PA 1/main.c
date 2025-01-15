//
//  main.c
//  Lab 1
//
//  Created by Kyle Parker on 1/14/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FitbitTypes.h"
#include "PA 1 Help.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    
    FitbitData data;
    
    char * line = malloc(100 * sizeof(char));
    
    strncpy(line, "1,,,3.0,!", 100);
    
    /// MARK: Implement cleanLine
    // Verify clean line works
    cleanLine(line, "-");
    puts(line); // Expects "1,-,-,3.2,!"
    
    char ** parsedData = seperateLine(line, ",");
    
    if (parsedData != NULL) {
        int segment = 0;
        
        while (parsedData[segment] != NULL) {
            switch (segment) {
                case 0:
                    setFitbitInt(parsedData[segment], &data.floors);
                    break;
                case 1:
                    setFitbitInt(parsedData[segment], &data.heartRate);
                    break;
                case 3:
                    setFitbitDouble(parsedData[segment], &data.calories);
                    break;
                default:
                    break;
            }
            ++segment;
        }
        
    }
    
    // Print the floors, heart rate and calories
    //       VALID;1     INVLAID;???     VALID;3.2
    printf("Floor: isValid - %d ; value - %u\nHeart rate: isValid - %d ; value - %u\nCalories: isValid - %d ; value - %lf",
           data.floors.isValid, data.floors.value,
           data.heartRate.isValid, data.floors.value,
           data.calories.isValid, data.calories.value);
    
    destroyList(parsedData);
    free(line);
    
    return 0;
}
