//
//  List.c
//  Lab 2
//
//  Created by Kyle Parker on 9/2/24.
//

#include "List.h"
#include <string.h>

// Description: Allocates space for a Node on the heap and initializes the Node with the information found in newData.
// Returns: The address of the start of the block of memory on the heap or NULL if no memory was allocated
Node * makeNode(Contact newData) {
    Node * tmp = (Node*)malloc(sizeof(Node));
    
    if (tmp) {
        tmp->data = newData;
        tmp->pNext = NULL;
    }
    
    return tmp;
}

/// Pre-condition: *pList is non-null.
void insertInOrder(Node * node, Node ** pList) {
    Node * cur = *pList;
    Node * last = cur;
    char name[50];
    strcpy(name, node->data.name); // For large lists, this saves computions
    
    // Make sure we have a next AND
    // Make sure the name should go closer to the end
    while (cur && strcmp(name, cur->data.name) >= 0) {
        last = cur;
        cur = cur->pNext;
    }
    
    node->pNext = cur;
    last->pNext = node;
}

// Description: Uses makeNode () to allocate space for a new Node and inserts the new Node into the list in alphabetic order ('a' - 'z')
// based on the name field
// Returns: TRUE if memory was allocated for a Node; FALSE otherwise
bool insertContactInOrder(Node **pList, Contact newData) {
    Node * newNode = makeNode(newData);
    
    if (newNode) {
        if (*pList) {
            insertInOrder(newNode, pList);
        } else {
            *pList = NULL;
        }
    }
    
    return newNode != NULL;
}

// Description: Deletes a Contact in the list based on the name field; deletes the first occurence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
bool deleteContact(Node **pList, Contact searchContact) {
    // Set pCur to the first node, or NULL if pList is NULL
    Node * pCur = pList == NULL ? NULL : *pList;
    Node * pLast = NULL;
    bool found = false;
    
    char * name = searchContact.name;
    
    // Keep looking while not found and pCur is non-NULL
    while (pCur) {
        
        // Set found to true if the names match
        if (strcmp(pCur->data.name, name) == 0) {
            found = true;
            
            if (pLast) {
                pLast->pNext = pCur->pNext;
            }
            else {
                *pList = pCur->pNext;
            }
            
            free(pCur);
            pCur = NULL;
        } else {
            // Go to next.
            pLast = pCur;
            pCur = pCur->pNext;
        }
        
    }
    
    return found;
}

// Description: Edits a Contact in the list based on the name field; edits the first occurence of the name
// Returns: TRUE if the Contact was found; FALSE otherwise
bool editContact(Node *pList, Contact searchContact) {
    char * name = searchContact.name;
    
    bool found = false;
    
    // Go from pList to NULL (end of list)
    for (pList; pList != NULL && !found; pList = pList->pNext) {
        if (strcmp(name, pList->data.name) == 0) {
            pList->data = searchContact;
            found = true;
        }
    }
    
    return found;
}

// Description: Loads all Contact information from the given file, in alphabetic order, based on the name, into the list
// Returns: TRUE if all Contacts were loaded; FALSE otherwise
bool loadContacts(FILE *infile, Node **pList) {
    char * line = (char*)malloc(150);
    
    // Make sure the input file, list, and line are non-NULL. Stop if any are true
    if (!infile || !pList || !line) {
        return false;
    }
    
    while (fgets(line, 150, infile)) {
        
        Contact newContact;
        
        strcpy(newContact.name, strtok(line, ","));
        strcpy(newContact.phone, strtok(NULL, ","));
        strcpy(newContact.email, strtok(NULL, ","));
        strcpy(newContact.title, strtok(NULL, "\n"));
        
        insertContactInOrder(pList, newContact);
        
    }
    
    free(line);
        
    return true;
}

// Description: Stores all Contact information from the list into the given file
// Returns: TRUE if all Contacts were stored; FALSE otherwise
bool storeContacts(FILE *infile, Node *pList) {
    // Make sure the input file and list are non-NULL. Stop if any are true.
    if (!infile || !pList) {
        return false;
    }
    
    // iterate through pList
    for (pList; pList != NULL; pList = pList->pNext) {
        
        fprintf(infile, "%s,%s,%s,%s\n",
                pList->data.title,
                pList->data.name,
                pList->data.email,
                pList->data.phone);
        
    }
    
    return false;
}

// Description: Prints all contact information in the list
// Returns: Nothing
void printList(Node *pList) {
    storeContacts(stdout, pList);
}
