#include <iostream>
#include <iomanip>
using namespace std;
double recursion(int n, int *a, int sum)
{
	if (n == 2)
	{
		return a[n - 1] * 1.0;
	}
	else if (a[0] > sum)
	{
		return sum * 1.0;
	}
	else
	{
		return (sum + a[0]) / 2.0;
	}
}
int sum(int n, int *a)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}
int main()
{
	int n, i, j, temp;
	while (~scanf("%d", &n))
	{
		int *a = new int[n];
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n - i - 1; j++)
			{
				if (a[j] < a[j + 1])
				{
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		cout << fixed << setprecision(1) << recursion(n, a, sum(n, a)) << endl;
	}
	return 0;
}
