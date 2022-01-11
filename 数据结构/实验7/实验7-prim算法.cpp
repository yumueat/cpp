#include <iostream>
using namespace std;
#define MAXCOST 0x7fffffff
#define VMAX 100
int graph[VMAX][VMAX];
void prim(int n)
{
    //lowcost[i]��ʾ��iΪ�յ����СȨֵ��mst[i]��ʾ��Ӧlowcost[i]�����
    int lowcost[VMAX],mst[VMAX];
    //minΪȨֵ����Сֵ��indexΪλ��
    int i,j,min,index;
    //��Ե�һ�������Ԥ����
    for (i=1;i<n;i++)
    {
        lowcost[i] = graph[0][i];//�洢0��ÿһ�����Ȩֵ���������ıȽ�
        mst[i]=0;//��¼��Щ�յ�Ϊi�ıߵ������0
    }
    // mst[0]=0;
    for (i=1;i<n;i++){
        min=MAXCOST;//�ȸ���Сֵ��һ�����ֵ���������ıȽ�
        index=0;
        for (j=1;j<n;j++)
        {
            if (lowcost[j]<min&&lowcost[j]!=0)
            {
                //�������бߣ�Ѱ��Ȩֵ��С�����
                min=lowcost[j];
                //��¼��СȨֵ��Ӧ�ĵ�
                index=j;
            }
        }
        //������������
        cout<<"v"<<mst[index]<<"-v"<<index<<endl;
        //����һ����ıȽϽ���Ԥ����index������Ѿ���������С�������ˣ����Զ�Ӧ�ĵ�index������Ȩֵ��0���������ܵ���
        lowcost[index]=0;
        for (j=1;j<n;j++)
        {
            // �ٴα������е�
            if (graph[index][j] < lowcost[j])
            {
                // ���θ�����СȨֵ
                lowcost[j]=graph[index][j];
                // ��¼��СȨֵ��Ӧ�ĵ�
                mst[j]=index;
            }
        }
    }
}
int main()
{
    int i,j,m,n,k,w;
    cout<<"������ڵ�ĸ����ͱ���:";
    cin>>n>>m;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            graph[i][j]=MAXCOST;
        }
    }
    cout<<"������߹����ĵ��Ȩֵ:"<<endl;
    for (k=0;k<m;k++)
    {
        cin>>i>>j>>w;
        graph[i][j]=w;
        graph[j][i]=w;
    }
    prim(n);
    return 0; 
}
