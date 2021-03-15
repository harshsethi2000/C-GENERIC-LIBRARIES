#ifndef __HS_QUEUE_C
#define __HS_QUEUE_C
#include<hs_queue.h>
#include<hs_sll.h>
#include<hs_common.h>
#include<stdlib.h>
Queue * createQueue(bool *success)
{
Queue *queue;
SinglyLinkedList *singlyLinkedList;
singlyLinkedList=createSinglyLinkedList(success);
if(success==false)return NULL;
queue=(Queue *)malloc(sizeof(Queue));
if(queue==NULL)
{
if(success)*success=false;
return NULL;
}
queue->singlyLinkedList=singlyLinkedList;
if(success)*success=true;
return queue;
}
void addToQueue(Queue *queue,void *ptr,bool *success)
{
if(success)*success=false;
if(queue==NULL || queue->singlyLinkedList==NULL)return;
addToSinglyLinkedList(queue->singlyLinkedList,ptr,success);
}
void * removeFromQueue(Queue *queue,bool *success)
{
void *ptr;
if(success)*success=false;
if(isQueueEmpty(queue))return NULL;
ptr=removeFromSinglyLinkedList(queue->singlyLinkedList,0,success);
if(success)*success=true;
return ptr;
}
bool isQueueEmpty(Queue *queue)
{
if(queue==NULL)return true;
if(queue->singlyLinkedList==NULL)return true;
if(getSizeOfSinglyLinkedList(queue->singlyLinkedList)==0)return true;
return false;
}
void * elementAtFrontOfQueue(Queue *queue,bool *success)
{
void *ptr;
if(success)*success=false;
if(isQueueEmpty(queue))return NULL;
ptr=getFromSinglyLinkedList(queue->singlyLinkedList,0,success);
return ptr;
}
int getSizeOfQueue(Queue *queue)
{
if(queue==NULL || queue->singlyLinkedList==NULL)return 0;
bool *success;
return getSizeOfSinglyLinkedList(queue->singlyLinkedList);
}
void clearQueue(Queue *queue)
{
if(queue==NULL)return;
if(queue->singlyLinkedList==NULL)return;
clearSinglyLinkedList(queue->singlyLinkedList);
return;
}
void destroyQueue(Queue *queue)
{
if(queue==NULL)return;
if(queue->singlyLinkedList==NULL)return;
destroySinglyLinkedList(queue->singlyLinkedList);
free(queue);
}

#endif