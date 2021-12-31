#include<iostream>
using namespace std;
#define MAX 255
int length(char *foo)
{
    int foolen=0;
    while(foo[foolen++]!='\0');
    return --foolen;
}
bool charCompare(char * foo,char *bar)
{
    int foolen=0,barlen=0;
    int i,j;
    foolen=length(foo);
    barlen=length(bar);
    if (foolen!=barlen)
    {
        return false;
    }
    else
    {
        for (i=0;i<barlen;i++)
        {
            if (foo[i]!=bar[i])
            {
                return false;
            }
        }
        return true;
    }
}
void charConnect(char * foo,char * bar,char * temp)
{
    int foolen=length(foo);
    int barlen=length(bar);
    int i,j;
    for (i=0;i<foolen;i++)
    {
        temp[i] = foo[i];
    }
    for (i=0;i<barlen;i++)
    {
        temp[i+foolen] = bar[i];
    }
    temp[i+foolen]='\0';
}
void charCopy(char *foo,char *bar)
{
    int foolen=length(foo);
    int i;
    for (i=0;i<=foolen;i++)
    {
        bar[i] = foo[i];
    }

}
int main()
{
    char foo[MAX]="abcdefg";
    char bar[MAX]="qwertyu";
    char temp1[MAX];
    char temp2[MAX];
    cout<<charCompare(foo,bar)<<endl;
    charConnect(foo,bar,temp1);
    cout<<temp1<<endl;
    charCopy(foo,temp2);
    cout<<temp2<<endl;
    return 0;
}
