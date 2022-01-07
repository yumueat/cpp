#include <iostream>
#include<cstring>
using namespace std;
int index(char s[],char t[],int pos=0)
{
    int i=0,j=0,flag=0,k;
    for (k=pos;k<strlen(s);k++)
    {
        for (i=k;i<strlen(s);i++)
        {
            if (s[i]==t[j++])
            {
                flag++;
                if (flag==strlen(t))
                {
                    return i+2-strlen(t);
                }
            }
            else
            {
                j=0;
                flag=0;
            }
        }
    }
    cout<<"Ã»ÓÐÆ¥ÅäµÄ×Ö·û´®"<<endl;
}
int main()
{
    char s[]="acabaabcaabaabcac";
    char t[]="abaabcac";
    cout<<index(s,t,0);
    return 0;
}
