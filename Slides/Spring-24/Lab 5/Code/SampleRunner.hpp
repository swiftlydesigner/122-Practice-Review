//
//  SampleRunner.hpp
//  122 Lab 5
//
//  created by Kyle Parker on 2/12/24.
//

#ifndef SampleRunner_hpp
#define SampleRunner_hpp

#include <iostream>
#include "SampleProgram.hpp"

class SampleRunner {
private: 
    static bool hasInstance;
    SampleProgram * program;
    
public:
    SampleRunner(void);
    
    SampleRunner(SampleRunner& copy);
    
    ~SampleRunner(void);
    
    void run(void);
};

#endif /* SampleRunner_hpp */
