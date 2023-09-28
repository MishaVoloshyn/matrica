//Тема: шаблоны

//Задание

//Создайте шаблонный класс матрица.
//Необходимо реализовать динамическое выделение памяти+, очистку памяти+,
//заполнение матрицы с клавиатуры, заполнение случайными значениями+, 
//отображение матрицы, арифметические операции с помощью перегруженных операторов(+, -, *, / ),
//поиск максимального и минимального элемента.

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
	void Print(const char* Obj)
	{
		cout << "Object: " << Obj << endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << Matr[i][j] << "\t";
			cout << endl;
		}
		cout << endl << endl;
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

}
