//
//  nodeExample.h
//  122 Lab Sample Code
//
//  Created by Kyle Parker on 1/21/24.
//

#ifndef nodeExample_h
#define nodeExample_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 50

// Use lowercaseCamelCase for the name
// prefixed by a _ so we can use the name
// person in our code. If we do not use the _,
// then we cannot use person anywhere in our code.
typedef struct _person {
    char name[MAX_BUF];
    char degree[MAX_BUF];
    short age;
    int siblingCount;
    // siblings must be * since it is an
    // incomplete type at this point.
    struct _person * siblings;
} Person;

typedef struct _node {
    Person * data; // Can be pointer or non-pointer
   // next must be * since it is an
   // incomplete type at this point.
    struct _node * next;
} Node;

Node * createNode(Person * data);
Person * createPerson(char * name, char * degree,
                    short age, int siblingCount,
                    Person * siblings);

#endif /* nodeExample_h */
