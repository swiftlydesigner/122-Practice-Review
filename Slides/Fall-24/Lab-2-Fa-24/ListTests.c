//
//  ListTests.c
//  Lab 2
//
//  Created by Kyle Parker on 9/3/24.
//

#include "ListTests.h"
#include <string.h>

void testMakeNode(void) {
    
    Contact contact = {
        .name = "Jim",
        .title = "Title",
        .email = "jim@wsu.edu",
        .phone = "760-442-6612"
    };
    
    bool success = false;
    
    Node * node = makeNode(contact);
    
    if (node) {
        puts("[testMakeNode] Allocated space successfully!");
        
        if (strcmp(contact.name, node->data.name) == 0 &&
            strcmp(contact.title, node->data.title) == 0 &&
            strcmp(contact.email, node->data.email) == 0 &&
            strcmp(contact.phone, node->data.phone) == 0) {
            
            puts("[testMakeNode] Node contents are correct!");
            
            success = true;
        }
        
    }
    
    if (success) {
        puts("[testMakeNode] Passed!");
    } else {
        puts("[testMakeNode] Failed!");
    }
}


void testInsertContactInOrder(void) {
    
}

void testDeleteContact(void) {
    
}

void testEditContact(void) {
    
}

void testLoadContacts(void) {
    
}

void testStoreContacts(void) {
    
}
