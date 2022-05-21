#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"

const int ROWS = 3;
const int COLS = 5;

void FillRand(double arr[ROWS][COLS], const int ROWS, const int COLS);
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS);
void FillRand(char arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>
void Print(T arr[ROWS][COLS], const int ROWS, const int COLS);


template<typename T>
T Sum(T arr[ROWS][COLS], const int ROWS, const int COLS);


template<typename T>
double Avg(T arr[ROWS][COLS], const int ROWS, const int COLS);
template<typename T>
T MAX(T arr[ROWS][COLS], const int ROWS, const int COLS);
template<typename T>
T MIN(T arr[ROWS][COLS], const int ROWS, const int COLS);


template<typename T>
void shiftLeft(T arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts);

template<typename T>
void Sort(T arr[ROWS][COLS], const int ROWS, const int COLS);


void main()
{
	setlocale(LC_ALL, "");
	int arr[ROWS][COLS];
	FillRand(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	cout << "Сумма элементов массива: " << Sum(arr, ROWS, COLS) << endl;
	cout << "Среднее арифмектическое элементов массива: " << Avg(arr, ROWS, COLS) << endl;

	Print(arr, ROWS, COLS);

	int number_of_shifts;
	cout << "Введите количество сдвигов влево: "; cin >> number_of_shifts;
	shiftLeft(arr, ROWS, COLS, number_of_shifts);
	Print(arr, ROWS, COLS);
	cout << endl;
	Sort(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);

	cout << delimiter << endl;

	double arr_d[ROWS][COLS];
	FillRand(arr_d, ROWS, COLS);
	Print(arr_d, ROWS, COLS);
	cout << "Сумма элементов массива: " << Sum(arr_d, ROWS, COLS) << endl;
	cout << "Среднее арифмектическое элементов массива: " << Avg(arr_d, ROWS, COLS) << endl;

	Print(arr_d, ROWS, COLS);

	int number_of_shifts_d;
	cout << "Введите количество сдвигов влево: "; cin >> number_of_shifts_d;
	shiftLeft(arr_d, ROWS, COLS, number_of_shifts_d);
	Print(arr_d, ROWS, COLS);
	cout << endl;
	Sort(arr_d, ROWS, COLS);
	Print(arr_d, ROWS, COLS);

	cout << delimiter << endl;
	char arr_c[ROWS][COLS];
	FillRand(arr_c, ROWS, COLS);
	Print(arr_c, ROWS, COLS);

	int number_of_shifts_c;
	cout << "Введите количество сдвигов влево: "; cin >> number_of_shifts_c;
	shiftLeft(arr_c, ROWS, COLS, number_of_shifts_c);
	Print(arr_c, ROWS, COLS);
}

void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = double(rand() % 100000) / 100;
		}
	}
}
void FillRand(char arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand();
		}
	}
}

template<typename T>
void Print(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

template<typename T>
T Sum(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	T sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}


template<typename T>
double Avg(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr, ROWS, COLS) / (ROWS * COLS);
}

template<typename T>
T MAX(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	double max = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	}
	return max;
}

template<typename T>
T MIN(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	double min = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] < min)
			{
				min = arr[i][j];
			}
		}
	}
	return min;
}
template<typename T>
void shiftLeft(T arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts)
{
	for (int b = 0; b < ROWS; b++)
	{
		for (int i = 0; i < number_of_shifts; i++)
		{
			T buffer = arr[b][0];
			for (int i = 0; i < COLS; i++)
			{
				arr[b][i] = arr[b][i + 1];
			}
			arr[b][COLS - 1] = buffer;
		}
	}
}

template<typename T>
void Sort(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int a = 0; a < ROWS; a++)
			{
				for (int b = 0; b < COLS; b++)
				{
					if (arr[a][b] > arr[i][j])
					{
						T temp = arr[a][b];
						arr[a][b] = arr[i][j];
						arr[i][j] = temp;
					}
				}
			}
		}
	}
}