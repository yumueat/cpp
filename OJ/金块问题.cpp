#include<iostream>
using namespace std;
int main() 
{
	int n;
	int temp;
	int i,j;
	
	while(cin>>n)
	{
		int a[n];
		int flag=n;
		int i=0;
		while(flag--)
		{
			cin>>a[i++];
		}
/*		for (i=0;i<n;i++)
		{
			cout<<a[i]<<endl;
			printf("%d ",a[i]);
		}*/
		for (i=1;i<n;i++)
		{
			for (j=0;j<n-i;j++)
			{
				if (a[j]>a[j+1])
				{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
		cout<<a[n-1]<<' '<<a[0]<<endl;
	}
	return 0;
}
