#include<stdio.h>
int main()
{
	int n,m,number;
	while(~scanf("%d/%d %d",&n,&m,&number))
	{
		int k;
		k=n/m;
		printf("%d.",k);
		if(k!=0)
		{
			n=n%m;
		}
			
		int i;
		for(i=0;i<number;i++)
		{
			n=n*10;
			k=n/m;
			printf("%d",k);
			n=n%m;
			if(n==0)
			{
				break;
			}
			
		}
		printf("\n");
	}

	return 0;
}
