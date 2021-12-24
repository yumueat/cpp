#include<stdio.h>
int main()
{
	int a,b,s;
	scanf("%d %d",&a,&b);
	s=a+b;
	printf("%d",s);
	return 0;
}
/*#include<stdio.h>
 
#define MAX 1000                
 
int main(){
    int i=0, n, flag;
    char s[MAX];
//    while(1)
//    {
    	while((s[i++]=getchar())!='\n'); 
		flag = n = 0;        
	    for (i = 0;s[i]; i++) 
		{
	        if (s[i] == ' ')
	            flag = 0;        
	        else if (!flag) 
			{    
	            n++;
	            flag = 1;        
	        }
	    }
		printf("%d\n", n);
// 		i=0;
// 		getchar();
 		
//	}
    return 0;
}*/
