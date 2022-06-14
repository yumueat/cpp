#include <iostream>
#include <string>
#define MAX 100
using namespace std;
int fans[MAX][MAX];
int main()
{
    int n, i, j;
    while (cin >> n)
    {
        int *count = new int[n];
        for (int i = 0; i < n; i++)
        {
            count[i] = 0;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> fans[i][j];
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (fans[i][j] == 1 && fans[j][i] != 1)
                {
                    count[j]++;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            cout << count[i] << endl;
        }
    }
    system("pause");
    return 0;
}
