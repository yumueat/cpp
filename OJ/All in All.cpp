#include <stdio.h>
#include <string.h>
#define  N 100001
char str1[N],str2[N];
int main()
{
    int i,j,len1,len2;
    while(scanf("%s %s",str1,str2)!=EOF)
    {
        j=0;
        len1=strlen(str1);
        len2=strlen(str2);
        for(i=0;i<len2;i++)
        {
        	if(str1[j]==str2[i])
        	{
        		j++;
			}
                
		}
            
        if(j==len1)
        {
        	printf("Yes\n");
		}
            
        else
        {
        	printf("No\n");
		}
            
    }
    return 0 ;
}
