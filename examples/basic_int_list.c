/*
    Showcases how to create a linked list from int array,
    append items to that list, convert it back to the array,
    and the get and set functions.
*/

#include <stdio.h>
#include "linked_list.h"

void displayList(LLNode* root);

int main(void)
{
    int x[] = {1,2,3,4};
    LLNode* root = I_initLinkedList(x, 4); // 4 elements in array
    displayList(root); // 1 2 3 4
    I_appendItemLL(root, 5);
    displayList(root); // 1 2 3 4 5
    I_setItemLL(root, 4, 6);
    int* y = I_linkedListToArray(root);
    for (int i=0;i < 5;i++)
        printf("%d ", y[i]); // 1 2 3 4 6
    freeLinkedList(root);
}

void displayList(LLNode* root)
{
    for (int i=0;i < getLinkedListSize(root);i++)
        printf("%d ", I_getItemLL(root, i)); 
    printf("\n");
}
