#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
	{
        int i,j,k,s,p;
	    int ans[3000][30],temp[3000][30];
	    int a,b,h;
	    p=0;
        for(i=1;i<=9;i++)
	    {
           ans[i][1]=i;
    
	    }
        p=9;
        for(i=2;i<=n;i++)
		{
            s=0;
            for(j=1;j<=p;j++)
			{
                for(k=0;k<=9;k++)
				{
                    ans[j][i]=k;
                    a=0;
                    for(b=1;b<=i;b++)
					{
                        a=a*10+ans[j][b];
                        a=a%i;
                    }                     
					if(a==0)
					{
                        s++;
                        for(h=1;h<=i;h++)
						{
                            temp[s][h]=ans[j][h];
                        }
                    }
                }
            }
            p=s;
            for(a=1;a<=p;a++)
			{
                for(b=1;b<=i;b++)
				{
                    ans[a][b]=temp[a][b];
                }
            }
        }
        for(i=1;i<=p;i++)
		{
            for(j=1;j<=n;j++)
			{
                printf("%d",ans[i][j]);
            }
            fflush(stdin);
            printf("\n");
        }
    }
    return 0;
} 
