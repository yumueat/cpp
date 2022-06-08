#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        printf("%o\n", n);
    }
    system("pause");
    return 0;
}
