#include<stdio.h>
#include<stdlib.h>


struct RBTreeNode 
{
	int color/*0-Red,1-Black*/, value;
	struct RBTreeNode *left, *right, *parent;
};
int getcolor(struct RBTreeNode *node)
{
	if(node==NULL)
		return 1;
	else 
		return node->color;
}
struct RBTreeNode * single_right(struct RBTreeNode *root)
{
	struct RBTreeNode *LC;
	LC=gp->left;
	//gp->right=RC->left;
	LC->right=gp;
	(gp->color)=1-(gp->color);
	(LC->color)=1-(LC->color);	
	return LC;
}

struct RBTreeNode *single_left(struct RBTreeNode *gp)
{
	struct RBTreeNode *RC;
	RC=gp->right;
	//gp->right=RC->left;
	RC->left=gp;
	(gp->color)=1-(gp->color);
	(RC->color)=1-(RC->color);	
	return RC;
}
struct RBTreeNode *double_left_right(struct RBTreeNode *gp)
{
	struct RBTreeNode *RC,*LC,*p;
	p=gp->left;
	RC=p->right;
	RC->left=p;
	LC=gp->left;
	//gp->right=RC->left;
	LC->right=gp;
	(gp->color)=1-(gp->color);
	(LC->color)=1-(LC->color);	
	return root;
}
struct RBTreeNode *double_right_left(struct RBTreeNode *root)
{
	root->right=single_right(root->right);
	root=single_left(root);
	return root;
} 
struct RBTreeNode *getUncle(struct RBTreeNode *newnode)
{
/* Its sure that uncle exists*/
	struct RBTreeNode *p,*gp;
	p=newnode->parent;
	gp=p->parent;
	if(p==gp->left)	return gp->right;
	else return gp->left;
	
}

struct RBTreeNode * insert(struct RBTreeNode * r,int v)
{
	struct RBTreeNode * newnode,*p,*uncle,*gp;
	newnode=(struct RBTreeNode*)malloc(sizeof(struct RBTreeNode));
	if(newnode==NULL)
		{
			printf("Malloc failed\n");
			exit(-1);
		}
	newnode->color=0;
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->value=v;	
	if(r==NULL)
	{
		newnode->parent=NULL;
		newnode->color=1;
		return newnode;
	}
	p=r;
	while(1)
	{
		if(v<p->value)
		{	
			if(p->left==NULL)
			{
				p->left=newnode;
				newnode->parent=p;
				if(p->color==1)
					break;
				else
					uncle=getUncle(newnode);
					if(getcolor(uncle)->color==0)
					{	p->color=uncle->color=1;
						(p->parent)->color=0;
						newnode=p->parent;
						p=newnode->parent;
					}
				else/*Uncle is Black*/
				{
					gp=p->parent;
					if(p==gp->left)
					{
						if(newnode==p->left)
							gp=singlerightrotate(gp);
						else
							gp=doublerotateleftright(gp);
					}
					else 
					{
						if(newnode==p->right)
							gp=singleleftrotate(gp);
						else
							gp=doublerotaterightleft(gp);
										
					}
				}			
			}
		}
	}
	return root;
	
	
}

void traverse(struct RBTreeNode *root)
{
	if(root==NULL)
		return;
	traverse(root->left);
	printf("%d  %s\n", root->value, (root->color)?"Black":"Red");
	traverse(root->right);
}
void main()
{
	struct RBTreeNode *root=NULL;
	int v;
	printf("Enter the value(-1) to exit\n");
	while(1)
	{
		scanf("%d", &v);
		if(v==-1)
			break;
		root=insert(root, v);
	}
	printf("RB Tree is:- \n");
	traverse(root);
}
