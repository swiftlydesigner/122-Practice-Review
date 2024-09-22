#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _data {
	int x;
	int y;
	char * description;
} Data;

typedef struct _node {
	Data * pData;
	struct _node * pNext;
} Node;

/// You should also consider making a deleteNode function
/// as that will ensure all the contents are deleted. In C++,
/// we have a destructor which will act as our deleteNode function!

bool copyData(Data ** dest, const Data * src) {

    /// Allocate space for data
	*dest = malloc(sizeof(Data));

    /// Check to ensure data was allocated
	if (*dest) {
        /// Copy over the x var
		(*dest)->x = src->x;
        /// Copy over the y var
		(*dest)->y = src->y;

        /// Get the length of the string, add 1 for null char
		int len = strlen(src->description) + 1;
		
        /// Use malloc to allocate space for the description
		(*dest)->description = malloc(len);

        
        /// Check to ensure description was allocated
		if ((*dest)->description && len > 0) {
            /// Copy the string over
			strcpy((*dest)->description, src->description);
            /// Ensure the string it is null terminated
			*((*dest)->description + len - 1) = '\0';
		} else {
            /// Failed to allocate space for description, delete *dest
            free(*dest);
            *dest = NULL
        }
	}

    /// Return success (aka, dest is not null and therefore allocated.
	return *dest != NULL;
}

Node * makeNode(const Data* pNewData) {
	Node * pMem = malloc(sizeof(Node));

	if (pMem) {
		pMem->pNext = NULL;
	
		// Why is this dangerous?
        /// It could reference a pointer on the local call stack
        /// which would result in a possible invalid read/write
        /// operation. Since we use const in the param, this is
        /// also invalid due to the qualifier. Since pData is not
        /// const, the qualifer is dropped and therefore an illegal
        /// statement.
		//pMem->pData = pNewData;
	
		copyData(&pMem->pData, pNewData);
	}
	

	return pMem;
}

int main(void) {
	
}
