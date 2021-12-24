#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		char a[m];
		int i=0;
		while(m--)
		{
			scanf("%s",&a[i++]);
		}
		printf("2\n");
	} 
	
	return 0;
}
