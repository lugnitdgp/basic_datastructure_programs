#include<stdio.h>
#include<malloc.h>
//Declaring a node.
struct Node
{
	int data; //data part of node.
	struct Node *link; //pointer to next node.
};

struct Node *header;  //First Node of list.(global)


void createlist(int n)
	{
			struct Node *temp=header;	
			temp=(struct Node*)malloc(sizeof(struct Node)); //allocating memory to first node.
			if(temp==NULL)
			printf("Overflow"); //if there is no space in memory
			temp->link=NULL;
			int i=1;
			printf("Enter The Value Of Node%d: ",i);
			scanf("%d",&temp->data);
			if(header==NULL)
			{
				temp->link=NULL;
				header=temp;
			}
	         i=i+1;
		while(i<=n)
		{
			struct Node* temp1=temp;
			temp=(struct Node*)malloc(sizeof(struct Node)); //allocating memory to ith node.
			if(temp==NULL)
			printf("Overflow");
			printf("Enter The Value for Node%d: ",i);
			scanf("%d",&temp->data);
			temp1->link=temp;
			temp->link=NULL;
			i=i+1;
		}
	temp->link=header;
	
	}


//display of linkedlist
void displaylist()
	{
		struct Node* temp=header;
		printf("\nElements Of List :");
		printf("%d",temp->data);
		temp=temp->link;
		while(temp!=header)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}
		
	}



//Main Body
int main()
{
	int num;
	printf("Enter The Number Of Nodes For Linkedlist: ");
	scanf("%d",&num);
	createlist(num);
	displaylist();
	return 0;
}
