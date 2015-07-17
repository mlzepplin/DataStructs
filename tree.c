#include<stdio.h>
#include<stdlib.h>
struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};
typedef struct tree node;
node *root=NULL;
node *builder(node *temp,int d);
void main(void)
{
	int i=1,info;
	for(i=0;i<5;i++)
	{
	printf("enter data");
	scanf("%d",&info);
	root=builder(root,info);
	}
	printf("success");
	printf("%d",root->right->left->data);
}
node *builder(node *temp,int d)
{
	if(temp==NULL)
	{
	temp=(node*)malloc(sizeof(node));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=d;
	return temp;
	}
	if(d<(temp)->data)
	temp->left=builder(temp->left,d);
	else
	temp->right=builder(temp->right,d);
	return temp;//MOST IMP STATEMENT ,as the current state is to be assigned to the previous's pointer
}
