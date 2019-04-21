#include<stdio.h>
#include<conio.h>
int count=0;
void creategraph(int n,int a[10][10])
{
	int i,j;
	printf("Enter the adjacency vertex\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
}
void bfs(int a[10][10],int n,int source,int s[])
{
	int f,r,q[10],u,v,i;
	printf("Enter the source vertex\n");
	scanf("%d",&source);
	printf("The nodes reachable are\n");
	for(i=1;i<=n;i++)
		s[i]=0;
	f=r=0;
	q[r]=source;
	s[source]=1;
	while(f<=r)
	{
		u=q[f++];
		for(v=1;v<=n;v++)
		{
			if(a[u][v]==1&&s[v]==0)
			{
				printf("\n %d",v);
				s[v]=1;
				q[++r]=v;
			}
		}
	}
}
void dfs(int a[10][10],int n,int vis[],int v)
{
	int i;
	count++;
	vis[v]=count;
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0&&a[v][i]==1)
		dfs(a,n,vis,i);
	}
}
int main()
{
	int a[20][20],n,source,s[10],i,j,vis[10];
	int ch;
	while(1)
	{
		printf("\n Enter your choice:\n 1:Create graph\n 2:Check reachability\n 3:Check connectivity\n 4:Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the no. of nodes\n");
					scanf("%d",&n);
					creategraph(n,a);
					break;
			case 2: bfs(a,n,source,s);
					break;
			case 3: for(i=1;i<=n;i++)
					vis[i]=0;
					dfs(a,n,vis,1);
					if(count==n)
						printf("The graph is connected\n");
					else
						printf("The graph is not connected\n");
					break;
			case 4: exit(0);
		}
	}
	return 0;
}
