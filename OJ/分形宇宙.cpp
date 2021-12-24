#include<stdio.h>

#include<math.h>
char lz[1000][1000];
void model(int n,int x,int y)
{
	if(n==1)
		lz[x][y]='X';
	else
	{
		int s=pow(3.0,n-2);
		model(n-1,x,y);
		model(n-1,x,y+2*s);
		model(n-1,x+s,y+s);
		model(n-1,x+2*s,y);
		model(n-1,x+2*s,y+2*s);
	}
}

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int s=pow(3.0,n-1);
		int i;
		for(i=0;i<=s;i++)
		{
			for(int j=0;j<=s;j++)
			{
				lz[i][j]=' ';
			}
			
		}
		model(n,1,1);
		for(i=1;i<=s;i++)
		{
			for(int j=1;j<=s;j++)
			{
				printf("%c",lz[i][j]);
			}
				
		printf("\n");
		}
		
		printf("-\n");
	}
	return 0;
}


