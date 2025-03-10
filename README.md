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
