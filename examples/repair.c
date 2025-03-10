/*
    Splits and concatenates a linked list using the
    splitLL and concatLL functions
*/

#include <stdio.h>
#include "linked_list.h"

void displayList(LLNode* root);

int main(void)
{
    float x[] = {1.1,2.2,3.3,4.4,5.5,6.6};
    LLNode* root = F_initLinkedList(x, 6);
    displayList(root);

    LLTuple split = splitLL(root, 2); // 1-3 goes into root1
    displayList(split.root1);
    displayList(split.root2);
    
    LLNode* concat = concatLL(split);
    displayList(concat);
    
    // NOTE: Don't free root, it was split into 2. Instead, free concat
    freeLinkedList(concat);
}

void displayList(LLNode* root)
{
    for (int i=0;i < getLinkedListSize(root);i++)
        printf("%f ", F_getItemLL(root, i));
    printf("\n");
}