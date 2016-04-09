
#if 0

//The isEmpty function verifies if the queue is empty (1) or if it contains some elements (0)

int isEmpty(circularQueue_d *theQueue)
{
    if(theQueue->validItems==0)
        return(1);
    else
        return(0);
}

//The putItem function, verifies if there is space in the queue, and, in this case, add an item at the end of the queue (theQueue->last element). Then it updates the value of theQueue->last the modulus operator is needed to stay into the boundaries of the array.

int putItem(circularQueue_d *theQueue, int theItemValue)
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

int getItem(circularQueue_d *theQueue, int *theItemValue)
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
#endif

