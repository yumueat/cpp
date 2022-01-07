#include<iostream>
#include<cstring>
using namespace std;
typedef struct RIndex//定义结构体作为文本串的行表
{
    int row;
    int start;
    int len;
}rindex;
void delRow(string &temp,rindex rIndex[],int row)//删除行的函数
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
void insertRow(string &temp,rindex rIndex[],string p,int row)//插入行的函数
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
void rowIndex(rindex rIndex[],string temp)//编制文本串行表的函数
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
    string temp="main(){\n    float a,b,max;\n    scanf(\"%f,%f\",&a,&b);\n    if a>b max =a;\n    else max=b;\n}";//输入一段文字
    rowIndex(rIndex,temp);//为输入的文字编制行表
    cout<<rIndex[0].row<<endl;//输出行数验证是否成功
    string p="    int d;";//准备要插入的字符串
    insertRow(temp,rIndex,p,3);//选择行数进行插入
    cout<<temp<<endl;//输出插入后的文本以验证
    cout<<rIndex[0].row<<endl;//输出行数以验证
    delRow(temp,rIndex,3);//选择行数进行删除
    cout<<temp<<endl;//输出文本以验证
    cout<<rIndex[0].row<<endl;//输出行数以验证
    return 0;
}

