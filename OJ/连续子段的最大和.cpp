#include<stdio.h>
int main()
{
	int n;
	int a[10001];
	while(~scanf("%d",&n))
	{
		int i;
		for (i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int p,s=0;
		int max=0;
		for (i=0;i<n;i++)
		{
			s+=a[i];
			if (s<0)
			{
				s=0;
			}
			if (s>max)
			{
				max =s;
			}
		}
		printf("%d\n",max);
	}
	
	return 0;
	
 } 
