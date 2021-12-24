#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000];
	while(~scanf("%s",a))
	{
		int len=strlen(a);
		int i;
		for (i=0;i<len;i++)
		{
			if (a[i]=='A')
			{
				printf(".-");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='B')
			{
				printf("-...");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='C')
			{
				printf("-.-.");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='D')
			{
				printf("-..");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='E')
			{
				printf(".");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='F')
			{
				printf("..-.");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='G')
			{
				printf("--.");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='H')
			{
				printf("....");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='I')
			{
				printf("..");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='J')
			{
				printf(".---");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='K')
			{
				printf("-.-");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='L')
			{
				printf(".-..");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='M')
			{
				printf("--");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='N')
			{
				printf("-.");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='O')
			{
				printf("---");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='P')
			{
				printf(".--.");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='Q')
			{
				printf("--.-");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='R')
			{
				printf(".-.");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='S')
			{
				printf("...");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='T')
			{
				printf("-");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='U')
			{
				printf("..-");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='V')
			{
				printf("...-");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='W')
			{
				printf(".--");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='X')
			{
				printf("-..-");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='Y')
			{
				printf("-.--");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='Z')
			{
				printf("--..");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='0')
			{
				printf(".----");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='1')
			{
				printf("..---");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='2')
			{
				printf("...--");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='3')
			{
				printf("....-");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='4')
			{
				printf(".....");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='5')
			{
				printf("-....");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='6')
			{
				printf("--...");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='7')
			{
				printf("---..");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='8')
			{
				printf("----.");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
			if (a[i]=='9')
			{
				printf("-----");
				if (i<len-1)
				{
					printf("===");
				}
				continue;
			}
		}
		printf("\n");
//		memset(a,0,sizeof(a));
	}
	return 0;
}

