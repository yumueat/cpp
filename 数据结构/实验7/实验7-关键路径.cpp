#include <iostream>
#include <cstring>
using namespace std; 
#define VMAX 100
void showVe(int * ve,int n)
{
    int i;
    cout << "Ve数组：";
    for(int i = 1; i <= n; i++){
        cout << ve[i] << " ";
    }
    cout << endl;
}
void showVl(int * vl,int n)
{
    int i;
    cout << "Vl数组：";
    for(int i = 1; i <= n; i++){
        cout << vl[i] << " ";
    }
    cout<<endl;
}  
int main()
{
    int graph[VMAX][VMAX]; //邻接矩阵
    // 初始化矩阵的值全部为0表示各个顶点间没有边连接
    for(int i = 0; i <= VMAX-1; i++){
        for(int j = 0; j <= VMAX-1; j++){
            graph[i][j] = -1;
        }
    }
    
    int i,j,w;  //定义i,j，用来输入,w存储权值
    int n,m;  //顶点数和边数
    
    cout << "请输入顶点数：";
    cin >> n;
    cout << "请输入边数：";
    cin >> m;
    cout << "请输入边：" << endl;
    
    for(int k = 1; k <= m; k++){
            cin >> i >> j >> w;
            graph[i][j] = w; // 表示顶点i指向顶点j的边,且权值为w
    }
    
    int k; //用于计算度数
    int ID[VMAX],OD[VMAX];  //储存各顶点的入度和出度
    int ve[VMAX]={0},vl[VMAX];  //ve为事件的最早发生事件，vl为事件的最晚发生时间，对最早发生时间，顺拓扑序列取大，因为在有很多可能性的情况下只有所有的都完成了才能开始该事件，为了保证所有都完成，时间取最大值；逆拓扑序列取小，同理，说白了就是保证万无一失
     //初始化ve数组全为0，因为要算时间然后比较，全部取0保证都比其他情况小
    
    for(int i = 1; i <= n; i++)// 计算入度
    {  
        k = 0;
        for(int j = 1; j <= n; j++)
        {
            if(graph[j][i] != -1) //如果顶点j到顶点i有边，则顶点i的入度+1
                k++;
        }
        ID[i] = k;
    }
    for(int i = 1; i <= n; i++){  //顺拓扑序列
        if(ID[i] == 0)//寻找入度为0的点
        {   
            for(int j = 1; j <= n; j++)
            {
                if(graph[i][j] != -1)//如果顶点i到顶点j有边，则删除这条边，并且顶点j的入度-1
                {     
                    if(ve[j] < graph[i][j] + ve[i])  //计算事件最早发生时间，取大值
                    {
                        ve[j] = graph[i][j] + ve[i];
                    }
                    ID[j]--;  //顶点j的入度-1
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){  // 计算出度
        k = 0;
        for(int j = 1; j <= n; j++){
            if(graph[i][j] != -1)
                k++;
        }
        OD[i] = k;
    }
    
    k = n;
    for(int i = 1; i <= n; i++)    //将 vl 数组全部初始化为ve最后一顶点的值
    {
        vl[i] = ve[k];  //这是因为vl数组要取最小值，需要从终点逆推
    }
    for(int i = k; i>=1; i--)//逆拓扑序列
    {  
        if(OD[i] == 0)  //寻找出度为0的点
        {
            for(int j = 1; j <= n; j++)
            {
                if(graph[j][i] != -1) //判断j到i是否有边
                {
                    if(vl[j] > vl[i] - graph[j][i])   //计算事件的最晚发生时间，取小值
                    {
                        vl[j] = vl[i] - graph[j][i];
                    }
                    OD[j]--; //j点的出度-1
                }
            }
        }
    }
    showVe(ve,n);
    showVl(vl,n);
    char table[12]={'A','B','C','D','E','F','G','H','I','J','K','L'};
    cout << "关键路径：";
    for(int i = 1; i <= k - 1 ; i++)//关键路径由关键事件组成
    {   
        if(ve[i] == vl[i])//事件的最早发生时间和最晚发生时间相同的事件为关键事件，因为这条路决定了事件需要花费的时间，要缩短这个时间只能优化关键事件的时间
        {   
            cout << table[i-1] << "->"; //不在这里输出终点是因为如果在这里输出了最后会额外输出一个->符号
        }
    }
    cout << 'L' << endl; //最后需要补上输出终点
    cout<<"工期为:"<<ve[k]<<endl; //总时间就等于ve或者vl的最后一个值
    return 0;
}
