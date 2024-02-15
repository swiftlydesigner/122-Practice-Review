//
//  PPPExt.cpp
//  122 Lab 5
//
//  created by Kyle Parker on 2/12/24.
//

#include "PPPExt.hpp"

PPPExt::PPPExt() {
    
}

PPPExt::PPPExt(int value) {
    // this->privInteger = 100; // ERROR: 'privInteger' is a private member of 'PrivateProtectedPublic'
    this->protDouble = 50; // Protected in PrivateProtectedPublic, so I can access from PPPExt
    this->onlyThisClass = value; // Private in PPPExt, so I can access
    this->pubChar = 'F'; // Public in PrivateProtectedPublic, so I can access *anywhere*
    
    // this->privFunc(); // ERROR: 'privFunc' is a private member of 'PrivateProtectedPublic'
    this->protFunc(); // Protected in PrivateProtectedPublic, so I can access from PPPExt
    this->pubFunc(); // Public in PrivateProtectedPublic, so I can access *anywhere*
}

PPPExt::~PPPExt() {
    
}
