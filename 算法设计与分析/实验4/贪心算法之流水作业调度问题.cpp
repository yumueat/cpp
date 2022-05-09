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

int solve(int n, int *a, int *b) //�����ˮ��ҵ��������
{
	int i, j, k;
	NodeType c[N];
	for (i = 0; i < n; i++) // n����ҵ��,���ÿ����ҵ����С�ӹ�ʱ��
	{
		c[i].no = i;
		c[i].group = (a[i] <= b[i]);
		// a[i]<=b[i]��Ӧ��1��N1,a[i]>b[i]��Ӧ��0��N2
		c[i].time = a[i] <= b[i] ? a[i] : b[i];
		//��1����a[i],��0����b[i]
	}
	sort(c, c + n); // cԪ�ذ�time��������
	j = 0;
	k = n - 1;
	for (i = 0; i < n; i++) //ɨ��c����Ԫ��,�������ŵ��ȷ���
	{
		if (c[i].group == 1) //��1��,��time�������з���best��ǰ�沿��
			best[j++] = c[i].no;
		else //��0��,��time�ݼ����зŵ�best�ĺ��沿��
			best[k--] = c[i].no;
	}
	int f1 = 0; //�ۼ�M1�ϵ�ִ��ʱ��
	int f2 = 0; //���ŵ����µ�������ʱ��
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
	
	cout << "��������ҵ��:";
	cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	cout << "��ֱ�������ҵʱ��:";
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	cout << "���ŵ���ʱ��Ϊ��" << solve(n, a, b) << endl;
	cout << "����Ϊ��";
	for (i = 0; i < n; i++)
	{
		cout << best[i] + 1;
	}
	cout << endl;
	return 0;
}
