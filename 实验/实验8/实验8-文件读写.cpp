#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<sstream>
#define MAX 255
using namespace std;
typedef struct Student{
    int id;
    string name;
    int chineseScore;
    int mathScore;
    int enghlishScore;
}student;
int main()
{
    int a,i=0,j,k;
    student s[MAX];
    ifstream infile;
    ofstream outfile;
    student temp;
    string fileName;
    infile.open("stu_info.txt",ios::in);
    if (!infile.is_open()){
        cout<<"文件打开失败"<<endl;
    }
    while(!infile.eof())
    {
        infile>>s[i++].id>>s[i].name>>s[i].chineseScore>>s[i].mathScore>>s[i].enghlishScore;
    }
    infile.close();
    for (j=0;j<i-1;j++)
    {
        for (k=0;k<i-j-1;k++)
        {
            if (s[k].id>s[k+1].id)
            {
                temp=s[k];
                s[k]=s[k+1];
                s[k+1]=temp;                
            }
        }
    }
    cout<<"请输入要保存到的文件名:";
    cin>>fileName;
    outfile.open(fileName,ios::app | ios::binary);
    if (!outfile.is_open())
    {
        cout<<"打开文件出错"<<endl;
    }
    for (k=0;k<i;k++)
    {
        outfile.write(reinterpret_cast<char *>(&s[k].id),sizeof(s[k].id));
        outfile.write(reinterpret_cast<char *>(&s[k].name),sizeof(s[k].name));
        outfile.write(reinterpret_cast<char *>(&s[k].chineseScore),sizeof(s[k].chineseScore));
        outfile.write(reinterpret_cast<char *>(&s[k].mathScore),sizeof(s[k].mathScore));
        outfile.write(reinterpret_cast<char *>(&s[k].enghlishScore),sizeof(s[k].enghlishScore));
        // outfile<<s[k].id<<" "<<s[k].name<<" "<<s[k].chineseScore<<" "<<s[k].mathScore<<" "<<s[k].enghlishScore<<endl;
    }
    outfile.close();
    // for (k=0;k<i;k++)
    // {
    //     cout<<s[k].id<<" "<<s[k].name<<s[k].chineseScore<<s[k].mathScore<<s[k].enghlishScore<<endl;
    // }
    return 0;
}
