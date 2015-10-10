// 各装饰子类
#ifndef DECORATE_CLASS_H
#define DECORATE_CLASS_H

#include <iostream>
#include "Decorate.h"

// 1.衬衫类
class DecorateBlouse : public Decorate
{
public:
	DecorateBlouse()
		: Decorate()
	{
	}

	virtual void show()
	{
		std::cout << "衬衫 ";
		Decorate::show();
	}
};

// 2.牛仔裤类
class DecorateJeans : public Decorate
{
public:
	DecorateJeans()
		: Decorate()
	{
	}

	virtual void show()
	{
		display();
		Decorate::show();
	}

protected:
	void display()
	{
		std::cout << "牛仔裤 ";
		/*
		 	可执行一系列的操作
		 */
	}


};

#endif

