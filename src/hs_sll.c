#ifndef __HS_SLL_C
#define __HS_SLL_C
#include<hs_sll.h>
#include<stdlib.h>
SinglyLinkedList * createSinglyLinkedList(bool *success)
{
if(success)*success=false;
SinglyLinkedList *singlyLinkedList;
singlyLinkedList=(SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));
singlyLinkedList->start=NULL;
singlyLinkedList->end=NULL;
singlyLinkedList->size=0;
if(success)*success=true;
return singlyLinkedList;
}
void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
if(singlyLinkedList==NULL)return;
clearSinglyLinkedList(singlyLinkedList);//for all the data nodes
free(singlyLinkedList);//for main node
}
int getSizeOfSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
if(singlyLinkedList==NULL)return 0;
return singlyLinkedList->size;
}
void clearSinglyLinkedList(SinglyLinkedList *singlyLinkedList)
{
if(singlyLinkedList==NULL)return;
SinglyLinkedListNode *node;
while(singlyLinkedList->start!=NULL)
{
node=singlyLinkedList->start;
singlyLinkedList->start=singlyLinkedList->start->next;
free(node);
}
singlyLinkedList->size=0;
}
void addToSinglyLinkedList(SinglyLinkedList *singlyLinkedList,void *ptr,bool *success)
{
if(success)*success=false;
if(singlyLinkedList==NULL)return;
SinglyLinkedListNode *singlyLinkedListNode;
singlyLinkedListNode=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(singlyLinkedListNode==NULL)return;
singlyLinkedListNode->next=NULL;
singlyLinkedListNode->ptr=ptr;
if(singlyLinkedList->start==NULL)
{
//no node is present
singlyLinkedList->start=singlyLinkedList->end=singlyLinkedListNode;
}
else
{
//atleast one node is present
singlyLinkedList->end->next=singlyLinkedListNode;
singlyLinkedList->end=singlyLinkedListNode;
}
singlyLinkedList->size++;
if(success)*success=true;
return;
}
void insertIntoSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,void *ptr,bool *success)
{
SinglyLinkedListNode *t,*p,*node;
if(success)*success=false;
if(singlyLinkedList==NULL)return;
if(index<0 || index >singlyLinkedList->size)return;
if(index ==singlyLinkedList->size)
{
addToSinglyLinkedList(singlyLinkedList,ptr,success);
return;
}
node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL)return;
node->ptr=ptr;
node->next=NULL;
if(index==0)
{
node->next=singlyLinkedList->start;
singlyLinkedList->start=node;
singlyLinkedList->size++;
if(success)*success=true;
return;
}

t=singlyLinkedList->start;
for(int i=0;i<index;i++)
{
p=t;
t=t->next;
}
node->next=t;
p->next=node;
singlyLinkedList->size++;
if(success)*success=true;
}

void * removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success)
{
SinglyLinkedListNode *p1,*p2;
void *ptr;
if(success)*success=false;
if(singlyLinkedList==NULL)return NULL;
if(index<0 || index>=singlyLinkedList->size)return NULL;
p1=singlyLinkedList->start;
for(int i=0;i<index;i++)
{
p2=p1;
p1=p1->next;
}
if(p1==singlyLinkedList->start && p1==singlyLinkedList->end)
{
//only one node and we have to remove that node
singlyLinkedList->start=NULL;
singlyLinkedList->end=NULL;
}else if(p1==singlyLinkedList->start)
{
singlyLinkedList->start=p1->next;
}else if(p1==singlyLinkedList->end)
{
singlyLinkedList->end=p2;
p2->next=NULL;
}else
{
p2->next=p1->next;
}
ptr=p1->ptr;
free(p1);
singlyLinkedList->size--;
if(success)*success=true;
return ptr;
}

void * getFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success)
{
SinglyLinkedListNode *t;
if(success)*success=false;
if(singlyLinkedList==NULL)return NULL;
if(index<0 || index>=singlyLinkedList->size)return NULL;
t=singlyLinkedList->start;
for(int i=0;i<index;i++)
{
t=t->next;
}
if(success)*success=true;
return t->ptr;
}

void appendToSinglyLinkedList(SinglyLinkedList *targetSinglyLinkedList,SinglyLinkedList * sourceSinglyLinkedList,bool *success)
{
SinglyLinkedListNode *s,*e,*t,*node;
bool done;
if(success) *success=false;
if(targetSinglyLinkedList==NULL) return;
if(sourceSinglyLinkedList==NULL || sourceSinglyLinkedList->size==0)
{
if(success) *success=true;
return;
}
s=NULL;
e=NULL;
done=true;
t=sourceSinglyLinkedList->start;
while(t!=NULL)
{
node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
if(node==NULL)
{
done=false;
break;
}
node->ptr=t->ptr;
node->next=NULL;
if(s==NULL)
{
s=node;
e=node;
}
else
{
e->next=node;
e=node;
}
t=t->next;
}
if(done==false)
{
while(s!=NULL)
{
node=s;
s=s->next;
free(node);
}
return;
}
if(targetSinglyLinkedList->start==NULL)
{
targetSinglyLinkedList->start=s;
targetSinglyLinkedList->end=e;
targetSinglyLinkedList->size=sourceSinglyLinkedList->size;
}
else
{
targetSinglyLinkedList->end->next=s;
targetSinglyLinkedList->end=e;
targetSinglyLinkedList->size+=sourceSinglyLinkedList->size;
}
if(success) *success=true;
}//funtion ends


SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *singlyLinkedList,bool *success)
{
SinglyLinkedListIterator singlyLinkedListIterator;
singlyLinkedListIterator.node=NULL;
if(success)*success=false;
if(singlyLinkedList==NULL)return singlyLinkedListIterator;//return iterator nhi uske 4 bytes return honge
if(singlyLinkedList->start==NULL)
{
if(success)*success=true;
return singlyLinkedListIterator;
}
if(success)*success=true;
singlyLinkedListIterator.node=singlyLinkedList->start;
return singlyLinkedListIterator;
}
bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator)
{
if(singlyLinkedListIterator==NULL)return false;
if(singlyLinkedListIterator->node==NULL)return false;
return true;
}
void *getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator,bool * success)
{
void *ptr=NULL;
if(success)*success=false;
if(singlyLinkedListIterator==NULL || singlyLinkedListIterator->node==NULL)return ptr;
ptr=singlyLinkedListIterator->node->ptr;
singlyLinkedListIterator->node=singlyLinkedListIterator->node->next;
if(success)*success=true;
return ptr;
}

#endif
