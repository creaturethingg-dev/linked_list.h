# linked_list.h

``` linked_list.h ``` is a utility C library that adds linked lists and several related utility functions.

## Repo

- ```examples\``` contains multiple code examples, showcasing the functions' usages.
- ```include\``` contains the ```linked_list.h``` header file.
- ```bin\``` contains ```liblinked_list.a```, ```linked_list32.lib```, and ```linked_list64.lib```
  
## Naming Conventions

Many functions are prefixed with S_, I_, D_, F_, and P_ .
These prefixes represent types
- S_ = string
- I_ = int
- D_ = double
- F_ = float
- P_ = pointer (```void *```)

They specify what type the function deals with.
For example, ```S_setItemLL(LLNode* root, int index, const char* value)``` sets the value of a linked list at index
to a string value specified. Similarly, ```S_getItemLL(LLNode* root, int index)``` retrieves a string value at
index of a linked list. The other prefixes do the same thing for different types.
While P_ prefixed functions can be used solely for pointers, they can also be used to use custom types in a 
linked list (see ```examples/struct_list.c```). 

All functions have descriptions (in ```linked_list.h```), so refer to that if something is unclear.

## How to use it

### Linux/macOS/Windows (MSYS2 or Cygwin)
Download the ```liblinked_list.a``` file, and the ```linked_list.h``` file in ```include\```.
I would suggest keeping the files in the same folder as your code for simplicity, but you can keep them 
in a different folder, too.
When compiling, link the .a file. I use gcc, so I'd use this command:
```gcc file.c -o file.exe -Lpath/to/lib/folder -llinked_list```.

If you keep the files in the same folder as your code, your can use ```-L.``` in the gcc command to specify that
it is in the same folder.

### Windows (Visual Studio)
Download the ```linked_list32.lib``` or ```linked_list64.lib``` file, depending on whether you're building
for 32-bit or 64-bit. Place ```linked_list.h``` (found in include folder) inside your ```include\``` directory.
Add the ```.lib``` file to your project's additional library directories (in VS settings).

## How does it work

It uses a system of nodes, each containing a pointer to the last node and the next.
They also hold a void pointer to their value. 
This is part of the reason why many functions are prefixed, so that they automatically typecast and dereference the value pointers.
The P_ prefixed function just return the void pointer directly, though.

## Function list (also available in ```include\linked_list.h```)

### `void configErrorActionLL(void (*func)(const char*));`
Configures what function is called in the event of an error. By default, a message is printed to stderr, and the program is aborted.

### `void freeLinkedList(LLNode* root);`
Frees memory of linked list nodes and their data.

### `void mapLL(LLNode* root, void* (*func)(void *));`
Passes the node's value to the function and sets its value to whatever is returned, for every node in a linked list.

### `LLTuple splitLL(LLNode* root, int index);`
Splits a linked list into two, based on the index. The node at the specified index is put into the first root in the returned tuple (root1).

### `LLNode* concatLL(LLTuple tuple);`
Concatenates two linked lists, and returns the new linked list's root. It is recommended that you free the LLTuple after using this function if you don't plan on using it again. This function manipulates the values of the original linked lists.

### `LLNode* removeNodeLL(LLNode* root, int index);`
Removes and frees a node from a linked list. Reconnects the two parts of the list afterward. If you remove the root, it will return the new root.

### `int removeValueLL(LLNode* root, void* value, int (*cmp)(void*, void*));`
Removes the first node in the linked list which contains a value that causes the comparison function to return 1. Returns the index that the node was at, and returns -1 if the value wasn't found.

### `int S_removeValueLL(LLNode* root, const char* value);`
Removes the first node in the linked list which contains a string value equal to the specified value, and returns the index it was at. Returns -1 if the value isn't found.

### `int I_removeValueLL(LLNode* root, int value);`
Removes the first node in the linked list which contains an integer value equal to the specified value, and returns the index it was at. Returns -1 if the value isn't found.

### `int D_removeValueLL(LLNode* root, double value);`
Removes the first node in the linked list which contains a double value equal to the specified value, and returns the index it was at. Returns -1 if the value isn't found.

### `int F_removeValueLL(LLNode* root, float value);`
Removes the first node in the linked list which contains a float value equal to the specified value, and returns the index it was at. Returns -1 if the value isn't found.

### `LLNode* popFrontLL(LLNode* root);`
Removes the first node in the linked list (the root), and returns the new root.

### `void popBackLL(LLNode* root);`
Removes the last node in the linked list.

### `int findValueLL(LLNode* root, void* value, int (*cmp)(void*, void*));`
Returns the index of the first node that contains a value which causes the comparison function to return 1. Returns -1 if the value isn't found.

### `int S_findValueLL(LLNode* root, const char* value);`
Returns the index of the first node that contains the same string value as the one specified. Returns -1 if the value isn't found.

### `int I_findValueLL(LLNode* root, int value);`
Returns the index of the first node that contains the same integer value as the one specified. Returns -1 if the value isn't found.

### `int D_findValueLL(LLNode* root, double value);`
Returns the index of the first node that contains the same double value as the one specified. Returns -1 if the value isn't found.

### `int F_findValueLL(LLNode* root, float value);`
Returns the index of the first node that contains the same float value as the one specified. Returns -1 if the value isn't found.

### `LLNode* initLinkedList(void);`
Initializes an empty linked list.

### `LLNode* S_initLinkedList(char* src[], unsigned int srcLen);`
Initializes a linked list from a string array.

### `LLNode* I_initLinkedList(int src[], unsigned int srcLen);`
Initializes a linked list from an integer array.

### `LLNode* D_initLinkedList(double src[], unsigned int srcLen);`
Initializes a linked list from a double array.

### `LLNode* F_initLinkedList(float src[], unsigned int srcLen);`
Initializes a linked list from a float array.

### `unsigned int getLinkedListSize(LLNode* root);`
Returns the number of elements in a linked list.

### `char** S_linkedListToArray(LLNode* root);`
Converts a linked list to a string array.

### `int* I_linkedListToArray(LLNode* root);`
Converts a linked list to an integer array.

### `double* D_linkedListToArray(LLNode* root);`
Converts a linked list to a double array.

### `float* F_linkedListToArray(LLNode* root);`
Converts a linked list to a float array.

### `const char* S_appendItemLL(LLNode* root, const char* value);`
Appends a string value to a linked list.

### `int I_appendItemLL(LLNode* root, int value);`
Appends an integer value to a linked list.

### `double D_appendItemLL(LLNode* root, double value);`
Appends a double value to a linked list.

### `float F_appendItemLL(LLNode* root, float value);`
Appends a float value to a linked list.

### `void* P_appendItemLL(LLNode* root, void* value);`
Appends a pointer value to a linked list.

### `char* S_getItemLL(LLNode* root, int index);`
Gets a string value from a linked list at the specified index. This is more efficient than converting to an array and getting the value.

### `int I_getItemLL(LLNode* root, int index);`
Gets an integer value from a linked list at the specified index. This is more efficient than converting to an array and getting the value.

### `double D_getItemLL(LLNode* root, int index);`
Gets a double value from a linked list at the specified index. This is more efficient than converting to an array and getting the value.

### `float F_getItemLL(LLNode* root, int index);`
Gets a float value from a linked list at the specified index. This is more efficient than converting to an array and getting the value.

### `void* P_getItemLL(LLNode* root, int index);`
Gets a void pointer value from a linked list at the specified index. You will likely need to cast it to a pointer of the type you want and dereference it.

### `const char* S_setItemLL(LLNode* root, int index, const char* value);`
Sets the value of a linked list element at the specified index to the given string value.

### `int I_setItemLL(LLNode* root, int index, int value);`
Sets the value of a linked list element at the specified index to the given integer value.

### `double D_setItemLL(LLNode* root, int index, double value);`
Sets the value of a linked list element at the specified index to the given double value.

### `float F_setItemLL(LLNode* root, int index, float value);`
Sets the value of a linked list element at the specified index to the given float value.

### `void* P_setItemLL(LLNode* root, int index, void* value);`
Sets the value of a linked list element at the specified index to the given pointer value.

