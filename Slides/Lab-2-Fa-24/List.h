//
//  List.h
//  Lab 2
//
//  Created by Kyle Parker on 9/2/24.
//

#ifndef List_h
#define List_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct contact
{
    char name[50];
    char phone[12]; // 18005557577
    char email[50];
    char title[20];
} Contact;

typedef struct node
{
    Contact data;
    struct node *pNext;
} Node;

Node * makeNode(Contact newData);
void printList(Node *pList);

bool insertContactInOrder(Node **pList, Contact newData);
bool deleteContact(Node **pList, Contact searchContact);
bool editContact(Node *pList, Contact searchContact);
bool loadContacts(FILE *infile, Node **pList);
bool storeContacts(FILE *infile, Node *pList);


#endif /* List_h */
