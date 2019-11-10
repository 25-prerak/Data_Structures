/* The following code carries out iterative insertion and recursive deletion of nodes from Binary search tree.
    It also does preorder,postorder,inorder and level order traversal of BST.
    It also generates a clone for a given tree
*/
#include <stdio.h>
#include <stdlib.h>
#define N 20
struct BST
{
    int value;
    struct BST * lptr;
    struct BST * rptr;
};
struct BST * I_insert(struct BST *r,int v)
{
        struct BST *newnode,*temp;
        temp=r;
        newnode=(struct BST *)malloc(sizeof(struct BST));
        if(newnode==NULL)
        {
            printf("Malloc failed\n");
            exit(-1);
        }
        newnode->value=v;
        newnode->lptr=NULL;
        newnode->rptr=NULL;
        if(r==NULL)
        {
            r=newnode;
            return r;
        }
        while(1)
        {
            if(v<temp->value)
            {
                if(temp->lptr==NULL)
                    {
                        temp->lptr=newnode;
                        break;
                    }
                    temp=temp->lptr;
            }
            else
            {
                if(temp->rptr==NULL)
                    {
                        temp->rptr=newnode;
                        break;
                    }
                    temp=temp->rptr;
            }
        }
        return r;
};
struct BST * inorder_predecessor(struct BST *ptr)
{
    while((ptr->rptr)!=NULL)
        ptr=ptr->rptr;
    return ptr;
};
struct BST * R_delete(struct BST *r,int v)
{
    struct BST *temp,*ptr;
    if(r==NULL)
        return r;
    if(v<r->value)
        r->lptr=R_delete(r->lptr,v);
    else if(v>r->value)
        r->rptr=R_delete(r->rptr,v);
    else
    {
        if((r->lptr==NULL)&&(r->rptr)==NULL)
         {
             free(r);
             return NULL;
         }
        if(r->lptr==NULL)
        {
            temp=r->rptr;
            free(r);
            return temp;
        }
        if(r->rptr==NULL)
        {
            temp=r->lptr;
            free(r);
            return temp;
        }
        ptr=inorder_predecessor(r->lptr);
        r->value=ptr->value;
        r->lptr=R_delete(r->lptr,ptr->value);
    }
    return r;
};
struct BST * clone(struct BST * r)
{
    struct BST * newnode;
    newnode=(struct BST *)malloc(sizeof(struct BST));
        if(newnode==NULL)
        {
            printf("Malloc failed\n");
            exit(-1);
        }
    if(r==NULL)
        return r;
    else
        {
            newnode->value=r->value;
            newnode->lptr=clone(r->lptr);
            newnode->rptr=clone(r->rptr);
            return newnode;
        }
};
void pre_order(struct BST *r)
{
    if(r==NULL)
      return ;
    printf("%d\n",r->value);
    pre_order(r->lptr);
    pre_order(r->rptr);
}
void post_order(struct BST *r)
{
    if(r==NULL)
      return ;
    post_order(r->lptr);
    post_order(r->rptr);
    printf("%d\n",r->value);

}
void in_order(struct BST *r)
{
    if(r==NULL)
      return ;
    in_order(r->lptr);
    printf("%d\n",r->value);
    in_order(r->rptr);
}
void insert_in_Q(struct BST * q[],int *f,int *r,struct BST * val)
{
    if(((*r)+1)>=N)
    {
        printf("Queue is full\n");
        exit(-1);
    }
    (*r)++;
    q[(*r)]=val;
    if((*f)==-1)
        (*f)++;
}
struct BST * delete_from_Q(struct BST * q[],int *f,int *r)
    {
        struct BST * d;
        if((*f)==-1)
        {
            printf("Queue is empty\n");
            return NULL;
        }
        d=q[(*f)];
        if((*f)==(*r))
                (*f)=(*r)=-1;
        else
            (*f)++;
        return d;
    }
void level_order(struct BST *r)
{
    struct BST * q[N];
    int F,R;
    F=R=-1;

    struct BST * temp;
    temp=r;
    while(temp!=NULL)
    {
        printf("%d\n",temp->value);
        if(temp->lptr!=NULL)
            insert_in_Q(q,&F,&R,(temp->lptr));
        if(temp->rptr!=NULL)
            insert_in_Q(q,&F,&R,(temp->rptr));
        temp=delete_from_Q(q,&F,&R);

    }
}
int main()
{
    int val,v;
    struct BST * root,*clone_root;
    root=NULL;
    printf("Enter values for the Tree, -1 to terminate\n");
    while(1)
    {
    printf("Enter the value of tree node:\n");
    scanf("%d",&val);
    if(val==-1)
        break;
    root=I_insert(root,val);
    }
    printf("pre_order traversal is:\n");
    pre_order(root);
    printf("post_order traversal is:\n");
    post_order(root);
    printf("in_order traversal is:\n");
    in_order(root);
    printf("level_order traversal is:\n");
    level_order(root);
    printf("Clone of the existing tree\n");
    clone_root=clone(root);
    printf("pre_order traversal of cloned tree is:\n");
    pre_order(clone_root);
    printf("Enter the value of node to be deleted,-1 to terminate\n");
    while(1)
    {
        printf("Enter the value of tree node to be deleted:\n");
        scanf("%d",&v);
        if(v==-1)
        break;
        root=R_delete(root,v);
    }
    printf("Pre order traversal of tree after deletion is:\n");
    pre_order(root);

}
/* OUTPUT
Enter values for the Tree, -1 to terminate
Enter the value of tree node:
50
Enter the value of tree node:
30
Enter the value of tree node:
70
Enter the value of tree node:
20
Enter the value of tree node:
40
Enter the value of tree node:
60
Enter the value of tree node:
80
Enter the value of tree node:
-1
pre_order traversal is:
50
30
20
40
70
60
80
post_order traversal is:
20
40
30
60
80
70
50
in_order traversal is:
20
30
40
50
60
70
80
level_order traversal is:
50
30
70
20
40
60
80
Queue is empty
Clone of the existing tree
pre_order traversal of cloned tree is:
50
30
20
40
70
60
80
Enter the value of node to be deleted,-1 to terminate
Enter the value of tree node to be deleted:
50
Enter the value of tree node to be deleted:
40
Enter the value of tree node to be deleted:
70
Enter the value of tree node to be deleted:
-1
Pre order traversal of tree after deletion is:
30
20
60
80


*/
