#include<iostream>
using namespace std;
int main()
{
	int i,j,k;
	char foo[]="acdijtuy";
	char bar[]="cfklns";//新建顺序表 
	for (i=0;i<8;i++)
	{
		cout<<foo[i]<<' ';
	}
	cout<<endl;
	for (i=0;i<6;i++)
	{
		cout<<bar[i]<<' ';
	}//查看是否创建成功
	cout<<endl;
	char flag[14];//新建顺序表 
	i=j=k=0;
	while (i<14)
	{
		while(j<8&&k<6)//比较数据大小进行合并 
		{
			if (foo[j]<=bar[k])
			{
				flag[i++]=foo[j++];
			}
			else
			{
				flag[i++]=bar[k++];
			}
		}
		if (j<8)//处理剩余的数据 
		{
			flag[i++]=foo[j++];
		}
		if (k<6)
		{
			flag[i++]=bar[k++];
		}
	} //合并顺序表 
	for (i=0;i<14;i++)
	{
		cout<<flag[i]<<' ';
	}//检验合并结果 
	return 0;
}
