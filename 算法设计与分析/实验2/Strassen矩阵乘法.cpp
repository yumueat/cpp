#include <iostream>
#define MAX 10
using namespace std;
class Matrix
{
public:
	Matrix(int nn) : n(nn)
	{
		int i, j;
		for (i = 0; i < MAX; i++)
		{
			for (j = 0; j < MAX; j++)
			{
				data[i][j] = 0;
			}
		}
	}
	void set_matrix()
	{
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				cin >> data[i][j];
			}
		}
	}
	void show_matrix()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}
	Matrix operator*(const Matrix &B) const
	{
		Matrix C(n);
		int i, j, k;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (k = 0; k < n; k++)
				{
					C.data[i][j] += this->data[i][k] * B.data[k][j];
				}
			}
		}
		return C;
	}
	Matrix operator+(const Matrix &B) const
	{
		Matrix C(n);
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				C.data[i][j] = this->data[i][j] + B.data[i][j];
			}
		}
		return C;
	}
	Matrix operator-(const Matrix &B) const
	{
		Matrix C(n);
		int i, j;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				C.data[i][j] = this->data[i][j] - B.data[i][j];
			}
		}
		return C;
	}
	Matrix decompose(int pos)
	{
		Matrix A(n / 2);
		int i, j;
		if (pos == 1)
		{
			for (i = 0; i < n / 2; i++)
			{
				for (j = 0; j < n / 2; j++)
				{
					A.data[i][j] = this->data[i][j];
				}
			}
		}
		else if (pos == 2)
		{
			for (i = 0; i < n / 2; i++)
			{
				for (j = 0; j < n / 2; j++)
				{
					A.data[i][j] = this->data[i][n / 2 + j];
				}
			}
		}
		else if (pos == 3)
		{
			for (i = 0; i < n / 2; i++)
			{
				for (j = 0; j < n / 2; j++)
				{
					A.data[i][j] = this->data[n / 2 + i][j];
				}
			}
		}
		else if (pos == 4)
		{
			for (i = 0; i < n / 2; i++)
			{
				for (j = 0; j < n / 2; j++)
				{
					A.data[i][j] = this->data[n / 2 + i][n / 2 + j];
				}
			}
		}
		return A;
	}
	int data[MAX][MAX];
	int n;
};
Matrix combine(Matrix A11, Matrix A12, Matrix A21, Matrix A22)
{
	Matrix A(2 * A11.n);
	int i, j;
	for (i = 0; i < A11.n; i++)
	{
		for (j = 0; j < A11.n; j++)
		{
			A.data[i][j] = A11.data[i][j];
			A.data[i][j + A11.n] = A12.data[i][j];
			A.data[i + A11.n][j] = A21.data[i][j];
			A.data[i + A11.n][j + A11.n] = A22.data[i][j];
		}
	}
	return A;
}
Matrix Strassen(Matrix A, Matrix B)
{
	Matrix A11 = A.decompose(1);
	Matrix A12 = A.decompose(2);
	Matrix A21 = A.decompose(3);
	Matrix A22 = A.decompose(4);
	Matrix B11 = B.decompose(1);
	Matrix B12 = B.decompose(2);
	Matrix B21 = B.decompose(3);
	Matrix B22 = B.decompose(4);
	Matrix S1 = B12 - B22;
	Matrix S2 = A11 + A12;
	Matrix S3 = A21 + A22;
	Matrix S4 = B21 - B11;
	Matrix S5 = A11 + A22;
	Matrix S6 = B11 + B22;
	Matrix S7 = A12 - A22;
	Matrix S8 = B21 + B22;
	Matrix S9 = A11 - A21;
	Matrix S10 = B11 + B12;
	Matrix P1 = A11 * S1;
	Matrix P2 = S2 * B22;
	Matrix P3 = S3 * B11;
	Matrix P4 = A22 * S4;
	Matrix P5 = S5 * S6;
	Matrix P6 = S7 * S8;
	Matrix P7 = S9 * S10;
	Matrix C11 = P5 + P4 - P2 + P6;
	Matrix C12 = P1 + P2;
	Matrix C21 = P3 + P4;
	Matrix C22 = P5 + P1 - P3 - P7;
	Matrix res = combine(C11, C12, C21, C22);
	return res;
}
int main()
{
	Matrix A(4);
	A.set_matrix();
	Matrix B(4);
	B.set_matrix();
	Matrix C = Strassen(A, B);
	C.show_matrix();
	return 0;
}
