#include<iostream>
using namespace std;
int ans(int n)
{
	if (n==1)
	{
		return 1;
	}
	else if (n==2)
	{
		return 1;
	}
	else
	{
		return ans(n-1)+ans(n-2);
	}
}
int main()
{
	int i;
	cin>>i;
	while(i--)
	{
		int n;
		cout<<"������쳲���������������:";
		cin>>n;
		cout<<ans(n)<<endl;
	}
	return 0; 
}
