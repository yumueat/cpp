#include<stdio.h>
int main()
{
	int n,i,j,flag;
	while(~scanf("%d",&n))
	{
		for (i=1;i<=n;i++)
		{
			flag=i;
//			printf("%d ",flag);
			for (j=1;j<=n;j++)
			{
				if (j==1)
				{
					printf("%d ",flag);
				}
				else if (j%2!=0)
				{
					printf("%d ",flag+=2*i-1);
				}
				else
				{
					printf("%d ",flag+=2*(n-i)+1);
				}
			}
//			printf("%d",i);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
