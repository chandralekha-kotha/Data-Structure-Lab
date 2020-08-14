#include<stdio.h>
int binary_search(int first, int last, int a[20], int target)
{
	if(first <= last)
	{
		int mid = (first + last) / 2;
		if(a[mid] == target)
			return mid;
		else if(a[mid] < target)
			return binary_search(mid+1,last,a,target);
		else if(a[mid] > target)
			return binary_search(first,mid-1,a,target);
	}
	else
		return -1;
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