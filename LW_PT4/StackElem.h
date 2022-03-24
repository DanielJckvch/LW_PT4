#pragma once

template <typename sv>
class stackElem
{
private:
	sv val;
public:
	stackElem* down;
	stackElem(void);
	~stackElem(void);
	sv getval(void);
	void setval(sv v);
};
