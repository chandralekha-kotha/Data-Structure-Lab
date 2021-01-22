#include<stdio.h>
int source, v, e, time, visited[20], G[20][20];
void dfs(int i)
{
	int j;
	visited[i]= 1;
	printf("%d -> ", i+1);
	for(j=0;j<v;j++)
	{
		if(G[i][j] == 1 && visited[j] == 0)
		dfs(j);
	}
}

int main()
{
	int i,j,v1, v2;
	printf("Enter the number of edges: \n");
	scanf("%d", &e);
	printf("Enter number of vertices: \n");
	scanf("%d", &v);
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			G[i][j] = 0;
	for(i=0; i<e;i++)
	{
	printf("Enter edge (v1 v2) format:  ");
	scanf("%d %d", &v1, &v2);
	G[v1-1][v2-1] = 1;
	}
	for(i = 0; i<v;i++)
	{
		for(j=0;j<v;j++)
			printf("%d\t", G[i][j]);
		printf("\n");
	}
	printf("Enter the source: ");
	scanf("%d", &source);
		dfs(source-1);
	return 0;
}
