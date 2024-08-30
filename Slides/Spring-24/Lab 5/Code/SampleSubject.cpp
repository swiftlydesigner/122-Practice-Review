//
//  SampleSubject.cpp
//  122 Lab 5
//
//  created by Kyle Parker on 2/12/24.
//

#include "SampleSubject.hpp"

SampleSubject::SampleSubject() {
    this->ID = 0;
    this->name = "UNSET";
}

SampleSubject::SampleSubject(string newName) {
    this->ID = 0;
    this->name = newName;
}

SampleSubject::SampleSubject(int newID, string newName) {
    this->ID = newID;
    this->name = newName;
}

SampleSubject::SampleSubject(SampleSubject &copy) {
    this->ID = copy.ID;
    this->name = copy.name;
}

SampleSubject::~SampleSubject() {
    
}
