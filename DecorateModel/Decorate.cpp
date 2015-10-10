
#include "Decorate.h"

#define NULL 0

Decorate::Decorate()
	: m_obj(NULL)
{
}

Decorate::~Decorate()
{
}

void Decorate::DecorateObj(BaseClass *obj)
{
	m_obj = obj;
}

void Decorate::show()
{
	if(m_obj != NULL)
		m_obj -> show();
}

