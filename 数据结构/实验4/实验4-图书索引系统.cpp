#include <iostream>
#include<fstream>
#include<cstring>
#define MAX 255
using namespace std;
struct Index//定义结构体来储存索引
{
    string keywords[MAX];
    int len=0;
    string nub;
};
void temp_split(string *temp,string *num,string *book,int len)//分割书名和序号的函数 
{
    int i=0,j=0,k=0;
    for (i=0;i<len;i++)
    {
        j=0;
        while (temp[i][j]!=' ')
        {
            j++;
        }
        num[i]=temp[i].substr(0,j);
        book[i]=temp[i].substr(j+1);
    }
}
bool is_in(string a)//判断分割出来的词是否是关键词的函数 
{
    string normalwords[4]={"an","a","of","the"};
    for (int i=0;i<4;i++)
    {
        if (a==normalwords[i])
        {
            return true;
        }
        
    }
    return false;
}
void keywords_split(string *book,struct Index *index,string *num,int len)//分离书名中的每一个词并跟序号关联存入结构体中
{
    int i=0,j=0,start;
    string temp;
    for (i=0;i<len;i++)
    {
        start=0;
        j=0;
        while(book[i][j]!='\0')
        {
            while(book[i][j]!=' ')
            {
                if (book[i][j]=='\0')
                {
                    j--;
                    break;
                }
                j++;
            }
            if (book[i][j+1]=='\0')
            {
                temp=book[i].substr(start,j-start+1);
            }
            else
            {
                temp=book[i].substr(start,j-start);
            }
            
            start=j+1;
            if (!is_in(temp))
            {
                index[i].keywords[index[i].len++]=temp;
                index[i].nub=num[i];
            }
            j++;
        }
    }
    for (int j=0;j<len;j++)//输出索引验证是否成功
    {
        for (int k=0;k<index[j].len;k++)
        {
            cout<<index[j].keywords[k]<<' '<<index[j].nub<<endl;
        }
    }
}
int main() {
    int i=0;
    ifstream infile;
    string foo[MAX];//暂时存放数据
    string num[MAX];
    string book[MAX];
    Index index[MAX];
    infile.open("C:/Users/yumu/Desktop/vscode/c++/.vscode/book.txt",ios::in);//打开文件
    if (!infile.is_open())//判断是否打开成功
    {
        cout<<"Open file failure"<<endl;
    }
    while (getline(infile,foo[i++]));//读入文件内容
    infile.close();//关闭文件
    temp_split(foo,num,book,i-1);//分离书名和序号
    keywords_split(book,index,num,i-1);//分离关键词并制作索引
    return 0;
}

