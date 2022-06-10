#include <iostream>
#include <cmath>
using namespace std;
int *q;
int *sta;
int *mp;
int n = 8, sum = 0, k = 0;
bool cmp() //从可行的摆放方法中选择符合题意的
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
bool place(int i) //判断该位置是否合理
{
    for (int j = 1; j < i; j++) //从第一行的棋子一直判断到现在选择的这一行
    {
        if (q[j] == q[i] || abs(i - j) == abs(q[i] - q[j])) //判断横向纵向和斜线上是否有棋子
        {
            return false;
        }
    }
    return true;
}
void backTrace() //回溯算法
{
    int i = 1;
    q[i] = 0; //初始化q数组，将第一颗棋子摆在第一行，且暂时位于第0列，方便配合后面循环里面的+1
    while (i >= 1)
    {
        q[i]++;                        //每次循环往后找一列
        while (q[i] <= n && !place(i)) //判断一下现在找的位置是否合理
        {
            q[i]++; //不合理就再往后一列继续找
        }
        if (q[i] <= n) //如果这一行有合适的位置
        {
            if (i == n && cmp()) //且此时已经找完8个棋子，那就得到了一套可行的摆放方法
            {
                sum++; //如果这套摆放方法符合题目限制的棋子位置，则解+1
            }
            else //如果这一行有合适的位置且棋子没找完，则继续找下一行
            {
                i++;
                q[i] = 0;
            }
        }
        else //如果这一行没有合适的位置，则向前回溯
        {
            i--;
        }
    }
}
int main()
{
    q = new int[n + 1];   //存储摆放方案
    sta = new int[n + 1]; //存储已经确定的棋子（题目给出）
    mp = new int[n + 1];  // 储存题目给出棋子所在的行
    int i, j, temp;
    for (i = 1; i <= n; i++) //初始化sta和mp数组，记录题目给的棋子的位置
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
