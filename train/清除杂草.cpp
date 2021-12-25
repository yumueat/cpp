#include<iostream>
#include<string.h>
#include<string>
using namespace std;
char p[100][100];
char b[100];
int main()
{
	int n,m,i,j,q=0,k;
	
	char a;
	cin>>n>>m;
	for (i=0;i<n;i++)
	{
		
		cin>>p[i];

	}
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			cout<<p[i][j];
		}
		cout<<endl;
	}
	return 0;
}
