#include<iostream>
using namespace std;
int a[1000];
int oil(int n, int m)
{
	if (n == 0 || m < 0)
	return 0;
	else
	{
		if (m == a[n])
		{
			return 1;
		}
			
		else
		{
			if (oil(n - 1, m - a[n]) == 1)
			{
				return 1;
			}
				
			if (oil(n - 1, m) == 1)
			{
				return 1;
			}
				
		}
	}
	return 0;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		if (oil(n, m))
		{
			printf("yes\n");
		}
			
		else
		{
			printf("no\n");
		}
	}
	return 0;

}
