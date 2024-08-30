//
//  main.cpp
//  122 Lab 5
//
//  created by Kyle Parker on 2/10/24.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "SampleRunner.hpp"
#include "SampleTypeClass.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;


int main(int argc, const char * argv[]) {
    // insert code here...
    
    auto t = SampleTypeClass<int>();
    auto f = SampleTypeClass<double>();
    f.
    
    fstream inputFile;
    
    inputFile.open("myFile.txt"); // Option 1
    inputFile.open("myFile.txt", std::ios::in); // Option 2: specify stream type (default in | out)
    
    if (inputFile.is_open()) {
        
    }
    
    
    std::cout << "Hello, World!\n";
    
//    auto runner = new SampleRunner;
    
    SampleRunner().run();
    
//    delete runner;
    
    return 0;
}

/*
 
 size_t count = 100;
 
 int * myNumber = new int;
 int myNumbers[count];
 int * myNumbersDyn = new int[count];
 
 delete myNumber;
 delete[] myNumbersDyn;
 */
