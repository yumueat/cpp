#include<iostream>
using namespace std;
int main()
{
	int n,m,t;
	while(~scanf("%d/%d %d",&n,&m,&t))
	{
		int rem,zero=0;
		int con[100];
		int i=0;
		while(n)
		{
			if (n/m==0)
			{
				con[i++]=n*10/m;
				zero++;
				
			}
		}
		printf("0.");
		for (int j;j<zero;j++)
		{
			printf("0");
		}
		printf("%d\n",con);
		
	}
	return 0;
	
}
