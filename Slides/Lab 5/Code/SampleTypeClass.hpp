//
//  SampleTypeClass.hpp
//  122 Lab 5
//
//  created by Kyle Parker on 2/12/24.
//

#ifndef SampleTypeClass_hpp
#define SampleTypeClass_hpp

#include <iostream>
#include <string>
using std::string;

template <class T>
class SampleTypeClass {
    T value;
    string name;
    
public:
    SampleTypeClass(void) {
        this->value = T();
        this->name = "UNSET";
    }
    
    SampleTypeClass(T value, string ID) {
        this->value = value;
        this->name = name;
    }
    
    ~SampleTypeClass(void) {
        
    }
    
    /// Return the current value
    T GetValue(void) {
        return this->value;
    }

    /// Return old value and set the new value
    T SetValue(T newValue) {
        T oldVal = value;
        this->value = newValue;
        return oldVal;
    }

};

#endif /* SampleTypeClass_hpp */
