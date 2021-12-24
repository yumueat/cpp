#include<stdio.h>
#include<string.h>
int main()
{
	char a[200];
	char b;
	int i,j,len;
	
	while(~scanf("%s",a))
	{
		j=0;
		int s=0;
		len=strlen(a);
		for (i=0;i<len;i++)
		{
			if (a[i]!='+')
			{
				j=j*10+(a[i]-'0');
			}
			else
			{
				s+=j;
				j=0;
			}
		}
		s+=j;
		printf("%d\n",s);
	}
	return 0;
}
