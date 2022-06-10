#include <iostream>
#include <cmath>
using namespace std;
int *q;
int *sta;
int *mp;
int n = 8, sum = 0, k = 0;
bool cmp() //�ӿ��еİڷŷ�����ѡ����������
{
    for (int i = 0; i < k; i++)
    {
        if (q[mp[i]] != sta[mp[i]])
        {
            return false;
        }
    }
    return true;
}
bool place(int i) //�жϸ�λ���Ƿ����
{
    for (int j = 1; j < i; j++) //�ӵ�һ�е�����һֱ�жϵ�����ѡ�����һ��
    {
        if (q[j] == q[i] || abs(i - j) == abs(q[i] - q[j])) //�жϺ��������б�����Ƿ�������
        {
            return false;
        }
    }
    return true;
}
void backTrace() //�����㷨
{
    int i = 1;
    q[i] = 0; //��ʼ��q���飬����һ�����Ӱ��ڵ�һ�У�����ʱλ�ڵ�0�У�������Ϻ���ѭ�������+1
    while (i >= 1)
    {
        q[i]++;                        //ÿ��ѭ��������һ��
        while (q[i] <= n && !place(i)) //�ж�һ�������ҵ�λ���Ƿ����
        {
            q[i]++; //�������������һ�м�����
        }
        if (q[i] <= n) //�����һ���к��ʵ�λ��
        {
            if (i == n && cmp()) //�Ҵ�ʱ�Ѿ�����8�����ӣ��Ǿ͵õ���һ�׿��еİڷŷ���
            {
                sum++; //������װڷŷ���������Ŀ���Ƶ�����λ�ã����+1
            }
            else //�����һ���к��ʵ�λ��������û���꣬���������һ��
            {
                i++;
                q[i] = 0;
            }
        }
        else //�����һ��û�к��ʵ�λ�ã�����ǰ����
        {
            i--;
        }
    }
}
int main()
{
    q = new int[n + 1];   //�洢�ڷŷ���
    sta = new int[n + 1]; //�洢�Ѿ�ȷ�������ӣ���Ŀ������
    mp = new int[n + 1];  // ������Ŀ�����������ڵ���
    int i, j, temp;
    for (i = 1; i <= n; i++) //��ʼ��sta��mp���飬��¼��Ŀ�������ӵ�λ��
    {
        for (j = 1; j <= n; j++)
        {
            cin >> temp;
            if (temp == 1)
            {
                sta[i] = j;
                mp[k++] = i;
            }
        }
    }
    backTrace();
    cout << sum << endl;
    system("pause");
    return 0;
}
