#include<iostream>
using namespace std;
int main()
{
 	int n;
 	int i,j;
 	while(cin>>n)
 	{
 		int a[1000][1000];  
		a[0][0]=1; 
	 	for(i=1;i<=n-1;i++) 
	 	{
	 		a[i][i]=a[i-1][i-1]+2*i; 
			if(i%2==1)
		 	{
			 	for(j=i;j>=0;j--)
			 	{
			 		a[j-1][i]=a[j][i]-1; 
				}
			 	    
			 	for(j=i;j>=0;j--) 
			 	{
			 		a[i][j-1]=a[i][j]+1; 
				}
			 	    
		    }
			else
			{
			 	for(j=i;j>=0;j--) 
			 	{
			 		a[j-1][i]=a[j][i]+1;
				}
			 	    
			 	for(j=i;j>=0;j--) 
			 	{
			 		a[i][j-1]=a[i][j]-1;
				}
			 	     
			}	
		}
		 
		for(i=0;i<n;i++)
		{
		 	for(j=0;j<n;j++)
		 	{
		 		cout<<a[i][j];
		 		if (j<n-1)
				{
				 	cout<<' ';
				}
			}
			 
			cout<<endl;
		}
	}
}

