# linked_list.h

``` linked_list.h ``` is a utility C library that adds linked lists and several related utility functions.

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

If you are using Linux/macOS, download the ```liblinked_list.a```.
If you are using Windows, download the ```linked_list.lib``` file.
Download the ```linked_list.h``` header file in ```include\```.

You should be able to use the libraries now.

Make sure you link the libraries when compiling.

## How does it work

It uses a system of nodes, each containing a pointer to the last node and the next.
They also hold a void pointer to their value. 
This is part of the reason why many functions are prefixed, so that they automatically cast and dereference the value pointers.
The P_ prefixed function just return the void pointer directly, though
