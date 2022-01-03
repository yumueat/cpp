#include<iostream>
using namespace std;
enum Kind {atom,tab,head};
// typedef struct Link{
//     char value;
//     struct Link* next;
// }link;
typedef struct GLink{
    enum Kind kind;
    struct GLink* next;
    union
    {
        char value;
        struct GLink * p;
    };
}Glink;
// void insertLink(link * p,char value,int pos)
// {
//     int i;
//     link * temp=p;
//     for (i=1;i<=pos;i++)
//     {
//         temp=temp->next;
//     }
//     temp->value=value;
// }
// void insertGlink(GLink* generalizedTable,GLink* p,int pos)
// {
//     int i;
//     Glink * temp=generalizedTable;
//     for (i = 1; i <= pos ;i++)  
//     {
//         temp=temp->next;
//     }
//     temp->p=p;
// }
void insertGlink(GLink* generalizedTable,char value,int pos)
{
    int i;
    Glink * temp=generalizedTable;
    for (i = 1; i <= pos ;i++) 
    {
        temp=temp->next;
    }
    temp->value=value;
}
void insertGlink(GLink* generalizedTable,Glink * p,int pos)
{
    int i;
    Glink * temp = generalizedTable;
    for (i = 1; i <= pos ;i++)
    {
        temp=temp->next;
    }
    temp->p=p;
}
// void showLink(link * p)
// {
//     link * temp=p->next;
//     while(temp != NULL)
//     {
//         cout<<temp->value<<' ';
//         temp=temp->next;
//     }
//     cout<<endl;
// }
void showGlink(Glink* generalizedTable)
{
    cout<<generalizedTable->next<<endl;
    Glink * temp=generalizedTable;
    cout<<"flag1"<<endl;
    if (generalizedTable->next == NULL)
    {
        cout<<"该表是一个空表"<<endl;
    }
    else
    {
        cout<<"flag2"<<endl;
        temp=temp->next;
        while(temp!=NULL)
        {
            if (temp->kind==atom)
            {
                cout<<temp->value<<endl;
            }
            else
            {
                showGlink(temp->p);
            }
        }
    }
}
int main()
{
    Glink *AgeneralizedTable;
    // AgeneralizedTable->kind = head;
    cout<<"flag3"<<endl;
    // AgeneralizedTable->next = NULL;
    cout<<"flag3"<<endl;
    showGlink(AgeneralizedTable);
    Glink *BgeneralizedTable;
    BgeneralizedTable->kind = head;
    BgeneralizedTable->next = NULL;
    Glink * Blink;
    Blink->kind = head;
    Blink->next = NULL;
    insertGlink(Blink,'b',1);
    insertGlink(Blink,'c',2);
    insertGlink(Blink,'d',3);
    insertGlink(BgeneralizedTable,'a',1);
    insertGlink(BgeneralizedTable,Blink,2);
    showGlink(BgeneralizedTable);
    Glink *CgeneralizedTable;
    CgeneralizedTable->kind = head;
    CgeneralizedTable->next = NULL;
    insertGlink(CgeneralizedTable,'e',1);
    showGlink(CgeneralizedTable);
    Glink *DgeneralizedTable;
    DgeneralizedTable->kind = head;
    DgeneralizedTable->next = NULL;
    insertGlink(DgeneralizedTable,AgeneralizedTable,1);
    insertGlink(DgeneralizedTable,BgeneralizedTable,2);
    insertGlink(DgeneralizedTable,CgeneralizedTable,3);
    insertGlink(DgeneralizedTable,'f',4);
    showGlink(DgeneralizedTable);
    return 0;
}
