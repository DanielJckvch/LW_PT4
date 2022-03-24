#include "StackElem.h"

template <typename sv>
stackElem<sv>::stackElem(void)
{
	val = 0;
	down = nullptr;
}
template <typename sv>
stackElem<sv>::~stackElem(void)
{}
template <typename sv>
sv stackElem<sv>::getval(void)
{
	return val;
}
template <typename sv>
void stackElem<sv>::setval(sv v)
{
	val = v;
}