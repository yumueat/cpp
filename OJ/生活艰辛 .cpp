#include<stdio.h>
int main()
{
	int n,k,i;
	while(~scanf("%d %d",&n,&k))
	{
		if (200/(n-k)<=20&&n>k)
		{
			if (200%(n-k)==0)
				printf("%d\n",200/(n-k));
			else
				printf("%d\n",200/(n-k)+1);
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}

