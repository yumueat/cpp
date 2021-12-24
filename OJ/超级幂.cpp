#include<stdio.h>
#include<string.h>
#define X 1337
int b[100]={0};
void transform(char p[],int q[],int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		q[len-i-1]=p[i]-'0';
	}
	
}
int cut(int a,int loc,int ans,int len)
{
	if(loc>len)
	{
		return ans;
	}
		
	int k,t,i;
	k=a%X;
	for(i=1;i<=b[loc];i++)
	{
		ans=(ans*k)%X;
	}
	t=1;	
	for(i=1;i<=10;i++)
	{
		t=(t*k)%X;
	}
		
	
	return cut(t,loc+1,ans,len);
}

int main()
{
	int a,n;
	char b1[100];
	while(~scanf("%d",&a))
	{
		scanf("%s",b1);
		transform(b1,b,strlen(b1));
		printf("%d\n",cut(a,0,1,strlen(b1)-1));
	}
	return 0;
}
