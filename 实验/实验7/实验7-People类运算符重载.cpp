#include <iostream>
# include <cstring>
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
        printf("����������:%d��%d��%d��\n",year,month,day);
    }
    Date(Date & d)
    {
        cout<<"�������캯������"<<endl;
        year=d.year;
        month=d.month;
        day=d.day;
    }
    int year;
    int month;
    int day;
};
class People
{
public:
    People()
    {
        cout<<"���캯����ʼ����"<<endl;
    }
    ~People()
    {
        cout<<"����������ʼ����"<<endl;
    }
    void setPeople(char * newNumber,char * newName,char * newId,char * newSex,int newYear,int newMonth,int newDay);
    void showPeople()
    {
        cout<<"��Ա��������:"<<name<<endl;
        cout<<"��Ա��number��:"<<number<<endl;
        cout<<"��Ա��id��:"<<id<<endl;
        cout<<"��Ա��sex��:"<<sex<<endl;
        birthday.showDate();
    }
    bool operator==(const People & a)
    {
        if (strcmp(this->name,a.name)==0&&
        strcmp(this->number,a.number)==0&&
        strcmp(this->sex,a.sex)==0&&
        strcmp(this->id,a.id)==0&&
        this->birthday.year==a.birthday.year&&
        this->birthday.month==a.birthday.month&&
        this->birthday.day==a.birthday.day)
        {
            return true;
        }
        else {
            return false;
        }
    }
    People operator=(const People & a)
    {
        People p;
        p=a;
        return p;
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
    char name[]="����";
    char number[]="0001";
    people.setPeople(name,number,id,sex,1994,5,14);
    People people1=people;
    People people2;
    people2.setPeople(name,number,id,sex,4521,5,14);
    if (people1==people)
    {
        cout<<"��ͬ"<<endl;
    }
    else
    {
        cout<<"����ͬ"<<endl;
    }
    if (people2==people)
    {
        cout<<"��ͬ"<<endl;
    }
    else
    {
        cout<<"����ͬ"<<endl;
    }
    
    return 0;
}
