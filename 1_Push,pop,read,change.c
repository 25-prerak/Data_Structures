#include <stdio.h>
#include <stdlib.h>
#define N 20
void push(char s[],int *t,int n,char ch)
    {
        if((*t)>=(n-1))
            printf("Stack is full\n");
        else
        {
            (*t)++;
            s[(*t)]=ch;
        }

    }
char pop(char s[],int *t,int n)
{   char c;
    if((*t)==-1)
    {
        printf("Stack is empty\n");
        exit(-1);
    }
    else
        {
            c=s[(*t)];
            (*t)--;
        }
        return c;
}
char read(char s[],int *t,int m)
{
    char r;
    if((*t)==-1)
    {
        printf("Stack is empty\n");
        exit(-1);
    }
    else
    {
        if((m-1)>(*t))
        {
            printf("Not Possible\n");
            exit(-1);
        }
        else
        r=s[(*t)-(m-1)];
    }
    return r;
}
void change(char s[],int *t,int m,char ch)
{
    if((*t)==-1)
    {
        printf("Stack is empty\n");
        exit(-1);
    }
    else
    {
        if((m-1)>(*t))
        {
            printf("Not Possible\n");
            exit(-1);
        }
        else
        s[(*t)-(m-1)]=ch;
    }
}
 int main()
 {
     int m,w;
     char s[N],val,ch,r,chan;
     int top=-1;
     printf("Enter 5 elements to be pushed in stack\n");
     for(int i=0;i<5;i++)
     {
         scanf("%c",&val);
         push(s,&top,N,val);
         fflush(stdin);
     }
     printf("Pop 2 elements\n");
     for(int i=0;i<2;i++)
     {
         ch=pop(s,&top,N);
         printf("Deleted element is %c\n",ch);
     }
        printf("Which element do you want to read starting from top??\n");
        scanf("%d",&m);
        r=read(s,&top,m);
        printf("%d element is %c\n",m,r);
        printf("Which element do you want to change starting from top??\n");
        scanf("%d",&w);
        fflush(stdin);
        printf("Enter new value of element to be changed \n");
        scanf("%c",&chan);
        change(s,&top,w,chan);
        printf("New Stack contains:\n");
        for(int i=0;i<=top;i++)
        {
         printf("%c\n",s[i]);
        }
     return 0;
 }
    /* Output:
    Enter 5 elements to be pushed in stack
q
w
e
r
t
Pop 2 elements
Deleted element is t
Deleted element is r
Which element do you want to read starting from top??
2
2 element is w
Which element do you want to change starting from top??
2
Enter new value of element to be changed
q
New Stack contains:
q
q
e
 */
