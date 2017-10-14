#include<stdio.h>
#include<malloc.h>

//Declaring a node.
struct Node
{
	int data; //data part of node.
	struct Node *link; //pointer to next node.
};


struct Node *header;  //First Node of list.(global)

//creation of linkedlist
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
	
	
	}


//display of linkedlist
void displaylist()
	{
		struct Node* temp=header;
		printf("\nElements Of List:");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->link;
		}
		
	}

//to delete  a node	
void delete_node(int num,int del)
{
	struct Node* temp=header;
	struct Node* prev;
	int i=1;
	if(del==1)
	{
		header=temp->link;
		free(temp);
	}
    
	else if(del<=num)
	{
	    while(i<del)
	    {
		printf("hello ");
		prev=temp;
		temp=temp->link;
		i=i+1;
	    }
	prev->link=temp->link;
	free(temp);
	temp=header;
	}
displaylist();
}


//Main Body
int main()
{
	int num,del;
	printf("Enter The Number Of Nodes For Linkedlist: ");
	scanf("%d",&num);
	createlist(num);
	displaylist();
	printf("\nEnter The Node You Want To delete: ");
	scanf("%d",&del);
	delete_node(num,del);
	return 0;
}