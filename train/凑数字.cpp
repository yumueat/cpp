#include<stdio.h>
//76,68,62,56 
int main()
{
	int i,j;
	int s;
	for (i=0;i<98;i++)
	{
		for (j=0;j<108;j++)
		{
			if (76*i+56*j==8561) 
			{
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	return 0;
}
