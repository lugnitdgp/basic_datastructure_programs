#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node *stack;

int isempty(stack s)
{
	if(s==NULL)
	return 1;
	else 
	return 0;
}

stack push(stack s,int x)
{
	stack temp;
	temp=(stack)malloc(sizeof(struct node));
	if(temp==NULL)
	{ 
	printf("\nOut of Memory Space");
	exit(0);
	}
	temp->info=x;
	temp->next=s;
	s=temp;
	return s;
}


stack Pop(stack s)
{
	stack temp;
	int x;
	if(isempty(s))
	{
		printf("\nstack empty");
		exit(0);
	}
	temp=s;
	x=s->info;
	printf("\nPopped Element is :%d",x);
	s=s->next;
	free(temp);
	return s;
}


void display(stack s)
{
	stack ptr;
	ptr = s;
	printf("\n The Elements In The Stack Are\n");
	if (ptr ==NULL)
	{
		printf("\n Stack Empty\n\n");
		return ;
	}
	while (ptr!=NULL)
	{
		printf("%d\n",ptr->info);
		ptr=ptr->next;
	}
}
int main()
{
	stack s =NULL;
	int x;
	char ch='1';
	while(ch!='4')
	{
		printf("\n 1 - Push");
		printf("\n 2 - Pop");
		printf("\n 3 - Display");
		printf("\n 4 - Quit");
		printf("\nEnter your Choice");
		fflush(stdin);
		ch=getchar();
		switch(ch)
		{
			case '1':
				printf("\n enter the element to be pushed");
				scanf("%d",&x);
				s=push(s,x);
				break;
			case '2':
				s=Pop(s);
				break ;
			case '3':
				display(s);
				break;
				case '4':
				break ;
			default:
				printf("\n Wrong Choice Try Again");
				break;
		}
	}
	return 0;
}
