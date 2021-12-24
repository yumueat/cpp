#include<iostream>
using namespace std;
int main()
{
	int n;
	int i,j;
	while(cin>>n)
	{
		int door[n+1];
		for (i=0;i<n+1;i++)
		{
			door[i]=1;
		}
		for (i=1;i<=n;i++)
		{
			for (j=i;j<=n;j=j+i)
			{
				door[j]=1-door[j];
			}
		}
		for (i=1;i<=n;i++)
		{
			if (door[i]==0)
			{
				cout<<i<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}
