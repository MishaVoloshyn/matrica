//Тема: шаблоны

//Задание

//Создайте шаблонный класс матрица.
//Необходимо реализовать динамическое выделение памяти+, очистку памяти+,
//заполнение матрицы с клавиатуры, заполнение случайными значениями+, 
//отображение матрицы+, арифметические операции с помощью перегруженных операторов(+, -, *, / ),
//поиск максимального+ и минимального элемента+.

//Реализовать собственный класс А(с перегрузками), и использовать в шаблоне класса.
#include <iostream>
using namespace std;

template<typename T>
class matrica 
{
private:
	int m;
	int n;
	T** Matr;
public:
	matrica()
	{
		m = 0;
		n = 0;
	}
	matrica(int x, int y)
	{
		m = x;
		n = y;
		Matr = (T**) new T* [m];
		for (int i = 0; i < m; i++)
		{
			Matr[i] =(T*) new T[n];
		}
		for (int i = 0; i < m; i++)
		{
			for (int k = 0; k < n; k++)
			{
				Matr[i][k] = rand() % 20;
			}
		}
	}

	void InputKlaviatura(int x, int y)
	{
		m = x;
		n = y;

		Matr = new T * [m];
		for (int i = 0; i < m; i++)
		{
			Matr[i] = new T[n];
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << "Enter Value in row: " << i + 1 << " col: " << j + 1 << "  : ";
				cin >> Matr[i][j];
			}
		}
	}
	void Print(const char* Obj)
	{
		cout<< Obj << endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << Matr[i][j] << "\t";
			cout << endl;
		}
		cout << endl << endl;
	}
	T FindMinValue()
	{
		T min = Matr[0][0];
		for (int i = 0; i < m; i++)
		{
			for (int k = 0; k < n; k++)
			{
				if (Matr[i][k] < min)
				{
					min = Matr[i][k];
				}
			}
		}
		return min;
	}
	T FindMaxValue()
	{
		T max = Matr[0][0];
		for (int i = 0; i < m; i++)
		{
			for (int k = 0; k < n; k++)
			{
				if (Matr[i][k] > max)
				{
					max = Matr[i][k];
				}
			}
		}
		return max;
	}
	~matrica()
	{
		for (int  i = 0; i < m; i++)
		{
			delete[] Matr[i];
		}
	}
};
int main()
{
	matrica<int> M(2, 3);
	M.Print("Matrica test 1");

	int minNum;
	minNum = M.FindMinValue();
	cout << "Min Value in matrica: " << minNum << endl << endl;

	int maxNum;
	maxNum = M.FindMaxValue();
	cout << "Max Value in matrica: " << maxNum << endl << endl;



	matrica<int> M2;
	int rows;
	int cols;
	cout << "Enter Rows";
	cin >> rows;
	cout << "Enter Cols";
	cin >> cols;

	M2.InputKlaviatura(rows, cols);
	M2.Print("Matrica test 2");

	int minNum2;
	minNum2 = M2.FindMinValue();
	cout << "Min Value in matrica: " << minNum2 << endl << endl;

	int maxNum2;
	maxNum2 = M2.FindMaxValue();
	cout << "Max Value in matrica: " << maxNum2 << endl << endl;

}
