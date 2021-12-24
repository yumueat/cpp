#include<stdio.h>
int fun(int n)
{
	if (n==1)
	{
		return 1;
	} 
	else if (n==2)
	{
		return 2;
	}
	else 
	{
		return fun(n-2)+fun(n-1);
	}
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		printf("%d\n",fun(n));
	}
	return 0;
}
