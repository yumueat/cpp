#include<stdio.h>
#include<string.h>
struct lz
{
	int number;
	char country[100];
	int people;
	char nation[100];
};
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int i,j,k=-1,d,temp,m;
		lz t[100];
		char s[100],q[100],w[100]={"China"};
		for(i=0;i<n;i++)
		{
			scanf("%d%s%d%s",
			&t[i].number,t[i].country,&t[i].people,t[i].nation);
		}
			
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1-i;j++)
			{
				if(strcmp(t[j].country,t[j+1].country)>0)
				{	
					strcpy(s,t[j].country);
					strcpy(t[j].country,t[j+1].country);
					strcpy(t[j+1].country,s);
					temp=t[j].number;
					t[j].number=t[j+1].number;
					t[j+1].number=temp;
					strcpy(q,t[j].nation);
					strcpy(t[j].nation,t[j+1].nation);
					strcpy(t[j+1].nation,q);
					m=t[j].people;
					t[j].people=t[j+1].people;
					t[j+1].people=m;
				}
			}
				
		}
			
		for(i=0;i<n;i++)
		{
			if(strcmp(w,t[i].country)==0)
			{
				k=1;
				d=i;
				continue;
			}
			printf("%d %s %d %s\n",
			t[i].number,t[i].country,t[i].people,t[i].nation);
		}
			
		if(k>0)
		{
			printf("%d %s %d %s\n",
			t[d].number,t[d].country,t[d].people,t[d].nation);
		}
	}
	return 0;

}
