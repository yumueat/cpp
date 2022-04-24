#include <iostream>
#define MAX 32
using namespace std;
int a[MAX][MAX];
void recursion(int n, int pxs, int pxe, int pys, int pye, int num)
{
	if (n == 2)
	{
		a[pxs][pys] = num;
		a[pxs][pye] = num + 1;
		a[pxe][pys] = num + 1;
		a[pxe][pye] = num;
	}
	else
	{
		recursion(n / 2, pxs, pxe - n / 2, pys, pye - n / 2, num);
		recursion(n / 2, pxs, pxe - n / 2, pys + n / 2, pye, num + n / 2);
		recursion(n / 2, pxs + n / 2, pxe, pys, pye - n / 2, num + n / 2);
		recursion(n / 2, pxs + n / 2, pxe, pys + n / 2, pye, num);
	}
}
int main()
{
	int n;
	cin >> n;
	int i, j;
	recursion(n, 0, n - 1, 0, n - 1, 1);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%2d",a[i][j]);
			cout<<" "; 
		}
		cout << endl;
	}
	return 0;
}
