#include<stdio.h>
int count=0;
void H(char F,char T,char U,int N)
	{	count++;
		if(N==1)
			printf("Move %d from %c to %c\n",N,F,T);
		else
			{
				H(F,U,T,N-1);
				printf("Move %d from %c to %c\n",N,F,T);
				H(U,T,F,N-1);
			}
	}


void main()
	{
		int p;
		printf("Enter number of platters\n");
		scanf("%d",&p);
		H('A','C','B',p);
		printf("No. of calls to H are %d\n",count);
	}
/* Output
Enter number of platters
3
Move 1 from A to C
Move 2 from A to B
Move 1 from C to B
Move 3 from A to C
Move 1 from B to A
Move 2 from B to C
Move 1 from A to C
No. of calls to H are 7
*/
