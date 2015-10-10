
#ifndef DECORATE_H
#define DECORATE_H

#include "BaseClass.h"

// 装饰基类
class Decorate : public BaseClass
{
public:
	Decorate();

	virtual ~Decorate();

	void DecorateObj(BaseClass *obj);

	virtual void show();

protected:
	BaseClass *m_obj;
	
};

#endif

