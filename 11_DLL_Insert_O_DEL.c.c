/* THIS PROGRAMME CARRIES OUT INSERTION IN ORDER AND ALSO DELETION OF NODES (ALL CASES) FROM A DOUBLY LINKED LIST.IT ALSO DISPLAYS THE NODES.*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int value;
	struct node *lptr;
	struct node *rptr;
};

struct node * InsertInOrder(struct node **l,struct node **r,int val)
{
	struct node * newnode;
	struct node * temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Error in malloc\n");
		exit(-1);
	}
	if((*l)==NULL)
	{
		newnode->value=val;
		newnode->lptr=NULL;
		newnode->rptr=NULL;
		(*l)=(*r)=newnode;
		return 0;
	}
	else if(((*l)->value)>=val)
	{
		newnode->value=val;
		newnode->lptr=NULL;
		newnode->rptr=(*l);
		(*l)->lptr=newnode;
		(*l)=newnode;
		return 0;
	}
	else if(((*r)->value)<=val)
	{
		newnode->value=val;
		newnode->rptr=NULL;
		newnode->lptr=(*r);
		(*r)->rptr=newnode;
		(*r)=newnode;
		return 0;
	}
	else
	{
	temp=*l;
	while((temp->value)<val)
		temp=temp->rptr;

		newnode->value=val;
		newnode->rptr=temp;
		newnode->lptr=temp->lptr;
		(temp->lptr)->rptr=newnode;
		temp->lptr=newnode;
		return 0;


	}
}
struct node * Delete(struct node **l,struct node **r,int val)
{
	struct node * newnode;
	struct node * temp;
	struct node * deletethis;

	if((*l)==NULL)
	{
		printf("List is empty\n");
		return 0;
	}
	else if(((*l)->value)==val && (*l)==(*r))
	{
		deletethis=(*l);
		(*l)=(*r)=NULL;
		free(deletethis);
		return 0;
	}
	else if(((*l)->value)==val)
	{
		deletethis=(*l);
		(((*l)->rptr)->lptr)=NULL;
		(*l)=(*l)->rptr;
		free(deletethis);
		return 0;

	}
	else if(((*r)->value)==val)
	{
		deletethis=(*r);
		(((*r)->lptr)->rptr)=NULL;
		(*r)=(*r)->lptr;
		free(deletethis);
		return 0;
	}
	else
	{
	temp=*l;
	while((temp->value)!=val)
		temp=temp->rptr;

		deletethis=temp;
		(temp->lptr)->rptr=(temp->rptr);
		(temp->rptr)->lptr=(temp->lptr);
		free(deletethis);

		return 0;


	}
}

void display(struct node *l)
{
	struct node *temp;
	temp=l;
	if(l==NULL)
	{
		printf("List is empty\n");
		exit(-1);
	}
	while(temp!=NULL)
	{
		printf("%d\n",temp->value);
		temp=temp->rptr;
	}


}


int main()
{
	struct node *L,*R;
	L=NULL;
	R=NULL;
	InsertInOrder(&L,&R,10);
	InsertInOrder(&L,&R,20);
	InsertInOrder(&L,&R,5);
	InsertInOrder(&L,&R,30);
	InsertInOrder(&L,&R,15);
	InsertInOrder(&L,&R,35);
	InsertInOrder(&L,&R,54);
	InsertInOrder(&L,&R,12);
    display(L);
    Delete(&L,&R,54); /*Deletion from last*/
	Delete(&L,&R,05);/*Deletion from first*/
	Delete(&L,&R,20);/*Deletion from between with a value v*/
	printf("List after deletion of nodes\n");
	display(L);
	return 0;
}
/* OUTPUT
5
10
12
15
20
30
35
54
List after deletion of nodes
10
12
15
30
35
*/
