#include <iostream>
#include <algorithm>
using namespace std;
#define N 10
struct NodeType
{
	int no;
	bool group;
	int time;
	bool operator<(const NodeType &s) const { return time < s.time; }
};
int best[N];

int solve(int n, int *a, int *b) //求解流水作业调度问题
{
	int i, j, k;
	NodeType c[N];
	for (i = 0; i < n; i++) // n个作业中,求出每个作业的最小加工时间
	{
		c[i].no = i;
		c[i].group = (a[i] <= b[i]);
		// a[i]<=b[i]对应第1组N1,a[i]>b[i]对应第0组N2
		c[i].time = a[i] <= b[i] ? a[i] : b[i];
		//第1组存放a[i],第0组存放b[i]
	}
	sort(c, c + n); // c元素按time递增排序
	j = 0;
	k = n - 1;
	for (i = 0; i < n; i++) //扫描c所有元素,产生最优调度方案
	{
		if (c[i].group == 1) //第1组,按time递增排列放在best的前面部分
			best[j++] = c[i].no;
		else //第0组,按time递减排列放到best的后面部分
			best[k--] = c[i].no;
	}
	int f1 = 0; //累计M1上的执行时间
	int f2 = 0; //最优调度下的消耗总时间
	for (i = 0; i < n; i++)
	{
		f1 += a[best[i]];
		f2 = max(f2, f1) + b[best[i]];
	}
	return f2;
}
int main()
{
	int n, i;
	
	cout << "请输入作业数:";
	cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	cout << "请分别输入作业时间:";
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	cout << "最优调度时间为：" << solve(n, a, b) << endl;
	cout << "方案为：";
	for (i = 0; i < n; i++)
	{
		cout << best[i] + 1;
	}
	cout << endl;
	return 0;
}
