#ifndef __HS_DLL_C
#define __HS_DLL_C
#include<hs_dll.h>
#include<stdlib.h>
DoublyLinkedList * createDoublyLinkedList(bool *success)
{
if(success)*success=false;
DoublyLinkedList *doublyLinkedList;
doublyLinkedList=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;
if(success)*success=true;
return doublyLinkedList;
}
void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL)return;
clearDoublyLinkedList(doublyLinkedList);//for all the data nodes
free(doublyLinkedList);//for main node
}
int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL)return 0;
return doublyLinkedList->size;
}
void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList)
{
if(doublyLinkedList==NULL)return;
DoublyLinkedListNode *node;
while(doublyLinkedList->start!=NULL)
{
node=doublyLinkedList->start;
doublyLinkedList->start=doublyLinkedList->start->next;
free(node);
}
doublyLinkedList->size=0;
}
void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success)
{
if(success)*success=false;
if(doublyLinkedList==NULL)return;
DoublyLinkedListNode *doublyLinkedListNode;
doublyLinkedListNode=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(doublyLinkedListNode==NULL)return;
doublyLinkedListNode->next=NULL;
doublyLinkedListNode->prev=NULL;
doublyLinkedListNode->ptr=ptr;
if(doublyLinkedList->start==NULL)
{
//no node is present
doublyLinkedList->start=doublyLinkedList->end=doublyLinkedListNode;
}
else
{
//atleast one node is present
doublyLinkedListNode->prev=doublyLinkedList->end;
doublyLinkedList->end->next=doublyLinkedListNode;
doublyLinkedList->end=doublyLinkedListNode;

}
doublyLinkedList->size++;
if(success)*success=true;
return;
}
void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success)
{
DoublyLinkedListNode *t,*p,*node;
if(success)*success=false;
if(doublyLinkedList==NULL)return;
if(index<0 || index >doublyLinkedList->size)return;
if(index ==doublyLinkedList->size)
{
addToDoublyLinkedList(doublyLinkedList,ptr,success);
return;
}
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)return;
node->ptr=ptr;
node->next=NULL;
node->prev=NULL;
if(index==0)
{
doublyLinkedList->start->prev=node;
node->next=doublyLinkedList->start;
doublyLinkedList->start=node;
doublyLinkedList->size++;
if(success)*success=true;
return;
}

t=doublyLinkedList->start;
for(int i=0;i<index;i++)
{
p=t;
t=t->next;
}
node->next=t;
p->next=node;
node->prev=p;
doublyLinkedList->size++;
if(success)*success=true;
}

void * removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
DoublyLinkedListNode *p1,*p2;
void *ptr;
if(success)*success=false;
if(doublyLinkedList==NULL)return NULL;
if(index<0 || index>=doublyLinkedList->size)return NULL;
p1=doublyLinkedList->start;
for(int i=0;i<index;i++)
{
p2=p1;
p1=p1->next;
}
if(p1==doublyLinkedList->start && p1==doublyLinkedList->end)
{
//only one node and we have to remove that node
doublyLinkedList->start=NULL;
doublyLinkedList->end=NULL;
}else if(p1==doublyLinkedList->start)
{
doublyLinkedList->start=p1->next;
doublyLinkedList->start->prev=NULL;
}else if(p1==doublyLinkedList->end)
{
doublyLinkedList->end=p2;
p2->next=NULL;
}else
{
p1->next->prev=p2;
p2->next=p1->next;
}
ptr=p1->ptr;
free(p1);
doublyLinkedList->size--;
if(success)*success=true;
return ptr;
}

void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)
{
DoublyLinkedListNode *t;
if(success)*success=false;
if(doublyLinkedList==NULL)return NULL;
if(index<0 || index>=doublyLinkedList->size)return NULL;
t=doublyLinkedList->start;
for(int i=0;i<index;i++)
{
t=t->next;
}
if(success)*success=true;
return t->ptr;
}

void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList * sourceDoublyLinkedList,bool *success)
{
DoublyLinkedListNode *s,*e,*t,*node;
bool done;
if(success) *success=false;
if(targetDoublyLinkedList==NULL) return;
if(sourceDoublyLinkedList==NULL || sourceDoublyLinkedList->size==0)
{
if(success) *success=true;
return;
}
s=NULL;
e=NULL;
done=true;
t=sourceDoublyLinkedList->start;
while(t!=NULL)
{
node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
if(node==NULL)
{
done=false;
break;
}
node->ptr=t->ptr;
node->next=NULL;
node->prev=NULL;
if(s==NULL)
{
s=node;
e=node;
}
else
{
e->next=node;
node->prev=e;
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
if(targetDoublyLinkedList->start==NULL)
{
targetDoublyLinkedList->start=s;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size=sourceDoublyLinkedList->size;
}
else
{
targetDoublyLinkedList->end->next=s;
s->prev=targetDoublyLinkedList->end;
targetDoublyLinkedList->end=e;
targetDoublyLinkedList->size+=sourceDoublyLinkedList->size;
}
if(success) *success=true;
}//funtion ends

DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success)
{
DoublyLinkedListIterator doublyLinkedListIterator;
doublyLinkedListIterator.node=NULL;
if(success)*success=false;
if(doublyLinkedList==NULL)return doublyLinkedListIterator;//return iterator nhi uske 4 bytes return honge
if(doublyLinkedList->start==NULL)
{
if(success)*success=true;
return doublyLinkedListIterator;
}
if(success)*success=true;
doublyLinkedListIterator.node=doublyLinkedList->start;
return doublyLinkedListIterator;
}
bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator)
{
if(doublyLinkedListIterator==NULL)return false;
if(doublyLinkedListIterator->node==NULL)return false;
return true;
}
void *getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool * success)
{
void *ptr=NULL;
if(success)*success=false;
if(doublyLinkedListIterator==NULL || doublyLinkedListIterator->node==NULL)return ptr;
ptr=doublyLinkedListIterator->node->ptr;
doublyLinkedListIterator->node=doublyLinkedListIterator->node->next;
if(success)*success=true;
return ptr;
}

DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,bool *success)
{
DoublyLinkedListReverseIterator doublyLinkedListReverseIterator;
doublyLinkedListReverseIterator.node=NULL;
if(success)*success=false;
if(doublyLinkedList==NULL)return doublyLinkedListReverseIterator;//return iterator nhi uske 4 bytes return honge
if(doublyLinkedList->start==NULL)
{
if(success)*success=true;
return doublyLinkedListReverseIterator;
}
if(success)*success=true;
doublyLinkedListReverseIterator.node=doublyLinkedList->end;
return doublyLinkedListReverseIterator;
}
bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator)
{
if(doublyLinkedListReverseIterator==NULL)return false;
if(doublyLinkedListReverseIterator->node==NULL)return false;
return true;
}
void *getPreviousElementFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,bool * success)
{
void *ptr=NULL;
if(success)*success=false;
if(doublyLinkedListReverseIterator==NULL || doublyLinkedListReverseIterator->node==NULL)return ptr;
ptr=doublyLinkedListReverseIterator->node->ptr;
doublyLinkedListReverseIterator->node=doublyLinkedListReverseIterator->node->prev;
if(success)*success=true;
return ptr;
}




#endif