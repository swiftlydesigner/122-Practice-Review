//
//  myStrTokTests.c
//  122 Lab Sample Code
//
//  Created by Kyle Parker on 1/14/24.
//

#include "myStrTokTests.h"

/// This function will print out a message to indiate if and where the calls to mystrtok fail.
/// If mystrtok works, there will be many duplicate good messages.
///
/// - Precondition: A **single** call to strtok and mystrtok have been called.
/// - Postcondition: Success or failure with message is printed.
/// - Parameter intputE: The expected input string value's (The string fed into strtok)
/// - Parameter inputA: The actual input string value's (The string fed into mystrtok)
/// - Parameter expected: The expected value returned from strtok
/// - Parameter actual: The actual value returned from strtok
/// - Parameter rst: Flag to reset the count.
/// - Returns: A boolean indicating success. true = good; false = fail
/// - Date: Jan 14, 2024
///
/// - Version: 1.0
bool printSuccessFailureResult(char * inputE, char * inputA,
                               char * expected, char * actual,
                               bool rst) {
    // Keep track of count. Initally set to 0. Being static,
    // this will remain while the program remains in memory.
    static int count = 0;
    // Define restult
    int result;
    
    // When the rst flag is passed, set count to 0.
    if (rst) {
        count = 0;
    }
    
    // Set result to the string comparison of expected
    // and actual. We hope this is 0.
    result = strcmp(expected, actual);
    
    // If result is 0 (good), then print success and return.
    if (result == 0) {
        printf("[%d] mystrtok good!\n", count);
        return true;
    }
    
    // Test failed. Print out expected values.
    // Expected values are from strtok.
    // Actual values are from mystrtok (your code).
    
    printf("[%d] mystrtok failed.\n", count);
    
    printf("\torig input (Expected) = %s\n", inputE);
    printf("\torig input (Actual) = %s\n", inputA);
    
    printf("\tValue returned (Expected) = %s\n", expected);
    printf("\tValue returned (Actual) = %s\n", actual);
    return false;
}

/// Test mystrtok() with splitting at spaces.
///
/// - Postcondition: The first test is completed. Results are displayed.
/// - Date: Jan 14, 2024
///
/// - Version: 1.0
void testMyStrTok1(void) {
    // Define the delims for test 1 (spaces)
    char * delims = " ";
    
    // Define standard varaibles for testing.
    char * inputE = "This is a string with spaces.";
    char * inputA = "This is a string with spaces.";
    char * expected, * actual;
    
    // Initalize to true so we can see it if ever fails by using &&
    bool success = true;
    
    expected = strtok(inputE, delims);
    actual = mystrtok(inputA, delims);
    
    success = success && printSuccessFailureResult(
                                inputE, inputA, // Input strings
                                expected, actual, // Vals returned from (my)strtok
                                true); // Reset count
    
    while (expected != NULL && actual != NULL) {
        expected = strtok(NULL, delims);
        actual = mystrtok(NULL, delims);
        
        success = success && printSuccessFailureResult(
                               inputE, inputA, // Input strings
                               expected, actual, // Vals returned from (my)strtok
                               false); // Do not reset count
    }
    
    success = success && printSuccessFailureResult(
                               inputE, inputA, // Input strings
                               expected, actual, // Vals returned from (my)strtok
                               false); // Do not reset count
    
    if (success) {
        printf("Success! Test 1 passed!\n\n\n");
    } else {
        printf("Fail! Test 1 failed, see trace above.\n\n\n");
    }
}

/// Test mystrtok() with splitting at commas, spaces, and periods.
///
/// - Postcondition: The second test is completed. Results are displayed.
/// - Date: Jan 14, 2024
///
/// - Version: 1.0
void testMyStrTok2(void) {
    // Define the delims for test 2 (space, period, comma)
    char * delims = "., ";
    
    // Define standard varaibles for testing.
    char * inputE = "This, is a.string with spaces;periods, and commas.";
    char * inputA = "This, is a.string with spaces;periods, and commas.";
    char * expected, * actual;
    
    // Initalize to true so we can see it if ever fails by using &&
    bool success = true;
    
    expected = strtok(inputE, delims);
    actual = mystrtok(inputA, delims);
    
    success = success && printSuccessFailureResult(
                               inputE, inputA, // Input strings
                               expected, actual, // Vals returned from (my)strtok
                               true); // Reset count
    
    while (expected != NULL && actual != NULL) {
        expected = strtok(NULL, delims);
        actual = mystrtok(NULL, delims);
        
        success = success && printSuccessFailureResult(
                               inputE, inputA, // Input strings
                               expected, actual, // Vals returned from (my)strtok
                               false); // Do not reset count
    }
    
    success = success && printSuccessFailureResult(
                               inputE, inputA, // Input strings
                               expected, actual, // Vals returned from (my)strtok
                               false); // Do not reset count
    
    if (success) {
        printf("Success! Test 2 passed!\n\n\n");
    } else {
        printf("Fail! Test 2 failed, see trace above.\n\n\n");
    }
}

/// Test mystrtok() with splitting at new lines, tabs, and chars 'f', 'm'
///
/// - Postcondition: The third test is completed. Results are displayed.
/// - Date: Jan 14, 2024
///
/// - Version: 1.0
void testMyStrTok3(void) {
    // Define the delims for test 3 (new lines, tabs, 'f', 'm')
    char * delims = "\n\tfm";
    
    // Define standard varaibles for testing.
    char * inputE = "Hopefully\nthis\tpassesfwhen the last mtest works\t\nfmOtherwise, therefismSomething\t\tWrong.";
    char * inputA = "Hopefully\nthis\tpassesfwhen the last mtest works\t\nfmOtherwise, therefismSomething\t\tWrong.";
    char * expected, * actual;
    
    // Initalize to true so we can see it if ever fails by using &&
    bool success = true;
    
    expected = strtok(inputE, delims);
    actual = mystrtok(inputA, delims);
    
    success = success && printSuccessFailureResult(
                               inputE, inputA, // Input strings
                               expected, actual, // Vals returned from (my)strtok
                               true); // Reset count
    
    while (expected != NULL && actual != NULL) {
        expected = strtok(NULL, delims);
        actual = mystrtok(NULL, delims);
        
        success = success && printSuccessFailureResult(
                               inputE, inputA, // Input strings
                               expected, actual, // Vals returned from (my)strtok
                               false); // Do not reset count
    }
    
    success = success && printSuccessFailureResult(
                               inputE, inputA, // Input strings
                               expected, actual, // Vals returned from (my)strtok
                               false); // Do not reset count
    
    if (success) {
        printf("Success! Test 3 passed!\n\n\n");
    } else {
        printf("Fail! Test 3 failed, see trace above.\n\n\n");
    }
}

