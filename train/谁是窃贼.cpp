#include<iostream>
using namespace std;
void A(int &flag,int n)
{
	if (n==4)
	{
		flag++;
	}
	else if (n==2)
	{
		flag++;
	}
}
void B(int &flag,int n)
{
	if (n==3)
	{
		flag++;
	}
	else if (n==2)
	{
		flag++;
	}
}
void C(int &flag,int n)
{
	if (n==2)
	{
		flag++;
	}
	else if (n==1)
	{
		flag++;
	}
}
void D(int &flag,int n)
{
	if (n==4)
	{
		flag++;
	}
	else if(n!=4)
	{
		flag++;
	}
}
int main()
{
	int n,flag;
	for (n=1;n<=4;n++)
	{
		flag=0;
		A(flag,n);
		B(flag,n);
		C(flag,n);
		D(flag,n);
		if (flag==4)
		{
			cout<<n;
		}
	}
	return 0;
}
