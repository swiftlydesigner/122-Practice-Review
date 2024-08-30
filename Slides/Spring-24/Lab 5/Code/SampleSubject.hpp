//
//  SampleSubject.hpp
//  122 Lab 5
//
//  created by Kyle Parker on 2/12/24.
//

#ifndef SampleSubject_hpp
#define SampleSubject_hpp

#include <string>
using std::string;

class SampleSubject {
    int ID;
    string name;
    
public:
    SampleSubject();
    
    SampleSubject(string newName);
    
    SampleSubject(int newID, string newName = "UNSET_NAME");
    
    SampleSubject(SampleSubject &copy);
    
    ~SampleSubject();
};

#endif /* SampleSubject_hpp */
