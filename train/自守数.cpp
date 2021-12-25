#include<iostream>
using namespace std;
int com(int a)
{
	int c[1000],d[1000],m[10000]={0};
	int n,j=0,i,len,s=0;
	while(a)
	{
		c[j]=a%10;
		d[j++]=a%10;
		a/=10;
		n++;
	}
/*	for (i=0;i<n;i++)
	{
		cout<<c[i]<<' '<<d[i]<<endl;
		cout<<m[i]<<endl; 
	}
	*/
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			m[i+j]+=c[i]*d[j];
		}
	}
	len=2*n;
	for (i=0;i<len;i++)
	{
		m[i+1]+=m[i]/10;
		m[i]=m[i]%10;
	}
	if (m[len+1]!=0)
	{
		len++;
	}
/*	for (i=0;i<len;i++)
	{
		cout<<m[i];
	}
	cout<<endl;*/
	for (i=n-1;i>=0;i--)
	{
		s=s*10+m[i];
	}
	return s;
}
/*int ans(int a,int b)
{
	int flag=0;
	while(b)
	{
		if (a%10==b%10)
		{
			a/=10;
			b/=10;
			flag=1;
		}
		else
		{
			flag=0;
			break;
		}
	}
//	cout<<flag<<endl;
	return flag;
}*/
int main()
{
	int m,n,i;
	cin>>m>>n;
	for (i=m;i<=n;i++)
	{
		if (com(i)==i)
		{
			cout<<i<<endl;
		}
	}

	return 0;
}
