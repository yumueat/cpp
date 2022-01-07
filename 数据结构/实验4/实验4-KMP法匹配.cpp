#include <iostream>
#include <string>
using namespace std;
 //��ȡnext���飬���Ƕ�T���Լ����Լ��ıȽ�
int* getNext(string T)
{
    int* next = new int[T.size()];    // ����next����
    int T_len = T.size();
    int i = 0;    // T���±�
    int j = -1;
    next[0] = -1;
    while (i < T_len)
    {
        if (j == -1 || T[i] == T[j])
        {
            if (T[i + 1] == T[j + 1])  
                next[++i] = next[++j]; //���Ĳ��裬���
            else
                next[++i] = ++j;
        }
        else
            j = next[j];//����
    }
    return next;

}

// KMP�㷨,�� S ���ҵ� T ��һ�γ��ֵ�λ�� 
int KMP_index(string S, string T)    // SΪ������TΪģʽ��
{
    int* next = getNext(T);
    int i = 0;        // S�±�
    int j = 0;        // T�±�
    int s_len = S.size();
    int t_len = T.size();
    while (i < s_len && j < t_len)//ֻ��һ��ѭ��������ʱ�临�Ӷȵ�
    {
        if (j == -1 || S[i] == T[j])    //Ϊ��һ���ַ���S[i] == T[j]
        {
            i++;
            j++;
        }
        else
            j = next[j];        // ��ǰ�ַ�ƥ��ʧ�ܣ�������ת
    }
    if (j == t_len)            // ƥ��ɹ�
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
