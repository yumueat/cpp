#include<stdio.h>
#include<string.h>
int main()
{
char s[10000];
getchar();
while(scanf("%[^\n]",&s)!=EOF)
{
fflush(stdin);
int n=strlen(s);
int i;
  for(i=0; i<=n/2; i++)
        {
            if (s[i] != s[n-1-i])
                break;
        }
        if (i > n/2)
            {
			printf("YES\n");}
        else
            {
			printf("NO\n");}

    }
return 0;
}

