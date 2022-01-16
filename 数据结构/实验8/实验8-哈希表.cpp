#include<iostream>
using namespace std;
typedef struct HashTable{
	bool flag=false;
	int data;
}hashtable;
typedef struct ZipHashTable{
	ZipHashTable * conflict = NULL;
	int data;
	bool flag=false;
}ziphashtable;
int Hash(int n)//哈希函数
{
	return n%11;
}
void linearProbing(int  * s, hashtable * t,int len)//线性探测
{
	for (int i=0;i<len;i++) 
	{
		int hash = Hash(s[i]);
		if (t[hash].flag==false)
		{
			t[hash].data = s[i];
			t[hash].flag=true;
		}
		else
		{
			while(1)
			{
				if (++hash>=len)
				{
					hash=0;
				}
				if  (t[hash].flag==false)
				{
					t[hash].data = s[i];
					t[hash].flag=true;
					break;
				}
			}
			
		}
	}
}
void secondaryRehashing (int * s, hashtable * t,int len)//二次探测
{
	for (int i=0;i<len;i++)
	{
		int hash = Hash(s[i]);
		for (int j=0;;j++)
		{
			int hash1 = (hash+j*j)%len;
			int hash2 = hash-j*j;
			if (hash2<0)
			{
				hash2 = len + hash2;
			}
			if (t[hash1].flag==false)
			{
				t[hash1].flag=true;
				t[hash1].data=s[i];
				break;
			}
			else if (t[hash2].flag==false)
			{
				t[hash2].flag=true;
				t[hash2].data=s[i];
				break;
			}
		}
	}
}
void Chaining(int  * s, ziphashtable * t,int len)//链地址法
{
	for (int i=0; i<len; i++)
	{
		int hash = Hash(s[i]);
		if (t[hash].flag==false)
		{
			t[hash].flag=true;
			t[hash].data=s[i];
			t[hash].conflict = NULL;
		}
		else
		{
			ziphashtable * p = &t[hash];
			while(p->conflict)
			{
				p=p->conflict;
			}
			ziphashtable * temp = new ziphashtable;
			temp->conflict=NULL;
			p->conflict=temp;
			temp->data=s[i];
			temp->flag=true;
		}
	}
}
int main()
{
	int s[]={19, 01, 23, 14, 55, 68, 11, 82, 36};
	int len = sizeof(s)/sizeof(s[0]);
	hashtable t1[sizeof(s)/sizeof(s[0])];
	hashtable t2[sizeof(s)/sizeof(s[0])];
	ziphashtable t3[sizeof(s)/sizeof(s[0])];
	for (int i  = 0; i < len; i++)//初始化链地址法使用的哈希表
	{
		t3[i].data = -1;//设-1为空
		t3->conflict = NULL;
	}

	linearProbing(s,t1,len);//线性探测处理冲突
	for (int i=0; i<len; i++)//验证是否成功
	{
		cout<<t1[i].data<<" ";
	}
	cout<<endl;

	secondaryRehashing(s,t2,len);//二次探测处理冲突
	for (int i=0; i<len; i++)//验证是否成功
	{
		cout<<t2[i].data<<' ';
	}

	Chaining(s,t3,len);//链地址法处理冲突
	for (int i=0; i<len; i++)//验证是否成功
	{
		ziphashtable * p = &t3[i];
		while(p)
		{
			cout<<p->data<<' ';
			p=p->conflict;
		}
		cout<<endl;
	}

	return 0; 
}
