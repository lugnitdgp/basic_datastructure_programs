#include<stdio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};

void insertpos(int,int);
void insertbegin(int);
void insertend(int);
struct Node *head=NULL;
	
void createlist(int n)
{
	struct Node *temp=head;
	temp=(struct Node*)malloc(sizeof (struct Node));
	int i=1;
	printf("\nEnter The Data For Node %d:",i);
	scanf("%d",&temp->data);

	if(head==NULL)
	{
	temp->prev=NULL;
	temp->next=NULL;
	head=temp;
	}
	i++;
	while(i<=n)
	{
	struct Node *temp1=temp;
	temp=(struct Node*)malloc(sizeof(struct Node*));
 	printf("\nEnter The Data for Node %d:",i);
	scanf("%d",&temp->data);
	temp1->next=temp;	
	temp->prev=temp1;
	i++;
	}
	temp=NULL;
}

void display()
{
	struct Node *temp=head;
	while(temp!=NULL)
	{
	printf("%d  ",temp->data);
	temp=temp->next;
    }
}
void search(int s,int n)
{
	int pos,f=0;
	struct Node *temp=head;
	while(temp!=NULL)
	{
	if(temp->data==s)
		{
		printf("Element Is Present In List:");
		f=1;
		break;
    	}
	temp=temp->next;
	}
     	
	   	 	
 	if(f==0)
			{   
				printf("Number Not Present");
				printf("\nEnter Position For Element:");
				scanf("%d",&pos);
				if(pos==1)
				insertbegin(s);
				if(pos>1&&pos<n)
				insertpos(pos,s);
				if(pos==n+1)
				insertend(s);
				
			}
			

}

void insertpos(int pos,int s)
{
	struct Node *temp=head;
	int i=1;
	struct Node *temp1;
	while(i<pos)
	{
	  temp1=temp;
         	  temp=temp->next;
	  i++;
		
	}
	struct Node *new_node;
	new_node=(struct Node*)malloc(sizeof(struct Node*));
	new_node->data=s;
	temp1->next=new_node;
	new_node->prev=temp1;
	new_node->next=temp;
	temp->prev=new_node;
	display();
	
}

void insertbegin(int s)
{
	struct Node *new_node;
	new_node=(struct Node*)malloc(sizeof(struct Node*));
	new_node->data=s;
	new_node->prev=NULL;
	new_node->next=head;
	head->prev=new_node;
	head=new_node;
	display();
}


void insertend(int s)
{
	struct Node *temp=head;
	struct Node* prev1;
	while(temp!=NULL)
	{
	 prev1=temp;
	temp=temp->next;	
	}
	struct Node *new_node;
	new_node=(struct Node*)malloc(sizeof(struct Node*));
	new_node->data=s;
	new_node->prev=prev1;
	new_node->next=NULL;
	temp->next=new_node;
	temp=new_node;
	display();
}

void delete_node(int del)
{
	struct Node *temp=head;
	if (head->data==del)
	{
	if(head->next==NULL){
		free(temp);
		head=NULL;
	}
	else{
		head->next->prev=NULL;
		head=head->next;
		free(temp);
	}
	}
	else{
	while(temp->next!=NULL){
	if(temp->data==del){
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
	else temp=temp->next;
	}
	if(temp->data==del){
	temp->prev->next=NULL;
	free(temp);
	}
	}
	
	display();
}

int main()
{
	int n,s;
	printf("To Create List");
	printf("\nEnter The Number Of Elements In List: ");
	scanf("%d",&n);
	createlist(n);
	//printf("%d",head->data);
	display();
	printf("\nEnter A number To search");
	scanf("%d",&s);
	search(s,n);
	printf("\nEnter A Number To delete");
	int del;
	scanf("%d",&del);
	delete_node(del);
	return 0;
}


 



