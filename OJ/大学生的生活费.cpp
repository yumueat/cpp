#include<stdio.h>
int main()
{
	double m;
	while(~scanf("%lf",&m))
	{
		double t=0;
		int i;
		for(i=1;i<=48;i++)
		{
			t=(t+m)/(1+0.0171/12);
		}
		printf("%.2lf\n",t);
	}
	return 0;
	    
}
