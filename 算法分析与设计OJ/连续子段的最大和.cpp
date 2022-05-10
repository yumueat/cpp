#include<iostream>
using namespace std;
int n;
int * dp = new int[n+1];
int * a = new int[n];
void getAn()
{
	int mini=0,maxi=0,max=dp[0],i;
	for (i=1;i<=n;i++)
	{
		if (dp[i] >= max)
		{
			max = dp[i];
			maxi = i;
		} 
		if (dp[i] == 0 && maxi >= i)
		{
			mini = i;
		}
		
	}
	cout<<max; 
}
void getDp()
{
	dp[0] = 0;
	int i=1;
	for (;i<=n;i++)
	{
		dp[i] =dp[i-1] + a[i-1];
		if (dp[i]<=0)
		{
			dp[i] = 0;
		}
	}
}
int main()
{
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	getDp();
	getAn();
	return 0;
} 
