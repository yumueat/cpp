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
}//�����Ӧ���Ƶ���
int main()  
{  
	int p,r,i,n;  
	char d[10];//�������鴦��d��ÿһλ�ϵ�����  
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
		        
		}//��ʮ�������ϵĽ��Ƶ���ת���ɴ�����  
		long sum=0;  
		for(i=0;i<n;i++)
		{
			sum=sum*p+d[i];
		}  
		    //�����Ӧ��ʮ������  
		aa(sum,r);//ת����R������  
		printf("\n");  
	}  
    return 0;  
}  

