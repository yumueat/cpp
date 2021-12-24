#include<stdio.h>
int main()
{
	int n,m,j,i,p,flag;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int a[n+1];
		for (int k=0;k<=n;k++)
		{
			a[k]=1;
		}
		i=0;
		p=0;
		while(1)
		{
			
			for (j=1;j<=m;j++)
			{
				flag=i+1;
				if (flag==n+1)
				{
					flag=1;
				}
				if (a[flag]==0)
				{
					j--;
				}
				i++;
				if (i>=n+1)
				{
					i=1;
				}
//				printf("%d %d\n",i,j);
			}
			a[i]=0;
//			printf("x\n");
			printf("%d ",i);
			p++;
			if (p==n)
			{
				break;
			}
			
		}
		printf("\n");
	}
	return 0;
}
