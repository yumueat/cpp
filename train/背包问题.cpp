#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int w[500],v[500],dp[500]={0};
	int n,i,j,t;
	cin>>t;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>w[i]>>v[i];
		cout<<w[i]<<v[i]<<endl;
	}
	for (i=0;i<n;i++)
	{
		for (j=t;j>=w[i];j--)
		{
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[t];
	return 0;
} 
