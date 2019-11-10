/* Recursive formulation of insert function */

#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int value;
    struct BST * lptr;
    struct BST * rptr;
};
struct BST * R_insert(struct BST *r,int v)
{
        struct BST *newnode;
        newnode=(struct BST *)malloc(sizeof(struct BST));
        if(newnode==NULL)
        {
            printf("Malloc failed\n");
            exit(-1);
        }
            if(r==NULL)
        {
            newnode->value=v;
            newnode->lptr=NULL;
            newnode->rptr=NULL;
            r=newnode;
            return r;
        }
        else
        {
            if(v<r->value)
                r->lptr=R_insert(r->lptr,v);
            else
                r->rptr=R_insert(r->rptr,v);
            return r;
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

int main()
{
    int val;
    struct BST * root;
    root=NULL;
    printf("Enter values for the Tree, -1 to terminate\n");
    while(1)
    {
    printf("Enter the value of tree node:\n");
    scanf("%d",&val);
    if(val==-1)
        break;
    root=R_insert(root,val);
    }
    printf("pre_order traversal is:\n");
    pre_order(root);

}
/* OUTPUT
Enter values for the Tree, -1 to terminate
Enter the value of tree node:
20
Enter the value of tree node:
10
Enter the value of tree node:
30
Enter the value of tree node:
5
Enter the value of tree node:
15
Enter the value of tree node:
35
Enter the value of tree node:
25
Enter the value of tree node:
-1
pre_order traversal is:
20
10
5
15
30
25
35

*/