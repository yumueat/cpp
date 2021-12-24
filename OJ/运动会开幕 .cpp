#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n,i,j;
	while (cin>>n)
	{
		struct country 
		{
			int num;
			char name;
			int peo;
			char location;
		}cou[n],temp;
		for (i=0;i<n;i++)
		{
			cin>>cou[i].num>>cou[i].name>>cou[i].peo>>cou[i].location;
		}
		for (i=0;i<n;i++)
		{
			for (j=0;j<n-i;j++)
			{
				char s1,s2;
				strcpy(s1,cou[i].name);
				strcpy(s2,cou[2].name);
				if (strcmp(cou[i].name,cou[i+1].name)>0)
				{
					temp=cou[i];
					cou[i]=cou[i+1];
					cou[i+1]=temp;
				}
			}
		}
		for (i=0;i<n;i++)
		{
			cout<<cou[i].num<<cou[i].name<<cou[i].peo<<cou[i].location;
		}
	}
	return 0;
}
