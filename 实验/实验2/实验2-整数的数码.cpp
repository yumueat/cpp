#include<iostream>
using namespace std;
void ans(int n,int k)
{
	int i=0;
	int flag[100];
	while(n)//����ȡ��ֱ���ÿһλ������ 
	{
		flag[i++]=n%10;
		n/=10;
	}
	if (k>--i)
	{
		cout<<"�����λ������"<<endl;
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
		cout<<"����������֪�����������:";
		cin>>n;
		cout<<"�����������λ��:";
		cin>>k;
		ans(n,k);
	}
	
	return 0;
}
