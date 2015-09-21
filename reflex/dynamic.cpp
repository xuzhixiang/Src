
#include "dynamic.h"

std::list<QRegisterClass *> QRegisterClass::m_registerList;

QRegisterClass::QRegisterClass(std::string className, CreateFunction pFun)
{
	MS::registerClass(className, pFun);
	// 先清掉之前生成的对象
	clearRegisterList();
	m_registerList.push_back(this);
}

void QRegisterClass::clearRegisterList()
{
	for(std::list<QRegisterClass *>::iterator it = m_registerList.begin(); it != m_registerList.end(); ++it)
	{
		std::list<QRegisterClass *>::iterator nit = it++;
		delete *nit;
		--it;
	}
	m_registerList.clear();
}	

namespace MS
{
	void clearRegisterList()
	{
		QRegisterClass::clearRegisterList();
	}
};

