#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** r, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j);
void Print(int** r, const int rowCount, const int colCount, int i, int j);
void Sort(int** r, const int rowCount, const int colCount, int j);
void Change(int** r, const int row1, const int row2, const int colCount, int j, int rowCount);
int Calc(int** r, const int rowCount, const int colCount, int i, int j, int S, int k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -8;
	int High = 42;
	int rowCount = 8;
	int colCount = 7;
	int** r = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		r[i] = new int[colCount];
	Create(r, rowCount, colCount, Low, High, 0, 0);
	Print(r, rowCount, colCount, 0, 0);
	Sort(r, rowCount, colCount, 0);
	Print(r, rowCount, colCount, 0, 0);
	int S = 0;
	int k = 0;
	S = Calc(r, rowCount, colCount, 0, 0, S, k);
	cout << "S = " << S << endl;
	Print(r, rowCount, colCount, 0, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] r[i];
	delete[] r;
	return 0;
}
void Create(int** r, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	r[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(r, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(r, rowCount, colCount, Low, High, i + 1, 0);
}
void Print(int** r, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << r[i][j];
	if (j < colCount - 1)
		Print(r, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(r, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void Sort(int** r, const int rowCount, const int colCount, int j)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((r[i1][0] < r[i1 + 1][0])
				||
				(r[i1][0] == r[i1 + 1][0] &&
					r[i1][1] > r[i1 + 1][1])
				||
				(r[i1][0] == r[i1 + 1][0] &&
					r[i1][1] == r[i1 + 1][1] &&
					r[i1][3] < r[i1 + 1][3]))
				Change(r, i1, i1 + 1, colCount, 0, rowCount);
}
void Change(int** r, const int row1, const int row2, const int colCount, int j, int rowCount)
{
	int tmp;
	if (j < colCount)
	{
		tmp = r[row1][j];
		r[row1][j] = r[row2][j];
		r[row2][j] = tmp;
		j++;
	}
	Sort(r, rowCount, colCount, j);
}
int Calc(int** r, const int rowCount, const int colCount, int i, int j, int S, int k)
{
	if (r[i][j] % 2 != 0 && r[i][j] < 0)
	{
		S += r[i][j];
		k++;
	}
	if (j < colCount - 1)
		return Calc(r, rowCount, colCount, i, j + 1, S, k);
	else
		if (i < rowCount - 1)
			return Calc(r, rowCount, colCount, i + 1, 0, S, k);
		else
			cout << "k = " << k << endl;
	return S;
}
