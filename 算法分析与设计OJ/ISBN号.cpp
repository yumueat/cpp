#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, i, flag, lenth, j;
    cin >> n;
    while (n--)
    {
        string isbn;
        int idCode, flag;
        cin >> isbn;
        idCode = ((isbn[0] - '0') * 1 + (isbn[2] - '0') * 2 + (isbn[3] - '0') * 3 + (isbn[4] - '0') * 4 + (isbn[6] - '0') * 5 + (isbn[7] - '0') * 6 + (isbn[8] - '0') * 7 + (isbn[9] - '0') * 8 + (isbn[10] - '0') * 9) % 11;
        flag = isbn[12] - '0';
        if (flag == idCode)
        {
            cout << "Right" << endl;
        }
        else
        {
            cout << isbn[0] << '-' << isbn[2] << isbn[3] << isbn[4] << '-' << isbn[6] << isbn[7] << isbn[8] << isbn[9] << isbn[10] << '-' << idCode << endl;
        }
    }
    system("pause");
    return 0;
}
