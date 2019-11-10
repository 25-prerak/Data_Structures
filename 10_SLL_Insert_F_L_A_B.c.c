/* THIS PROGRAMME CARRIES OUT INSERTION AT HEAD,TAIL AND BEFORE AND AFTER A NODE.IT ALSO DISPLAYS THE NODES.*/


#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node * ptr;
};
struct node * insert_at_head(struct node *h,int val)
{
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node *));
    if(newnode==NULL)
    {
        printf("Malloc failed \n");
        exit(-1);
    }
        newnode->value=val;
        newnode->ptr=h;
        h=newnode;
        return h;

};
struct node * insert_at_tail(struct node *h,int val)
{
    struct node *t;
    t=h;
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node *));
    if(newnode==NULL)
    {
        printf("Malloc failed \n");
        exit(-1);
    }
    if(h==NULL)
    {
        newnode->value=val;
        newnode->ptr=NULL;
        h=newnode;
        return h;
    }
        while((t->ptr)!=NULL)
        t=t->ptr;

        newnode->value=val;
        newnode->ptr=NULL;
        t->ptr=newnode;
        return h;
}
struct node * insert_before(struct node *h,int b,int val)
{
    struct node *t;
    t=h;
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node *));
    if(newnode==NULL)
    {
        printf("Malloc failed \n");
        exit(-1);
    }

        while(((t->ptr)->value)!=b)
        t=t->ptr;

        newnode->value=val;
        newnode->ptr=t->ptr;
        t->ptr=newnode;
        return h;
}
struct node * insert_after(struct node *h,int a,int val)
{
    struct node *t;
    t=h;
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node *));
    if(newnode==NULL)
    {
        printf("Malloc failed \n");
        exit(-1);
    }

        while((t->value)!=a)
        t=t->ptr;

        newnode->value=val;
        newnode->ptr=t->ptr;
        t->ptr=newnode;
        return h;
}

void display(struct node *h)
{
    struct node *temp;
    temp=h;
    while(temp!=NULL)
    {
        printf("%d\n",temp->value);
        temp=temp->ptr;
    }
}
int main()
{
    struct node * h;
    int after,before;
    h=NULL;
    h=insert_at_head(h,55);
    h=insert_at_head(h,44);
    h=insert_at_head(h,87);
    printf("Insert in front\n");
    display(h);
    h=insert_at_tail(h,10);
    h=insert_at_tail(h,25);
    h=insert_at_tail(h,54);
    printf("Insert at end\n");
    display(h);
    printf("Enter the value after which you want to enter the next node\n");
    scanf("%d",&after);
    h=insert_after(h,after,20);
    h=insert_after(h,after,30);
    h=insert_after(h,after,40);
    printf("Node's Inserted after %d are: \n",after);
    display(h);
    printf("Enter the value before which you want to enter the next node's\n");
    scanf("%d",&before);
    h=insert_before(h,before,50);
    h=insert_before(h,before,60);
    h=insert_before(h,before,70);
    printf("Node's Inserted before %d are: \n",before);
    display(h);
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
