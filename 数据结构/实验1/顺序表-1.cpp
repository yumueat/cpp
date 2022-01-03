#include<iostream>
using namespace std;
int main()
{
	int i;
	char flag[10]="ajcniydu";//新建顺序表 
	for (i=0;i<=7;i++)
	{
		cout<<flag[i]<<' ';
	}//查看是否新建成功 
	cout<<endl; 
	for (i=9;i>=2;i--)
	{
		flag[i]=flag[i-1];
	}//将第三位开始的数据后移 
	flag[2]='p';//插入数据 
	for (i=0;i<=8;i++)
	{
		cout<<flag[i]<<' ';
	}//查看插入是否成功 
	cout<<endl;
	for (i=2;i<=9;i++)
	{
		flag[i]=flag[i+1];
	}//从第3位开始将数据前移，直接覆盖第3位的数据，起到删除的效果
	for (i=0;i<=7;i++)
	{
		cout<<flag[i]<<' ';
	}//查看删除是否成功 
	return 0;
}
