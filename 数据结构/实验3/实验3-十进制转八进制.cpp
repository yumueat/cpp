#include<iostream>
using namespace std;
void ans(int a[],int b)//������ 
{
    int i=1;
    while(b)
    {
        a[i++]=b%8;//��8ȡ�ಢ�ұ����� 
        b/=8; 
    }
    a[0]=i;
}
void show (int a[])//���ջ 
{
    for (int i=a[0]-1;i>0;i--)
    {
        cout<<a[i];
    }
    cout<<endl;
}
int main()
{
    int a[255];
    int b;
    cin>>b;
    ans(a,b);
    show(a);
    return 0;
}
