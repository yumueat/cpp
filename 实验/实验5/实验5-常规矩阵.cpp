#include<iostream>
using namespace std;
void transposedMatrix(int matrix[][3],int temp[][3])
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            temp[j][i]=matrix[i][j];
        }
    }
}
void show (int matrix[][3])
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cout<<matrix[i][j]<<' ';
        }
        cout<<endl;
    }
}
int main()
{
    int matrix[3][3],tmatrix[3][3];
    int i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            cin>>matrix[i][j];
        }
    }
    transposedMatrix(matrix,tmatrix);
    show(tmatrix);
    return 0;
}
