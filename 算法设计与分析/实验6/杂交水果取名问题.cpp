#include <iostream>
#include <cstring>
#include <vector>
#define MAX 51
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;
int m, n;
int dp[MAX][MAX];
string arr1, arr2;

void LCSlength()
{
	int i, j;
	for (i = 0; i <= m; i++)
	{
		dp[i][0] = 0;
	}
	for (j = 0; j <= n; j++)
	{
		dp[0][j] = 0;
	}
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (arr1[i - 1] == arr2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
}
void Output(int i, int j)
{						  //利用递归输出新水果取名
	if (i == 0 && j == 0) //输出完毕
		return;
	if (i == 0)
	{ // arr1完毕，输出arr2的剩余部分
		Output(i, j - 1);
		printf("%c", arr2[j - 1]);
		return;
	}
	else if (j == 0)
	{ // arr2完毕，输出arr1的剩余部分
		Output(i - 1, j);
		printf("%c", arr1[i - 1]);
		return;
	}
	if (arr1[i - 1] == arr2[j - 1])
	{ // arr1[i-1]=arr2[j-1]的情况
		Output(i - 1, j - 1);
		printf("%c", arr1[i - 1]);
		return;
	}
	else if (arr1[i - 1] != arr2[j] && dp[i - 1][j] > dp[i][j - 1])
	{
		Output(i - 1, j);
		printf("%c", arr1[i - 1]);
		return;
	}
	else
	{
		Output(i, j - 1);
		printf("%c", arr2[j - 1]);
		return;
	}
}
int main()
{
	int t; //输入测试用例个数
	printf("测试用例个数: ");
	scanf("%d", &t);
	while (t--)
	{
		arr1 = "";
		arr2 = "";
		cin >> arr1 >> arr2;
		m = arr1.length(); // m为arr1的长度
		n = arr2.length(); // n为arr2的长度
		LCSlength();	   //求出dp, 并且给b[][]数组赋值
		printf("结果: ");
		Output(m, n); //输出新水果取名
		printf("\n");
	}
	return 0;
}

