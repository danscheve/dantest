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
typedef struct circularQueue_d  //try making this dynamic
{
    int     data;
    struct circularQueue_d *next;

} circularQueue_d;

circularQueue_d *front=NULL, *rear=NULL, *temp;

// and the function protoypes:
void initializeQueueElement(circularQueue_d *qNode);
void removeQueueElement(circularQueue_d *qNode);
void printQueue();

void insert_(void);
void remove_(void);

//Now let's start coding the functions, the initializeQueue function, simply, sets to zero the structure:

void initializeQueueElement(circularQueue_d *qNode)
{
    if (rear == NULL)
      front=rear= qNode;
    else
    {
      rear->next = qNode;
      rear = qNode;
    }
    rear->next = front;
}

void removeQueueElement(circularQueue_d *qNode)
{
  circularQueue_d *tmpQ = front;
  if(front)
  {
    if(front == rear)
    {
      front = rear = NULL;
    }
    else
    {
      front = front->next;
      rear->next = front;
    }
    tmpQ->next = NULL;
    printf("freeing @ %p\n", tmpQ);
    free(tmpQ);
  }
}
void printQueue()
{
    circularQueue_d *tmpQ = front;
    while(tmpQ)
    {
      printf("data: %d\n", tmpQ->data);
      tmpQ=tmpQ->next;
      if(tmpQ == front) break;
    }

}
void _insert(void)
{
  circularQueue_d *insElement = (circularQueue_d *)malloc(sizeof(circularQueue_d));
  initializeQueueElement(insElement);
  printf ("New element allocated at %p\n",insElement);
  printf ("\nEnter data for new element: ");
  scanf ("%d", &insElement->data);
  printf("node at %p: %d\n", insElement, insElement->data);
}


void _remove(void)
{
  int tmpData;
  circularQueue_d *tmp;
  printf("\nEnter data of element to remove : ");
  scanf("%d",&tmpData);
  tmp = front;

  do
  {
    if(tmp)
    {
      if (tmpData == front->data)
      {
        printf("matched %d with %d at %p\n", tmpData, front->data, tmp);
        removeQueueElement(tmp);
        break;
      }
      else
        tmp = tmp->next;
    }else 
    {
      printf("NULL reached\n");
      break; 
    }
  }while(tmp != rear);
  printf("Queue at end of remove\n");
  printQueue();
}


// here's the test implementation:
int main(void)
{
  int i;
  circularQueue_d *myQueue, *printQ;

  for(i=0; i<MAX_ITEMS; i++)
  {
    myQueue = (circularQueue_d *)malloc(sizeof(circularQueue_d));
    initializeQueueElement(myQueue);
    myQueue->data = i*5;
  }
  printQ = front;
  while (printQ)
  {
    printf("Element %d\n", printQ->data);
    printQ = printQ->next;
    if(printQ==front) break;
  }
  printQueue();
  while (front)
  {
    printf("front: %p front->next: %p\n", front, front->next);
    removeQueueElement(myQueue);
  }
  int ch;
  do
  {	
    //system("clear"); 
    printf("\npress 1 to create an element : ");
    printf("\npress 2 to delete an element : ");
    printf("\npress 3 to traverse the queue : ");
    printf("\npress 4 to exit  : ");
    printf("\nEnter choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        _insert();
      break;
      case 2:
        _remove();
      break;
      case 3:
        printQueue();
      break;
      case 4:
        exit(1);
      default:
        printf("\nInvalid choice :");
      }
      getchar();
    } while(1);
}

