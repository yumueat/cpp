#include<stdio.h>
int syf(int x,int y,int z)
{
	if(x==1)
	{
		return (z+y-1)%z+1;
	}
		
	else
	{
		return (syf(x-1,y,z-1)+y-1)%z+1;
	}
		

}
int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		printf("%d",syf(n,m,n));
		printf("\n");
	}
	return 0;
}

