/* THIS PROGRAMME CARRIES OUT INSERTION AT HEAD,TAIL AND BEFORE AND AFTER A NODE IN A DOUBLY LINKED LIST.IT ALSO DISPLAYS THE NODES.*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node * lptr;
    struct node * rptr;
};
void insert_at_head(struct node **l,struct node **r,int val)
{
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node ));
    if(newnode==NULL)
    {
        printf("Malloc failed \n");
        exit(-1);
    }
        if((*l)==NULL)
        {
            newnode->value=val;
            newnode->rptr=NULL;
            newnode->lptr=NULL;
            (*l)=(*r)=newnode;
        }
        else
        {
            newnode->value=val;
            newnode->rptr=(*l);
            newnode->lptr=NULL;
            (*l)->lptr=newnode;
            (*l)=newnode;
        }

};
void insert_at_tail(struct node **l,struct node **r,int val)
{
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node ));
    if(newnode==NULL)
    {
        printf("Malloc failed \n");
        exit(-1);
    }
        if((*l)==NULL)
        {
            newnode->value=val;
            newnode->rptr=NULL;
            newnode->lptr=NULL;
            (*l)=(*r)=newnode;
        }
        else
        {
            newnode->value=val;
            newnode->rptr=NULL;
            newnode->lptr=(*r);
            (*r)->rptr=newnode;
            (*r)=newnode;
        }
}
void insert_before(struct node **l,struct node **r,int b,int val)
{
    struct node *t;
    t=*l;
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node ));
    if(newnode==NULL)
    {
        printf("Malloc failed \n");
        exit(-1);
    }
        if(((*l)->value)==b)
        {
            newnode->value=val;
            newnode->lptr=NULL;
            newnode->rptr=*l;
            (*l)->lptr=newnode;
            (*l)=newnode;

        }
        else
        {
        while((t->value)!=b)
        t=t->rptr;
        newnode->value=val;
        newnode->lptr=t->lptr;
        newnode->rptr=t;
        (t->lptr)->rptr=newnode;
        t->lptr=newnode;
        }
}
void  insert_after(struct node **l,struct node **r,int a,int val)
{
    struct node *t;
    t=*l;
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node ));
    if(newnode==NULL)
    {
        printf("Malloc failed \n");
        exit(-1);
    }
        if(((*r)->value)==a)
        {
            newnode->value=val;
            newnode->lptr=(*r);
            newnode->rptr=NULL;
            (*r)->rptr=newnode;
            (*r)=newnode;

        }
        else
        {
        while((t->value)!=a)
        t=t->rptr;
        newnode->value=val;
        newnode->lptr=t;
        newnode->rptr=t->rptr;
        (t->rptr)->lptr=newnode;
        t->rptr=newnode;
        }
}

void display(struct node *l)
{
    struct node *temp;
    temp=l;
    while(temp->rptr!=NULL)
    {
        printf("%d\n",temp->value);
        temp=temp->rptr;
    }
    printf("%d\n",temp->value);

}
int main()
{

    struct node * l,* r;
    int after,before;
    l=r=NULL;
    insert_at_head(&l,&r,55);
    insert_at_head(&l,&r,44);
    insert_at_head(&l,&r,87);
    printf("Insert in front\n");
    display(l);

    insert_at_tail(&l,&r,10);
    insert_at_tail(&l,&r,25);
    insert_at_tail(&l,&r,54);
    printf("Insert at end\n");
    display(l);

    printf("Enter the value after which you want to enter the next node\n");
    scanf("%d",&after);
    insert_after(&l,&r,after,20);
    insert_after(&l,&r,after,30);
    insert_after(&l,&r,after,40);
    printf("Node's Inserted after %d are: \n",after);
    display(l);

    printf("Enter the value before which you want to enter the next node's\n");
    scanf("%d",&before);
    insert_before(&l,&r,before,50);
    insert_before(&l,&r,before,60);
    insert_before(&l,&r,before,70);
    printf("Node's Inserted before %d are: \n",before);
    display(l);

    return 0;
}
/*
output
Insert in front
87
44
55
Insert at end
87
44
55
10
25
54
Enter the value after which you want to enter the next node
25
Node's Inserted after 25 are:
87
44
55
10
25
40
30
20
54
Enter the value before which you want to enter the next node's
20
Node's Inserted before 20 are:
87
44
55
10
25
40
30
50
60
70
20
54

*/
