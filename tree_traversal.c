//Tree Traversal
//C++ Implementation
#include<stdio.h>
#include<malloc.h>
struct Node //Node Initialization
{
	int data; //Node data
	struct Node *left; //Pointer to left child node
	struct Node *right; //Pointer to right child node
};

struct Node *newNode(int data)
{
	struct Node *node=(struct Node*)malloc(sizeof(struct Node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
};

void inorder(struct Node* node)//recursive function to traverse nodes using inorder method
{
	if(node==NULL)
	return ;

		inorder(node->left);
		printf("%d ",node->data);
		inorder(node->right);

}

void preorder(struct Node* node)//recursive function to traverse nodes using preorder method
{
	if(node==NULL)
	return ;

		printf("%d ",node->data);
		preorder(node->left);
		preorder(node->right);

}

void postorder(struct Node* node)//recursive function to traverse nodes using postorder method
{
	if(node==NULL)
	return ;

		postorder(node->left);
		postorder(node->right);
		printf("%d ",node->data);


}

void copynode(struct Node *root,struct Node *copy_node) //Function to create a copy of tree
{

	if(root==NULL){

	copy_node=NULL;
    return ;

	}
	copy_node->data=root->data;
	printf(" %d",copy_node->data);
// 1st recur
	copynode(root->left,copy_node->left);
// 2nd recur
	copynode(root->right,copy_node->right);

}

void equivalence(struct Node *root,struct Node *root1) //Function to check if two trees are equal
{
	if(root==NULL&&root1==NULL)
	return;

	if(root->data==root1->data)
	{
		equivalence(root->left,root1->left);
		equivalence(root->right,root1->right);

	}
	else
	printf("\nRoot and Root1 are Not Equivalent\n");

}

//Driver Function
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

    printf("Tree Name: Root");
	printf("\n");
	printf("\n");

	printf("Tree in inorder Form:");
	inorder(root);
	printf("\n");

	printf("Tree in preorder form:");
	preorder(root);
	printf("\n");

	printf("Tree in postorder form :");
	postorder(root);
    printf("\n");

    printf("\nCopy of binary tree 'Root' in preorder form:");
	copynode(root,copy_node);
	printf("\n");

	printf("\n\nNew tree (Root1): ");
	preorder(root1);
	printf("\n");

	//comparison of Root & Root1
	equivalence(root,root1);
	return 0;
}
