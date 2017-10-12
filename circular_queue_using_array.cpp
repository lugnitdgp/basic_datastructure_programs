#include<stdio.h>
#define MAXQ 100
typedef struct
{
	int front ,rear;
	int items[MAXQ];
	
}queue;

int isempty(queue * q)
{
	if(q->front==-1)
	return 1;
	else 
	return 0;
}

int isfull(queue *q)
{
	if(q->front ==(q->rear+1)%MAXQ)
	return 1;
	else
	return 0;
}
int insert(queue *q,int x)
{
	if (isfull(q))
	{
		printf("\nqueue is full");
		return 0 ;
	}
	if(q->front==-1)
	{
		q->front=0;
		q->rear=0;
	}
	else
	q->rear =(q->rear+1)%MAXQ;
	q->items[q->rear] = x;
}

int Delete(queue *q)
{
	int x;
	if(isempty(q))
	{
		printf("\nqueue empty");
		return 0;
	}
	x=q->items[q->front];
	if(q->front == q->rear)
	{
		q->front =-1;
		q->rear=-1;
		
	}
	else
	q->front=(q->front +1)%MAXQ;
	return x;
}
void display(queue *q)
{
	int i;
	if (isempty(q))
	{
		printf("\nqueue empty");
		return;
	}
	else
	printf("\nElements In the Queue Are:\n");
	if(q->rear>=q->front)
	{
		for(i=q->front;i<=q->rear;i++)
		printf("%d\n",q->items[i]);
	}
	else
	for(i=q->front;i<=MAXQ;i++)
	printf("%d\n",q->items[i]);
	for(i=0;i<=q->rear;i++)
	printf("%d\n",q->items[i]);
	
}

int main()
{
	queue q;
	int x;
	char ch='1';
	q.front=-1;
	q.rear=-1;
		while(ch!='4')
	{
		printf("\n 1 - Insert");
		printf("\n 2 - Delete");
		printf("\n 3 - Display");
		printf("\n 4 - Quit");
		printf("\nEnter your Choice :");
		fflush(stdin);
		scanf("%c",&ch);
		
		switch(ch)
		{
			case '1':
				printf("\nEnter The Element To Be inserted :");
				scanf("%d",&x);
				insert(&q,x);
				break;
				case '2':
					x=Delete(&q);
					printf("\nDeleted Element Is %d\n:",x);
					break;
					case '3':
						display(&q);
						break ;
						case '4':
							break;
							default:
								printf("\nYou Entered Wrong Choice.Try again!");
					
		
		}
	}
	return 0;
}

