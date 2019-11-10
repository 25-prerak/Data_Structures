#include<stdio.h>
#include<stdlib.h>
#define N 4

void insert(int q[], int *f, int *r, int val)
{
	if ((*f)==-1)
	{
		(*f)++; (*r)++;
		q[(*f)] = val;
	}

	else if ((*r)>=N-1)
	{
		printf("Queue is full\n");
		exit(-1);
	}

	else
	{
		(*r)++;
		q[(*r)] = val;
	}
}

int delete(int q[], int *f, int *r)
{
	int c;

	if ((*f)==-1)
	{
		printf("Queue is empty\n");
		exit(-1);
	}

	else if ((*f)==(*r))
	{
		c = q[(*r)];
		(*f) = -1;
		(*r) = -1;
	}

	else
	{
		c = q[(*f)];
		(*f)++;
	}

	return c;
}

void main()
{
	int Q0[N], Q1[N], Q2[N], f0, f1, f2, r0, r1, r2, val, i0, i1, i2, delv0, delv1, delv2, a, b=0, c;
	f0 =f1= f2 =r0 =r1 =r2 = -1;

	printf("How many numbers you want to add?\n");
	scanf("%d", &a);

	for(b=0; b<a; b++)
	{
		printf("Enter the number you want to add\n");
		scanf("%d", &val);
		printf("What level of priority?(Enter 0, 1 or 2)\n");
		scanf("%d", &c);

		if(c==0)
		{
			insert(Q0, &f0, &r0, val);
		}
		else if(c==1)
		{
			insert(Q1, &f1, &r1, val);
		}
		else if(c==2)
		{
			insert(Q2, &f2, &r2, val);
		}
		else
		{
			printf("Invalid choice\n");
			exit(-1);
		}
	}
	
	if(f0 != -1)
	{
		for(i0=0; i0<=r0; i0++)
		{
			delv0 = delete(Q0, &f0, &r0);
			printf("Number deleted from queue 0 is %d\n", delv0);
		}
	}
	if(f0 == -1&&f1 != -1)
	{
		for(i1=0; i1<=r1; i1++)
		{
			delv1 = delete(Q1, &f1, &r1);
			printf("Number deleted from queue 1 is %d\n", delv1);
		}
	}
	if(f0 == -1&&f1 == -1&&f2 != -1)
	{
		for(i2=0; i2<=r2; i2++)
		{
			delv2 = delete(Q2, &f2, &r2);
			printf("Number deleted from queue 2 is %d\n", delv2);
		}
	}
	if(f0 == -1&&f1 == -1&&f2 == -1)
	{
	printf("All queues are empty\n");
	}
}

/*How many numbers you want to add?
6
Enter the number you want to add
1
What level of priority?(Enter 0, 1 or 2)
0
Enter the number you want to add
2
What level of priority?(Enter 0, 1 or 2)
0
Enter the number you want to add
3
What level of priority?(Enter 0, 1 or 2)
0
Enter the number you want to add
4
What level of priority?(Enter 0, 1 or 2)
1
Enter the number you want to add
5
What level of priority?(Enter 0, 1 or 2)
1
Enter the number you want to add
6
What level of priority?(Enter 0, 1 or 2)
2
Number deleted from queue 0 is 1
Number deleted from queue 0 is 2
Number deleted from queue 0 is 3
Number deleted from queue 1 is 4
Number deleted from queue 1 is 5
Number deleted from queue 2 is 6
All queues are empty*/
