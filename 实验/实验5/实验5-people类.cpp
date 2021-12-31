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
    void setPeople(char * newNumber,char * newName,char * newId,char * newSex,int newYear,int newMonth,int newDay);
    void showPeople()
    {
        cout<<"人员的名字是:"<<name<<endl;
        cout<<"人员的number是:"<<number<<endl;
        cout<<"人员的id是:"<<id<<endl;
        cout<<"人员的sex是:"<<sex<<endl;
        birthday.showDate();
    }
private:
    char name[11];
    char number[7];
    char id[20];
    char sex[3];
    Date birthday;
};

inline void People::setPeople(char  * newName,char * newNumber, char * newId, char * newSex, int newYear, int newMonth, int newDay)
{
    int i=0;
    while(newName[i] != '\0')
    {
        name[i] = newName[i];
        i++;
    }
    i=0;
    while(newNumber[i]!='\0')
    {
        number[i] = newNumber[i];
        i++;
    }
    number[i] = '\0';
    i=0;
    while(newSex[i]!='\0')
    {
        sex[i] = newSex[i];
        i++;
    }
    sex[i] = '\0';
    i=0;
    while(newId[i]!='\0')
    {
        id[i] = newId[i];
        i++;
    }
    id[i] = '\0';
    birthday.setDate(newYear,newMonth,newDay);
}
int main()
{
    People people;
    char id[]="520102199405140090";
    char sex[]="man";
    char name[]="张三";
    char number[]="0001";
    people.setPeople(name,number,id,sex,1994,5,14);
    people.showPeople();
    People people1=people;
    people1.showPeople();
    return 0;
}
