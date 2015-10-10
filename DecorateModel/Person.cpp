
#include <iostream>
#include "Person.h"

Person::Person(const std::string & name)
	: m_name(name)
{
}

Person::~Person()
{
}

void Person::show()
{
	std::cout << "装扮的 " << m_name;
}

