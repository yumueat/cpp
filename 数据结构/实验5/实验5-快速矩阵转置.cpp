#include<iostream>
using namespace std;
#define MAX 255
typedef struct{
    int i,j,v;
}triple;
void createMatrix(int array[MAX][MAX],triple *matrix)
{
    int i,j,k=1;
    for (i=1;i<=array[1][0];i++)
    {
        for (j=1;j<=array[0][1];j++)
        {
            if (array[i][j]!=0)
            {
                matrix[k].i=i;
                matrix[k].j=j;
                matrix[k].v=array[i][j];
                k++;

            }
        }
    }
    matrix[0].i=array[1][0];
    matrix[0].j=array[0][1];
    matrix[0].v=k-1;
}
void showTriple(triple *matrix)
{
    for(int i=1;i<=matrix[0].v;i++) 
    {
        cout<<matrix[i].i<<' '<<matrix[i].j<<' '<<matrix[i].v<<endl;
    }
    cout<<endl;
}
void MatrixTranspose(triple *matrix,triple *Tmatrix)
{
    int temp1[MAX],temp2[MAX],i,j,m=0,n=1;
    for (i=1;i<=matrix[0].j;i++)
    {
        temp1[i] = 0;
    }
    temp1[0]=matrix[0].j;
    for (i=1;i<=matrix[0].v;i++)
    {
        temp1[matrix[i].j]++;
    }
    temp2[0]=temp1[0];
    temp2[1]=1;
    for (i=2;i<=temp1[0];i++)
    {
        temp2[i]=temp2[i-1]+temp1[i-1];
    }
    for (i=1;i<=matrix[0].v;i++)
    {
        Tmatrix[temp2[matrix[i].j]].i=matrix[i].j;
        Tmatrix[temp2[matrix[i].j]].j=matrix[i].i;
        Tmatrix[temp2[matrix[i].j]++].v=matrix[i].v;
    }
    Tmatrix[0].v=matrix[0].v;
    Tmatrix[0].i=matrix[0].j;
    Tmatrix[0].j=matrix[0].i;
}
int main()
{
    int rows,columns,i,j;
    int array[MAX][MAX];
    triple matrix[MAX];
    triple Tmatrix[MAX];
    cout<<"请输入矩阵的行数和列数:";
    cin>>rows>>columns;
    array[0][1]=columns;
    array[1][0]=rows;
    for (i=1;i<=rows;i++)
    {
        for (j=1;j<=columns;j++)
        {
            cin>>array[i][j];
        }
    }
    createMatrix(array,matrix);
    showTriple(matrix);
    MatrixTranspose(matrix,Tmatrix);
    showTriple(Tmatrix);
    return 0;
}
