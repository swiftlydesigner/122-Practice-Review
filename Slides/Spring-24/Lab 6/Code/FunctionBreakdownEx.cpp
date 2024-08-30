//
//  FunctionBreakdownEx.cpp
//  122 Lab 6
//
//  Created by main on 2/22/24.
//

#include "FunctionBreakdownEx.hpp"

using std::cin;
using std::cout;
using std::endl;

using std::atoi;

// Bad solution: Most logic is in here.
// We cannot test to make all comps work correctly.
// Additionally, we cannot update code easily since
// it will be redundant.
bool allInOneExample() {
    // 42 lines (may change if we update functions)
    bool didCompute = false;
    string input1, input2;
    int number1, number2;
    bool isNumber1 = true;
    bool isNumber2 = true;
    bool isFirst = true;
    
    cout << "Enter a number:\n> ";
    cin >> input1;
    
    cout << "Enter another number:\n> ";
    cin >> input2;
    
    for (auto & ch : input1) {
        if (isblank(ch)) {
            ; // Do nothing
        } else if (isdigit(ch) || (isFirst && (ch == '+' || ch == '-'))) {
            isFirst = false;
        } else {
            isNumber1 = false;
        }
    }
    
    isFirst = true;
    
    for (auto & ch : input2) {
        if (isblank(ch)) {
            ; // Do nothing
        } else if (isdigit(ch) || (isFirst && (ch == '+' || ch == '-'))) {
            isFirst = false;
        } else {
            isNumber2 = false;
        }
    }
    
    if (isNumber1 && isNumber2) {
        number1 = std::atoi(input1.c_str());
        number2 = std::atoi(input2.c_str());
        cout << "Sum of numbers = " << addNumbers(number1, number2) << endl;
        didCompute = true;
    }
    
    return didCompute;
}

// Ideal solution: Everything is broken down into function.
// It allows us to easily update code and track down bugs.
bool callingFunctionsExample() {
    // 18 lines (will not change as any modficaitons will be external)
    bool didCompute = false;
    string input1, input2;
    int number1, number2;
    
    cout << "Enter a number:\n> ";
    getUserInput(input1);
    
    cout << "Enter another number:\n> ";
    getUserInput(input2);
    
    if (isStringNumber(input1) && isStringNumber(input2)) {
        number1 = atoi(input1.c_str());
        number2 = atoi(input2.c_str());
        
        cout << "Sum of numbers = " << addNumbers(number1, number2) << endl;
        didCompute = true;
    }
    
    return didCompute;
}






/// Simply gets input from the user. You may prefer to call
/// cin by itself to reduce the number of function calls or
/// you may like the look of calling the function.
template <class T>
T getUserInput(T& item) {
    cin >> item;
    return item;
}

/// Note: This is not the best solution, but it will get the job done
/// in most cases.
///
/// This will check if the input string is a number. It will allow for
/// spaces, but it also allows for spaces throughout the value.
/// If you use this in practice, please be sure to update this
/// so it invalidates `-50 325235\n `,
/// but allows `  \t  -124125   \n  `.

// Testable!
bool isStringNumber(const string& str) {
    bool success = true;
    bool isFirst = true;

    for (auto & ch : str) {
        if (isblank(ch)) {
            ; // Do nothing
        } else if (isdigit(ch) || (isFirst && (ch == '+' || ch == '-'))) {
            isFirst = false;
        } else {
            success = false;
        }
    }
    
    return success;
}

/// This will ensure the value of input is between max and min.
///
/// Being a template, if all types match, then there is no need to
/// declare a type explicitly. If all types do not match, then we need
/// to call it as such: validateIntput<double>(i1, max, min); where
/// i1 is the number we are testing, max is the largest possible val
/// and min is the smallest possible val. Suppose you hardcode
/// max and min as 50 and 20. These are assumed ints, but i1 is a
/// double, so this may (not guaranteed) to cause an error.
///
/// tl;dr:
/// If all types match, you can call this as a regular function. If the types
/// may mismatch, you will need to specify the type by calling the
/// function as validateInput<double>(VALUE, MAX, MIN);.

// Testable!
template <class T>
bool validateInput(const T& input, const T& max, const T& min) {
    return input <= max && input >= min;
}


// Note: In test-driven development, we want to write skelton code first.
// Once we write the test function and commit it to GitHub (or other VCS),
// then, we can come back and fill in with the uncommented version below.
//
// template <class T>
// T addNumbers(const T& first, const T& second) {
//     return 0;
// }

/// Simply sum the numbers first and second, then return the
/// value. Being a template, it follows the same rule as
/// explained for validateInput.

// Testable!
template <class T>
T addNumbers(const T& first, const T& second) {
    return first + second;
}
