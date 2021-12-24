#include<stdio.h>
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		long long a[40]={0};
		a[1]=3;a[2]=9;
		for(int i=3;i<=n;i++)
		{
			a[i]=a[i-2]+a[i-1]*2;
		}
//		printf("%d",a[39]);	
		if(n==1||n==2)
		{
			printf("%d\n",a[n]);
		}
		
		else
		{
			printf("%lld\n",a[n]);
		}
		
	
	}
	return 0;
}
