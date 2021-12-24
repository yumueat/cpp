#include <stdio.h>
int main() 
{
    int n;
    while(~scanf("%d", &n))
    {
        int res[500]={0}, up = 0, cnt = 1, j = 0, i = 0;
        res[0] = 1;
        for(i = 0; i < n; i++)
        {
            up = 0;
            for(j = 0; j < cnt; j++)
            {
                up = res[j] * 2 + up;
                res[j] = up % 10;
                up /= 10;
            }
            if(j<=499){
                while(up)
                {
                    cnt++;
                    res[j++] += up % 10;
                    up /= 10;
                }
            }
        }
        for(i = 499; i >= 1; i--)
        {
            printf("%d",res[i]);
        }
        printf("%d", res[0] - 1);
        printf("\n");
    }
    return 0;
}

