#include <stdio.h>  
#include <string.h>  
void aa(unsigned int i ,int x)  
{
	int t;  
    t=i%x;  
    if(i/x>0)
	{
		aa(i/x,x);
	} 
          
    if(t>=10)
	{
		putchar(55+t);
	} 
          
    else
	{
		printf("%d",t);
	} 
      
    return;  
}//输出对应进制的数
int main()  
{  
	int p,r,i,n;  
	char d[10];//建立数组处理d的每一位上的数字  
	while(1)  
	{  
	    scanf("%d %d %s",&p,&r,d);  
	    if(p==0) 
		{
			break;
		}  
	    n=strlen(d);  
		for(i=0;i<n;i++)  
		{  
			if(d[i]<='9')
			{
				d[i]-='0';
			} 
			        
			else
			{
				d[i]=d[i]-'A'+10;
			} 
		        
		}//将十进制以上的进制的数转换成纯数字  
		long sum=0;  
		for(i=0;i<n;i++)
		{
			sum=sum*p+d[i];
		}  
		    //计算对应的十进制数  
		aa(sum,r);//转换成R进制数  
		printf("\n");  
	}  
    return 0;  
}  

