#include<iostream>
using namespace std;
void hanoi(int n,char a,char b,char c)
{
    int s=n+1;
    if (n==1)
    {
        printf("%dºÅ:%c-->%c\n",s-n,a,c);
    }
    else
    {
        hanoi(n-1,a,c,b);
        printf("%dºÅ%c-->%c\n",n,a,c);
        hanoi(n-1,b,a,c);
    }
}
int main()
{
    int n;
    cin>>n;
    hanoi(n,'a','b','c');
    
    return 0;
}
