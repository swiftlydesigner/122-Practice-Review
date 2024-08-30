//
//  SampleProgram.cpp
//  122 Lab 5
//
//  created by Kyle Parker on 2/12/24.
//

#include "SampleProgram.hpp"

void SampleProgram::CopySubjects(vector<SampleSubject *> newSubjects) {
    // How do we properly copy everything over?
    for (auto & var : newSubjects) {
        
        auto newSub = new SampleSubject;
        newSub->name = var->name;
        newSub->ID = var->ID;
        
        this->subjects.push_back(newSub);
    }
}

SampleProgram::SampleProgram() {
    
}

SampleProgram::SampleProgram(SampleProgram &copy) {
    this->listOfInts = copy.listOfInts;
    this->subjects = copy.subjects; // Is this dangerous?
    // How to copy these subjects over?
}

SampleProgram::~SampleProgram() {
    for (auto & var : this->subjects) {
        if (var) {
            delete var;
        }
    }
    // How do we properly deallocate everything?
}

int SampleProgram::Sum() {
    int summation = 0;
    for (auto& var : this->listOfInts) {
        summation += var;
    }
    return summation;
}

int SampleProgram::Sum(vector<int> ints) {
    int summation = 0;
    for (auto& var : ints) {
        summation += var;
    }
    return summation;
}

int SampleProgram::Sum(int a, int b) {
    return a + b;
}

int SampleProgram::Sum(int a, int b, int c) {
    return a + b + c;
}

double SampleProgram::Sum(vector<double> dbls) {
    double summation = 0;
    for (auto& var : dbls) {
        summation += var;
    }
    return summation;
}

double SampleProgram::Sum(double a, double b, double c) {
    return a + b + c;
}

void SampleProgram::addRandomSubject() {
    // Focus on the three different calls, not the logic
    auto subject =
        arc4random() % 4 == 0 ?
            new SampleSubject(arc4random(), "Random Strings") /* int, string */ :
            arc4random() % 4 == 1 ?
                new SampleSubject(arc4random()) /* int */ :
                new SampleSubject("Random alone") /* string */ ;
    
    // Note how we declare two initalizer, but we have a total of 3 different calls.
    // SampleSubject(string newName); // Gives 1 call
    // SampleSubject(int newID, string newName = "UNSET_NAME"); // Gives 2 calls
    //
    // When we declare a default value for an argument, there becomes another available
    // call (we pass a value OR do not pass a value).
    
    
    if (subject) {
        this->subjects.push_back(subject);
    }
    
}
