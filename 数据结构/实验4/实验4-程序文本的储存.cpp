#include<iostream>
#include<cstring>
using namespace std;
typedef struct RIndex//����ṹ����Ϊ�ı������б�
{
    int row;
    int start;
    int len;
}rindex;
void delRow(string &temp,rindex rIndex[],int row)//ɾ���еĺ���
{
    int len=rIndex[row].len;
    temp.erase(rIndex[row].start-1,rIndex[row].len+1);
    for (int i=row+1;i<=rIndex[0].row;i++)
    {
        rIndex[i-1].row=i-1;
        rIndex[i-1].len=rIndex[i].len;
        rIndex[i-1].start=rIndex[i].start-len;
    }
    rIndex[0].row--;
}
void insertRow(string &temp,rindex rIndex[],string p,int row)//�����еĺ���
{
    int len=p.size();
    for (int i=rIndex[0].row;i>row;i--)
    {
        rIndex[i+1].row=i+1;
        rIndex[i+1].len=rIndex[i].len;
        rIndex[i+1].start=rIndex[i].start+len;
    }
    rIndex[row].len=len;

    temp.insert(rIndex[row].start,p+'\n');
    rIndex[0].row++;
}
void rowIndex(rindex rIndex[],string temp)//�����ı����б�ĺ���
{
    rIndex[0].start=0;
    rIndex[0].len=0;
    rIndex[0].row=0;
    int i=0,j=1,num=0;
    while(temp[i]!='\0')
    {
        if (temp[i]=='\n')
        {
            rIndex[j].row=j;
            rIndex[j].len=++num;
            rIndex[j].start=rIndex[j-1].start+rIndex[j-1].len;
            num=0;
            j++;
        }
        else
        {
            num++;
        }
        i++;
    }
    rIndex[0].row=j;
}
int main()
{
    rindex rIndex[255];
    string T;
    string temp="main(){\n    float a,b,max;\n    scanf(\"%f,%f\",&a,&b);\n    if a>b max =a;\n    else max=b;\n}";//����һ������
    rowIndex(rIndex,temp);//Ϊ��������ֱ����б�
    cout<<rIndex[0].row<<endl;//���������֤�Ƿ�ɹ�
    string p="    int d;";//׼��Ҫ������ַ���
    insertRow(temp,rIndex,p,3);//ѡ���������в���
    cout<<temp<<endl;//����������ı�����֤
    cout<<rIndex[0].row<<endl;//�����������֤
    delRow(temp,rIndex,3);//ѡ����������ɾ��
    cout<<temp<<endl;//����ı�����֤
    cout<<rIndex[0].row<<endl;//�����������֤
    return 0;
}

