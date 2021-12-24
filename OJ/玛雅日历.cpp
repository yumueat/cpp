#include<stdio.h>
#include<string.h>
struct lz
{
int day;
char name[100];
int year;
};
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		lz a,b;
		int i,date,k;
		scanf("%d%s%d",&a.day,a.name,&a.year);
		char habbmonth[19][10]=
		{"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen",
		"yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu"};
		char holly[20][10]=
		{"imix","ik","akbal","kan","chicchan","cimi","manik","lamat",
		"muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab",
		"canac","ahau"};
		for(i=0;i<19;i++)
		{
			if(strcmp(a.name,habbmonth[i])==0)
				break;
		}
			
		date=365*a.year+i*20+a.day+1;
		b.year=date/260;
		k=date%260;
		b.day=k%13;
		k=k%20;
		strcpy(b.name,holly[k-1]);
		printf("%d %s %d\n",b.day,b.name,b.year);
	}
	return 0;
}
