#include<stdio.h>
int main()
{
	int n,k,i,j,temp;
	while(~scanf("%d %d",&n,&k))
	{
		int s=0,f=1;
		int a[n];
		int p[k];
		for (i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for (i=0;i<k;i++)
		{
			scanf("%d",&p[i]);
		}
		for (i=1;i<n;i++)
		{
			for (j=0;j<n-i;j++)
			{
				if (a[j]<a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		s+=a[0];
		for (i=0;i<k;i++)
		{
			for (j=1;j<n;j++)
			{
				a[j]-=p[i];
			}
			if (f>=k)
			{
				printf("%d\n",s);
			}
			else 
			{
				s+=a[f++];
			}
		}
		
		
	}
	return 0;
}
