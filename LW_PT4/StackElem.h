#pragma once

template <typename sv>
class stackElem
{
private:
	sv val;
public:
	stackElem<sv>* down;
	stackElem(void);
	~stackElem(void);
	sv getval(void);
	void setval(sv v);
};
