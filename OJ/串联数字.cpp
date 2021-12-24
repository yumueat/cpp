#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a,i=1;
		scanf("%d",&a);
		while(a>i)
		{
			a=a-i;
			i++; 
		}
		
		if(a%9==0)
		{
			printf("9\n");
		}
		else
		{
			printf("%d\n",a%9);
		}
		
	}
	return 0;
}
