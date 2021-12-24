#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000],b[1000];
	while(~scanf("%s%s",a,b))
	{
		int i,j,lena,lenb,k;
		lena=strlen(a);
		lenb=strlen(b);
		int c[10000],d[10000];
		for(i=0;i<lena;i++)
		{
			c[i]=a[lena-1-i]-'0';
		}
			
		for(i=0;i<lenb;i++)
		{
			d[i]=b[lenb-1-i]-'0';
		}
			
		int m[10000];
		for(i=0;i<10000;i++)
		{
			m[i]=0;
		}
		
		for(i=0;i<lena;i++)
		{
			for(j=0;j<lenb;j++)
			{
				m[i+j]+=c[i]*d[j];
			}
				
		}
			
		k=lena+lenb;
		for(i=0;i<k;i++)
		{
			m[i+1]+=m[i]/10;
			m[i]=m[i]%10;
		}
		if(m[k+1]>0)
		{
			k++;
		}
			
		for(i=k-2;i>=0;i--)
		{
			printf("%d",m[i]);
		}
		
		printf("\n");
	}
	
		return 0;
}
