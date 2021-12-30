#include <iostream>
# include <string.h>
using namespace std;
class Date
{
public:
    Date() {}
    void setDate(int newYear,int newMonth,int newDay)
    {
        year=newYear;
        month=newMonth;
        day=newDay;
    }
    void showDate()
    {
        printf("出生日期是:%d年%d月%d日\n",year,month,day);
    }
    Date(Date & d)
    {
        cout<<"拷贝构造函数运行"<<endl;
        year=d.year;
        month=d.month;
        day=d.day;
    }



private:
    int year;
    int month;
    int day;
};
class People
{
public:
    People()
    {
        cout<<"构造函数开始运行"<<endl;
    }
    ~People()
    {
        cout<<"析构函数开始运行"<<endl;
    }
    void setPeople(int newNumber,char newId[],char newSex[],int newYear,int newMonth,int newDay);
    void showPeople()
    {
        cout<<"人员的number是:"<<number<<endl;
        printf("人员的id是:%s\n",id);
        printf("人员的sex是:%s\n",sex);
        date.showDate();
    }
private:
    int number;
    char id[20];
    char sex[10];
    Date date;
};

inline void People::setPeople(int newNumber, char newId[], char newSex[], int newYear, int newMonth, int newDay)
{
    int i;
    number=newNumber;
    for (i=0;i<= strlen(newSex);i++ )
    {
        sex[i]=newSex[i];
    }
    for (i=0;i< strlen(newId);i++)
    {
        id[i]=newId[i];
    }
    date.setDate(newYear,newMonth,newDay);
}
int main()
{
    People people;
    char id[]="520102199405140090";
    char sex[]="man";
    people.setPeople(001,id,sex,1994,5,14);
    people.showPeople();
    People people1=people;
    people1.showPeople();
    return 0;
}
