//
//  SampleProgram.hpp
//  122 Lab 5
//
//  created by Kyle Parker on 2/12/24.
//

#ifndef SampleProgram_hpp
#define SampleProgram_hpp

#include "SampleSubject.hpp"

#include <iostream>
#include <vector>
using std::vector;

class SampleProgram {
    vector<int> listOfInts;
    vector<SampleSubject *> subjects;
    
    void CopySubjects(vector<SampleSubject *> newSubjects);
    
public:
    SampleProgram();
    
    SampleProgram(SampleProgram &copy);
    
    ~SampleProgram();
    
    int Sum();
    
    int Sum(vector<int> ints);
    
    int Sum(int a, int b);
    
    int Sum(int a, int b, int c);
    
    double Sum(vector<double> dbls);
    
    double Sum(double a, double b, double c);
    
    void addRandomSubject(void);
};

#endif /* SampleProgram_hpp */
