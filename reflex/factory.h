
#ifndef FACTORY_H
#define FACTORY_H

#include <map>
#include <string>

typedef void * (* CreateFunction) ();

// 全局函数
namespace MS
{
	// 注册函数
	void registerClass(std::string className, CreateFunction pFun);

	// 创建对象
	void * getClassObjByName(std::string className);

	// 销毁工厂
	void destroyFactory();
};

// 唯一例
class QClassFactory
{
	friend void MS::registerClass(std::string, CreateFunction);
	friend void * MS::getClassObjByName(std::string);
	friend void MS::destroyFactory();

public:
	static QClassFactory * getFactory();

	virtual ~QClassFactory();

private:
	// 释放工厂
	static void destroyFactory();

	// 注册类
	void registerClass(std::string className, CreateFunction pFun);

	// 根据类名创建对象
	void * createObject(std::string className);

private:
	QClassFactory();

private:
	// 存储类名及创建函数指针
	std::map<std::string, CreateFunction> m_registerMap;

	// 唯一例对象指针
	static QClassFactory * m_factory;
	
};

#endif

