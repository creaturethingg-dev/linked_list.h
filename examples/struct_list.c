/*
    Demonstrates how to use linked lists with
    custom struct types using pointer functions
*/

#include <stdio.h>
#include "linked_list.h"

struct myStruct
{
    int num;
};

int main(void)
{
    struct myStruct a = {0};
    struct myStruct b = {1};
    struct myStruct c = {2};

    LLNode* root = initLinkedList(); // Creates an empty linked list

    P_appendItemLL(root, &a); // Append pointers to a, b, c
    P_appendItemLL(root, &b);
    P_appendItemLL(root, &c);

    struct myStruct x = {-1}; // We'll copy a, b, c into x, y, z from the list
    struct myStruct y = {-1};
    struct myStruct z = {-1};

    // We start at 1 since we left root null. If you want to give root a value, use P_setItemLL(root, 0, ...)
    x = *((struct myStruct*)P_getItemLL(root, 1)); // a
    y = *((struct myStruct*)P_getItemLL(root, 2)); // b
    z = *((struct myStruct*)P_getItemLL(root, 3)); // c

    printf("%d, ", x.num); // 0
    printf("%d, ", y.num); // 1
    printf("%d\n", z.num); // 2

    freeLinkedList(root);
}
