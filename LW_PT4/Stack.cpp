#include "Stack.h"
#include <iostream>
#include <cstring>
using namespace std;
template <typename sv>
stack<sv>::stack(void)
{
	top = 0;
	size = 0;
}
template <typename sv>
stack<sv>::~stack(void)
{
	stackElem<sv>* temp = top;
	while (top)
	{
		temp = top;
		top = top->down;
		delete temp;
	}

}
template <typename sv>
int stack<sv>::getsize(void)
{
	return size;
}
template <typename sv>
stack<sv>& stack<sv>::operator=(stack<sv>& r)
{
	if (this == &r)
	{
		return *this;
	}
	stackElem<sv>* ptr1 = top;
	stackElem<sv>* ptr2;
	while (size)
	{
		ptr1 = top;
		top = top->down;
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
				top = new stackElem<sv>;
				ptr1 = top;
			}
			ptr1->setval(ptr2->getval());
			if (l)
			{
				ptr1->down = new stackElem<sv>;
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
template <typename sv>
sv stack<sv>::operator-()
{
	if (!top)
	{
		return 0;
	}
	sv v = top->getval();
	stackElem<sv>* temp = top;
	top = top->down;
	delete temp;
	size--;
	return v;
}
template <typename sv>
sv stack<sv>::operator+=(sv r)
{
	try
	{
		stackElem<sv>* temp = new stackElem<sv>;
		temp->down = top;
		temp->setval(r);
		top = temp;
		size++;
	}
	catch (bad_alloc e)
	{
		cout << "Error of operator new." << endl;
		exit(0);
	}
	return r;
}
