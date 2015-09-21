
#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <list>
#include "factory.h"

namespace MS
{
	// 释放注册类对象
	void clearRegisterList();
};

// 注册类，每构造一个对象便注册一个类
class QRegisterClass
{
	friend void MS::clearRegisterList();

public:
	QRegisterClass(std::string className, CreateFunction pFun);

private:
	// 释放所有的已创建注册类对象
	inline static void clearRegisterList();

private:
	// 存储所有的对象，方便释放
	static std::list<QRegisterClass *> m_registerList;
};

// 定义宏(定义私有的注册对象，利用静态编译时方便注册，不可继承)
#define MS_DECLARE_CLASS(class_name) \
	private: \
		static QRegisterClass * m_##class_name##dr;
		
// 注册宏(构造注册对象，且所有的对象必需存在 static createObject 函数来构造本身)
#define MS_REGISTER_CLASS(class_name) \
	QRegisterClass * class_name::m_##class_name##dr = \
		new QRegisterClass(#class_name, (CreateFunction)class_name::createObject);

// 属性构造器
#define MS_PROPERTY(TYPE, val) \
	void set##val(TYPE val) { \
		this -> val = val; \
	} \
	TYPE get##val() { \
		return val; \
	}
		
#endif

