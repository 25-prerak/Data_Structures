#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 100
typedef struct node
{
    int value;
    struct node* ptr;
}node;
void display(node a[],int n)
{
    int i;node* temp;
    for(int i=0;i<n;i++)
    {
        printf("\n");
        printf("Friend of %d is...",a[i].value);
        temp=a[i].ptr;
        while(temp!=NULL)
        {
            printf("  %d  ",temp->value);
            temp=temp->ptr;
        }
    }
}
void insert(int q[],int *f,int *r,int val)   //function that insert element
{
    if((*r)+1>=N) { printf("full\n"); exit(-1); }
    (*r)++;
    q[*r]=val;
    if((*f)==-1)  (*f)=0;
}
void delete(int q[],int *f,int*r)    //function that delete the element
{
    int val;
    if((*f)==-1) { printf("Queue is Empty..."); exit -1; }
    if((*f)==(*r)) (*f)=(*r)=-1;
    else           (*f)++;
}
/*void bfs(node a[],int n)
{
    int i,q[N],b[n],k,j;  node* temp,*temp1; int *f=-1; int *r=-1;
    int flag=0; int l=0;
    for(i=0;i<n;i++)
    {
        insert(q,&f,&r,a[i].value);
        printf(" %d \n",a[i].value);
        b[l++]=a[i].value;
        temp=a[i].ptr;
        while(1)
        {
            if(temp==NULL)  break;
            for(k=0;k<n;k++)
            {
              if(temp->value==b[k])  flag=1;
            }
            if(flag==0)
            {
                insert(q,&f,&r,temp->value);
                b[l++]=temp->value;
            }
            temp1=temp;
            temp=temp->ptr;
            flag=0;
        }
        for(j=0;j<n;j++)
        {
            if(a[j].value==temp1->value)  break;
        }
        i=j-1;
        delete(q,&f,&r);
    }
}*/
node* addFriend(node*head,int val)
{
    node* temp=head;
    node* newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("MALLOC ERROR...\n");
        exit(1);
    }
    newnode->value=val;
    newnode->ptr=NULL;
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    while(temp->ptr!=NULL)
        temp=temp->ptr;
    temp->ptr=newnode;
    return head;
}
void main()
{
    int n,f,i;
    printf("Enter the total num of friends :");
    scanf("%d",&n);
    printf("number given to the friends is %d to %d\n",n-n,n-1);
    node a[n];
    for(i=0;i<n;i++)
    {
        a[i].value=i;
        a[i].ptr=NULL;
        while(1)
        {
            printf("Enter the friend of %d (press -1 to end) :",i);
            scanf("%d",&f);
            if(f==-1) break;
            if(f>=n) printf("%d is not in social media account ...\n",f);
            else
            a[i].ptr=addFriend(a[i].ptr,f);

        }
    }
    display(a,n);
}
