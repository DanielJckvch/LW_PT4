#pragma once
#include "StackElem.h"
#include <iostream>
using namespace std;
template <typename sv>
class stack
{
	//дндекюрэ ярей
private:
	stackElem<sv>* top;
	int size;
public:
	explicit stack(void);
	~stack(void);
	int getsize(void);
	sv operator=(sv r);
	sv operator-(void);
	sv operator+=(sv r);
	friend ostream& operator<<(ostream& o, stack<sv> st);
	//istream& operator>>(istream& i);
};

