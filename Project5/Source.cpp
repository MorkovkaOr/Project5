#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"

const int ROWS = 3;
const int COLS = 5;

void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS);
void FillRand(double arr[ROWS][COLS], const int ROWS, const int COLS);
void FillRand(char arr[ROWS][COLS], const int ROWS, const int COLS);

void Print(int arr[ROWS][COLS], const int ROWS, const int COLS);
void Print(double arr[ROWS][COLS], const int ROWS, const int COLS);
void Print(char arr[ROWS][COLS], const int ROWS, const int COLS);


int Sum(int arr[ROWS][COLS], const int ROWS, const int COLS);
double Sum(double arr[ROWS][COLS], const int ROWS, const int COLS);


double Avg(double arr[ROWS][COLS], const int ROWS, const int COLS);
double Avg(int arr[ROWS][COLS], const int ROWS, const int COLS);
int MAX(int arr[ROWS][COLS], const int ROWS, const int COLS);
double MAX(double arr[ROWS][COLS], const int ROWS, const int COLS);
int MIN(int arr[ROWS][COLS], const int ROWS, const int COLS);
double MIN(double arr[ROWS][COLS], const int ROWS, const int COLS);


void shiftLeft(double arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts);
void shiftLeft(int arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts);
void shiftLeft(char arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts);

void Sort(int arr[ROWS][COLS], const int ROWS, const int COLS);
void Sort(double arr[ROWS][COLS], const int ROWS, const int COLS);

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


void Print(int arr[ROWS][COLS], const int ROWS, const int COLS)
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
void Print(double arr[ROWS][COLS], const int ROWS, const int COLS)
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
void Print(char arr[ROWS][COLS], const int ROWS, const int COLS)
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

int Sum(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}
double Sum(double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	double sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}


double Avg(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr, ROWS, COLS) / (ROWS * COLS);
}
double Avg(double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr, ROWS, COLS) / (ROWS * COLS);
}

double MAX(double arr[ROWS][COLS], const int ROWS, const int COLS)
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
int MAX(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int max = arr[0][0];
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
double MIN(double arr[ROWS][COLS], const int ROWS, const int COLS)
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
int MIN(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int min = arr[0][0];
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
void shiftLeft(int arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts)
{
	for (int b = 0; b < ROWS; b++)
	{
		for (int i = 0; i < number_of_shifts; i++)
		{
			int buffer = arr[b][0];
			for (int i = 0; i < COLS; i++)
			{
				arr[b][i] = arr[b][i + 1];
			}
			arr[b][COLS - 1] = buffer;
		}
	}
}
void shiftLeft(double arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts)
{
	for (int b = 0; b < ROWS; b++)
	{
		for (int i = 0; i < number_of_shifts; i++)
		{
			double buffer = arr[b][0];
			for (int i = 0; i < COLS; i++)
			{
				arr[b][i] = arr[b][i + 1];
			}
			arr[b][COLS - 1] = buffer;
		}
	}
}
void shiftLeft(char arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts)
{
	for (int b = 0; b < ROWS; b++)
	{
		for (int i = 0; i < number_of_shifts; i++)
		{
			char buffer = arr[b][0];
			for (int i = 0; i < COLS; i++)
			{
				arr[b][i] = arr[b][i + 1];
			}
			arr[b][COLS - 1] = buffer;
		}
	}
}

void Sort(int arr[ROWS][COLS], const int ROWS, const int COLS)
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
						int temp = arr[a][b];
						arr[a][b] = arr[i][j];
						arr[i][j] = temp;
					}
				}
			}
		}
	}
}
void Sort(double arr[ROWS][COLS], const int ROWS, const int COLS)
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
						int temp = arr[a][b];
						arr[a][b] = arr[i][j];
						arr[i][j] = temp;
					}
				}
			}
		}
	}
}