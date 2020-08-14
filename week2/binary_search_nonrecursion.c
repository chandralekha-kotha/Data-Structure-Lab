#include<stdio.h>
int binary_search(int first, int last, int a[20], int target)
{
	int pos = -1;
	while(first <= last)
	{
		int mid = (first + last) / 2;
		if(a[mid] == target)
		{
			pos = mid;
			break;
		}
		else
		{
			if(a[mid] < target)
				first = mid + 1;
			else
				last = mid - 1;
		}
	}
}
int main()
{
	int n , pos, target, a[20], i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&target);
	pos = binary_search(0, n-1, a, target);
	if(pos == -1)
		printf("Element not found");
	else
		printf("Element present at %d location",pos+1);
}