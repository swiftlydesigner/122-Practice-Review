//
//  PublicProtectedPrivate.hpp
//  122 Lab 5
//
//  created by Kyle Parker on 2/10/24.
//

#ifndef PublicProtectedPrivate_hpp
#define PublicProtectedPrivate_hpp

#include <stdio.h>

class PrivateProtectedPublic {
private:
    int privInteger;
    int privFunc(void);
    
protected:
    double protDouble;
    double protFunc(void);
    
public:
    /// We do not like declaring variables are public as anybody can modify them.
    /// Most of the time, it will be under private, but there are times where protected
    /// is better. Rarely will there be a reason to do this.
    char pubChar;
    
    /// Instead of declaring variables public, we use getters and setters.
    /// Other langs have different ways of handing this.
    char pubFunc(void);
    
};

#endif /* PublicProtectedPrivate_hpp */
