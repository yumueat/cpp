#include<iostream>
using namespace std;
int ans(int n)
{
    if (n==1)
    {
        return 1;
    }
    else
    {
         
        return n*ans(n-1);
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<ans(n);
    return 0;
}
