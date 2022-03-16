#include <iostream>
#include <iomanip>
using namespace std;

void Input(int** a, const int rowCount, const int colCount, int rowNo);
void Input2(int** a, const int rowNo, const int colCount, int colNo);
void Show(int** a, const int rowCount, const int colCount, int rowNo);
void Show2(int** a, const int rowNo, const int colCount, int colNo);
void Find(int** a, int rowCount, const int colCount, int& min, int** y);
void Find2(int** a, int** y, const int rowCount, const int colCount, int rowNo, int colNo, int& min, int n,int & k);
void Find3(int** a, int** y, const int rowCount, const int colCount, int rowNo, int colNo, int& s1, int& s2, int& k);
void Switch2(int** a, int** y, const int rowCount, const int colCount, int rowNo, int colNo);
void Switch(int** a, int** y, const int rowCount, int colCount, int rowNo, int colNo);


int main()
{
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	int** y = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		y[i] = new int[colCount];
	Input(a, rowCount, colCount, 0);
	Show(a, rowCount, colCount, 0);
	int min = a[0][0];
	Find(a, rowCount, colCount, min,y);
	cout << min << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;


	for (int i = 0; i < rowCount; i++)
		delete[] y[i];
	delete[] y;
	return 0;
}

void Find(int** a, int rowCount, const int colCount,int &min,int **y)
{
	int s1, s2, k = rowCount,n=rowCount;


	Switch(a, y, rowCount,colCount,0,0);
	Find2(a, y, rowCount, colCount, 0, 0, min, n,k);

}

void Find2(int** a, int** y, const int rowCount, const int colCount, int rowNo, int colNo,int & min,int n,int & k)
{
	int s1 = 0, s2 = 0;
	Find3(a, y, rowCount, colCount, rowNo, colNo, s1, s2, k);

	if (s1 < min)
		min = s1;
	if (s2 < min)
		min = s2;
	k--;
	if (n>2)
	{
		Find2(a, y, rowCount, colCount, rowNo,colNo,min,n-1,k);
	}
}

void Find3(int** a, int** y, const int rowCount, const int colCount, int rowNo, int colNo,int &s1,int &s2,int &k)
{
	s1 += abs(a[rowNo][k - rowNo - 2]);
	s2 += abs(y[rowNo][k - rowNo - 2]);
	if (rowNo<k-2)
	{
		Find3(a, y, rowCount, colCount, rowNo + 1, colNo, s1, s2, k);
	}
}

void Switch(int** a, int** y, const int rowCount,int colCount,int rowNo,int colNo)
{
	Switch2(a, y, rowCount, colCount,rowNo,colNo);
	if (rowNo<rowCount-1)
	{
		Switch(a, y, rowCount, colCount, rowNo + 1, colNo);
	}


}

void Switch2(int** a, int** y, const int rowCount,const int colCount,int rowNo,int colNo)
{
	y[rowNo][colNo] = a[colCount - colNo - 1][rowCount - rowNo - 1];
	if (colNo< rowCount - rowNo-1)
	{
		Switch2(a, y, rowCount, colCount, rowNo, colNo + 1);
	}
	
}

void Input(int** a, const int rowCount, const int colCount, int rowNo)
{
	Input2(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
	{
		Input(a, rowCount, colCount, rowNo + 1);
	}
	else
	{
		cout << endl;
	}
}

void Input2(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < colCount - 1)
	{
		Input2(a, rowNo, colCount, colNo + 1);
	}
	else
	{
		cout << endl;
	}
}

void Show(int** a, const int rowCount, const int colCount, int rowNo)
{
	Show2(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
	{
		Show(a, rowCount, colCount, rowNo + 1);
	}
	else
	{
		cout << endl;
	}

}

void Show2(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
	{
		Show2(a, rowNo, colCount, colNo + 1);
	}
	else
	{
		cout << endl;
	}
}


