
#ifndef TEST_H
#define TEST_H

#include "dynamic.h"

class QTest
{
	MS_DECLARE_CLASS(QTest)

public:
	QTest()
	{
	}

	static QTest * createObject()
	{
		return new QTest();
	}
	
	MS_PROPERTY(int, m_val)
	MS_PROPERTY(std::string, m_name)

private:
	int m_val;

	std::string m_name;

};

MS_REGISTER_CLASS(QTest)

#endif

