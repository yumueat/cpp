#include<iostream>
using namespace std;
int main()
{
	int n,i,j,k,s=0;
	cin>>n;
	for (i=1;i<n;i++)
	{
		for (j=1;j<n/2;j++)
		{
			for (k=1;k<n/5;k++)
			{
				if (i*1+j*2+k*5==n)
				{
					s++;
				}
			}
		}
	}
	cout<<s;
	return 0;
} 
