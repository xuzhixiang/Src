
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "implicit_string.h"

namespace MS
{
	ms_string::ms_string()
		: m_data(NULL)
		, m_size(0)
	{
	}

	ms_string::ms_string(const char *data)
		: m_data(NULL)
		, m_size(0)
	{
		if(data == NULL)
			return;
		m_size = strlen(data);
		char *ptr = new char[m_size + 1];
		memcpy(ptr, data, m_size);
		m_data = new VAR(ptr);
	}

	ms_string::ms_string(const ms_string &str)
		: m_data(NULL)
		, m_size(0)
	{
		if(str.m_data != NULL)
		{
			m_data = new VAR(*(str.m_data)); // 调用 VAR 拷贝构造
			m_size = strlen(*(*m_data));
		}
	}

	ms_string & ms_string::operator=(const ms_string &str)
	{
		if(**m_data == **(str.m_data))
			return *this;
		destroy(); // 首先清空自己
		if(str.m_data != NULL)
		{
			m_data = new VAR(*(str.m_data)); // 调用 VAR 拷贝构造
			m_size = strlen(*(*m_data));
		}
		return *this;
	}

	ms_string::~ms_string()
	{
		destroy();
	}

	const char ms_string::at(size_t index) const
	{
		if(index > m_size || m_size == 0)
		{
			printf("out of orange\n");
			exit(-1);
		}
		return (**m_data)[index];
	}
	
	char & ms_string::test(size_t index)
	{
		if(index > m_size || m_size == 0)
		{
			printf("out of orange\n");
			exit(-1);
		}
		return (**m_data)[index];
	}

	char & ms_string::operator[](size_t index)
	{
		if(index > m_size || m_size == 0)
		{
			printf("out of orange\n");
			exit(-1);
		}
		if(m_data -> isSignal())
			return (**m_data)[index];
		char *ptr = new char[m_size + 1];
		memcpy(ptr, **m_data, m_size);
		// 重新构建智能指针
		delete m_data;
		m_data = new VAR(ptr);
		return ptr[index];
	}

	const char ms_string::operator[](size_t index) const
	{
		return at(index);
	}

	const char * ms_string::c_str() const
	{
		return **m_data;
	}

	const char * ms_string::data() const
	{
		c_str();
	}

	ms_string & ms_string::append(const char c)
	{
		if(c == 0)
			return *this;
		m_size++;
		char *ptr = new char[m_size + 1];
		memcpy(ptr, **m_data, m_size);
		ptr[m_size - 1] = c;
		delete m_data;
		m_data = new VAR(ptr);
		return *this;
	}
	
	ms_string & ms_string::append(const char * val)
	{
		if(val == NULL)
			return *this;
		size_t size = strlen(val);
		m_size += size;
		char *ptr = new char[m_size + size + 1];
		sprintf(ptr, "%s%s", **m_data, val);
		delete m_data;
		m_data = new VAR(ptr);
		return *this;
	}
	
	ms_string & ms_string::append(const ms_string & str)
	{
		append(str.c_str());
	}

	size_t ms_string::size() const
	{
		return m_size;
	}

	void ms_string::destroy()
	{
		if(m_data != NULL)
		{
			delete m_data;
			m_data = NULL;
		}
		m_size = 0;
	}
};

