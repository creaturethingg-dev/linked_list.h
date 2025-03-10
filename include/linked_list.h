#ifndef LINKED_LIST_LIB
#define LINKED_LIST_LIB 

typedef struct __lln /* Represents a singular node in a linked list */
{
    struct __lln *prev;
    void *data;
    struct __lln *next;
}LinkedListNode;

typedef LinkedListNode LLNode; /* Shorter way to refer to type */

typedef struct 
{
    LLNode* root1;
    LLNode* root2;
}LinkedListTuple; /* Contains two linked lists, specifically for use with the splitLL & concatLL functions */

typedef LinkedListTuple LLTuple; /* Shorter way to refer to type */

// Configures what function is called in the event of an error.
// By default, a message is printed to stderr, and the
// program is aborted
void configErrorActionLL(void (*func)(const char*));


// Frees memory of linked list nodes and their data
void freeLinkedList(LLNode* root); 


// Passes the node's value to the function and
// sets its value to whatever is returned,
// for every node in a linked list
void mapLL(LLNode* root, void* (*func)(void *));


// Splits a linked list into two, based on index.
// The node at the specified index is put into
// the first root in the returned tuple
// (root1)
LLTuple splitLL(LLNode* root, int index);


// Concatenates two linked lists, and returns the
// new linked list's root. It is recommended
// that you free the LLTuple after using this function,
// if you don't plan on using it again. Note that
// this function does manipulate the values of the 
// original linked lists provided in the tuple
LLNode* concatLL(LLTuple tuple);


// Removes and frees a node from a linked list.
// Reconnects the two parts of list afterwards.
// If you remove the root, it will return the new root.
LLNode* removeNodeLL(LLNode* root, int index);


// Removes the first node in linked list which contains a value
// that causes the comparison function to return 1. 
// Returns the index that the node was at, and returns -1 if
// the value wasn't found
int removeValueLL(LLNode* root, void* value, int (*cmp)(void*, void*));

// Removes the first node in linked list which contains a value
// equal to the specified value, and returns which index it was at.
// If it isn't found, it returns -1
int S_removeValueLL(LLNode* root, const char* value);

// Removes the first node in linked list which contains a value
// equal to the specified value, and returns which index it was at.
// If it isn't found, it returns -1
int I_removeValueLL(LLNode* root, int value);

// Removes the first node in linked list which contains a value
// equal to the specified value, and returns which index it was at.
// If it isn't found, it returns -1
int D_removeValueLL(LLNode* root, double value);

// Removes the first node in linked list which contains a value
// equal to the specified value, and returns which index it was at.
// If it isn't found, it returns -1
int F_removeValueLL(LLNode* root, float value);


// Removes the first node in linked list (the root), and
// returns the new root
LLNode* popFrontLL(LLNode* root);

// Removes the last node in linked list
void popBackLL(LLNode* root);


// Returns the index of the first node that which contains a value
// that causes the comparsion function to return 1.
// If the value isn't found, it returns -1
int findValueLL(LLNode* root, void* value, int (*cmp)(void*, void*));

// Returns the index of the first node that contains the same value
// as the one specified. If the value isn't found, it returns 1
int S_findValueLL(LLNode* root, const char* value);

// Returns the index of the first node that contains the same value
// as the one specified. If the value isn't found, it returns 1
int I_findValueLL(LLNode* root, int value);

// Returns the index of the first node that contains the same value
// as the one specified. If the value isn't found, it returns 1
int D_findValueLL(LLNode* root, double value);

// Returns the index of the first node that contains the same value
// as the one specified. If the value isn't found, it returns 1
int F_findValueLL(LLNode* root, float value);


// Intialises an empty linked list
LLNode* initLinkedList(void);

// Initialises a linked list from string array
LLNode* S_initLinkedList(char* src[], unsigned int srcLen);

// Initialises a linked list from int array
LLNode* I_initLinkedList(int src[], unsigned int srcLen);

// Initialises a linked list from double array
LLNode* D_initLinkedList(double src[], unsigned int srcLen);

// Initialises a linked list from float array
LLNode* F_initLinkedList(float src[], unsigned int srcLen);


// Returns the number of elements in a linked list
unsigned int getLinkedListSize(LLNode* root);


// Converts a linked list to a string array
char** S_linkedListToArray(LLNode* root);

// Converts a linked list to an int array
int* I_linkedListToArray(LLNode* root);

// Converts a linked list to a double array
double* D_linkedListToArray(LLNode* root);

// Converts a linked list to a float array
float* F_linkedListToArray(LLNode* root);


// Appends a string value to a linked list
const char* S_appendItemLL(LLNode* root, const char* value);

// Appends an int value to a linked list
int I_appendItemLL(LLNode* root, int value);

// Appends a double value to a linked list
double D_appendItemLL(LLNode* root, double value);

// Appends a float value to a linked list
float F_appendItemLL(LLNode* root, float value);

// Appends a pointer value to a linked list
void* P_appendItemLL(LLNode* root, void* value);

// Gets a string value from a linked list at index.
// This is more efficient than converting to array 
// and getting value
char* S_getItemLL(LLNode* root, int index);

// Gets an int value from a linked list at index.
// This is more efficient than converting to array 
// and getting value
int I_getItemLL(LLNode* root, int index);

// Gets a double value from a linked list at index.
// This is more efficient than converting to array 
// and getting value
double D_getItemLL(LLNode* root, int index);

// Gets a float value from a linked list at index.
// This is more efficient than converting to array 
// and getting value
float F_getItemLL(LLNode* root, int index);

// Gets a void pointer value from a linked list at index.
// Note that you will probably need to cast it to
// a pointer of the type you want and dereference it.
// (e.g x = *((struct type*)P_getItemLL(root, 0) )
void* P_getItemLL(LLNode* root, int index);


// Sets the value of a linked list element at index
// to string value specified
const char* S_setItemLL(LLNode* root, int index, const char* value);

// Sets the value of a linked list element at index
// to int value specified
int I_setItemLL(LLNode* root, int index, int value);

// Sets the value of a linked list element at index
// to double value specified
double D_setItemLL(LLNode* root, int index, double value);

// Sets the value of a linked list element at index
// to float value specified
float F_setItemLL(LLNode* root, int index, float value);

// Sets the value of a linked list element at index
// to pointer specified
void* P_setItemLL(LLNode* root, int index, void* value);

#endif
