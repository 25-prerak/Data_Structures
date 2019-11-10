#include<stdio.h>
#include<stdlib.h>
#define N 100

void insert(int heap[],int n,int csize)
{
	int i;
	if(csize>=N)
	{
		printf("Heap is full\n");
		exit(-1);
	}
	i=csize;
	while((i>0) && (n>heap[(i-1)/2]))
	{
		heap[i]=heap[(i-1)/2];
		i=(i-1)/2;
	}
	heap[i]=n;
}

int delete(int heap[],int csize)
{
	int item,parent,child,temp;
	if(csize==0)
	{
		printf("Heap is empty\n");
		exit(-1);
	}
	item=heap[0];
	heap[0]=heap[csize-1];
	csize--;
	temp=heap[0]; parent=0 ; child=1;
	while(child<csize)
	{
		if((child<csize-1) && (heap[child]<heap[child+1]))
		child++;
		if(heap[parent]>=heap[child])
		break;
		heap[parent]=heap[child];
		parent=child;
		child=2*parent + 1;
	}
	heap[parent]=temp;
	return item;
}
void display(int heap[],int csize)
{
	int i;
	for(i=0;i<csize;i++)
		printf("%d\n",heap[i]);
	printf("\n");
}

int main()
{
	int heap[N],num,currentsize=0;
	printf("Enter numbers to insert, -1 to end\n");
	while(1)
	{
		if(currentsize>=N)
			break;
		scanf("%d",&num);
		if(num==-1)
			break;
		insert(heap,num,currentsize);
		currentsize++;
	}

	printf("DISPLAY\n");
	display(heap,currentsize);
	printf("Deleting elements from heap\n");
	while(currentsize>4)
	{
		num=delete(heap,currentsize);
		printf("%d\n",num);
		currentsize--;
	}
	printf("After deletion\n");
	display(heap,currentsize);
}
/* output
Enter numbers to insert, -1 to end
24
12
18
6
30
21
27
-1
DISPLAY
30
24
27
6
12
18
21

Deleting elements from heap
30
27
24
After deletion
21
18
12
6
*/
