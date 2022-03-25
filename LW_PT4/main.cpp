#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <random>
#include <cstring>

#include "Stack.h"
#include "Stack.cpp"
#include "StackElem.h"
#include "StackElem.cpp"
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

template<typename stType>
void stProc(void);
template<>
void stProc<char*>()
{
	stack<char*> st1;
	stack<char*> st2;
	int sw = 1;
	char* v = nullptr;
	int l;
	char* p;
	cout << "Enter type of stack processing: 0: exit, 1: cin>>stack1, 2: cin>>stack2, 3: cout<<stack1, 4: cout<<stack2, 5: stack1+=val, 6: stack2+=val, 7: -stack1, 8: -stack2, 9: stack1 = stack2;" << endl;
	try
	{
		cin >> sw;
		if (cin.bad() || cin.fail())
		{
			int a = 5;
			throw a;
		}
	}
	catch (int)
	{
		exit(1);
	}
	cout << endl;
	while (sw)
	{

		switch (sw)
		{
		case 1:
			cout << "Enter new values into the stack1 step by step:" << endl;
			cin >> st1;
			cout << endl;
			break;
		case 2:
			cout << "Enter new values into the stack2 step by step:" << endl;
			cin >> st2;
			cout << endl;
			break;
		case 3:
			cout << "Stack1 contents:" << endl;
			cout << st1 << endl;
			break;
		case 4:
			cout << "Stack2 contents:" << endl;
			cout << st2 << endl;
			break;
		case 5:
			cout << "Enter new element of stack1";
			cout << '\n';
			try {
				v = new char[20];
			}
			catch (bad_alloc e)
			{
				cout << "Size is null." << endl;
				exit(0);
			}
			cin.ignore();
			cin.getline(v, 20);
			st1 += v;
			cout << endl;
			break;
		case 6:
			cout << "Enter new element of stack2";
			cout << '\n';
			try {
				v = new char[20];
			}
			catch (bad_alloc e)
			{
				cout << "Size is null." << endl;
				exit(0);
			}
			
			cin.ignore();
			cin.getline(v, 20);
			st2 += v;
			cout << endl;
			break;
		case 7:
			cout << "Stack1 before:" << endl;
			cout << st1;
			cout << endl;
			-st1;
			cout << "Stack1 after:" << endl;
			cout << st1;
			cout << endl;
			break;
		case 8:
			cout << "Stack2 before:" << endl;
			cout << st2;
			cout << endl;
			-st2;
			cout << "Stack2 after:" << endl;
			cout << st2;
			cout << endl;
			break;
		case 9:
			cout << "Stack1:" << endl;
			cout << st1;
			cout << "Stack2:" << endl;
			cout << st2;
			cout << "Stack2 = stack1:" << endl;
			st2 = st1;
			cout << st2;
			cout << endl;
			break;
		default:
			cout << "Uncorrect mode. Try again:" << endl;
		}
		cout << "Enter type of stack processing: 0: exit, 1: cin>>stack1, 2: cin>>stack2, 3: cout<<stack1, 4: cout<<stack2, 5: stack1+=val, 6: stack2+=val, 7: -stack1, 8: -stack2, 9: stack1 = stack2;" << endl;
		try
		{
			cin >> sw;
			if (cin.bad() || cin.fail())
			{
				int a = 5;
				throw a;
			}
		}
		catch (int)
		{
			exit(1);
		}
		cout << endl;
	}
}

void avProc(void);
void stFab(void);

int main(void)
{
	int sw;
	cout << "Enter task: 0-exit, 1-average, 2-stack;" << endl;
	try
	{
		cin >> sw;
		if (cin.bad() || cin.fail())
		{
			int a = 5;
			throw a;
		}
	}
	catch (int)
	{
		exit(1);
	}
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
			stFab();
			break;
		default:
			cout << "Uncorrect mode. Try again:" << endl;
		}
		cout << "Enter task: 0-exit, 1-average, 2-stack;" << endl;
		try
		{
			cin >> sw;
			if (cin.bad() || cin.fail())
			{
				int a = 5;
				throw a;
			}
		}
		catch (int)
		{
			exit(1);
		}
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
	try
	{
		cin >> sw;
		if (cin.bad() || cin.fail())
		{
			int a = 5;
			throw a;
		}
	}
	catch (int)
	{
		exit(1);
	}
	cout << endl;
	while (sw)
	{
		switch (sw)
		{
		case 1:
			cout << "Enter size of array" << endl;
			cin >> size;
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
		try
		{
			cin >> sw;
			if (cin.bad() || cin.fail())
			{
				int a = 5;
				throw a;
			}
		}
		catch (int)
		{
			exit(1);
		}
		cout << endl;
		
		
	}
}
void stFab(void)
{
	int sw = 0;
	cout << "Enter type of stack: 0: exit, 1: char, 2: int, 3: float, 4: double, 5: char* (string);" << endl;
	try
	{
		cin >> sw;
		if (cin.bad() || cin.fail())
		{
			int a = 5;
			throw a;
		}
	}
	catch (int)
	{
		exit(1);
	}
	cout << endl;
	while (sw)
	{

		switch (sw)
		{
		case 1:
			stProc<char>();
			cout << endl;
			break;
		case 2:
			stProc<int>();
			cout << endl;
			break;
		case 3:
			stProc<float>();
			break;
		case 4:
			stProc<double>();
			break;
		case 5:
			stProc<char*>();
			break;
		default:
			cout << "Uncorrect mode. Try again:" << endl;
		}
		cout << "Enter type of stack: 0: exit, 1: char, 2: int, 3: float, 4: double, 5: char* (string);" << endl;
		try
		{
			cin >> sw;
			if (cin.bad() || cin.fail())
			{
				int a = 5;
				throw a;
			}
		}
		catch (int)
		{
			exit(1);
		}
		cout << endl;
	}
}

template<typename stType>
void stProc()
{
	stack<stType> st1;
	stack<stType> st2;
	int sw = 1;
	stType v = 0;
	cout << "Enter type of stack processing: 0: exit, 1: cin>>stack1, 2: cin>>stack2, 3: cout<<stack1, 4: cout<<stack2, 5: stack1+=val, 6: stack2+=val, 7: -stack1, 8: -stack2, 9: stack1 = stack2;" << endl;
	try
	{
		cin >> sw;
		if (cin.bad() || cin.fail())
		{
			int a = 5;
			throw a;
		}
	}
	catch (int)
	{
		exit(1);
	}
	cout << endl;
	while (sw)
	{
		
		switch (sw)
		{
		case 1:
			cout << "Enter new values into the stack1 step by step:" << endl;
			cin >> st1;
			cout << endl;
			break;
		case 2:
			cout << "Enter new values into the stack2 step by step:" << endl;
			cin >> st2;
			cout << endl;
			break;
		case 3:
			cout << "Stack1 contents:" << endl;
			cout << st1 << endl;
			break;
		case 4:
			cout << "Stack2 contents:" << endl;
			cout << st2 << endl;
			break;
		case 5:
			cout << "Enter new element of stack1" << endl;
			try {
				cin >> v;
				if (cin.peek() != '\n')
				{
					char e = 0;
					throw e;
				}
			}
			catch (char)
			{
				while (cin.get() != '\n');
				cout << "Too many characters!" << endl;
			}
			st1 += v;
			cout << endl;
			break;
		case 6:
			cout << "Enter new element of stack2" << endl;
			try {
				cin >> v;
				if (cin.peek() != '\n')
				{
					char e = 0;
					throw e;
				}
			}
			catch (char)
			{
				while (cin.get() != '\n');
				cout << "Too many characters!" << endl;
			}
			st2 += v;
			cout << endl;
			break;
		case 7:
			cout << "Stack1 before:" << endl;
			cout << st1;
			cout << endl;
			cout << "Deleting element: " << -st1 << endl;
			cout << endl;
			cout << "Stack1 after:" << endl;
			cout << st1;
			cout << endl;
			break;
		case 8:
			cout << "Stack2 before:" << endl;
			cout << st2;
			cout << endl;
			cout << "Deleting element: " << -st2 << endl;
			cout << endl;
			cout << "Stack2 after:" << endl;
			cout << st2;
			cout << endl;
			break;
		case 9:
			cout << "Stack1:" << endl;
			cout << st1;
			cout << "Stack2:" << endl;
			cout << st2;
			cout << "Stack2 = stack1:" << endl;
			st2 = st1;
			cout << st2;
			cout << endl;
			break;
		default:
			cout << "Uncorrect mode. Try again:" << endl;
		}
		cout << "Enter type of stack processing: 0: exit, 1: cin>>stack1, 2: cin>>stack2, 3: cout<<stack1, 4: cout<<stack2, 5: stack1+=val, 6: stack2+=val, 7: -stack1, 8: -stack2, 9: stack1 = stack2;" << endl;
		try
		{
			cin >> sw;
			if (cin.bad() || cin.fail())
			{
				int a = 5;
				throw a;
			}
		}
		catch (int)
		{
			exit(1);
		}
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





