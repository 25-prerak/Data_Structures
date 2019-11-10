#include <stdio.h>
#include <ctype.h>
#define SIZE 50

int s[SIZE];
int top=-1;
int flag=0;
int pop()
{
  return(s[top--]);
}

int push(int elem)
{
      if(flag==1)
    {
        int num;
        num=pop();
        s[++top]=elem+10*num;
    }
  else if(flag==0)
  {
    s[++top]=elem;
    flag=1;
  }
}


int main()
{
  char pofx[50],ch;
  int i=0,op1,op2;
  printf("Enter the Postfix Expression:(Enter space after each operator or operand)\n");
  fgets(pofx,100,stdin);
  while( (ch=pofx[i++]) != '\n')
  {
    if(isdigit(ch)) push(ch-'0');
    else if(ch==' ')
      flag=0;
    else
    {
      flag=0;
      op2=pop();
      op1=pop();
      switch(ch)
      {
        case '+':push(op1+op2);break;
        case '-':push(op1-op2);break;
        case '*':push(op1*op2);break;
        case '/':push(op1/op2);break ;
        default:
                 printf("Input invalid ... give proper input\n");
                 return 0;
      }
    }
  }
  printf("Result: %d\n",s[top]);
}
/* output
Enter the Postfix Expression:10 15 + 20 *
Result: 500
*/
