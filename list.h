typedef struct __lln
{
    struct __lln *prev;
    void *data;
    struct __lln *next;
}LinkedListNode;

typedef LinkedListNode LLNode; /* Shorter way to refer to type */

void freeLinkedList(LLNode* linkedList);
LLNode* S_initLinkedList(char* src[], unsigned int srcLen);
LLNode* I_initLinkedList(int src[], unsigned int srcLen);
LLNode* D_initLinkedList(double src[], unsigned int srcLen);
LLNode* F_initLinkedList(float src[], unsigned int srcLen);

unsigned int getLinkedListSize(LLNode root);

// String later, add null checks below
int* I_linkedListToArray(LLNode root);
double* D_linkedListToArray(LLNode root);
float* F_linkedListToArray(LLNode root);

int I_appendItemLL(LLNode* root, int value);

int I_getItemLL(LLNode root, int index);