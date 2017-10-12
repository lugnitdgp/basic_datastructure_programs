#include<stdio.h>
#include<malloc.h>
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int data)
{
	struct Node *node=(struct Node*)malloc(sizeof(struct Node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
};

void inorder(struct Node* node)
{
	if(node==NULL)
	return ;
	
		inorder(node->left);
		printf("%d ",node->data);
		inorder(node->right);
		
}

void preorder(struct Node* node)
{
	if(node==NULL)
	return ;
	
		printf("%d ",node->data);
		preorder(node->left);
		preorder(node->right);
		
}

void postorder(struct Node* node)
{
	if(node==NULL)
	return ;
	
		postorder(node->left);
		postorder(node->right);
		printf("%d ",node->data);

	
}

void copynode(struct Node *root,struct Node *copy_node)
{

	if(root==NULL)
	copy_node==NULL;
	
	copy_node->data=root->data;
	printf("\n%d",copy_node->data);
	copynode(root->left,copy_node->left);
	copynode(root->right,copy_node->right);
	preorder(copy_node);
}

void equivalence(struct Node *root,struct Node *root1)
{
	if(root==NULL&&root1==NULL)
	return;
	
	if(root->data==root1->data)
	{
		equivalence(root->left,root1->left);
		equivalence(root->right,root1->right);
	}
	else
	printf("\nNot Equivalent\n");
	
}


int main()
{
	struct Node *copy_node;
	copy_node=(struct Node*)malloc(sizeof(struct Node));
	copy_node=newNode(0);
	copy_node->left=newNode(0);
	copy_node->right=newNode(0);
	copy_node->left->left=newNode(0);
	copy_node->left->right=newNode(0);
	copy_node->right->left=newNode(0);
	copy_node->right->right=newNode(0);

	struct Node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(5);
	root->left->right=newNode(4);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	
	struct Node *root1=newNode(1);
	root1->left=newNode(2);
	root1->right=newNode(3);
	root1->left->left=newNode(15);
	root1->left->right=newNode(4);
	root1->right->left=newNode(6);
	root1->right->right=newNode(7);
	
	printf("Tree In Inorder Form:");
	inorder(root);
	printf("\n");
	
	printf("tree in preorder form:");
	preorder(root);
	printf("\n");
	
	printf("tree in postorder form :");
	postorder(root);
	
	copynode(root,copy_node);
	printf("\n\nNew tree: ");
	preorder(root1);
	printf("\n");
	
	equivalence(root,root1);
	return 0;
}
