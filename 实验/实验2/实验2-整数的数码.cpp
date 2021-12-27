#include<iostream>
using namespace std;
void ans(int n,int k)
{
	int i=0;
	int flag[100];
	while(n)//利用取余分别获得每一位的数码 
	{
		flag[i++]=n%10;
		n/=10;
	}
	if (k>--i)
	{
		cout<<"输入的位数有误"<<endl;
	} 
	else
	{
		cout<<flag[k]<<endl;
	}
	
}
int main()
{
	int i;
	cin>>i;
	while(i--)
	{
		int n,k;
		cout<<"请输入你想知道数码的数字:";
		cin>>n;
		cout<<"请输入数码的位数:";
		cin>>k;
		ans(n,k);
	}
	
	return 0;
}
