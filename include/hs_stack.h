#ifndef __HS_STACK__H
#define __HS_STACK__H
#include<hs_sll.h>
#include<hs_common.h>
typedef struct __$_hs_stack
{
SinglyLinkedList *singlyLinkedList;
}Stack;
Stack * createStack(bool *success);
void pushOnStack(Stack *stack,void *ptr,bool *success);
void * popFromStack(Stack *stack,bool *success);
bool isStackEmpty(Stack *stack);
void * elementAtTop(Stack *stack,bool *success);
int getSizeOfStack(Stack *stack);
void clearStack(Stack *stack);
void destroyStack(Stack *stack);
#endif