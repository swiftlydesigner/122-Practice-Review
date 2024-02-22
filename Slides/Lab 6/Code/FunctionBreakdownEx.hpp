//
//  FunctionBreakdownEx.hpp
//  122 Lab 6
//
//  Created by main on 2/22/24.
//

#ifndef FunctionBreakdownEx_hpp
#define FunctionBreakdownEx_hpp

#include <iostream>
#include <string>

using std::string;

bool allInOneExample();

template <class T>
T getUserInput(T& item);

bool isStringNumber(const string& str);

template <class T>
bool validateInput(const string&, const T& max, const T& min);

template <class T>
T addNumbers(const T& first, const T& second);

#endif /* FunctionBreakdownEx_hpp */
