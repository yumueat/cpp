#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, m, i, j;
    cin >> n >> m;
    int checkerBoard[100][100] = {0};
    checkerBoard[1][1] = 1;
    for (j = 2; j <= n; j++) //�������ܵĵ�
    {
        for (i = 2; i <= m; i++)
        {
            if (j >= 3) //���ܲ���������������
            {
                if (i >= 2)
                { //�����λ�õĿ���Ϊ�ܵ����λ�õ���һ�������п��ܼ�����
                    checkerBoard[i][j] += checkerBoard[i - 1][j - 2];
                }
            }
            if (j >= 2) //���ܲ�������������
            {
                if (i >= 3)
                {
                    checkerBoard[i][j] += checkerBoard[i - 2][j - 1];
                }
            }
        }
    }
    cout << checkerBoard[m][n] << endl;
    // for (i = 1; i <= n; i++)
    // {
    //     for (j = 1; j <= m; j++)
    //     {
    //         cout << checkerBoard[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    system("pause");
    return 0;
}
