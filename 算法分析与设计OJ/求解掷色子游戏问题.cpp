#include<iostream>
using namespace std;
int recursion(int n)
{
	if (n==1)
	{
		return 1;
	}
	else if (n==2)
	{
		return recursion(1) + 1;
	}
	else if (n==3)
	{
		return recursion(1) + recursion(2) + 1;
	}
	else if (n==4)
	{
		return recursion(1) + recursion(2) + recursion(3) + 1;
	}
	else if (n==5)
	{
		return recursion(1) + recursion(2) + recursion(3) + recursion(4) + 1;
	} 
	else if (n==6)
	{
		return recursion(1) + recursion(2) + recursion(3) + recursion(4) + recursion(5) + 1;
	}
 
} 
int main()
{
	int n;
	cin>>n;
	cout<<recursion(n);
	return 0;
}
