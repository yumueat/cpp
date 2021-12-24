#include<stdio.h>
int main()
{
	long long n;
	while(~scanf("%lld",&n))
	{
		long long h,m,s;
		n/=1000;
		s=n%60;
		n/=60;
		m=n%60;
		n/=60;
		h=n%24;
		printf("%02lld:%02lld:%02lld\n",h,m,s);
	}
	
	return 0;
}
