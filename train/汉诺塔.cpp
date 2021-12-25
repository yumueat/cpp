#include<iostream>
using namespace std;
int ans (int n)
{
	if (n==1)
	{
		return 1;
	}
	else if (n==2)
	{
		return 3;
	}
	else
	{
		return 1+ans(n-1)*2;
	}
}
int main()
{
	cout<<ans(6);
	return 0;
 } 
