#include <iostream>
using namespace std;
#define MAX 255
typedef struct Link{
    int value=0;
    int row=1;
    int column=1;
    struct Link * l=NULL;
    struct Link * r=NULL;
    struct Link * t=NULL;
    struct Link * b=NULL;
}link;
void initialization(link *matrix)
{
    matrix->row=1;
    matrix->column=1;
    matrix->value=0;
    matrix->r=NULL;
    matrix->l=NULL;
    matrix->b=NULL;
    matrix->t=NULL;
}
void insertLink(link *matrix,int row,int column,int value)
{
    link * p=matrix;
    while (p->row != row)
    {
        if (p->b!=NULL)
        {
            p=p->b;
        }      
        else
        {
            link * temp=(link*)malloc(sizeof(link));
            initialization(temp);
            p->b=temp;
            temp->t=p;
            temp->row=p->row+1;
            temp->column=p->column;
            p=temp;
        }  
        
    }
    while (p->column != column)
    {
        if (p->r!=NULL)
        {
            p=p->r;
        }
        else
        {
            link * temp=(link*)malloc(sizeof(link));
            initialization(temp);
            p->r=temp;
            temp->l=p;
            temp->column=p->column+1;
            temp->row=p->row;
            p=temp;
        }
    }
    p->value=value;
}
void showLink(link *matrix)
{
    link * p=matrix;
    link * temp=p;
    for (;p!=NULL;p=p->b)
    {
        temp=p;
        for (;temp!=NULL;temp=temp->r)
        {
            cout<<temp->value<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    link *matrix=(link*)malloc(sizeof(link));
    initialization(matrix);
    int temp;
    int rows,columns,i,j;
    cout<<"请输入矩阵的行数和列数";
    cin>>rows>>columns;
    for (i=1;i<=rows;i++)
    {
        for (j=1;j<=columns;j++)
        {
            cin>>temp;
            insertLink(matrix,i,j,temp);
        }
    }
    showLink(matrix);
    
    return 0;
}
