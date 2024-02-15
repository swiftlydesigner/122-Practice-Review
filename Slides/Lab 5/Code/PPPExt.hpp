//
//  PPPExt.hpp
//  122 Lab 5
//
//  created by Kyle Parker on 2/12/24.
//

#ifndef PPPExt_hpp
#define PPPExt_hpp

#include "PublicProtectedPrivate.hpp"

class PPPExt: PrivateProtectedPublic {
    int onlyThisClass;
    
public:
    PPPExt();
    
    PPPExt(int value);
    
    ~PPPExt();
};

#endif /* PPPExt_hpp */
