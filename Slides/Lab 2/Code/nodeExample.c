//
//  nodeExample.c
//  122 Lab Sample Code
//
//  Created by Kyle Parker on 1/21/24.
//

#include "nodeExample.h"

Node * createNode(Person * data) {
    Node * node = (Node *)malloc(sizeof(Node));
    
    // Check if node was allocated
    if (node) {
        // Since we are here, it was allocated
        node->data = data;
        // Be sure to always set next to NULL.
        node->next = NULL;
    }
    
    return node;
}

Person * createPerson(char * name, char * degree,
                    short age, int siblingCount,
                    Person * siblings) {
    Person * person = (Person *)malloc(sizeof(Person));
    
    // Check if person was allocated
    if (person) {
        strncpy(person->name, name, MAX_BUF);
        strncpy(person->degree, degree, MAX_BUF);
        person->age = age;
        person->siblingCount = siblingCount;
        person->siblings = siblings;
    }
    
    return person;
}
