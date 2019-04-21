#include<stdio.h>
#include<stdlib.h>
#define max 100
int create(int num)
{
	int key;
	key=num%100;
	return key;
}
void linear_prob(int a[max],int key,int num)
{
	int flag=0,i,count=10;
	if(a[key]==-1)
		a[key]=num;
	else
	{
		for(i=10;i<max;i++)
		{
			if(a[i]!=-1)
			count++;
		}
		if(count==max)
		{
			printf("\n Hash table is full");
			display(a);
			exit(1);
		}
		for(i=key+1;i<max;i++)
			if(a[i]==-1)
			{
				a[i]=num;
				flag=1;
				break;
			}
			for(i=10;i<key&&flag==0;i++)
				if(a[i]==-1)
				{
					a[i]=num;
					flag=1;
					break;
				}
	}
}
void display(int a[max])
{
	int i;
	printf("\n The hash table is \n");
	printf("Key/index \t employee id\n");
	printf("");
	for(i=10;i<max;i++)
		printf("\n %d %d\n",i,a[i]);
		
}
int main()
{
	int a[max],num,key,i;
	int ans;
	printf("Collision handling by linear probing\n");
	for(i=10;i<max;i++)
		a[i]=-1;
	do
	{
		printf("\n Enter the four digit number:");
		scanf("%d",&num);
		key=create(num);
		linear_pron(a,keyt,num);
		printf("Do you want to continue?\n");
		scanf("%d",&ans);
	}
	while(ans==1)
	display(a);
}
