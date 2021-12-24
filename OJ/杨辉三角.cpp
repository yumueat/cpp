#include<stdio.h>
#include<string.h>
#define N 1000
int main()
{
	int n;
	int i,j;
	int a[N][N]={0};
	a[1][1]=1;
	for ( i=2;i<N;i++)
	{
		for ( j=1;j<=i;j++)
		{
			a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
	}
	scanf("%d",&n);
	for (i=1;i<N;i++)
	{
		for (j=1;j<=i;j++)
		{
			if (n==a[i][j])
			{
				printf("%d",i*(i-1)/2+j);
				return 0;
			}
		}
	}
	return 0;
}
