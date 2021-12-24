#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,e,min,max;
        cin>>a>>b>>c>>d>>e;
        int x1[a],x2[b],x3[c],x4[d],x5[e];
        int cnt=0;
        int temp1,temp2,temp3,temp4,temp5;
        int res1,res2,res3,res4;
        for(int i=0; i<a; i++)
            cin>>x1[i];
        for(int i=0; i<b; i++)
            cin>>x2[i];
        for(int i=0; i<c; i++)
            cin>>x3[i];
        for(int i=0; i<d; i++)
            cin>>x4[i];
        for(int i=0; i<e; i++)
            cin>>x5[i];
        cin>>min>>max;
        for(temp4=0; temp4<d; temp4++)
        {
            for(int i=temp4; i<d; i++)
            {
                if(i==temp4)
                {
                    res1=x4[temp4];
                }
                else
                {
                    res1=x4[temp4]+x4[i];
                }
                for(temp5=0; temp5<e; temp5++)
                {
                    for(int j=temp5; j<e; j++)
                    {
                        if(j==temp5)
                        {
                            res2=x5[temp5];
                        }
                        else
                        {
                            res2=x5[temp5]+x5[j];
                        }
                        for(temp2=0; temp2<b; temp2++)
                            for(temp1=0; temp1<a; temp1++)
                            {
                                res3=x2[temp2]+x1[temp1];
                                int res=res1+res2+res3;
                                if(res>=min&&res<=max)
                                {
                                	cnt++;
								}
                                    
                            }//情况1
                        for(temp3=0; temp3<c; temp3++)
                        {
                            res4=x3[temp3];
                            int res=res1+res2+res4;
                            if(res>=min&&res<=max)
                            {
                                cnt++;
                            }
                        }//情况二
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
}

