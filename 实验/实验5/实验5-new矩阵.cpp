#include<iostream>
using namespace std;
void transposedMatrix(int matrix[][3],int temp[][3])
{
    int i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            temp[i][j] = matrix[j][i];
        }
    }
}
void showMatrix(int matrix[][3])
{
    int i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}
int main()
{
    int (*matrix)[3]=new int[3][3];
    int (*tmatrix)[3]=new int[3][3];
    int i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            cin>>matrix[i][j];
        }
    }
    // showMatrix(matrix);
    transposedMatrix(matrix,tmatrix);
    showMatrix(tmatrix);
    delete matrix;
    delete tmatrix;
    return 0;
}
