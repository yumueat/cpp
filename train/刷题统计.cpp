#include<iostream>
using namespace std;
int main(){
	long long  a,b,n,s=0;
	cin>>a>>b>>n;
	long long i; 
	for (i=1;s<n;i++)
	{
		if (i%7 == 6 || i%7 == 0)
		{
			s += b;
		}
		else
		{
			s += a;
		} 
	}
	cout<<i-1;
	return 0;
} 
