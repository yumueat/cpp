#include<iostream>
using namespace std;
typedef struct Sqlist//定义结构体，用于新建顺序表 
{
	char a[255];
	int len;
}SqList;
void ReverseSqList(SqList &L)//倒置顺序表的函数 
{
	char temp;
	for (int i=0;i<=L.len/2;i++)
	{
		temp=L.a[i];
		L.a[i]=L.a[L.len-1-i];
		L.a[L.len-1-i]=temp;
	}
}
void show(SqList &L)//输出顺序表 
{
	for (int i=0;i<L.len;i++)
	{
		cout<<L.a[i]<<' ';
	}
	cout<<endl;
}
int main()
{
	int n,i;
	cin>>n;//输入数据个数 
	SqList L;
	for (i=0;i<n;i++)
	{
		cin>>L.a[i];//依次输入数据并赋值 
	}
	L.len=i;//记录数据个数 
	show (L); 
	ReverseSqList(L);//倒置 
	show(L);//验证结果 
	return 0;
}
