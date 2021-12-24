#include<stdio.h>
#include<string.h>
 
 int ans(int n)
{
	if (n==1)
	{
		return 1;
	}
	else if (n==2)
	{
		return 2;
	}
	else 
	{
		return ans(n-1)+2*ans(n-2);
	}
}

int lz(char *zone1,char *zone2)
{
	char zone[32][10]={"UTC","GMT","BST","IST","WET","WEST","CET","CEST","EET","EEST","MSK","MSD","AST","ADT","NST","NDT","EST","EDT","CST","CDT","MST","MDT","PST","PDT","HST","AKST","AKDT","AEST","AEDT","ACST","ACDT","AWST"};
	float time[32]={0,0,1,1,0,1,1,2,2,3,3,4,-4,-3,-3.5,-2.5,-5,-4,-6,-5,-7,-6,-8,-7,-10,-9,-8,10,11,9.5,10.5,8};
	int i,j;
	for(i=0;strcmp(zone[i],zone1);i++);
	for(j=0;strcmp(zone[j],zone2);j++);
	return (int)((time[i]-time[j])*60);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int hours,minute;
		char time[9];
		scanf("%s",time);		
		switch(time[0])
		{
			case 'n':hours=12;
					 minute=0;
					 break;
			case 'm':hours=0;
					 minute=0;
					 break;
			default:sscanf(time,"%d:%d",&hours,&minute);
					hours=hours%12;
					scanf("%s",time);
					if(time[0]=='p') hours+=12;
		}
		char timezone1[5],timezone2[5];
		scanf("%s%s",timezone1,timezone2);
		int newTime;
		newTime=hours*60+minute+lz(timezone2,timezone1);
		if(newTime<0) 
		{
			newTime+=1440;
		}
		newTime%=1440;
		switch(newTime)
		{
			case 0:printf("midnight\n");
			break;
			case 720:printf("noon\n");
			break;
			default:
				hours=newTime/60;
				minute=newTime%60;
				if(hours==0)
				{
					printf("12:%d a.m.\n",minute);
				}
					
				else if(hours<12)
				{
					printf("%d:%d a.m.\n",hours,minute);
				}
					
				else if(hours==12)
				{
					printf("12:%d p.m.\n",minute);
				}
					
				else
				{
					printf("%d:%d p.m.\n",hours%12,minute);
				}
					
		}
	}
	return 0;
}
