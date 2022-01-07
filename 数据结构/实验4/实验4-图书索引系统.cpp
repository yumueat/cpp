#include <iostream>
#include<fstream>
#include<cstring>
#define MAX 255
using namespace std;
struct Index//����ṹ������������
{
    string keywords[MAX];
    int len=0;
    string nub;
};
void temp_split(string *temp,string *num,string *book,int len)//�ָ���������ŵĺ��� 
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
bool is_in(string a)//�жϷָ�����Ĵ��Ƿ��ǹؼ��ʵĺ��� 
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
void keywords_split(string *book,struct Index *index,string *num,int len)//���������е�ÿһ���ʲ�����Ź�������ṹ����
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
    for (int j=0;j<len;j++)//���������֤�Ƿ�ɹ�
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
    string foo[MAX];//��ʱ�������
    string num[MAX];
    string book[MAX];
    Index index[MAX];
    infile.open("C:/Users/yumu/Desktop/vscode/c++/.vscode/book.txt",ios::in);//���ļ�
    if (!infile.is_open())//�ж��Ƿ�򿪳ɹ�
    {
        cout<<"Open file failure"<<endl;
    }
    while (getline(infile,foo[i++]));//�����ļ�����
    infile.close();//�ر��ļ�
    temp_split(foo,num,book,i-1);//�������������
    keywords_split(book,index,num,i-1);//����ؼ��ʲ���������
    return 0;
}

