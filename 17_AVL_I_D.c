/* This code carries out insertion and deletion in an AVL tree */

#include<stdio.h>
#include<stdlib.h>

struct AVLtreenode
{
	int value;
	int height;
	struct AVLtreenode * left;
	struct AVLtreenode * right;
};
int max(int a,int b)
{
	return (a>b)?a:b ;
}
int getHeight(struct AVLtreenode *r)
{
	int height,htr,htl;
	if(r==NULL)
	return -1;
	if(r->left==NULL && r->right==NULL)
	return 0;
	htl=getHeight(r->left);
	htr=getHeight(r->right);
	height=1+max(htl,htr);
	return height;
}
int getbalance(struct AVLtreenode * r)
{
    int g;
    g=getHeight(r->left)-getHeight(r->right);
    return g;
}
struct AVLtreenode * singlerotateright(struct AVLtreenode * P)
{
	struct AVLtreenode *LC;
	LC=P->left;
	P->left=LC->right;
	LC->right=P;
	P->height=getHeight(P);
	LC->height=1+max(getHeight(LC->left),getHeight(LC->right));
	return LC;
}
struct AVLtreenode * singlerotateleft(struct AVLtreenode * P)
{
	struct AVLtreenode *RC;
	RC=P->right;
	P->right=RC->left;
	RC->left=P;
	P->height=1+max(getHeight(P->left),getHeight(P->right));
	RC->height=1+max(getHeight(RC->left),getHeight(RC->right));
	return RC;
}
struct AVLtreenode * doublerotateleftright(struct AVLtreenode * P)
{
	struct AVLtreenode * ptr;
	P->left=singlerotateleft(P->left);
	ptr=singlerotateright(P);
	return ptr;
}
struct AVLtreenode * doublerotaterightleft(struct AVLtreenode * P)
{
	struct AVLtreenode * ptr;
	P->right=singlerotateright(P->right);
	ptr=singlerotateleft(P);
	return ptr;
}

void traverse (struct AVLtreenode *r)
{
	if(r==NULL)
	return ;

	traverse(r->left);
	printf("%d %d\n",r->value,r->height);
	traverse(r->right);
}
struct AVLtreenode * insert(struct AVLtreenode *r,int val)
{

	if(r==NULL)
	{
		struct AVLtreenode * newnode;
		newnode=(struct AVLtreenode *)malloc(sizeof(struct AVLtreenode));
		if(newnode==NULL)
		{
			printf("Malloc failed\n");
			exit(-1);
		}
		newnode->value=val;
		newnode->height=0;
		newnode->left=NULL;
		newnode->right=NULL;
		return newnode;
	}
	if(val<r->value)
		{
			r->left=insert(r->left,val);
			if((getHeight(r->left)-getHeight(r->right))==2)
			{
				if(val<(r->left)->value)
				r=singlerotateright(r);
				else
				r=doublerotateleftright(r);
			}
		}
	else if(val>=(r->value))
		{
			r->right=insert(r->right,val);
			if((getHeight(r->left)-getHeight(r->right))==-2)
			{
				if(val>=(r->right)->value)
				r=singlerotateleft(r);
				else
				r=doublerotaterightleft(r);
			}
		}
	r->height=max(getHeight(r->left),getHeight(r->right))+1;
	return r;

}
struct AVLtreenode * inorder_predecessor(struct AVLtreenode *ptr)
{
    while((ptr->right)!=NULL)
        ptr=ptr->right;
    return ptr;
};
struct AVLtreenode* Delete(struct AVLtreenode *r,int val)
{
    struct AVLtreenode *ptr,*temp;
    if(r==NULL)
        return r;
    if(val<r->value)
        r->left=Delete(r->left,val);
    if(val>r->value)
        r->right=Delete(r->right,val);
    if(val==r->value)
        {
               if((r->left==NULL)&&(r->right==NULL))
               {
                 free(r);
                 return NULL;
               }
               if(r->left==NULL)
               {
                   temp=r->right;
                   free(r);
                   return temp;
               }
               if(r->right==NULL)
               {
                   temp=r->left;
                   free(r);
                   return temp;
               }
               ptr=inorder_predecessor(r->left);
               r->value=ptr->value;
               r->left=Delete(r->left,ptr->value);
        }

            if(getbalance(r)==2)
                {
                            if(getbalance(r->left)>=0)
                                r=singlerotateright(r);
                            else
                                r=doublerotateleftright(r);
                }
            if(getbalance(r)==-2)
                {
                            if(getbalance(r->right)<=0)
                                r=singlerotateleft(r);
                            else
                                r=doublerotaterightleft(r);
                }

        r->height=max(getHeight(r->left),getHeight(r->right))+1;
        return r;

};
int main()
{
	struct AVLtreenode * root;
	root=NULL;
	int value,d;
	printf("Enter node values,-1 to end\n");
	while(1)
	{
		scanf("%d",&value);
		if(value==-1)
			break;
		root=insert(root,value);
	}
	printf("Displaying tree\n");
	traverse(root);
	printf("Enter node values to be deleted,-1 to end\n");
	while(1)
	{
		scanf("%d",&d);
		if(d==-1)
			break;
		root=Delete(root,d);
	}
	printf("Displaying tree after deletion\n");
	traverse(root);
}

/* Output
Enter node values,-1 to end
24
12
5
30
20
45
11
13
9
16
-1
Displaying tree
5 0
9 1
11 0
12 2
13 0
16 1
20 0
24 3
30 1
45 0
Enter node values to be deleted,-1 to end
45
24
16
5
-1
Displaying tree after deletion
9 1
11 0
12 2
13 0
20 1
30 0

*/


