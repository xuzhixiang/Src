 
#include "dynamic.h"

QClassFactory * QClassFactory::m_factory = NULL;

namespace MS
{
	void registerClass(std::string className, CreateFunction pFun)
	{
		QClassFactory::getFactory() -> registerClass(className, pFun);
	}
	
	void * getClassObjByName(std::string className)
	{
		return QClassFactory::getFactory() -> createObject(className);
	}

	void destroyFactory()
	{
		clearRegisterList();
		QClassFactory::destroyFactory();
	}
};

QClassFactory * QClassFactory::getFactory()
{
	if(m_factory == NULL)
		m_factory = new QClassFactory;
	return m_factory;
}

QClassFactory::QClassFactory()
{
}

QClassFactory::~QClassFactory()
{
}

void QClassFactory::destroyFactory()
{
	delete m_factory;
	m_factory = NULL;
}

void QClassFactory::registerClass(std::string className, CreateFunction pFun)
{
	m_registerMap[className] = pFun;
}

void * QClassFactory::createObject(std::string className)
{
	return m_registerMap[className]();
}

