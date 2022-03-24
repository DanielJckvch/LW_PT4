#include "Stack.h"
#include <iostream>
using namespace std;

template <typename sv>
stack<sv>::stack(void)
{
	top = 0;
	size = 0;
}
template <typename sv>
stack<sv>::~stack(void){}
template <typename sv>
int stack<sv>::getsize(void)
{
	return size;
}
template <typename sv>
sv stack<sv>::operator=(sv r)
{
	stackElem<sv>* temp = new stackElem<sv>;
	temp->down = top;
	temp->setval(r);
	size++;
}
template <typename sv>
sv stack<sv>::operator-(void)
{
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
	stackElem<sv>* temp = new stackElem<sv>;
	temp->down = top;
	temp->setval(r);
	size++;
	return r;
}
template <typename sv>
ostream& operator<<(ostream& o, stack<sv>& st)
{
	stackElem<sv>* ptr = st.top;
	while (ptr)
	{
		o << ptr->getval();
	}
	o << endl;
	return o;
}