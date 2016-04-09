//The queue will store a maximum of MAX_ITEMS items, if we'll try to put more items than MAX_ITEMS, the new items will be lost. To access the queue we will have 5 functions:

//    initialize
//    getItem
//    putItem
//    printQueue
//    isEmpty
//The initialize function clears the queue structure and it puts to zero both rear and front pointers
//The getItem function retrieves the next available item, the it moves the front pointer ahead by one element
//The putItem function puts a new item at the end of the queue and then it moves the rear pointer ahead by one element
//The printQueue function prints all valid data in the queue (not all data) valid data are those between front and rear pointers
//The isEmpty function returns true if rear and front pointers have the same values.
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS    10
//Here is the structure:
typedef struct circularQueue_s
{
    int     first;
    int     last;
    int     validItems;
    int     data[MAX_ITEMS];
} circularQueue_t;

// and the function protoypes:
void initializeQueue(circularQueue_t *theQueue);
int isEmpty(circularQueue_t *theQueue);
int putItem(circularQueue_t *theQueue, int theItemValue);
int getItem(circularQueue_t *theQueue, int *theItemValue);
void printQueue(circularQueue_t *theQueue);

//Now let's start coding the functions, the initializeQueue function, simply, sets to zero the structure:

void initializeQueue(circularQueue_t *theQueue)
{
    int i;
    theQueue->validItems  =  0;
    theQueue->first       =  0;
    theQueue->last        =  0;
    for(i=0; i<MAX_ITEMS; i++)
    {
        theQueue->data[i] = 0;
    }        
    return;
}

//The isEmpty function verifies if the queue is empty (1) or if it contains some elements (0)

int isEmpty(circularQueue_t *theQueue)
{
    if(theQueue->validItems==0)
        return(1);
    else
        return(0);
}

//The putItem function, verifies if there is space in the queue, and, in this case, add an item at the end of the queue (theQueue->last element). Then it updates the value of theQueue->last the modulus operator is needed to stay into the boundaries of the array.

int putItem(circularQueue_t *theQueue, int theItemValue)
{
    if(theQueue->validItems>=MAX_ITEMS)
    {
        printf("The queue is full num items: %d MAX_ITEMS: %d theItemValue: %d \n",
            theQueue->validItems,MAX_ITEMS, theItemValue);
        printf("You cannot add items\n");
        return(-1);
    }
    else
    {
        theQueue->validItems++;
        theQueue->data[theQueue->last] = theItemValue;
        theQueue->last = (theQueue->last+1)%MAX_ITEMS;
    }
    return(1);
}

//The getItem function returns -1 if the queue is empty, otherwise it takes the first element into the queue, then it updates the number of items and the first element of the queue (look at modulus operator).

int getItem(circularQueue_t *theQueue, int *theItemValue)
{
    if(isEmpty(theQueue))
    {
        printf("isempty\n");
        return(-1);
    }
    else
    {
        *theItemValue=theQueue->data[theQueue->first];
        theQueue->first=(theQueue->first+1)%MAX_ITEMS;
        theQueue->validItems--;
        return(0);
    }

}

//The printQueue functions, simply, prints validItems elements of theQueue starting from the theQueue->first element.
void printQueue(circularQueue_t *theQueue)
{
    int aux, aux1;
    aux  = theQueue->first;
    aux1 = theQueue->validItems;
    while(aux1>0)
    {
        printf("Element #%d = %d\n", aux, theQueue->data[aux]);
        aux=(aux+1)%MAX_ITEMS;
        aux1--;
    }
    return;
}

// here's the test implementation:
int main(void)
{
    int i;
    int readValue;
    circularQueue_t   myQueue;

    initializeQueue(&myQueue);
    for(i=1; i<MAX_ITEMS+1; i++)
    {
        putItem(&myQueue, i*5);
    }
    printQueue(&myQueue);
    
    for(i=1; i<MAX_ITEMS+1; i++)
    {
        getItem(&myQueue, &readValue);
        printf("readValue = %d\n", readValue);
    }
    printQueue(&myQueue);
    exit(1);
}

