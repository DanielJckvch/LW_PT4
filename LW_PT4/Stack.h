#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "StackElem.h"
#include <iostream>
#include <cstring>
using namespace std;

template <typename sv>
class stack
{
private:
	stackElem<sv>* top;
	int size;
public:
	explicit stack(void);
	~stack(void);
	int getsize(void);
	stack<sv>& operator=(stack<sv>& r);
	sv operator-();
	sv operator+=(sv r);
	friend ostream& operator<<(ostream& o, stack<sv>& st)
	{
		try
		{
			stackElem<sv>* ptr = st.top;
			while (ptr)
			{
				if (o.bad() || o.fail())
				{
					int a = 5;
					throw a;
					break;
				}
				o << ptr->getval() << endl;
				ptr = ptr->down;
			}
		}
		catch (int)
		{
			exit(1);
		}
		return o;
	}
	friend istream& operator>>(istream& i, stack<sv>& st)
	{
		try
		{
			sv val = 0;
			stackElem<sv>* ptr = st.top;
			while (ptr)
			{
				if (i.bad() || i.fail())
				{
					int a = 5;
					throw a;
					break;
				}
				i >> val;
				ptr->setval(val);
				ptr = ptr->down;
			}
		}
		catch (int)
		{
			exit(1);
		}
		return i;
	}
};

template<>
class stack<char*>
{
private:
	stackElem<char*>* top;
	int size;
public:
	explicit stack(void)
	{
		top = 0;
		size = 0;
	}
	~stack(void)
	{
		stackElem<char*>* temp = top;
		while (top)
		{
			temp = top;
			top = top->down;
			delete temp->getval();
			delete temp;
		}

	}
	int getsize(void)
	{
		return size;
	}
	stack<char*>& operator=(stack<char*>& r)
	{
		if (this == &r)
		{
			return *this;
		}
		stackElem<char*>* ptr1 = top;
		stackElem<char*>* ptr2;
		char* p = nullptr;
		while (size)
		{
			ptr1 = top;
			top = top->down;
			delete ptr1->getval();
			delete ptr1;
			size--;
		}
		int l = r.getsize();
		ptr2 = r.top;
		try {
			while (l--)
			{
				if (!top)
				{
					top = new stackElem<char*>;
					ptr1 = top;
				}
				p = new char[20];
				strcpy(p, ptr2->getval());
				ptr1->setval(p);
				if (l)
				{
					ptr1->down = new stackElem<char*>;
				}
				ptr1 = ptr1->down;
				ptr2 = ptr2->down;
				size = size + 1;
			}
			if (ptr1)
			{
				ptr1->down = nullptr;
			}
		}
		catch (bad_alloc e)
		{
			cout << "Error of operator new." << endl;
			exit(0);
		}

		return *this;
	}
	stack<char*>& operator-()
	{
		if (!top)
		{
			return *this;
		}
		char* v = top->getval();
		stackElem<char*>* temp = top;
		top = top->down;
		delete temp->getval();
		delete temp;
		size--;
		return *this;
	}
	char* operator+=(char* r)
	{
		try {
			stackElem<char*>* temp = new stackElem<char*>;
			temp->down = top;
			temp->setval(r);
			top = temp;
			size++;
		}
		catch (bad_alloc e)
		{
			cout << "Size is null." << endl;
			exit(0);
		}

		return r;
	}
	friend ostream& operator<<(ostream& o, stack<char*>& st)
	{
		try {
			stackElem<char*>* ptr = st.top;
			while (ptr)
			{
				if (o.bad() || o.fail())
				{
					int a = 5;
					throw a;
					break;
				}
				o.write(ptr->getval(), strlen(ptr->getval())) << endl;
				ptr = ptr->down;
			}
		}
		catch (int)
		{
			exit(1);
		}
		return o;
	}
	friend istream& operator>>(istream& i, stack<char*>& st)
	{
		try {
			char* p;
			stackElem<char*>* ptr = st.top;
			while (ptr)
			{
				if (i.bad() || i.fail())
				{
					int a = 5;
					throw a;
					break;
				}
				p = new char[20];
				i.ignore();
				i.getline(p, 20);
				delete (ptr->getval());
				ptr->setval(p);
				ptr = ptr->down;
			}
		}
		catch (bad_alloc e)
		{
			cout << "Error of operator new." << endl;
			exit(0);
		}
		catch (int)
		{
			exit(1);
		}
		return i;
	}
};
