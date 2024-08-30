//
//  SampleRunner.cpp
//  122 Lab 5
//
//  created by Kyle Parker on 2/12/24.
//

#include "SampleRunner.hpp"
#include "SampleProgram.hpp"

bool SampleRunner::hasInstance = false;
    
SampleRunner::SampleRunner() {
    if (hasInstance) {
        exit(-1);
    }
    
    this->program = new SampleProgram();
    
    hasInstance = true;
}
    
SampleRunner::SampleRunner(SampleRunner& copy) {
    // Copy over data
}
    
SampleRunner::~SampleRunner() {
    if (this->program) {
        delete this->program;
    }
}

void SampleRunner::run() {
    if (program) {
        program->addRandomSubject();
    }
}
