#include<stdio.h>
#include<malloc.h>
//Declaring a Node.
struct Node
{
	int data; //data part of Node.
	struct Node *link; //pointer to next Node.
};

struct Node *header;  //First Node of list.(global)


void createlist(int n)
{
		struct Node *temp=header;	
		temp=(struct Node*)malloc(sizeof(struct Node)); //allocating memory to first Node.
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
		temp=(struct Node*)malloc(sizeof(struct Node)); //allocating memory to ith Node.
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

//DELETES A NODE POINTED BY POINTER P
int deletep(struct Node *p)
{
	if(header == NULL)return -2;
	Node* temp = header;
	if(p == header)
	{
		int x = header->data;
		header = NULL;
		return x;
	}
	
	while(temp->link != p )
		{
			temp = temp->link;
		}
	
	temp->link = p->link;
	p->link = NULL;
	int y = p->data;
	p = NULL;
	return y;

}

//display of linkedlist
void displaylist()
	{
		struct Node* temp=header;
		printf("\nElements Of List :");
		printf("%d ",temp->data);
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
	printf("\n");
	//deletes third node
	Node* temp = header->link->link;
	int x = deletep(temp);
	printf("\n%d deleteed\n",x);
	displaylist();
	return 0;
}
