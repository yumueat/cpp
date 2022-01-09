#include<iostream>
using namespace std;
#define MAX 255
void matrixMultiplication(int Fmatrix[MAX][MAX],int Smatrix[MAX][MAX],int Amatrix[MAX][MAX])
{
    int i,j,k,s=0;
    for (i=1;i<=Fmatrix[1][0];i++)
    {
        for (j=1;j<=Smatrix[0][1];j++)
        {
            for(k=1;k<=Smatrix[0][1];k++) 
            {
                s+=Fmatrix[i][k]*Smatrix[k][j];
            }
            Amatrix[i][j]=s;
            s=0;
        }
    }
    Amatrix[1][0]=Fmatrix[1][0];
    Amatrix[0][1]=Smatrix[0][1];
}
int main()
{
    int Fmatrix[MAX][MAX];
    int Smatrix[MAX][MAX];
    int Amatrix[MAX][MAX];
    int i,j,rows,cols;
    cout<<"请输入矩阵的行数和列数";
    cin>>rows>>cols;
    Fmatrix[0][1]=cols;
    Fmatrix[1][0]=rows;
    for (i=1;i<=rows;i++)
    {
        for (j=1;j<=cols;j++)
        {
            cin>>Fmatrix[i][j];
        }
    }
    cout<<"请输入矩阵的行数和列数";
    cin>>rows>>cols;
    Smatrix[0][1]=cols;
    Smatrix[1][0]=rows;
    for (i=1;i<=rows;i++)
    {
        for (j=1;j<=cols;j++)
        {
            cin>>Smatrix[i][j];
        }
    }
    matrixMultiplication(Fmatrix,Smatrix,Amatrix);
    for (i=1;i<=Amatrix[0][1];i++)
    {
        for (j=1;j<=Amatrix[1][0];j++)
        {
            cout<<Amatrix[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0; 
}
