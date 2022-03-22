#include <iostream>
#include <random>
#include <cstring>

using namespace std;

/*
Вариант 2

Задание 1
Написать функцию-шаблон, вычисляющую среднее арифметическое по значениям в массиве.
Размер массива задается пользователем, значения массива генерируются случайным образом (от 0 до 50).
Задание 2
Создать параметризованный стек с перегруженными операторами потокового ввода/вывода,
оператор присваивания =, оператор += для добавления в стек, оператор – для извлечения из стека.
*/

template <typename v>
double getaverage(v*, int size);

template <typename v>
double getaverage(v**, int size);


void avProc(void);
//void stProc(void);
int main(void)
{
	int sw;
	cout << "Enter task: 0-exit, 1-average, 2-stack;" << endl;
	cin >> sw;
	cout << endl;
	while (sw) {

		switch (sw)
		{
		case 0:
			return 0;
		case 1:
			avProc();
			break;
		case 2:
			//stProc();
			break;
		default:
			cout << "Uncorrect mode. Try again:" << endl;
		}
		cout << "Enter class mode: 0-exit, 1-double digit, 2-stack;" << endl;
		cin >> sw;
		cout << endl;
	}
	return 0;
}

void avProc(void)
{
	random_device rd;   // non-deterministic generator
	mt19937 gen(rd());
	int size;
	int type;
	int sw = 1;
	char* a1 = nullptr;
	int* a2 = nullptr;
	float* a3 = nullptr;
	double* a4 = nullptr;
	char** a5 = nullptr;
	double v = 0.0;
	cout << "Enter type of array: 0: exit, 1: char, 2: int, 3: float, 4: double, 5: string;" << endl;
	cin >> sw;
	cout << endl;
	while (sw)
	{
		switch (sw)
		{
		case 1:
			cout << "Enter size of array" << endl;
			cin >> size;
			//cout << endl;
			try {
				if (!size)
				{
					throw 10;
				}
			}
			catch (...)
			{
				cout << "Size is null." << endl;
				exit(0);
			}
			cout << endl;
			try {
				a1 = new char[size];
			}
			catch (bad_alloc e)
			{
				cout << "Memory(char) isn't assigned" << endl;
				exit(0);
			}
			
			for (int i = 0; i < size; i++)
			{
				a1[i] = gen() % 51;
			}
			cout.setf(ios::dec);
			for (int i = 0;i < size; i++)
			{
				cout << static_cast<int>(a1[i]) << ' ';
			}
			cout.unsetf(ios::dec);
			cout << endl;
			cout << "Average mean: " << getaverage(a1, size) << endl;
			delete[] a1;
			a1 = nullptr;
			cout << endl;
			break;
		case 2:
			cout << "Enter size of array" << endl;
			cin >> size;
			//cout << endl;
			try {
				if (!size)
				{
					throw 10;
				}
			}
			catch (...)
			{
				cout << "Size is null." << endl;
				exit(0);
			}
			cout << endl;
			try {
				a2 = new int[size];
			}
			catch (bad_alloc e)
			{
				cout << "Memory(int) isn't assigned" << endl;
				exit(0);
			}
			for (int i = 0; i < size; i++)
			{
				a2[i] = gen() % 51;
			}
			for (int i = 0;i < size; i++)
			{
				cout << a2[i] << ' ';
			}
			cout << endl;
			cout << "Average mean: " << getaverage(a2, size) << endl;
			delete[] a2;
			a2 = nullptr;
			cout << endl;
			break;
		case 3:
			cout << "Enter size of array" << endl;
			cin >> size;
			//cout << endl;
			try {
				if (!size)
				{
					throw 10;
				}
			}
			catch (...)
			{
				cout << "Size is null." << endl;
				exit(0);
			}
			try {
				a3 = new float[size];
			}
			catch (bad_alloc e)
			{
				cout << "Memory(float) isn't assigned" << endl;
				exit(0);
			}

			for (int i = 0; i < size; i++)
			{
				a3[i] = static_cast<float>((gen() % 5001)) / 100.0;
			}
			for (int i = 0;i < size; i++)
			{
				cout << a3[i] << ' ';
			}
			cout << endl;
			cout << "Average mean: " << getaverage(a3, size) << endl;
			delete[] a3;
			a3 = nullptr;
			cout << endl;
			break;
		case 4:
			cout << "Enter size of array" << endl;
			cin >> size;
			//cout << endl;
			try {
				if (!size)
				{
					throw 10;
				}
			}
			catch (...)
			{
				cout << "Size is null." << endl;
				exit(0);
			}
			cout << endl;
			try {
				a4 = new double[size];
			}
			catch (bad_alloc e)
			{
				cout << "Memory(double) isn't assigned" << endl;
				exit(0);
			}

			for (int i = 0; i < size; i++)
			{
				a4[i] = static_cast<double>((gen() % 50001)) / 1000.0;
			}
			for (int i = 0;i < size; i++)
			{
				cout << a4[i] << ' ';
			}
			cout << endl;
			cout << "Average mean: " << getaverage(a4, size) << endl;
			delete[] a4;
			a4 = nullptr;
			cout << endl;
			break;
		case 5:
			cout << "Enter size of array" << endl;
			cin >> size;
			//cout << endl;
			try {
				if (!size)
				{
					throw 10;
				}
			}
			catch (...)
			{
				cout << "Size is null." << endl;
				exit(0);
			}
			cout << endl;
			try {
				a5 = new char*[size];
			}
			catch (bad_alloc e)
			{
				cout << "Memory(string) isn't assigned" << endl;
				exit(0);
			}
			try
			{
				for (int i = 0; i < size; i++)
				{
					int strSize = gen() % 50 + 1;
					a5[i] = new char[strSize];
					int j = 0;
					for (j = 0; j < strSize - 2;j++)
					{
						a5[i][j] = gen() % 50 + 1;
					}
					a5[i][j] = '\n';
					a5[i][j] = 0;
				}
			}
			catch (bad_alloc e)
			{
				cout << "Memory(string) isn't assigned" << endl;
				exit(0);
			}
			for (int i = 0;i < size; i++)
			{
				int strSize = strlen(a5[i]);
				for (int j = 0; j < strSize;j++)
				{
					cout << static_cast<int>(a5[i][j]) << ' ';
				}
				cout << endl;
				
			}
			cout << endl;
			cout << "Average mean: " << getaverage(a5, size) << endl;
			for (int i = 0; i < size;i++)
			{
				delete a5[i];
			}
			delete[] a5;
			a5 = nullptr;
			cout << endl;
			break;
		default:
			cout << "Uncorrect mode. Try again:" << endl;
		}
		cout << "Enter type of array: 0: exit, 1: char, 2: int, 3: float, 4: double, 5: string;" << endl;
		cin >> sw;
		cout << endl;
		
		
	}
}

template <typename v>
double getaverage(v* arr, int size)
{
	double sum = 0;
	for (int i = 0;i < size;i++)
	{
		sum += arr[i];
	}
	return sum / size;
}

template <typename v>
double getaverage(v** arr, int size)
{
	double sum = 0;
	for (int i = 0;i < size;i++)
	{
		sum += getaverage(arr[i], strlen(arr[i]));
	}
	return sum / size;
}
