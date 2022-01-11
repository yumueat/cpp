#include <iostream>
using namespace std;
#define MAXCOST 0x7fffffff
#define VMAX 100
int graph[VMAX][VMAX];
void prim(int n)
{
    //lowcost[i]表示以i为终点的最小权值，mst[i]表示对应lowcost[i]的起点
    int lowcost[VMAX],mst[VMAX];
    //min为权值的最小值，index为位置
    int i,j,min,index;
    //针对第一个点进行预处理
    for (i=1;i<n;i++)
    {
        lowcost[i] = graph[0][i];//存储0到每一个点的权值，方便后面的比较
        mst[i]=0;//记录这些终点为i的边的起点是0
    }
    // mst[0]=0;
    for (i=1;i<n;i++){
        min=MAXCOST;//先个最小值赋一个最大值，方便后面的比较
        index=0;
        for (j=1;j<n;j++)
        {
            if (lowcost[j]<min&&lowcost[j]!=0)
            {
                //遍历所有边，寻找权值最小的情况
                min=lowcost[j];
                //记录最小权值对应的点
                index=j;
            }
        }
        //输出这个点的情况
        cout<<"v"<<mst[index]<<"-v"<<index<<endl;
        //对下一个点的比较进行预处理，index这个点已经被加入最小生成树了，所以对应的到index这个点的权值是0，即不可能到达
        lowcost[index]=0;
        for (j=1;j<n;j++)
        {
            // 再次遍历所有点
            if (graph[index][j] < lowcost[j])
            {
                // 依次更新最小权值
                lowcost[j]=graph[index][j];
                // 记录最小权值对应的点
                mst[j]=index;
            }
        }
    }
}
int main()
{
    int i,j,m,n,k,w;
    cout<<"请输入节点的个数和边数:";
    cin>>n>>m;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            graph[i][j]=MAXCOST;
        }
    }
    cout<<"请输入边关联的点和权值:"<<endl;
    for (k=0;k<m;k++)
    {
        cin>>i>>j>>w;
        graph[i][j]=w;
        graph[j][i]=w;
    }
    prim(n);
    return 0; 
}
