#include<stdio.h>
int linear_search(int n, int a[15], int target)
{
	static int i;
	if(a[i] == target)
		return i;
	else if(i < n)
	{
		i++;
		linear_search(n,a,target);
	}
	else
		return -1;
}
int main()
{
	int a[20], i, n, target, pos;
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