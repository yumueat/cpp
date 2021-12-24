#include <stdio.h>
int main()
{ 
	int k,m,a,flag,n;
	int f[1000];
	while(~scanf("%d%d",&n,&m))
	{
		k=0;
		for (a=1;a<=n;a++)
		{
			flag=a;
		    while (flag%2==0) 
			{
				flag/=2;
			}      
		    while (flag%3==0)
			{
				flag/=3;
			}      
		    if (flag==1)
		    { 
				k++;
				f[k]=a;
			}
		}                     
		printf("%d\n",k); 
		printf("%d\n",f[m]); 
	}
	return 0; 
}
