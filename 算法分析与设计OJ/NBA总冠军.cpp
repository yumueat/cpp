#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct dic
{
    string name;
    string year;
};
bool cmp(dic &a, dic &b)
{
    return a.year < b.year;
}
int main()
{
    int n, i, flag, lenth, j;
    string temp;
    while (cin >> n)
    {
        dic dict[81];
        getchar();
        for (i = 0; i < n; i++)
        {

            getline(cin, temp);
            lenth = temp.size();
            for (j = 0; j < lenth; j++)
            {
                if (temp[j] == ' ')
                {
                    flag = j;
                }
            }
            dict[i].name = temp.substr(0, flag);
            dict[i].year = temp.substr(flag + 1);
        }
        sort(dict, dict + n, cmp);
        for (i = 0; i < n; i++)
        {
            if (dict[i].year == dict[i + 1].year)
            {
                continue;
            }
            cout << dict[i].year << " " << dict[i].name << endl;
        }
    }
    system("pause");
    return 0;
}
