/*
    Demonstrates the following search and remove functions:
        -S_removeValueLL    -popFrontLL
        -S_findValue
*/

#include <stdio.h>
#include "linked_list.h"

int main(void)
{
    char* x[] = {"foo", "bar", "baz", "qux"};
    LLNode* root = S_initLinkedList(x, 4);
    printf("%d\n", S_findValueLL(root, "baz")); // 2
    S_removeValueLL(root, "baz");
    root = popFrontLL(root); // New root after removing first one
    for (int i=0;i < getLinkedListSize(root);i++)
        printf("%s ", S_getItemLL(root, i)); // bar qux
    freeLinkedList(root);
}
