#include<stdio.h>
int linear_search(int n, int a[20], int target)
{
	int i, pos = -1;
	for(i=0;i<n;i++)
	{
		if(a[i] == target)
		{
			pos = i;
			break;
		}
	}
	if(pos != -1)
		return pos;
	else
		return -1;
}
int main()
{
	int n , pos, a[20], target;
	scanf("%d",&n);
	for(int i=0;i<n;i++)	
		scanf("%d",&a[i]);
	scanf("%d",&target);
	pos = linear_search(n,a,target);
	if(pos == -1)
		printf("Element not found");
	else
		printf("Element present at %d location",pos+1);
}