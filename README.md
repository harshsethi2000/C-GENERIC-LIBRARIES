# **C-GENERIC LIBRARIES**

 Unlike C++ and Java, the C language lacks any support for generic programming.Our library results from the idea to create a generic library of reusable algorithms in C language that an user can directly use for any data type.

 This library contains-

1. [Generic Singly Linked List](#generic-singly-linked-list)
2. [Generic Doubly Linked List](#generic-doubly-linked-list)
3. [Generic Stack](#generic-stack)
4. [Generic Queue](#generic-queue)
    

## **Generic Singly Linked List**
 This library contains the following function than an user can directly use to perform action on singly linked list
 
 
 >SinglyLinkedList * createSinglyLinkedList(bool *success)

    User can use this function to create Singly Linked List.
    then can perfrom the operation on that list. here success denotes wether a list is created or not.

    

 >void addToSinglyLinkedList(SinglyLinkedList *sll, void *ptr, bool *success)

    User can use this function to add data at the end of the Singly Linked List.

 >void insertIntoSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,void *ptr,bool *success)
    
     User can use this function to add data at any valid position in the Singly Linked List.


 >void * removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success)

    
    User can use this function to remove data from Singly Linked List


 >int getSizeOfSinglyLinkedList(SinglyLinkedList *singlyLinkedList)

    User can use this function to get the size of Singly Linked List

    


 >void * getFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success)

    User can use this function to get the data from Singly Linked List



 >void appendToSinglyLinkedList(SinglyLinkedList *targetSinglyLinkedList,SinglyLinkedList * sourceSinglyLinkedList,bool *success)

    User can use this function to append two Singly Linked List

 >void clearSinglyLinkedList(SinglyLinkedList *singlyLinkedList)

    User can use this function to clear Singly Linked List

 >void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList)

    User can use this function to destroy the Singly Linked List

>SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *singlyLinkedList,bool *success)

    user can use this function to get the reference of the Singly linked list Iterator.

> bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator)

    user can use this function to whether it has next element in singly linked list or not.

>void *getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator,bool * success)

    user can use this function to get next element from singly linked list.



## Usage

```C
//singly.c
#include<hs_sll.h> 
#include<stdio.h>
int main()
{
    SinglyLinkedList * singlyLinkedList;
    bool *success;
    int *data;
    singlyLinkedList= createSinglyLinkedList(&success);
    if(success==false)
    {
        printf("Cannot Create the list");
        return 0;
    }
    //To add data in SinglyLinkedList
    int a=100;
    addToSinglyLinkedList(singlyLinkedList,&a,&success);
    if(success==false)printf("data is not added\n");
    else printf("% d is successfully added",a);

    //To insert data in singlyLinkedList
    int b=200;
    insertIntoSinglyLinkedList(singlyLinkedList,0,&b,&success);
    if(success==false)printf("data is not added\n");
    else printf("% d is successfully added",a);

    //to get size of Singly Linked List
    int size=getSizeOfSinglyLinkedList(singlyLinkedList);

    //to iterate in Singly Linked List
    SinglyLinkedListIterator iter;
    iter=getSinglyLinkedListIterator(singlyLinkedList,&success);
    if(succ==true)
    {
     while(hasNextInSinglyLinkedList(&iter))
     {
      data=(int *)getNextElementFromSinglyLinkedList(&iter,&success);
      printf("%d\n",*data);
     }
    }

    return 0;
}
```
**To Compile the above code using mingw -**

    gcc singly.c -o singly.exe -I ..\include -L..\lib -lhs
    //hs is name of the library


## **Generic Doubly Linked List**
 This library contains the following function than an user can directly use to perform action on Doubly linked list
 
 
 >DoublyLinkedList * createDoublyLinkedList(bool *success)

    User can use this function to create Doubly Linked List.
    then can perform the operation on that list. here success denotes wether a list is created or not.

    

 >void addToDoublyLinkedList(DoublyLinkedList *sll, void *ptr, bool *success)

    User can use this function to add data at the end of the Doubly Linked List.

 >void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success)
    
     User can use this function to add data at any valid position in the Doubly Linked List.


 >void * removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)

    
    User can use this function to remove data from Doubly Linked List


 >int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList)

    User can use this function to get the size of Doubly Linked List

    


 >void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)

    User can use this function to get the data from Doubly Linked List



 >void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList * sourceDoublyLinkedList,bool *success)

    User can use this function to append two Doubly Linked List

 >void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList)

    User can use this function to clear Doubly Linked List

 >void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList)

    User can use this function to destroy the Doubly Linked List

>DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success)

    user can use this function to get the reference of the doubly linked list Iterator.

> bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator)

    user can use this function to check whether it has next element in doubly linked list or not.

>void *getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool * success)

    user can use this function to get next element from doubly linked list.

>DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,bool *success)

    user can use this function to get the reference of the doubly linked list Reverse Iterator.

> bool hasPreviousInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator)

    user can use this function to check whether it has previous element in doubly linked list or not.

>void *getPreviousElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool * success)

    user can use this function to get previous element from doubly linked list.



## Usage

```C
//Doubly.c
#include<hs_dll.h> 
#include<stdio.h>
int main()
{
    DoublyLinkedList * doublyLinkedList;
    bool *success;
    int *data;
    doublyLinkedList= createDoublyLinkedList(&success);
    if(success==false)
    {
        printf("Cannot Create the list");
        return 0;
    }
    //To add data in DoublyLinkedList
    int a=100;
    addToDoublyLinkedList(doublyLinkedList,&a,&success);
    if(success==false)printf("data is not added\n");
    else printf("% d is successfully added",a);

    //To insert data in doublyLinkedList
    int b=200;
    insertIntoDoublyLinkedList(doublyLinkedList,0,&b,&success);
    if(success==false)printf("data is not added\n");
    else printf("% d is successfully added",a);

    //to get size of Doubly Linked List
    int size=getSizeOfDoublyLinkedList(doublyLinkedList);

    //to iterate in Doubly Linked List
    DoublyLinkedListIterator iter;
    iter=getDoublyLinkedListIterator(doublyLinkedList,&success);
    if(success==true)
    {
     while(hasNextInDoublyLinkedList(&iter))
     {
      data=(int *)getNextElementFromDoublyLinkedList(&iter,&success);
      printf("%d\n",*data);
     }

   // Reverse Iterator in doubly linked list
   DoublyLinkedListReverseIterator revIter;
   revIter=getDoublyLinkedListReverseIterator(doublyLinkedList,&success);
   if(success==true)
   {
     while(hasPreviousInDoublyLinkedList(&revIter))
     {
      data=(int *)getPreviousElementFromDoublyLinkedList(&revIter,&success);
      printf("%d\n",*data);

     }
   }


    }

    return 0;
}
```
**To Compile the above code using mingw -**

    gcc doubly.c -o doubly.exe -I ..\include -L..\lib -lhs
    //hs is name of the library


## **Generic Stack**
 This library contains the following function than an user can directly use to perform action on Stack
 
 
 >Stack * createStack(bool *success);

    User can use this function to create Stack and
    then can perform the operation on that stack.

    

 >void pushOnStack(Stack *stack,void *ptr,bool *success);

    User can use this function to push data in stack.

 >void * popFromStack(Stack *stack,bool *success);
    
     User can use this function to pop data from stack.


 >bool isStackEmpty(Stack *stack);
    
    User can use this function to check whether the stack is empty or not.


 >void * elementAtTop(Stack *stack,bool *success);

    User can use this function to view the top element in stack.

    


 >int getSizeOfStack(Stack *stack);

    User can use this function to get the size of stack.



 >void clearStack(Stack *stack);

    User can use this function to clear the stack.

 

 >void destroyStack(Stack *stack);

    User can use this function to destroy the stack.

>

## Usage

```C
//Stack.c
#include<hs_stack.h> 
#include<stdio.h>
int main()
{
    Stack *stack;
    bool success;
    //to create stack
    stack=createStack(&success);
    if(success==false)
    {
      printf("Stack not created\n");
      return 0;
    }
    printf("Stack is created\n");
    //to push data in stack
    int a=100;
    int b=200;
    int c=300;
    pushOnStack(stack,&a,&success);
    pushOnStack(stack,&b,&success);
    pushOnStack(stack,&b,&success);

    //to find the size of the stack
    printf("Size of stack is %d \n",getSizeOfStack(stack));

    //use of pop and isStackEmpty function
    int *data;
    while(!isStackEmpty(stack))
    {
       data=popFromStack(stack,&success);
       printf("data is %d\n",*data);
    }
    
    //to clear and destroy the stack
    clearStack(stack);
    destroyStack(stack);
    return 0;
}
```



**To Compile the above code using mingw -**

    gcc stack.c -o stack.exe -I ..\include -L..\lib -lhs
    //hs is name of the library


## **Generic Queue**
 This library contains the following function than an user can directly use to perform action on Queue
 
 
 >Queue * createQueue(bool *success);

    User can use this function to create Queue and
    then can perform the operation on that queue.

    

 >void addToQueue(Queue *queue,void *ptr,bool *success);

    User can use this function to add data in queue.

 >void * removeFromQueue(Queue *queue,bool *success);
    
     User can use this function to remove data from queue.


 >bool isQueueEmpty(Queue *queue);
    
    User can use this function to check whether the queue is empty or not.


 >void * elementAtTopOfTheQueue(Queue *queue,bool *success);

    User can use this function to view the top element of queue.

    


 >int getSizeOfQueue(Queue *queue);

    User can use this function to get the size of queue.



 >void clearQueue(Queue *queue);

    User can use this function to clear the data from queue.

 

 >void destroyQueue(Queue *queue);

    User can use this function to destroy the queue.

>

## Usage

```C
//Queue.c
#include<hs_queue.h> 
#include<stdio.h>
int main()
{
    Queue *queue;
    bool success;
    //to create queue
    queue=createQueue(&success);
    if(success==false)
    {
      printf("Queue not created\n");
      return 0;
    }
    printf("Queue is created\n");
    //to push data in queue
    int a=100;
    int b=200;
    int c=300;
    pushOnQueue(queue,&a,&success);
    pushOnQueue(queue,&b,&success);
    pushOnQueue(queue,&b,&success);

    //to find the size of the queue
    printf("Size of queue is %d \n",getSizeOfQueue(queue));

    //use of pop and isQueueEmpty function
    int *data;
    while(!isQueueEmpty(queue))
    {
       data=popFromQueue(queue,&success);
       printf("data is %d\n",*data);
    }
    
    //to clear and destroy the queue
    clearQueue(queue);
    destroyQueue(queue);
    return 0;
}
```
**To Compile the above code using mingw -**

    gcc queue.c -o queue.exe -I ..\include -L..\lib -lhs
    //hs is name of the library




## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

