#include<iostream>
using namespace std;
enum Kind {atom,tab,head};
typedef struct GLink{
    enum Kind kind;
    struct GLink* next;
    union
    {
        char value;
        struct GLink * p;
    };
}Glink;
void insertGlink(GLink* generalizedTable,char value,int pos)
{
    int i;
    
    Glink * temp=generalizedTable;
    
    for (i = 1; i <= pos ;i++) 
    {
        temp=temp->next;
        cout<<"flag"<<endl;
    }

    if (temp!=NULL)
    {
        temp->value=value;
    }
    else
    {
 
        temp=(Glink*)malloc(sizeof(Glink));
        temp->next=NULL;
        temp->value=value;
        
    }
}
void insertGlink(GLink* generalizedTable,Glink * p,int pos)
{
    int i;
    Glink * temp = generalizedTable;
    for (i = 1; i <= pos ;i++)
    {
        temp=temp->next;
    }
    if (temp!=NULL)
    {
        temp->p=p;
    }
    else
    {
        temp=(Glink*)malloc(sizeof(Glink));
        temp->next=NULL;
        temp->p=p;
    }
}
void showGlink(Glink* generalizedTable)
{
    cout<<generalizedTable->next<<endl;
    Glink * temp=generalizedTable;
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
void initialization(Glink *generalizedTable)
{
    generalizedTable->kind=head;
    generalizedTable->next=NULL;
}
int main()
{
    Glink *AgeneralizedTable=(Glink*)malloc(sizeof(Glink));
    initialization(AgeneralizedTable);
    showGlink(AgeneralizedTable);
    Glink *BgeneralizedTable=(Glink*)malloc(sizeof(Glink));
    initialization(BgeneralizedTable);
    Glink * Blink=(Glink*)malloc(sizeof(Glink));
    initialization(Blink);
    
    insertGlink(Blink,'b',1);
    cout<<"flag3"<<endl;
    insertGlink(Blink,'c',2);
    cout<<"flag3"<<endl;
    insertGlink(Blink,'d',3);
    cout<<"flag4"<<endl;
    insertGlink(BgeneralizedTable,'a',1);
    insertGlink(BgeneralizedTable,Blink,2);
    showGlink(BgeneralizedTable);
    Glink *CgeneralizedTable=(Glink*)malloc(sizeof(Glink));
    initialization(CgeneralizedTable);
    insertGlink(CgeneralizedTable,'e',1);
    showGlink(CgeneralizedTable);
    Glink *DgeneralizedTable=(Glink*)malloc(sizeof(Glink));
    initialization(DgeneralizedTable);
    DgeneralizedTable->kind = head;
    DgeneralizedTable->next = NULL;
    insertGlink(DgeneralizedTable,CgeneralizedTable,1);
    insertGlink(DgeneralizedTable,BgeneralizedTable,2);
    insertGlink(DgeneralizedTable,CgeneralizedTable,3);
    insertGlink(DgeneralizedTable,'f',4);
    showGlink(DgeneralizedTable);
    return 0;
}
