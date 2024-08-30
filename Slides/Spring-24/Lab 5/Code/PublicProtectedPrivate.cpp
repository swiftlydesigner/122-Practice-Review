//
//  PublicProtectedPrivate.cpp
//  122 Lab 5
//
//  created by Kyle Parker on 2/10/24.
//

#include "PublicProtectedPrivate.hpp"

int PrivateProtectedPublic::privFunc() {
    return this->privInteger;
}

double PrivateProtectedPublic::protFunc() {
    return this->protDouble;
}

char PrivateProtectedPublic::pubFunc() {
    return this->pubChar;
}
