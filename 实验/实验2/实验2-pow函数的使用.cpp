#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int i;
	cin>>i;
	while(i--)
	{
		double a,b;
		cout<<"请分别输入底数和指数:"; 
		cin>>a>>b;
		cout<<pow(a,b)<<endl;
	}
	return 0;
}
