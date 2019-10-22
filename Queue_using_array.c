#include<stdio.h>
#include<malloc.h>
#include<limits.h>
//structure of Queue
struct queue
{
	int front=-1,rear=-1,size=0;
	unsigned capacity;
	int *array;
};

struct queue *create(unsigned capacity)
{
struct queue *Queue=(struct queue*)malloc(sizeof(struct queue));
Queue->capacity=capacity;
Queue->front=Queue->size=0;
Queue->rear=capacity-1;
Queue->array=(int*)malloc(capacity*sizeof(int));
return Queue;
}

int isEmpty(struct queue *Queue)
{
	return(Queue->size==0);
}

int isFull(struct queue *Queue)
{
	return(Queue->size==Queue->capacity);
}

void enqueue(struct queue *Queue,int n)
{
	if(isFull(Queue))
	return;
	Queue->rear=(Queue->rear+1)%Queue->capacity;
	Queue->array[Queue->rear]=n;
	Queue->size=Queue->size+1;
	printf("\nEnqueued Element%d",n);
}

int dequeue(struct queue *Queue)
{
	if (isEmpty(Queue))
	return 0;
	int item=Queue->array[Queue->front];
	Queue->front=(Queue->front+1)%Queue->capacity;
	Queue->size=Queue->size-1;
	return(item);
}

int front(struct queue *Queue)
{
int item=Queue->array[Queue->front];
return(item);	
}

int rear( struct queue *Queue)
{
	int item=Queue->array[Queue->rear];
	return(item);
}

int main()
{
	struct queue *Queue=create(50);
	enqueue(Queue,12);
	enqueue(Queue,13);
	enqueue(Queue,14);
	enqueue(Queue,15);
	enqueue(Queue,16);
	
	dequeue(Queue);
	printf("\nElement At front %d",front(Queue));
	printf("\nElement At Rear %d",rear(Queue));
	return 0;	
}
