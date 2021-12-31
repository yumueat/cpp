#include<iostream>
#include<cstring>
using namespace std;
#define MAX 255

int main()
{
    string foo="hello world";
    string bar="hello nuist";
    string temp1;
    string temp2;
    temp1=foo+bar;
    temp2=foo;
    if (foo==bar)
    {
        cout<<"两字符串相同"<<endl;
    }
    else
    {
        cout<<"两字符串不相同"<<endl;
    }
    cout<<temp1<<endl;
    cout<<temp2<<endl;
    return 0;
}
