/* THIS PROGRAMME CARRIES OUT INSERTION IN ORDER AND DELETION OF NODES(ALL CASES).IT ALSO DISPLAYS THE NODES.*/


#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    struct node * ptr;
};
struct node * insert_in_order(struct node *h,int val)
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
    else if(val<=(h->value))
    {
        newnode->value=val;
        newnode->ptr=h;
        h=newnode;
        return h;
    }
    while(((t->ptr)!=NULL)&&(((t->ptr)->value)<val))
        t=t->ptr;
    {
        if((t->ptr)==NULL)
    {
        newnode->value=val;
        newnode->ptr=NULL;
        t->ptr=newnode;
        return h;
    }
        else
    {
        newnode->value=val;
        newnode->ptr=t->ptr;
        t->ptr=newnode;
        return h;
    }

    }

};
struct node * delete_front(struct node *h)
{
        struct node * deletethis;
        if(h==NULL)
        {
            printf("List is empty\n");
            exit(-1);
        }
        deletethis=h;
        h=h->ptr;
        free(deletethis);
        return h;
};
struct node * delete_end(struct node *h)
{
        struct node * deletethis,*temp;
        temp=h;
        if(h==NULL)
        {
            printf("List is empty\n");
            exit(-1);
        }
         while(((temp->ptr)->ptr)!=NULL)
                temp=temp->ptr;
         deletethis=(temp->ptr);
         temp->ptr=NULL;
         free(deletethis);
         return h;
};
struct node * delete_val(struct node *h,int val)
{
        struct node * deletethis,*temp;
        temp=h;
        if(h==NULL)
        {
            printf("List is empty\n");
            exit(-1);
        }
        if((h->value)==val)
        {
            deletethis=h;
            h=h->ptr;
            free(deletethis);
            return h;

        }
        while((((temp->ptr)->value)!=val)&&((temp->ptr)!=NULL))
            temp=temp->ptr;
        if(((temp->ptr)->value)==val)
        {
            deletethis=temp->ptr;
            temp->ptr=(temp->ptr)->ptr;
            free(deletethis);
            return h;
        }
        else
        {
            printf("Element is not present in the list\n");
            exit(-1);
        }
};
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
    int del;
    h=NULL;
    h=insert_in_order(h,5);
    h=insert_in_order(h,100);
    h=insert_in_order(h,50);
    h=insert_in_order(h,75);
    h=insert_in_order(h,10);
    h=insert_in_order(h,110);
    h=insert_in_order(h,1);
    h=insert_in_order(h,70);
    h=insert_in_order(h,3);
    h=insert_in_order(h,79);
    printf("Insert in ordered_list :\n");
    display(h);
    h=delete_front(h);
    h=delete_front(h);
    printf("List after deletion of 2 nodes from front :\n");
    display(h);
    h=delete_end(h);
    h=delete_end(h);
    printf("List after deletion of 2 nodes from end :\n");
    display(h);
    printf("Enter the value of the node to be deleted\n");
    scanf("%d",&del);
    h=delete_val(h,del);

    printf("List after deletion of node with value %d is :\n",del);
    display(h);

    return 0;
}
/* OUTPUT
Insert in ordered_list :
1
3
5
10
50
70
75
79
100
110
List after deletion of 2 nodes from front :
5
10
50
70
75
79
100
110
List after deletion of 2 nodes from end :
5
10
50
70
75
79
Enter the value of the node to be deleted
50
List after deletion of node with value 50 is :
5
10
70
75
79

*/
