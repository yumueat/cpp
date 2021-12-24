#include <stdio.h>
#include <string.h>
int hex(char*s,int b)
{
    int res = 0,len = strlen(s),i;
    for(i = 0;i < len;i++)
    {
        if(s[i] - '0' >= b) 
		{
			return -1;
		}
        res *= b;
        res += s[i] - '0';
    }
    return res;
}
int main()
{
    char p[8],q[8],r[8];
    int pn,qn,rn,i;
    int n,j;
	scanf("%d",&n); 
	for (j=1;j<=n;j++)
	{
		scanf("%s%s%s",p,q,r);
	    for(i = 2;i < 17;i++)
	    {
	        if((pn = hex(p,i)) == -1 || (qn = hex(q,i)) == -1 || (rn = hex(r,i)) == -1) 
			{
				continue;
			}
	        if(rn == qn * pn)
	        {
	            printf("%d\n",i);
	            break;
	        }
	    }
	    if(i == 17) 
		{
			printf("0\n");
		}
	}
    
    return 0;
}
