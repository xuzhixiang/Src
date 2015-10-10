
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "BaseClass.h"

// 装扮对象类
class Person : public BaseClass
{
public:
	Person(const std::string & name);

	virtual ~Person();

	virtual void show();

protected:
	std::string m_name;
	
};

#endif

