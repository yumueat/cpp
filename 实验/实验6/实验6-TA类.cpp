#include <iostream>
# include <string.h>
#include <string>
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
        cout<<"��Ա�๹�캯����ʼ����"<<endl;
    }
    ~People()
    {
        cout<<"��Ա������������ʼ����"<<endl;
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
class student : virtual public People{
    public:
        student(){
            cout<<"ѧ���๹�캯����ʼ����"<<endl;
        }
        ~student(){
            cout<<"ѧ��������������ʼ����"<<endl;
        }
        string classNo;
        void showStudent(){
            showPeople();
            cout<<"classNo: "<<classNo<<endl;
        }
};
class teacher : virtual public People{
    public:
        teacher(){
            cout<<"��ʦ�๹�캯����ʼ����"<<endl;
        }
        ~teacher(){
            cout<<"��ʦ������������ʼ����"<<endl;
        }
        void showTeacher(){
            showPeople();
            cout<<"��ʦ��ְ���ǣ�"<<principalship<<endl;
            cout<<"��ʦ�Ĳ����ǣ�"<<department<<endl;
        }
        string principalship;
        string department;
};
class graduate : public student{
    public:
        string subject;
        teacher adviser;
        graduate(){
            cout<<"�о����๹�캯����ʼ����"<<endl;
        }
        ~graduate(){
            cout<<"�о���������������ʼ����"<<endl;
        }
        void showStudent(){
            cout<<"classNo: "<<classNo<<endl;
        }
        void showgraduate(){
            showPeople();
            showStudent();
            cout<<"�о�����רҵ�ǣ�"<<subject<<endl;
            cout<<"�о�����ʦ����Ϣ�ǣ�"<<endl;
            adviser.showTeacher();
        }
};
class TA :  public graduate , virtual public teacher{
    public:
        TA(){
            cout<<"�������๹�캯����ʼ����"<<endl;        
        }
        ~TA(){
            cout<<"������������������ʼ����"<<endl;
        }
        void showgraduate(){
            cout<<"ѧ��רҵ�ǣ�"<<subject<<endl;
        }
        void showTeacher(){
            cout<<"���ڵ�ְ���ǣ�"<<principalship<<endl;
            cout<<"���ڵĲ����ǣ�"<<department<<endl;
        }
        void showTA(){
            showPeople();
            showgraduate();
            showTeacher();
        }
};
int main()
{
    // ��Ա�����
    cout<<"��Ա�����"<<endl;
    People people;
    char id[]="520102199405140090";
    char sex[]="man";
    char name[]="����";
    char number[]="0001";
    people.setPeople(name,number,id,sex,1994,5,14);
    people.showPeople();
    People people1=people;
    people1.showPeople();
    // ѧ�������
    cout<<endl;
    cout<<"ѧ�������"<<endl;
    student student1;
    student1.classNo="1��";
    student1.setPeople(name,number,id,sex,1994,5,14);
    student1.showStudent();
    // ��ʦ�����
    cout<<endl;
    cout<<"��ʦ�����"<<endl;
    teacher teacher1;
    teacher1.setPeople(name,number,id,sex,1994,5,14);
    teacher1.department="����";
    teacher1.principalship="������";
    teacher1.showTeacher();
    // �о��������
    cout<<endl;
    cout<<"�о��������"<<endl;
    graduate graduate1;
    graduate1.setPeople(name,number,id,sex,1994,5,14);
    graduate1.subject="�����";
    graduate1.adviser.department="�����ϵ";
    graduate1.adviser.principalship="�о�����ʦ";
    graduate1.adviser.setPeople("����","0002","520102199406220534",sex,1994,6,22);
    graduate1.classNo="2��";
    graduate1.showgraduate();
    // �����������
    cout<<endl;
    cout<<"�����������"<<endl;
    TA ta;
    ta.setPeople(name,number,id,sex,1994,5,14);
    ta.subject="��ѧ";
    ta.department="��ѧϵ";
    ta.principalship="����";
    ta.showTA();
    cout<<endl;
    return 0;
}
