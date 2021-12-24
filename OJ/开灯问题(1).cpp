#include<stdio.h>
int main()
{
	int n,k,i,j;
	while(~scanf("%d %d",&n,&k))
	{
		int a[n+1]={0};
		for (i=1;i<=k;i++)
		{
			for (j=1;j<n+1;j++)
			{
				if (j%i==0)
				{
					a[j]=1-a[j];
				}
			}
		}
		for (i=1;i<n+1;i++)
		{
			if (a[i]==0)
			{
				printf ("%d",i);
				for (j=i+1;j<n+1;j++)
				{
					if (a[j]==0)
					{
						printf(" ");
						break;
					}
				}
			}
		}
		printf("\n");
		
	}
	return 0;
}
