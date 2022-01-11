#include <iostream>
#include <cstring>
using namespace std; 
#define VMAX 100
void showVe(int * ve,int n)
{
    int i;
    cout << "Ve���飺";
    for(int i = 1; i <= n; i++){
        cout << ve[i] << " ";
    }
    cout << endl;
}
void showVl(int * vl,int n)
{
    int i;
    cout << "Vl���飺";
    for(int i = 1; i <= n; i++){
        cout << vl[i] << " ";
    }
    cout<<endl;
}  
int main()
{
    int graph[VMAX][VMAX]; //�ڽӾ���
    // ��ʼ�������ֵȫ��Ϊ0��ʾ���������û�б�����
    for(int i = 0; i <= VMAX-1; i++){
        for(int j = 0; j <= VMAX-1; j++){
            graph[i][j] = -1;
        }
    }
    
    int i,j,w;  //����i,j����������,w�洢Ȩֵ
    int n,m;  //�������ͱ���
    
    cout << "�����붥������";
    cin >> n;
    cout << "�����������";
    cin >> m;
    cout << "������ߣ�" << endl;
    
    for(int k = 1; k <= m; k++){
            cin >> i >> j >> w;
            graph[i][j] = w; // ��ʾ����iָ�򶥵�j�ı�,��ȨֵΪw
    }
    
    int k; //���ڼ������
    int ID[VMAX],OD[VMAX];  //������������Ⱥͳ���
    int ve[VMAX]={0},vl[VMAX];  //veΪ�¼������緢���¼���vlΪ�¼���������ʱ�䣬�����緢��ʱ�䣬˳��������ȡ����Ϊ���кܶ�����Ե������ֻ�����еĶ�����˲��ܿ�ʼ���¼���Ϊ�˱�֤���ж���ɣ�ʱ��ȡ���ֵ������������ȡС��ͬ��˵���˾��Ǳ�֤����һʧ
     //��ʼ��ve����ȫΪ0����ΪҪ��ʱ��Ȼ��Ƚϣ�ȫ��ȡ0��֤�����������С
    
    for(int i = 1; i <= n; i++)// �������
    {  
        k = 0;
        for(int j = 1; j <= n; j++)
        {
            if(graph[j][i] != -1) //�������j������i�бߣ��򶥵�i�����+1
                k++;
        }
        ID[i] = k;
    }
    for(int i = 1; i <= n; i++){  //˳��������
        if(ID[i] == 0)//Ѱ�����Ϊ0�ĵ�
        {   
            for(int j = 1; j <= n; j++)
            {
                if(graph[i][j] != -1)//�������i������j�бߣ���ɾ�������ߣ����Ҷ���j�����-1
                {     
                    if(ve[j] < graph[i][j] + ve[i])  //�����¼����緢��ʱ�䣬ȡ��ֵ
                    {
                        ve[j] = graph[i][j] + ve[i];
                    }
                    ID[j]--;  //����j�����-1
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){  // �������
        k = 0;
        for(int j = 1; j <= n; j++){
            if(graph[i][j] != -1)
                k++;
        }
        OD[i] = k;
    }
    
    k = n;
    for(int i = 1; i <= n; i++)    //�� vl ����ȫ����ʼ��Ϊve���һ�����ֵ
    {
        vl[i] = ve[k];  //������Ϊvl����Ҫȡ��Сֵ����Ҫ���յ�����
    }
    for(int i = k; i>=1; i--)//����������
    {  
        if(OD[i] == 0)  //Ѱ�ҳ���Ϊ0�ĵ�
        {
            for(int j = 1; j <= n; j++)
            {
                if(graph[j][i] != -1) //�ж�j��i�Ƿ��б�
                {
                    if(vl[j] > vl[i] - graph[j][i])   //�����¼���������ʱ�䣬ȡСֵ
                    {
                        vl[j] = vl[i] - graph[j][i];
                    }
                    OD[j]--; //j��ĳ���-1
                }
            }
        }
    }
    showVe(ve,n);
    showVl(vl,n);
    char table[12]={'A','B','C','D','E','F','G','H','I','J','K','L'};
    cout << "�ؼ�·����";
    for(int i = 1; i <= k - 1 ; i++)//�ؼ�·���ɹؼ��¼����
    {   
        if(ve[i] == vl[i])//�¼������緢��ʱ���������ʱ����ͬ���¼�Ϊ�ؼ��¼�����Ϊ����·�������¼���Ҫ���ѵ�ʱ�䣬Ҫ�������ʱ��ֻ���Ż��ؼ��¼���ʱ��
        {   
            cout << table[i-1] << "->"; //������������յ�����Ϊ������������������������һ��->����
        }
    }
    cout << 'L' << endl; //�����Ҫ��������յ�
    cout<<"����Ϊ:"<<ve[k]<<endl; //��ʱ��͵���ve����vl�����һ��ֵ
    return 0;
}
