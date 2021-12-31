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
        printf("出生日期是:%d年%d月%d日\n",year,month,day);
    }
    Date(Date & d)
    {
        cout<<"拷贝构造函数运行"<<endl;
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
        cout<<"人员类构造函数开始运行"<<endl;
    }
    ~People()
    {
        cout<<"人员类析构函数开始运行"<<endl;
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
class student : virtual public People{
    public:
        student(){
            cout<<"学生类构造函数开始运行"<<endl;
        }
        ~student(){
            cout<<"学生类析构函数开始运行"<<endl;
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
            cout<<"老师类构造函数开始运行"<<endl;
        }
        ~teacher(){
            cout<<"老师类析构函数开始运行"<<endl;
        }
        void showTeacher(){
            showPeople();
            cout<<"老师的职务是："<<principalship<<endl;
            cout<<"老师的部门是："<<department<<endl;
        }
        string principalship;
        string department;
};
class graduate : public student{
    public:
        string subject;
        teacher adviser;
        graduate(){
            cout<<"研究生类构造函数开始运行"<<endl;
        }
        ~graduate(){
            cout<<"研究生类析构函数开始运行"<<endl;
        }
        void showStudent(){
            cout<<"classNo: "<<classNo<<endl;
        }
        void showgraduate(){
            showPeople();
            showStudent();
            cout<<"研究生的专业是："<<subject<<endl;
            cout<<"研究生导师的信息是："<<endl;
            adviser.showTeacher();
        }
};
class TA :  public graduate , virtual public teacher{
    public:
        TA(){
            cout<<"助教生类构造函数开始运行"<<endl;        
        }
        ~TA(){
            cout<<"助教生类析构函数开始运行"<<endl;
        }
        void showgraduate(){
            cout<<"学的专业是："<<subject<<endl;
        }
        void showTeacher(){
            cout<<"现在的职务是："<<principalship<<endl;
            cout<<"现在的部门是："<<department<<endl;
        }
        void showTA(){
            showPeople();
            showgraduate();
            showTeacher();
        }
};
int main()
{
    // 人员类测试
    cout<<"人员类测试"<<endl;
    People people;
    char id[]="520102199405140090";
    char sex[]="man";
    char name[]="张三";
    char number[]="0001";
    people.setPeople(name,number,id,sex,1994,5,14);
    people.showPeople();
    People people1=people;
    people1.showPeople();
    // 学生类测试
    cout<<endl;
    cout<<"学生类测试"<<endl;
    student student1;
    student1.classNo="1班";
    student1.setPeople(name,number,id,sex,1994,5,14);
    student1.showStudent();
    // 教师类测试
    cout<<endl;
    cout<<"老师类测试"<<endl;
    teacher teacher1;
    teacher1.setPeople(name,number,id,sex,1994,5,14);
    teacher1.department="教务处";
    teacher1.principalship="副主任";
    teacher1.showTeacher();
    // 研究生类测试
    cout<<endl;
    cout<<"研究生类测试"<<endl;
    graduate graduate1;
    graduate1.setPeople(name,number,id,sex,1994,5,14);
    graduate1.subject="计算机";
    graduate1.adviser.department="计算机系";
    graduate1.adviser.principalship="研究生导师";
    graduate1.adviser.setPeople("李四","0002","520102199406220534",sex,1994,6,22);
    graduate1.classNo="2班";
    graduate1.showgraduate();
    // 助教生类测试
    cout<<endl;
    cout<<"助教生类测试"<<endl;
    TA ta;
    ta.setPeople(name,number,id,sex,1994,5,14);
    ta.subject="数学";
    ta.department="数学系";
    ta.principalship="助教";
    ta.showTA();
    cout<<endl;
    return 0;
}
