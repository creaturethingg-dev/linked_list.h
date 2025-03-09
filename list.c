#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void registerError(char* error)
{
    fflush(NULL);
    fprintf(stderr, error);
    fflush(stderr);
    abort();
}

void freeLinkedList(LLNode* root)
{
    if (root == NULL)
        registerError("Root cannot be null");
    LLNode* current = root;
    LLNode* next = current->next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        if (current-> data != NULL)
            free(current->data);
        current = next;
    }
}

LLNode* S_initLinkedList(char* src[], unsigned int srcLen)
{
    LLNode* root = (LLNode*) malloc(sizeof(LLNode));
    if (root == NULL)
    {
        registerError("Unable to allocate memory to root");
    }

    root->data = &src[0];
    root->prev = NULL;
    root->next = NULL;

    LLNode* lastNode = root;
    for (register int i=1;i<srcLen;i++) // One since root already consumes an element
    {
        LLNode* newNode = (LLNode *) malloc(sizeof(LLNode));
        if (newNode == NULL)
        {
            registerError("Unable to allocate memory\nFreeing linked list");
            freeLinkedList(root);
        }
        newNode->data = &src[i];
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = NULL; // NULL until used
        lastNode = newNode;
    }

    return root;
}

LLNode* I_initLinkedList(int src[], unsigned int srcLen)
{
    LLNode* root = (LLNode*) malloc(sizeof(LLNode));
    if (root == NULL)
    {
        registerError("Unable to allocate memory to root");
    }
    
    root->data = &src[0];
    root->prev = NULL;
    root->next = NULL;

    LLNode* lastNode = root;
    for (register int i=1;i<srcLen;i++) // One since root already consumes an element
    {
        LLNode* newNode = (LLNode *) malloc(sizeof(LLNode));
        if (newNode == NULL)
        {
            registerError("Unable to allocate memory\nFreeing linked list");
            freeLinkedList(root);
        }
        newNode->data = &src[i];
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = NULL; // NULL until used
        lastNode = newNode;
    }

    return root;
}

LLNode* D_initLinkedList(double src[], unsigned int srcLen)
{
    LLNode* root = (LLNode*) malloc(sizeof(LLNode));
    if (root == NULL)
    {
        registerError("Unable to allocate memory to root");
    }
    
    root->data = &src[0];
    root->prev = NULL;
    root->next = NULL;

    LLNode* lastNode = root;
    for (register int i=1;i<srcLen;i++) // One since root already consumes an element
    {
        LLNode* newNode = (LLNode *) malloc(sizeof(LLNode));
        if (newNode == NULL)
        {
            registerError("Unable to allocate memory\nFreeing linked list");
            freeLinkedList(root);
        }
        newNode->data = &src[i];
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = NULL; // NULL until used
        lastNode = newNode;
    }

    return root;
}

LLNode* F_initLinkedList(float src[], unsigned int srcLen)
{
    LLNode* root = (LLNode*) malloc(sizeof(LLNode));
    if (root == NULL)
    {
        registerError("Unable to allocate memory to root");
    }
    
    root->data = &src[0];
    root->prev = NULL;
    root->next = NULL;

    LLNode* lastNode = root;
    for (register int i=1;i<srcLen;i++) // One since root already consumes an element
    {
        LLNode* newNode = (LLNode *) malloc(sizeof(LLNode));
        if (newNode == NULL)
        {
            registerError("Unable to allocate memory\nFreeing linked list");
            freeLinkedList(root);
        }
        newNode->data = &src[i];
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = NULL; // NULL until used
        lastNode = newNode;
    }

    return root;
}

unsigned int getLinkedListSize(LLNode root)
{
    unsigned int count = 1; // Account for root
    LLNode* node = root.next;
    while (node != NULL)
    {
        node = node->next;
        count++;
    }
    return count;
}

int* I_linkedListToArray(LLNode root)
{
    int *array = (int *) malloc(sizeof(int) * getLinkedListSize(root));
    LLNode* node = root.next;
    array[0] = *((int *)root.data);
    int idx = 1; // Account for root index
    while (node != NULL)
    {
        array[idx++] = *((int *)node->data);
        node = node->next;
    }
    return array;
}

double* D_linkedListToArray(LLNode root)
{
    double *array = (double *) malloc(sizeof(double) * getLinkedListSize(root));
    LLNode* node = root.next;
    array[0] = *((double *)root.data);
    int idx = 1; // Account for root index
    while (node != NULL)
    {
        array[idx++] = *((double *)node->data);
        node = node->next;
    }
    return array;
}

float* F_linkedListToArray(LLNode root)
{
    float *array = (float *) malloc(sizeof(float) * getLinkedListSize(root));
    LLNode* node = root.next;
    array[0] = *((float *)root.data);
    int idx = 1; // Account for root index
    while (node != NULL)
    {
        array[idx++] = *((float *)node->data);
        node = node->next;
    }
    return array;
}

int I_appendItemLL(LLNode* root, int value)
{
    if (root == NULL)
        registerError("Cannot append item to null root");
    LLNode *node = root;
    while (node->next != NULL)
    {
        node = node->next;
    }

    LLNode* newNode = (LLNode *) malloc(sizeof(LLNode));
    if (newNode == NULL)
        registerError("Unable to allocate memory for new linked list node");
    node->next = newNode;
    newNode->prev = node;
    int* val = (int *) malloc(sizeof(int));
    if (val == NULL)
        registerError("Unable to allocate memory for integer for new linked list node");
    *val = value;
    newNode->data = val;
    return value;
}

int I_getItemLL(LLNode root, int index)
{
    if (index == 0) 
        return *((int *)root.data);
    unsigned int idx = 1; // Account for root
    LLNode* node = root.next;
    while (node != NULL)
    {
        if (idx == index)
            return *((int *)node->data);
        node = node->next;
        idx++;
    }
    registerError("Index out of bounds");
}
