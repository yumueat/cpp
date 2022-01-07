#include <iostream>
#include <string>
using namespace std;
 //获取next数组，就是对T串自己和自己的比较
int* getNext(string T)
{
    int* next = new int[T.size()];    // 声明next数组
    int T_len = T.size();
    int i = 0;    // T的下标
    int j = -1;
    next[0] = -1;
    while (i < T_len)
    {
        if (j == -1 || T[i] == T[j])
        {
            if (T[i + 1] == T[j + 1])  
                next[++i] = next[++j]; //核心步骤，标记
            else
                next[++i] = ++j;
        }
        else
            j = next[j];//回跳
    }
    return next;

}

// KMP算法,在 S 中找到 T 第一次出现的位置 
int KMP_index(string S, string T)    // S为主串，T为模式串
{
    int* next = getNext(T);
    int i = 0;        // S下标
    int j = 0;        // T下标
    int s_len = S.size();
    int t_len = T.size();
    while (i < s_len && j < t_len)//只有一次循环，所以时间复杂度低
    {
        if (j == -1 || S[i] == T[j])    //为第一个字符或S[i] == T[j]
        {
            i++;
            j++;
        }
        else
            j = next[j];        // 当前字符匹配失败，进行跳转
    }
    if (j == t_len)            // 匹配成功
        return i - j+1;
    return -1;
}


int main()
{
    string S = "acabaabcaabaabcac";    
    string T = "abaabcac";
    int num = KMP_index(S, T);
    cout << num<<endl;
    // system("pause");
    return 0;
}
