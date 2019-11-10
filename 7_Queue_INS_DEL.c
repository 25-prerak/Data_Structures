#include <stdio.h>
#include <stdlib.h>
#define N 5
void insert_in_Q(int q[],int *f,int *r,int val)
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
int delete_from_Q(int q[],int *f,int *r)
    {
        int d;
        if((*f)==-1)
        {
            printf("Queue is empty\n");
            exit(-1);
        }
        d=q[(*f)];
        if((*f)==(*r))
                (*f)=(*r)=-1;
        else
            (*f)++;
        return d;
    }
int main()
{
    int q[N];
    int F,R,val,del;
    F=R=-1;
    for(int i=0;i<5;i++)
    {
        printf("Enter value to be inserted in Queue\n");
        scanf("%d",&val);
        insert_in_Q(q,&F,&R,val);
        fflush(stdin);
    }
     printf("Delete 3 elements from Queue\n");
     for(int i=0;i<3;i++)
     {
         del=delete_from_Q(q,&F,&R);
         printf("Deleted element %d is %d\n",i+1,del);
     }
        return 0;
}
/* OUTPUT
Enter value to be inserted in Queue
4
Enter value to be inserted in Queue
2
Enter value to be inserted in Queue
6
Enter value to be inserted in Queue
8
Enter value to be inserted in Queue
7
Delete 3 elements from Queue
Deleted element 1 is 4
Deleted element 2 is 2
Deleted element 3 is 6
*/
