#ifndef __HS_QUEUE__H
#define __HS_QUEUE__H
#include<hs_sll.h>
#include<hs_common.h>
typedef struct __$_hs_queue
{
SinglyLinkedList *singlyLinkedList;
}Queue;
Queue * createQueue(bool *success);
void addToQueue(Queue *queue,void *ptr,bool *success);
void * removeFromQueue(Queue *queue,bool *success);
bool isQueueEmpty(Queue *queue);
void * elementAtFrontOfQueue(Queue *queue,bool *success);
int getSizeOfQueue(Queue *queue);
void clearQueue(Queue *queue);
void destroyQueue(Queue *queue);
#endif