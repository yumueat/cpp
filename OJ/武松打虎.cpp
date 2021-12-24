#include<stdio.h>
int main()
{
	int n,m;
	int a[50000];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int s=0;
		int j,temp;
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1-i;j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j+1];
					a[j+1]=a[j];
					a[j]=temp;
				}
			}
				
		}
			
		for(i=0;i<n;i++)
		{
			s=s+a[i];
			if(s>m)
			{
				break;
			}
			
		}
		printf("%d\n",i);
	}
	return 0;
}
