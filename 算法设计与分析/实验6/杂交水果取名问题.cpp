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
{						  //���õݹ������ˮ��ȡ��
	if (i == 0 && j == 0) //������
		return;
	if (i == 0)
	{ // arr1��ϣ����arr2��ʣ�ಿ��
		Output(i, j - 1);
		printf("%c", arr2[j - 1]);
		return;
	}
	else if (j == 0)
	{ // arr2��ϣ����arr1��ʣ�ಿ��
		Output(i - 1, j);
		printf("%c", arr1[i - 1]);
		return;
	}
	if (arr1[i - 1] == arr2[j - 1])
	{ // arr1[i-1]=arr2[j-1]�����
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
	int t; //���������������
	printf("������������: ");
	scanf("%d", &t);
	while (t--)
	{
		arr1 = "";
		arr2 = "";
		cin >> arr1 >> arr2;
		m = arr1.length(); // mΪarr1�ĳ���
		n = arr2.length(); // nΪarr2�ĳ���
		LCSlength();	   //���dp, ���Ҹ�b[][]���鸳ֵ
		printf("���: ");
		Output(m, n); //�����ˮ��ȡ��
		printf("\n");
	}
	return 0;
}

